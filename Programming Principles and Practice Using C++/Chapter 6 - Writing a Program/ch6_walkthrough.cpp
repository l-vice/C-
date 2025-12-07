#include "std_lib_facilities.h"
/*

// Calculator

// HELPERS [H]


// FLOATING-POINT % [MOD]
double dbl_modulo(const double& xval1, const double& xval2) 
{
    double a = xval1;
    double b = xval2;
    return a - b * trunc(a / b);
}

// r = a - b * floor(a/b);
double remainder_val(double& a, double& b) 
{
    double r;
    r = a - b * floor(a/b);

    return r;
}

// MAIN [M]

// Issues: 
//  P1. PEMDAS does not work. Writing 2+3*6 will produce a wrong result (30 instead of 20). We need to fix this by looking ahead in our code.
//  Solutions:
//  S1. To solve the first problem we can apply tokenization.
//  Terminology: 
//  T1: Token: Sequence of characters that represents something we consider a unit, such as a number or an operator.
//  T2: Constructor: This is a special type of function called "constructor". These functions have the same names as their types, and are used to construct and initialize Token objects. Constructors do not return a value and there is not return type designed.  
//


Parsing inputs:
Ex. 45 + 11.5 * 7



                                                                                Expression
                                                                                    ^
                                                    Expression -------------------- | -------------------- Term   
                                                        |                           |                        ^
Expression:                                             |                           |                        |
    Term                                               Term                         | -------- Term -------- | --------            
    Expression '+':                                     |                           |           |            |          |
    Expression '-':                                     |                           |           |            |          |
Term:                                                Primary                        |         Primary        |        Primary  
    Primary                                             |                           |           |            |          |
    Expression '*':                                     |                           |           |            |          |
    Expression '/':                                     |                           |           |            |          |
    Expression '%':                                     |                           |           |            |          |
Primary:                                              Number                        |         Number         |        Number 
    Number:                                             |                           |           |            |          |
    "("Expression")"                                    |                           |           |            |          |
Number:                                      floating-point literal                 |           |            |          |          
    floating-point literal                              |                           |           |            |          |
                                                        2                           +          11.5          *          7


// We write one function for each grammar rule and use our Token to represent tokens. A program that implements grammar is often called a parser. 
// Lets set an example:

// get_token() // read characters and compose tokens, uses cin
// expression() // deals with '+' and '-', calls term() and get_token()
// term() // deal with "*", "\", and "%", calls primary() and get_token()
// primary() deal with numbers and parentheses, calls expression() and get_token()
// Point: Recursion is used to describe what happens when a function calls itself. Not all recursions are infinite, and recursion is a very useful programming technique.
*/

// 6.5.2.1 CALCULATOR
// 8+6*19+12+14
// Let '8' represent a number (fpv or integer)
// All else being standard.
// 8 = t.kind('8'), t.value(8);+ = t.kind('+'), t.value(0);6 = t.kind('8'), t.kind(6);* = t.kind('8'), t.value(0);19 = t.kind('8'), t.value(19);+ = t.kind('+'), t.value(0);12 = t.kind('8'), t.value(12);+ = t.kind('+'), t.value(0);14 = t.kind('8'), t.value(14);  

// -------------------------------------------------------------------------------------------------------- [TKN] --------------------------------------------------------------------------------------------------------

class Token{
    public:
        char kind;
        double value;
        Token(char ch)
            :kind(ch), value(0) {}
        Token(char ch, double val)
            :kind(ch), value(val) {}
};

Token get_token(); // reads characters and composes tokens (seems like it doesnt work with g++ compiler)

// Token_stream function [TSTREAM]
// This is an input stream that deals with tokens and that we can put back an already read token back into.
// Three member functions
// 1. get() = This function "returns" the next token
// 2. putback(t) = This function puts back t into the stream, which is an already read token.
// 3. Constructor = This is a function that constructs the previous two. 

class Token_stream{
    public:
        Token_stream();
        Token get(); 
        void putback(Token t);
        // user interface
    private:
        bool full; // In here we ask whether there is a token in the buffer.
        Token buffer; // This is the "location" where we store the token from the Token putback()   
        // implementation details
        // (not directly accessible to users of Token_stream)
};   

// 1. Constructor
// This function just sets full to false to indicate that the buffer is empty.
// Token: Every token MUST BE intialized.

Token_stream::Token_stream()
    :full(false),buffer(0) // no Token in buffer
{
}

// 2. putback() function 
// This function puts back its argument back into the Token_strems buffer

void Token_stream::putback(Token t)
{
    if(full = true)
        throw std::logic_error("[std::logic_error]: putback() into a full buffer");
    buffer = t; // copy t to buffer
    full = true; // buffer is now full
}

// 3. get() function
// This function ensures that if there isnt already a token in Token_streams::buffer, get() must read characters from cin and compose them into Tokens.

Token Token_stream::get()
{
    if(full) // Check: do we already have a token?
    {// If yes, we remove the Token from buffer.
        full=false;
        return buffer;
    }

    char ch;
    cin>>ch; // note that >> skips whitespace (space, newline, tab, etc...)
    
    switch(ch)
    {
        case ';': // ';' for print
        case 'q': // 'q' for quit
        case '(': case ')': case '+': case '-': case '*': case '/': case '%': 
            return Token(ch); // we let each character represent itself.
        case '.': // a numeric literal must start with a digit or '.'
        case '0': case '1': case '2': case '3': case '4': case '5':
        case '6': case '7': case '8': case '9':
        {// we open the parentheses because we must assign new values.
            cin.putback(ch); // put digit back into the input stream
            double val;
            cin>>val;
            return Token('8', val); // '8' represents a digit(fpv in this case), and the value is the value read by cin.
        }
        default:
            throw std::invalid_argument("[std::invalid_argument]: Bad token input.");
    }
}


Token_stream ts; 

// -------------------------------------------------------------------------------------------------------- [EXP] --------------------------------------------------------------------------------------------------------
// Expression:
// Term
//  Expression '+' Term
// Expression '-' Term

// 2 + 16 * 8
// 2 --> Integer --> Number --> Primary --> Expression
// + --> Expression
// 16 -> Integer --> Number --> Primary --> Term
// * --> Term ('*' preceeds '+' or '-')
// 8 --> Integer --> Number --> Primary       
double expression() // deal with '+' and '-'
{
    double left = term(); // read and evaluate an Expression
    Token t = get_token(); // get the next token
    while(true)
    {
        switch(t.kind) // see which kind of token it is
        {
            case '+':
                left+=term(); // read and evaluate a Term, then do an add
                t = get_token();
                break;
            case '-':
                left-=term(); // read and evaluate a Term, then do a subtraction
                t = get_token();
                break;
            default: // once there are no more '+' or '-' return the left value or lval.
                return left;
        }
    }
}

// Term:
// Primary
// Expression '*' Primary
// Expression '/' Primary
// Expression '%' Primary

// r = a - b * floor(a/b)

double mod_fpv(double& a, double& b)
{
    double r;
    r = a - b * floor(a/b);

    return r;
}

double term() // deal with '*' '/', and '%'
{
    double left = primary(); // read and evaluate a Term
    Token t = get_token(); // get the next token
    while(true)
    {
        switch(t.kind)
        {
            case '*':
                left*=term();
                t = get_token();
                break;
            case '/':
            {
                double d = primary();
                if(d == 0) 
                    throw std::domain_error("[std::domain_error]: Division by 0.");
                left/=d;
                t = get_token();
                break;
            } 
            case '%':
            {
                double a = term();
                left = mod_fpv(a, left);
                t = get_token();
                break;
            }
            default:
                return left;
        }
    }
}

// Primary:
// Number
// "("Expression")"
// Number:
// floating-point literal
double primary() // deal with numbers and parentheses
{
    Token t = get_token();
    switch(t.kind)
    {
        case '(': // This case is for handling '(' and ')'
        {
            double d = expression();
            t = get_token();
            if(t.kind != ')')
                throw std::domain_error("[std::domain_error]: Expected ')'.");
            return d;
            break;
        }
        case '8': // '8' represents a number.
            return t.value; // return numbers value.
            break;
        default:
            throw std::logic_error("[std::logic_error]: Primary expected.");
    }
}

// Running the program
// Main:
// To run the main we need to load in the token (cin) and print out the expression. 

void main_program()
{
    try
    {
        double val = 0;
        while(cin)
        {
            Token t = get_token(); // for now once you have the ts.get() function replace.
            if(t.kind == 'q') // 'q', exit program
                break;
            if(t.kind == ';') // ';' print now
                cout<<"= "<<expression()<<endl;
            else
                ts.putback(t); // 
            
            val = expression();
        }
    }
    catch(const std::domain_error& e)
    {
        cerr<<e.what()<<endl;
        keep_window_open();
        return;
    }
    catch(const std::logic_error& e)
    {
        cerr<<e.what()<<endl;
        keep_window_open();
        return;
    }
}

int main()
{
    try
    {
        main_program();
    }
    catch(const exception& e)
    {
        cerr<<e.what()<<endl;
        keep_window_open();
        return 0;
    }
}


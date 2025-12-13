#include "std_lib_facilities.h"

/*
Exercise 2-3:


// DECLARATIONS [DEC]

double expression();
double term();
double primary();

// HELPERS [H]

// FACTORIAL FN [F]

int factorial(const int& x)
{
    if(x == 0)
        return 1;
    
    int result = x;

    for(int i = 1;i < x; ++i)
        result*=i;

    return result;
}

// TOKENIZATION [T]

class Token
{
    public:
        char kind;
        double value;
            Token(char ch)
                :kind(ch), value(0) {}
            Token(char ch, double val)
                :kind(ch), value(val) {}
};

class Token_stream
{
    public:
        Token_stream(); // cin declaration
        void putback(Token t); // putback the leftover token or the unused token
        Token get(); // get the token into the stream
    private:
        bool full; // a bool statement to indicate whether the stream is full or not
        Token buffer; // this is the token itself, and the location in memory where the putback function places the token
};

// Token_stream() function - Constructor declaration
// Use: Initializes the private section of the token_stream. full = false, buffer = 0 (mandatory intialization).
Token_stream::Token_stream()
    :full(false), buffer(0) {}

// putback

void Token_stream::putback(Token t)
{
    if(full)
        throw std::runtime_error("[runtime_error]: putback() on a full buffer");
    
    buffer = t;
    full = true;
}

// get

Token Token_stream::get()
{
    if(full)
    {
        full = false;
        return buffer;
    }
    
    char ch;
    cin>>ch;

    switch(ch)
    {
        case 'q':
            exit(0);
        case '=':

        case '{': case '}': case '(': case ')': case '+': case '-': case '/': case '*': case '!':
            return Token(ch);
        
        case '.':
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
        {
            cin.putback(ch);
            
            double val;
            cin>>val;

            return Token('8', val);
        }
        default:
            throw std::invalid_argument("[invalid_argument]: Bad Token");
    }
}

// Declare token_stream [TS]

Token_stream ts;

//----------------------------------------------------------------------------------------------------------------------

// EXPRESSION [M]

double expression()
{
    double left = term();
    Token t = ts.get();

    while(true)
    {
        switch(t.kind)
        {
            case '+':
                left+=term();
                t = ts.get();
                break;
            case '-':
                left-=term();
                t = ts.get();
                break;
            default:
                ts.putback(t);
                return left;
        }
    }
}

double term()
{
    double left = primary();
    Token t = ts.get();

    while(true)
    {
        switch(t.kind)
        {
            case '*':
                left*=primary();
                t = ts.get();
                break;
            case '/':
            {
                double d = primary();
                if(d == 0)
                {
                    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
                    
                    throw std::domain_error("[domain_error]: Division by 0");
                }
                left/=d;
                t = ts.get();
                break;
            }
            default:
                ts.putback(t);
                return left;
        }
    }
}

double primary()
{
    
    Token t = ts.get();

    switch(t.kind)
    {
        case '!':
        {
            double d = expression();
            return factorial(d);
        }
        
        case '{':
        {
            double d = expression();
            t = ts.get();
            if(t.kind != '}')
                throw std::domain_error("[domain_error]: '}' expected");
            
            return d; 
        }
        
        case '(':
        {
            double d = expression();
            t = ts.get();
            if(t.kind != ')') 
                throw std::domain_error("[domain_error]: ')' expected");
            
            return d;
        }
        case '8':
            return t.value;   
        default:
            throw std::invalid_argument("[invalid_argument]: Primary expected.");
    }
}

// ---------------------------------------------------------------------------------------- MAIN [M] ----------------------------------------------------------------------------------------



// PROGRAM [P]

void main_program()
{
    try 
    {
        double val = 0.0;

        while(cin)
        {
            Token t = ts.get();

            if(t.kind == '=')
                cout<<"< "<<val<<endl;
            else
                ts.putback(t);

            val = expression();
        }
    }
    catch(const std::invalid_argument& e)
    {
        cerr<<e.what()<<endl;
        keep_window_open();
        return;
    }
    catch(const std::domain_error& e)
    {
        cerr<<e.what()<<endl;
        keep_window_open();
        return;
    }
}

// MAIN [MN]

int main()
{
    try
    {
        main_program();
    }   
    catch(const std::exception)
    {
        cerr<<"Unknown error";
        keep_window_open();
        return 0;
    } 
}


// MAKE FACTORIAL BIND TIGHTER THAN '*' OR '/'

// FLOATING POINT INTEGER --> NUMBER --> PRIMARY --> TERM --> EXPRESSION
// FLOATING POINT LITERAL = FACILITIATOR
// NUMBER = FLOATING POINT LITERAL
// PRIMARY = NUMBER AND '('Expression')' + FACTORIAL -->  IT DOES WORK BUT ITS NOT THE BEST STRUCTURE /// BUT WHAT IS THE ALTERNATIVE? TERM (EVEN WORSE...)?
// TERM = PRIMARY, HANDLES '*', '/', '%'
// EXPRESSION = TERM, PRIMARY, HANDLES '+', '-' 


//                                                                                 Expression
//                                                                                     ^
//                                                     Expression -------------------- | -------------------- Term   
//                                                         |                           |                        ^
// Expression:                                             |                           |                        |
//     Term                                               Term                         | -------- Term -------- | --------          
//     Expression '+':                                     |                           |           |            |          |
//     Expression '-':                                     |                           |           |            |          |
// Term:                                                Primary                        |         Primary        |        Primary  
//     Primary                                             |                           |           |            |          |
//     Expression '*':                                     |                           |           |            |          |
//     Expression '/':                                     |                           |           |            |          |
//     Expression '%':                                     |                           |           |            |          |
// Primary:                                              Number                        |         Number         |        Number 
//     Number:                                             |                           |           |            |          |
//     "("Expression")"                                    |                           |           |            |          |
//     Factorial                                           |                           |           |            |          |
// Number:                                      floating-point literal                 |           |            |          |
//     floating-point literal                              |                           |           |            |          |
//                                                         2                           +          11.5          *          7

*/
// Exercise 4:

class Name_value
{
    public:
        string name;
        double score;
            Name_value(string name, double scr)
                :name(name), score(scr) {}
};

class Name_stream
{
    public:
        Name_stream();
        Name_value get();
        void putback(Name_value n);
    private:
        bool full;
        Name_value buffer;
};

// Constructor

Name_stream::Name_stream()
    :full(false), buffer("",0) {}


// putback

void Name_stream::putback(Name_value n)
{
    if(full)
        throw std::runtime_error("[runtime_error]: putback() on a full buffer");
    
    buffer = n;
    full = true;
}

// Fill

Name_value Name_stream::get()
{
    string s = "";
    double d;
    
    cin>>s;
    if(s == "q")
        exit(0);
    cin>>d;
    
    return Name_value(s, d);
}

// declare

Name_stream ns;

// Declare

void main_program()
{
    try
    {
        vector<Name_value>xvals;

        while(cin)
        {
            Name_value n = ns.get();

            if(n.name == "No")
                ns.putback(n);
            xvals.push_back(n);
        }
        
        for(Name_value i : xvals) cout<<i.name<<" "<<i.score<<" ";        
    }
    catch(const std::invalid_argument& e)
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
    catch(const std::invalid_argument& e)
    {
        cerr<<e.what()<<endl;
        keep_window_open();
        return 0;
    }
}

// Grammar tree:
// GOAL --> REPLACE VECTOR WITH CLASS Name_value()
//                                                                                   Sentence
// Sentence:                                                                            ^
//  Noun Verb                                                                           |
//  Sentence Conjunction Sentence     --------------------------------------------------------------------------------------------------
//                                                         |                            |                           |       
//  Conjunction:                                           |                            |                           |       
//  "and"                                                  |                            |                           |       
//  "or"                                                   |                            |                           |       
//  "but"                                               Sentence                        |                        Sentence        
//                                                         ^                            |                           ^
// Noun:                                                   |                            |                           |       
//  "birds"                                    ------------ -------------               |              ------------   -------------
//  "fish"                                   |             |              |             |             |             |              |  
//  "C++"                                    |             |              |             |             |             |              |
//                                        "Article"      "Noun"         "Verb"     "Conjunction"   "Article"      "Noun"         "Verb"
//  Verb:                                    |             |              |             |             |             |              |  
//  "rules"                                  |             |              |             |             |             |              | 
//  "fly"                                    |             |              |             |             |             |              |   
//  "swim"                                   |             |              |             |             |             |              |
//                                           |             |              |             |             |             |              |
//  Article:                                 |             |              |             |             |             |              | 
//  "The"                                   The           bird           fly           but           the           fish           swim
//                                



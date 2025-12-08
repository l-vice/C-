#include "std_lib_facilities.h"
/*

TRY THIS 1:

class Token 
{
    public: 
        char kind;
        double value;
        //
        Token(char ch) // this is the placeholder for the operator
            :kind(ch), value(0) {}
        Token(char ch, double val)
            :kind(ch), value(val) {}
};

vector<Token>tok;
// This is outdated and this must be an issue with the compiler. [YOU NEED TO CHECK THE COMPILER]
Token get_token();
void read_token()
{
    char op;
    int val;

    cout<<"Enter values"<<endl;
    
    while(cin>>op>>val)
    {
        Token t = get_token();
        tok.push_back(t);    
    }
    //
}


TRY THIS 2:

// Forward declaration of functions
double expression();
double term();
double primary();

// Token and Token_stream [T]
class Token
{
    public:
        char kind;
        double value;
        //
        Token(char ch)
        :kind(ch), value(0) {}
        Token(char ch, double val)
        :kind(ch), value(val) {}
};

class Token_stream
{
    public:
        Token_stream(); // Constructor
        Token get(); // If no unused token, we read read cin and get another.
        void putback(Token t); // we put back the unused token. 

    private:
        bool full; // if there is a leftover token. This is full and there is a token in the buffer.
        Token buffer; // This is where the Token putback() function stores the token.
};

// 1. Constructor
Token_stream::Token_stream()
    :full(false), buffer(0) // we must initialize every token 
{    
}

// 2. putback() 

void Token_stream::putback(Token t)
{
    if(full) // if buffer is full then don't put back the token
        throw std::logic_error("[std::logic_error]: putback() on a full buffer.");
    buffer = t;
    full = true;  
}

// 3. get()
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
        case ';':
        case 'q':
        // Term:
        case '(': case ')': case '+': case '-':
            return Token(ch);
        // Primary:
        case '.':
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
        {
            cin.putback(ch);
            double val;
            cin>>val;
            return Token('8', val); 
        }
        default:
            throw std::invalid_argument("[std::invalid_argument]: Bad token input.");
    }
}

// TS CALL [TS]
Token_stream ts;

// 1. EXPRESSION [EXP]

double expression()
{
    double left = term();
    Token t = ts.get();
    //
    while(true)
    {
        switch(t.kind)
        {
            case '+':
                left += term();
                t = ts.get();
                break;
            case '-':
                left -= term();
                t = ts.get();
                break;
            default:
                ts.putback(t);
                return left;
        }
    }
}

// TERM [T]

double term()
{
    double left = primary();
    Token t = ts.get();
    while(true)
    { 
        switch(t.kind)
        {
            // Primary:
            case '*':
                left*=primary();
                t = ts.get();
                break;
            case '/':
            {
                double d = primary();
                if(d == 0) throw std::domain_error("[std::domain_eror]: Division by 0.");
                left/=d;
                t = ts.get();
                break;
            }
            default:
                ts.putback(t); //put back t into the token stream.
                return left;
        }
    }   
}

// PRIMARY [P]

double primary()
{
    Token t = ts.get();
    switch(t.kind)
    {
        case '(':
        {
            double d = expression();
            t = ts.get();
            if(t.kind != ')')
                throw std::domain_error("[std::domain_error]: ')' is expected");
            return d;
            break;
        }
        case '8':
            return t.value;
            break;
        default:
            ts.putback(t);
            throw std::logic_error("[std::logic_error]: Invalid input.");
    }
}

// CALCULATOR [C]
void calculator()
{
    try
    {
        double val = 0;
        
        while(cin)
        {
            Token t = ts.get();
            if(t.kind == 'q')
                break;
            if(t.kind == ';')
            {
                cout<<val<<endl;
            }
            else
                ts.putback(t);

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
        calculator();
    }
    catch(const exception& e)
    {
        cerr<<e.what()<<endl;
        keep_window_open();
        return 0;
    }
}

TRY THIS 2 TAKE 2
*/

// function declaration [DEC]

double expression();
double term();
double primary();

// Tokenization

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
        Token_stream();
        Token get();
        void putback(Token t);
    private:
        bool full;
        Token buffer;
};

// 1. Constructor

Token_stream::Token_stream()
    :full(false), buffer(0) {}

// 2. putback()

void Token_stream::putback(Token t)
{
    if(full)
        throw std::invalid_argument("[std::invalid_argument]: putback() on a full buffer");
    buffer = t;
    full = true;
}

// 3. get()

Token Token_stream::get()
{
    if(full)
    {// if there is a token in the buffer, empty the buffer
        full = false;
        return buffer;
    }

    char ch;
    cin>>ch;

    switch(ch)
    {
        case ';':
        case 'q':

        case '(': case ')': case '+': case '-': case '*': case '/': case '%':
            return Token(ch);

        case '.':
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
        {
            cin.putback(ch); //if there is a leftover token put it back in the buffer;
            
            double val;
            cin>>val;
            return Token('8', val);
        }
        default:
            throw std::invalid_argument("[std::invalid_argument]: Bad Token");
    }
}

// delcare token stream

Token_stream ts;

//

// Operations

// 1. expression

double expression()
{
    double left = term();
    Token t = ts.get();
    
    while(true)
    {
        switch(t.kind)
        {
            case '+':
                left += term();
                t = ts.get();
                break;
            case '-':
                left -= term();
                t = ts.get();
                break;
            default:
                ts.putback(t);
                return left;
        }
    }
}

// 2. term

double term()
{
    double left = primary();
    Token t = ts.get();

    while(true)
    {
        switch(t.kind)
        {
            case '*':
                left *=primary();
                t = ts.get();
                break;
            case '/':
            {
                double d = primary();
                if(d == 0)
                {
                    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
                    throw std::domain_error("[std::domain_error]: Division by 0");
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

// 3. primary

double primary()
{
    Token t = ts.get();

    switch(t.kind)
    {
        
        case 'q':
        {
            cout<<"Exiting program..."<<endl;
            break;
        }

        case '(':
        {
            double d = expression();
            t = ts.get();
            if(t.kind != ')')
                throw std::domain_error("[std::domain_error]: ')' expected");
            return d;
        }
        case '8':
            return t.value;
        default:
            throw std::invalid_argument("[std::invalid_argument]: Primary expected");
    }
}

// Calculator and main

void calculator()
{
    try
    {
        double val = 0.0;
    
        while(cin)
        {
            Token t = ts.get();
            if(t.kind == 'q')
            {
                cout<<"Exiting program..."<<endl;
                break;
            }
            if(t.kind == ';')
                cout<<"= "<<val<<endl;
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

int main()
{
    try
    {
        calculator();
    }
    catch(const std::exception& e)
    {
        cerr<<e.what()<<endl;
        keep_window_open();
        return 0;
    }
}


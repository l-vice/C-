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
    if(full = true) // if buffer is full then don't put back the token
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
            case '/':
            {
                double d = primary();
                if(d == 0) throw std::domain_error("[std::domain_eror]: Division by 0.");
                left/=d;
                t = ts.get();
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
    while(true)
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
                cout<<expression()<<endl;
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

*/

// Sieve of Erathosthenes

void soe(const int& x)
{
    vector<int>A(x+1, true);
    A[0] = A[1] = false;
    for(size_t i = 2;i*i <= x;++i)
    {
        if(A[i])
            for(size_t j = i*i;j <= x;j+=i)
                A[j] = false;
    }
    // COUT
    cout<<"The primes are: ";for(size_t i = 0;i <= x;++i) if(A[i]) cout<<i<<" ";
}

void fibonacci(const int& x)
{
    int a = 0, b = 1, c = 0;
    cout<<a<<" "<<b<<" ";
    while(c < x)
    {
        c = a+b;
        cout<<c<<" ";
        a = b;
        b = c;
    }
}


int mmplier(const int& x)
{
    int result = 1;
    if(x == 1) return result;
    if(x == 2) {result = 2; return result;}
    for(size_t i = 3;i <= x;++i)
    {
        if(x % 2 == 0)
        {
            result*=4;
        }
        if(x % 2 != 0)
        {
            result = 4;
            result*=4;
        }
    }
    return result;
}

int main()
{
    int x = 20;
    for(size_t i = 1;i < x;++i)
        cout<<mmplier(i)<<" ";
}


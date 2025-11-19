#include "std_lib_facilities.h"
#include <unordered_set>
#include <stdio.h>
#include <string.h>
/* 
Q1: Each try this exercise:

TRY THIS 1: Write a program that converts yen, euros, and pounds into dollars
USD/JPY = 147.3300 // 3-OCT-25
GBP/USD = 1.3481 // 3-OCT-25
EUR/USD = 1.1747 // 3-OCT-25

int main()
{
    const double usd_jpy_rate = 147.3300; // 1:147.3300 ratio; USD:JPY
    const double gbp_usd_rate = 1.3481; // 1:1.3481 ratio; GBP:USD
    const double eur_usd_rate = 1.1747; // 1:1.1747 ratio; EUR:USD
    double usd = 0.0; double eur = 0.0; double gbp = 0.0; double jpy = 0.0;
    string currency = " ";
    cout<<"Enter the amount the dollar amount followed by the currency you'd like to convert to.\n"
        <<"Available conversions are: USD/JPY, GBP/USD, and EUR/USD. \n"
        <<"Example input: 14.52 EUR\n";
    cin>>usd>>currency;
    if(currency == "JPY") 
    {
        jpy = usd * usd_jpy_rate;
        cout<<"You are holding: "<<jpy<<"JPY.\n\n";
        }
    else if(currency == "GBP")
    {
        gbp = usd * gbp_usd_rate;
        cout<<"You are holding: "<<gbp<<"GBP.\n\n";
    }
    else 
    {
        eur = usd * eur_usd_rate;
        cout<<"You are holding: "<<eur<<"EUR.\n\n";
    }

    cout<<"Thank you for using our program!\n\n";

    keep_window_open();
    return(0);
}

Using switch-statements: Conversion from i to c and vice-versa using switch-statement

int main()
{
    const double cm_per_inch = 2.54;
    double length = 0.0;
    char unit = ' ';
    cout<<"This program converts inches into centimeters and vice-versa.\n"<<"Enter the length followed by a metric.\n"<<"Example input: 123.12 c\n";
    cin>>length>>unit;
    switch(unit) {
    case 'i':
        cout<<"There are "<<cm_per_inch*length<<" centimeters in "<<length<<" inches.\n\n";
        break;
    case 'c':
        cout<<"There are "<<cm_per_inch*length<<" inches in "<<length<<" centimeters.\n\n";
        break;
    default:
        error("Specified metric is unknown!");
    }
    
    cout<<"Thank you for using our program!\n\n";
    
    keep_window_open();
    return(0);
}

TRY THIS 2: Write a program that converts japanese yen, euros, pounds, Danish Kroner, and Chinese yuan into dollars using a switch statement.
USD/JPY = 147.3300 // 3-OCT-25 SRC: FED RESERVE
GBP/USD = 1.3481 // 3-OCT-25 SRC: FED RESERVE
EUR/USD = 1.1747 // 3-OCT-25 SRC: FED RESERVE
CNY/USD = 7.1200 // 3-OCT-25 SRC: FED RESERVE
DKK/USD = 6.3570 // 3-OCT-25 SRC: FED RESERVE

int main()
{
    const double usd_to_jpy = 147.3300;
    const double gbp_to_usd = 1.3481;
    const double eur_to_usd = 1.1747;
    const double cny_to_usd = 7.1200;
    const double dkk_to_usd = 6.3570;  
    char currency = ' ';
    double dollars = 0;
    // 
    cout<<"The program outputs the conversion rate from USD into USD/JPY, GBP/USD, EUR/USD, CNY/USD, and DKK/USD.\n"
        <<"USD/JPY = J, GBP/USD = G, EUR/USD = E, CNY/USD = C, DKK/USD = K. "
        <<"Sample input: 12.5 E; Sample output: You have 9.85 Euros.\n"
        <<"Enter the amount of dollars followed by the currency symbol: \n";
    //
    cin>>dollars>>currency;
    switch(currency) {
    case 'J': 
        cout<<"You have "<<usd_to_jpy*dollars<<" Japanese Yen.\n\n";
        break;
    case 'G':
        cout<<"You have "<<gbp_to_usd*dollars<<" British Pounds.\n\n";
        break;
    case 'E':
        cout<<"You have "<<eur_to_usd*dollars<<" Euros.\n\n";
        break;
    case 'C':
        cout<<"You have "<<cny_to_usd*dollars<<" Chinese Yuan.\n\n";
        break;
    case 'K':
        cout<<"You have "<<dkk_to_usd*dollars<<" Danish Kroners.\n\n";
        break;
    default:
        cout<<"The currency symbol is not recognized by the program.\n\n";
    }
    
    cout<<"Thank you for using our program!\n\n";

    keep_window_open();
    return(0);
}

TRY THIS 3: Use loop to write out a table of characters with their corresponding integer values:

int main()
{
    int i = 0;
    while(i<26)
    {
        cout<<char('a'+i)<<'\t'<<int('a'+i)<<'\n';
        i++; // Increment i
    }
}
  
TRY THIS 4: Rewrite the character example using for-statement

int main()
{
    for(int i = 0; i<26;++i) {
        cout<<char('a'+i)<<'\t'<<int('a'+i)<<'\n';
    }
    for(int i = 0; i<10;++i) {
        cout<<char('0'+i)<<'\t'<<int('0'+i)<<'\n';
    }
    for(int i = 0; i<26;++i) {
        cout<<char('A'+i)<<'\t'<<int('A'+i)<<'\n';
    }
}

TRY THIS 5: Implement the square() without using the multiplication operator; that is do x*x by repeated addition.

// Define a square function by addition. with while-statement
int square(int x)
{
    int result = 0;
    int i = 0;
    while(i<x) {
        result+=x;
        i++;
    }
    return result;
}

TRY THIS 6: Write a program that "bleeps" out the word you don't like

int main()
{
    vector<string>words;
    string word = " ";
    vector<string>censored = {"Carrot", "Bananaman", "Void", "Trump", "Baguette"};
    string replacement = "BLEEP";
    // Load in the words
    cout<<"Please enter any number of words: \n\n";
    while(cin>>word) {words.push_back(word);}
    //
    cout<<"The original order: "; for (auto i : words) cout<<i<<" ";
    cout<<"\n\n";
    // Replacement
    for (int i = 0;i < censored.size();++i) {std::replace(words.begin(), words.end(), censored[i], replacement);}
    //
    cout<<"The updated order: "; for (auto i : words) cout<<i<<" ";
    cout<<"\n\n";

    cout<<"Thank you for using our program!\n\n";
    
    keep_window_open();
    return(0);
}


Q2:
int main()
{
    vector<int>xvals;
    int xval = 0;
    cout<<"Enter any number of integers: ";
    while(cin>>xval) xvals.push_back(xval);
    sort(xvals.begin(), xvals.end());
    double median = 0.0;
    int n = xvals.size();
    if(n % 2 == 0) 
    {
        median = (xvals[n/2 - 1] + xvals[n/2]) / 2.0;
    } else
    {
        median = xvals[n/2];
    }
    cout<<"Median: "<<median<<endl;
    cout<<endl<<"Thank you for using our program!";    
}

Q3:

int main()
{
    vector<double>distances;
    double distance = 0.0;
    cout<<"Enter distance between cities in km (separated by whitespace): ";
    while(cin>>distance) distances.push_back(distance);
    double sum = 0.0;
    double smallest = distances[0], largest = distances[0];
    double mean = 0.0;
    //
    for(int i = 0;i < distances.size();++i) 
    {
        if(distances[i] < smallest) {smallest = distances[i];}
        if(distances[i] > largest) {largest = distances[i];}
        sum += distances[i]; 
    }
    //
    mean = sum / distances.size();
    //
    cout<<"The smallest distance: "<<smallest<<endl
        <<"The greatest distance: "<<largest<<endl
        <<"The total distance between all cities: "<<sum<<endl
        <<"The mean distance: "<<mean<<endl;
    cout<<endl<<"Thank you for using our program!";
}

Q4: Not finished


bool getBooleanInput(const string& question)
{
    string answer;
    cout<<question<<" (yes/no)";
    cin>>answer;
}


int main()
{
    string input;
    //
    cout<<"Think of any number between 1 and 100. The program will try to guess the number by asking you questions."<<endl
    <<"You win if the program takes more than 7 questions or if it outputs a wrong result."<<"\n\n";
    //
    cout<<"Is the number lower or higher than 50?";
    cin>>input;
    if(input == "Higher" || input == "higher" || input == "its higher") cout<<"Is the number higher or lower than 75?"; 
    else if (input == "Lower" || input == "lower" || input == "its lower") cout<<"Is the number higher or lower than 25?";
    else error("Please use appropriate grammar.");
    //
    cin>>input;
    string question1 = "Is the number between 75-85 or 86-100? (Answer as: former/latter)";
    string question2 = "Is the number between 1-15 or 16-25? (Answer as: former/latter)";
    if(input == "Higher" || input == "higher" || input == "its higher") cout<<question1<<endl;
    else if (input == "Lower" || input == "lower" || input == "its lower") cout<<question2<<endl;
    else error("Please use appropriate grammar");
    //
    cin>>input;
    if(input == "Former" || input == "former" && cout<<question1) cout<<"Is the number higher or lower than 80"<<endl;
    else if (input == "Former" || input == "former" && cout<<question2) cout<<"Is the number higher or lower than 7"<<endl;
    //
    else if (input == "Latter" || input == "latter" && cout<<question1) cout<<"Is the number higher or lower than 93"<<endl;
    else if (input == "Latter" || input == "latter" && cout<<question2) cout<<"Is the number higher or lower than 20"<<endl;
    else error("Please use appropriate grammar");
    //
    cin>>input;
    if(input == "Higher" || input == "higher" || input == "its higher") cout<<"Is the number in the lower or upper half?"<<endl;
    else if(input == "Lower" || input == "lower" || input == "its lower") cout<<"Is the number in the lower or upper half?"<<endl;
    else error("Please use appropriate grammar");
    //
}

Q5:

double dbl_mod(const double& xval1, const double& xval2)
{
    double a = xval1, b = xval2;
    return a - (static_cast<int>(a / b) * b);    
}

int main()
{
   double xval1 = 0.0;
   double xval2 = 0.0;
   char operation = ' ';
   cout<<"Enter the operation: ";
   cin>>xval1>>operation>>xval2;
   //
   double min, max = 0.0;  
   if(xval1 < xval2) {min = xval1;max = xval2;}
   if(xval2 < xval1) {min = xval2;max = xval1;}
   switch(operation) 
   {
    case '+':
        cout<<"The sum of "<<xval1<<" and "<<xval2<<" is "<<xval1+xval2<<'.'<<endl; break;
    case '-':
        cout<<"The subtraction of "<<xval1<<" and "<<xval2<<" is "<<xval1-xval2<<'.'<<endl; break;
    case '*':
        cout<<"The product of "<<xval1<<" and "<<xval2<<" is "<<xval1*xval2<<'.'<<endl; break;
    case '/':
        cout<<"The division of "<<xval1<<" and "<<xval2<<" is "<<xval1/xval2<<'.'<<endl; break;
    case '%':
        cout<<"The remainder of "<<xval1<<" and "<<xval2<<" is "<<dbl_mod(xval1, xval2)<<'.'<<endl; break;
   }
   cout<<endl<<"Thank you for using our program!";
}

Q6:

int main()
{
    vector<string>xvals = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string xval = "";
    cout<<"Enter a number (0-9) or a word number (zero or nine): "<<endl;
    while(cin>>xval) 
    {
        bool is_digit = true;
        for (char c : xval) if(!isdigit(c)) is_digit = false;
        //
        if(is_digit) 
        {
            int i = stoi(xval);
            if(i >= 0 && i < 10) cout<<xvals[i]<<endl; else cout<<"Invalid input domain."<<endl;
        }
        else 
        {
            bool found = false;
            for(int i = 0;i < xvals.size();++i) 
            {
                if(xvals[i] == xval) {cout<<i<<endl;found = true;break;}
            }
            if(!found) cout<<"Invalid input domain."<<endl;
        }
        cout<<"Enter another (or CTRL+Z to exit)"<<endl;
    }
}

Q7:

double dbl_modulo(const double& xval1, const double& xval2) 
{
    double a = xval1;
    double b = xval2;
    return a - b * trunc(a / b);
}

int word_to_int(const string& xval) 
{
    vector<string>xvals = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int int_xval = 0;
    bool found = false;
    for(int i = 0;i < xvals.size();++i) {if(xvals[i] == xval) {int_xval = i;found = true; break;}} if(!found) cout<<"Invalid input domain.";
    return int_xval;
}

int main()
{
    vector<string>xvals ={"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string xval1 = "", xval2 = "";
    char operation = ' ';
    //
    cout<<"Calculator input: (ex. a + b): "<<endl;
    while(cin>>xval1>>operation>>xval2)
    {
        bool is_digit_xval1 = true, is_digit_xval2 = true;
        for (char c : xval1) if(!isdigit(c)) is_digit_xval1 = false;
        for (char c : xval2) if(!isdigit(c)) is_digit_xval2 = false;
        //
        if(is_digit_xval1 && is_digit_xval2) 
        {
            int int_xval1 = stoi(xval1), int_xval2 = stoi(xval2);
            if(int_xval1 >= 0 && int_xval1 < 10 && int_xval2 >= 0 && int_xval2 < 10) 
            {
                switch(operation) 
                {
                    case '+':
                        cout<<"The sum of "<<int_xval1<<" and "<<int_xval2<<" is "<<int_xval1+int_xval2<<'.'<<endl; break;
                    case '-':
                        cout<<"The sum difference of "<<int_xval1<<" and "<<int_xval2<<" is "<<int_xval1-int_xval2<<'.'<<endl; break;
                    case '*':
                        cout<<"The product of "<<int_xval1<<" and "<<int_xval2<<" is "<<int_xval1*int_xval2<<'.'<<endl; break;
                    case '/':
                        cout<<"The quotient of "<<int_xval1<<" and "<<int_xval2<<" is "; if(int_xval2 == 0) cout<<"Division by zero: NaN."<<endl; else cout<<int_xval1/int_xval2<<'.'<<endl; break;
                    case '%':
                        cout<<"The remainder of "<<int_xval1<<" and "<<int_xval2<<" is "<<int_xval1%int_xval2<<'.'<<endl; break;
                }
            } else cout<<"Invalid input domain."<<endl; 
        }
        else 
        {
            bool found1 = false, found2 = false;
            int int_xval1 = 0, int_xval2 = 0;
            for(int i = 0;i < xvals.size(); ++i) 
            {
                if(xval1 == xvals[i]) {int_xval1 = i;found1 = true;}
                if(xval2 == xvals[i]) {int_xval2 = i; found2 = true;}
            }
            if(found1 && found2) 
            {
                switch(operation) 
                {
                    case '+':
                        cout<<"The sum of "<<int_xval1<<" and "<<int_xval2<<" is "<<int_xval1+int_xval2<<'.'<<endl; break;
                    case '-':
                        cout<<"The sum difference of "<<int_xval1<<" and "<<int_xval2<<" is "<<int_xval1-int_xval2<<'.'<<endl; break;
                    case '*':
                        cout<<"The product of "<<int_xval1<<" and "<<int_xval2<<" is "<<int_xval1*int_xval2<<'.'<<endl; break;
                    case '/':
                        cout<<"The quotient of "<<int_xval1<<" and "<<int_xval2<<" is "; if(int_xval2 == 0) cout<<"Division by zero: NaN."<<endl; else cout<<int_xval1/int_xval2<<'.'<<endl; break;
                    case '%':
                        cout<<"The remainder of "<<int_xval1<<" and "<<int_xval2<<" is "<<int_xval1%int_xval2<<'.'<<endl; break;
                }
            } else cout<<"Invalid input domain."<<endl;
        }
        cout<<"Enter another operation (or CTRL+Z to exit):"<<endl; 
    }     
}

Q8:

Slower = pow(2, x-1) // converts double to int then int to double slowest
Medium = Loop version for each x; fine but it gets slower for each step
Med-High = Quadruple step; twice faster than the loop version
High = Bitwise shift; result = 1 << (n - 1); This is the fastest 


int seq_double(const int & n)
{
    int x = n; // the number of tiles or the tile number
    int result = 1; // we initialize to 1 because first tile is 1x1
    if(x == 1) return result;
    else 
    {
        for(int i = 1;i < n; ++i) result = result * 2;
    }
    return result;
}

int seq_double(const int & x)
{
    int result = 1;
    if(x == 1) return result;
    else 
    {
        result = pow(2, x-1);
    }
    return result;
}

int seq_double(const int& x)
{
    int result = 1;
    if(x == 1) return result;
    else 
        result = 1 << (x - 1); // push bits to the left by 1 for x - 1 times
    
    return result;
}

unsigned long long seq_double(const int& x)
{
    unsigned long long result = 1ULL;
    if(x == 1) return result;
    else if(x == 2) return result+1;
    else if(x % 2 == 0) // even        
    {
        result = 2ULL;
        for(int i = 2;i< x-1;i+=2) 
        {
            result = result * 4ULL;
        }
    }
    else if (x % 2 != 0) // odd
    {
        for(int i = 1;i < x-1;i+=2) 
        {
            result = result * 4ULL;
        }
    }
    return result;
}

int main()
{
   int exp = 0;
   int requirement1 = 0, requirement2 = 0, requirement3 = 0; // number of grains on the current exponent
   unsigned long long sum_previous = 0, num_current = 0; // total number of grains on all previous exponents, and the number of grains on the current tile
   int threshold_1 = 1000, threshold_2 = 2500, threshold_3 = 1000000000;
   int n = 0; // desired number of squares
   vector<unsigned long long>sum; // the sum where we store sum_previous
   std::cout<<"Enter the number of tiles (1-64): ";
   cin>>n;
   for(int i = 1; i <= n;++i)  
   {
        sum.push_back(seq_double(i));
   }
   for (int i = 1; i < sum.size();++i) {if(sum[i] >= threshold_1) {requirement1 = i+1;break;}}
   for (int i = 1; i < sum.size();++i) {if(sum[i] >= threshold_2) {requirement2 = i+1;break;}}
   for (int i = 1; i < sum.size();++i) {if(sum[i] >= threshold_3) {requirement3 = i+1;break;}}
   //
   num_current = seq_double(n);
   for(int i = 1; i < n;++i) 
   {
        sum_previous += seq_double(i);  
   }
   //
   std::cout<<"Exponents: ";for(int i = 1; i <= n;++i) {exp = i; std::cout<<exp<<" ";} std::cout<<endl;
   std::cout<<"The increments: ";for(int i = 1; i <=n;++i) std::cout<<seq_double(i)<<" "; std::cout<<endl;
   std::cout<<"The number of grains on the current tile: "<<num_current<<endl;
   std::cout<<"The total number of grains before the current tile: "<<sum_previous<<endl;
   std::cout<<"The number of tiles required for "<<threshold_1<<" grains or more: "<<requirement1<<endl;
   std::cout<<"The number of tiles required for "<<threshold_2<<" grains or more: "<<requirement2<<endl;
   std::cout<<"The number of tiles required for "<<threshold_3<<" grains or more: "<<requirement3<<endl;
   std::cout<<"The sum vector is: ";for(int i = 0; i < sum.size(); ++i) cout<<sum[i]<<" ";cout<<endl;
}

unsigned long long seq_double(const int& x) 
{
    unsigned long long result = 1ULL;
    //
    if(x == 1) return result;
    else if(x == 2) {result = 2ULL;return result;}
    else 
    {
        if(x % 2 == 0) 
        {
            result = 2ULL;
            for(int i = 2;i < x;i+=2) // even 
            {
                result*=4ULL;
            }
        };
        if(x % 2 != 0)
        {
            for(int i = 1;i < x;i+=2) // odd 
            {
                result*=4ULL;
            }
        }
    } 
    return result;
}

///

unsigned long long seq_double(const int& x)
{
    unsigned long long result = 1ULL;
    if(x == 1) return result;
    else 
    {
        result = 1ULL << (x - 1);
    }
    return result;
}

int main()
{
    int n = 0;
    int threshold_1 = 1000, threshold_2 = 1000000, threshold_3 = 1000000000;
    cout<<"Enter the number of tiles: ";
    while(cin>>n) {
        //
        unsigned long long sum_previous = 0ULL, num_current = 0ULL;
        int requirement_1 = 0, requirement_2 = 0, requirement_3 = 0;
        //
        for (int i = 1;i < n;++i) {sum_previous += seq_double(i);}
        num_current = seq_double(n);
        //
        for(int i = 1;i <= n;++i) // we use a separate for loop because 
        {
            unsigned long long grains = seq_double(i);
            if(!requirement_1 && grains >= threshold_1) requirement_1 = i;
            if(!requirement_2 && grains >= threshold_2) requirement_2 = i;
            if(!requirement_3 && grains >= threshold_3) requirement_3 = i;
            if(requirement_1 && requirement_2 && requirement_3) break;    
        }
        //
        cout<<"The number of tiles: ";for(int i = 1;i <= n;++i) cout<<i<<" ";cout<<endl;
        cout<<"The sequence: ";for(int i = 1;i <= n; ++i) cout<<seq_double(i)<<" ";cout<<endl;
        cout<<"The number of tiles required to reach "<<threshold_1<<" grains is: "<<requirement_1<<'.'<<endl;
        cout<<"The number of tiles required to reach "<<threshold_2<<" grains is: "<<requirement_2<<'.'<<endl;
        cout<<"The number of tiles required to reach "<<threshold_3<<" grains is: "<<requirement_3<<'.'<<endl;
        //
        cout<<"The number of grains on all previous tiles: "<<sum_previous<<endl;
        cout<<"The number of grains on the current tile: "<<num_current<<endl;
        //
        cout<<"Enter another number (or CTRL+Z to exit): "<<endl;
    } 
}



Q9:

// you can update the function to take in a vector directly.
string randomizer()
{
    vector<string>options = {"Rock", "Paper", "Scissors"};
    string result = "";
    int random_pos = std::rand() % options.size();
    result = options[random_pos];
    return result;
}

int main()
{
    std::srand(std::time(0));
    vector<string>input_sequence_1;
    char input_1 = ' ';
    string string_input_1 = " ";
    cout<<"Enter a sequence of rock, paper, scissors of any length (R = Rock, P = Paper, S = Scissors): "<<endl;
    while(cin>>input_1 && input_1 != '|') 
    {
        if(input_1 == 'R') string_input_1 = "Rock";
        else if(input_1 == 'P') string_input_1 = "Paper";
        else if(input_1 == 'S') string_input_1 = "Scissors";
        else error("Invalid input domain.");
        //
        input_sequence_1.push_back(string_input_1);
    }
    //
    char input_2 = ' ';
    string string_input_2 = " ";
    cout<<"Now, you get to actually play the game (Input any of the three options): "<<endl;
    for(int i = 0; i < input_sequence_1.size();++i)
    {
        while(cin>>string_input_2) 
        {
            if(string_input_2 == "Rock") {input_2 = 'R'; break;}
            else if(string_input_2 == "Paper") {input_2 = 'P'; break;}
            else if(string_input_2 == "Scissors") {input_2 = 'S'; break;}
            else error("Invalid input domain.");
            //
        }
        switch(input_2)
        {
            case 'R':
                cout<<"You chose "<<string_input_2<<'.'<<" "<<"The computer chose "<<randomizer()<<endl;break;
            case 'P':
                cout<<"You chose "<<string_input_2<<'.'<<" "<<"The computer chose "<<randomizer()<<endl;break;
            case 'S':
                cout<<"You chose "<<string_input_2<<'.'<<" "<<"The computer chose "<<randomizer()<<endl;break;
        }
    cout<<"Enter another: (or CTRL+Z to exit): ";    
    }
    //
}
/////////
string to_lowercase(string x)
{
    transform(x.begin(), x.end(), x.begin(),
            [] (unsigned char c) {return tolower(c);});
    return x;
}

string randomizer()
{
    vector<string>options = {"Rock", "Paper", "Scissors"};
    string result = "";
    int random_pos = std::rand() % options.size();
    result = options[random_pos];
    return result;
}

int main()
{
    std::srand(std::time(0));
    int games = 0;
    unordered_set<string>legal_names = {"rock", "paper", "scissors", "r", "p", "s"};
    cout<<"Enter the number of games you would like to play: "<<endl;
    cin>>games;
    //
    char input = ' ';
    string string_input = " ";
    double  wins = 0.0, draws = 0.0, losses = 0.0, wr = 0.0;
    cout<<"Now, you get to actually play the game (Input any of the three options): "<<endl;
    for(int i = 1; i <= games;++i)
    {
        while(true) 
        {
            if(!(cin>>string_input)) 
            {
                cout<<"\nDetected end of input (CTRL + Z). Exiting game...\n";
                goto end_game; 
            }
            string_input = to_lowercase(string_input);
            if(legal_names.find(string_input) == legal_names.end()) {
                error("Invalid input domain.");
            }
            //
            if(string_input == "rock" || string_input == "r") {input = 'R'; break;}
            else if(string_input == "paper" || string_input == "p") {input = 'P'; break;}
            else if(string_input == "scissors" || string_input == "s") {input = 'S'; break;}
            //
        }
        string computer = randomizer(); 
        switch(input)
        {
            case 'R':
                if(computer == "Rock") {cout<<"Tie!"<<endl;++draws;}
                else if(computer == "Paper") {cout<<"You lose!"<<endl;++losses;}
                else {cout<<"You win!"<<endl;++wins;}
                break;
            case 'P':
                if(computer == "Paper") {cout<<"Tie!"<<endl;++draws;}
                else if(computer == "Scissors") {cout<<"You lose!"<<endl;++losses;}
                else {cout<<"You win!"<<endl;++wins;}
                break;
            case 'S':
                if(computer == "Scissors") {cout<<"Tie!"<<endl;++draws;}
                else if(computer == "Rock") {cout<<"You lose!"<<endl;++losses;}
                else {cout<<"You win!"<<endl;++wins;}
                break;
        }    
    if(i == games-1) cout<<"LAST ROUND - Enter another: (or CTRL+Z to exit): "<<endl;
    else if(i != games) cout<<"Enter another: (or CTRL+Z to exit): "<<endl;   
    }
    end_game:
    if(losses == 0 && wins != 0) wr=1; else wr = wins/losses;
    cout<<"Statistics: "<<" | "<<"Wins: "<<wins
                        <<" | "<<"Losses: "<<losses
                        <<" | "<<"Draws: "<<draws
                        <<" | "<<"Winrate: "<<wr<<" | "<<endl;
}

// TAKE 2

string to_lowercase(string x)
{
    transform(x.begin(), x.end(), x.begin(),
                [] (unsigned char c) {return tolower(c);});
    return x;
}

string randomizer() 
{
    vector<string>options = {"Rock", "Paper", "Scissors"};
    int rand_int = std::rand() % options.size();
    
    return options[rand_int];
}

int main()
{
    string input = " ";
    int rounds = 0;
    char c_input = ' ';
    double wins, losses, draws, wr = 0.0;
    //
    unordered_set<string>legal_names = {"rock", "paper", "scissors", "rocks", "papers", "scissors", "r", "p", "s"};
    cout<<"Enter the number of rounds you would like to play: ";
    cin>>rounds;
    //
    for(int i = 1;i <=rounds;++i) 
    {
        cout<<"Enter your pick: ";
        while(true) 
        {
            if(!(cin>>input)) 
            {
                cout<<"\n Detected end of input (CTRL + Z). Exiting game...\n";
                goto end_game;
            }
            //
            input = to_lowercase(input);
            if(legal_names.find(input) == legal_names.end()) {error("Invalid input domain.");}
            if(input == "rock" || "rocks" || "r") {c_input = 'R';break;}
            else if(input == "paper" || "papers" || "p") {c_input = 'P';break;}
            else {c_input = 'S';break;}
            //
        }
        string computer = randomizer();
        switch(c_input) 
        {
            case 'R':
                if(computer == "Scissors") {cout<<"You win!"<<endl;++wins;}
                else if(computer == "Rock") {cout<<"Draw!"<<endl;++draws;}
                else cout<<"You lose!"<<endl;++losses;
                break;
            case 'P':
                if(computer == "Rock") {cout<<"You win!"<<endl;++wins;}
                else if(computer == "Paper") {cout<<"Draw!"<<endl;++draws;}
                else cout<<"You lose!"<<endl;++losses;
                break;
            case 'S':
                if(computer == "Paper") {cout<<"You win!"<<endl;++wins;}
                else if(computer == "Scissors") {cout<<"Draw!"<<endl;++draws;}
                else cout<<"You lose!"<<endl;++losses;
                break;
        }
        //
        if(i == rounds-1) cout<<"LAST ROUND - Enter another (or CTRL+Z to exit): "<<endl; 
        else cout<<"Enter another (or CTRL+Z to exit): "<<endl;
    }
    end_game:
    if (losses == 0) wr = 1; else wr = wins/losses;  
    cout<<"Statistics: "<<endl
        <<"Wins: "<<wins<<endl
        <<"Draws: "<<draws<<endl
        <<"Losses: "<<losses<<endl;
        cout.precision(3);cout<<"Winrate: "<<wr<<endl;
}

Q11:

//Definition: A prime number is a natural number greater than 1 that has no positive divisors other than 1 and itself. This means it can only be divided by 1 and itself.

// Solution 1 

bool is_prime(const int& x, const vector<int>primes)
{
    if(x == 1) return false;
    for(int i : primes) 
    {
        if(i < x && x % i == 0) return false;
    }
    return true;
}

int main()
{
    vector<int>primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    vector<int>my_primes;
    for(int i = 1; i <= 100;++i) {bool p = is_prime(i, primes); if(p == 1) my_primes.push_back(i);};
    cout<<"The original prime vector is: ";for(auto i : primes) cout<<i<<" ";
    cout<<endl;
    cout<<"The rendered prime vector is: ";for(auto i : my_primes) cout<<i<<" ";

}
 
// Solution 2

bool is_prime(const int& x, const vector<int>& primes)
{
    if(x == 1) return false;
    for(int i : primes) 
    {
        if(x % i == 0) return false;
    }
    return true;
}

int main()
{
    vector<int>primes;
    for(int i = 1;i <= 100;++i) 
    {
        bool p = is_prime(i, primes);
        if(p == 1) primes.push_back(i);
    }
    cout<<"The rendered vector of primes is: ";for(auto i : primes) cout<<i<<" ";
}


Q12:

bool is_prime(const int& x, vector<int>& primes)
{
    if(x == 1) return false;
    for(int i : primes) 
    {
        if(x % i == 0) return false;
        if (i * i > x) break;
    }
    return true;
}

int main()
{
    vector<int>primes;
    int max = 0;
    cout<<"Enter input domain for prime computation: "<<endl;
    cin>>max;
    //
    for(int i = 1;i <= max; ++i) 
    {
        if(is_prime(i, primes)) primes.push_back(i);
    }
    cout<<"The primes are: "; for(auto i : primes) cout<<i<< " "; 
}

Q13:

// Sieve of Eratosthenes: Algorithm for efficient computation of primes.  

// Version 1: Simplest known version:

void soe(const int& n) 
{
    bool A[n + 1];
    memset(A, true, sizeof(A));
    //
    for(int i = 2;i <= sqrt(n);++i) 
    {
       if(A[i]) 
       {
            for(int j = i*i;j <= n; j+=i)
                A[j] = false; 
       } 
    }
    // Print
    for(int i = 2;i <= n;++i) if(A[i]) cout<<i<<" ";
}

int main()
{
    int n = 0;
    cout<<"Enter domain size (n): ";
    cin>>n; 
    cout<<"The range of primes: ";
    soe(n);
}

// Version 2: Unecessarily complex but possible
vector<char> soe(const int& n) 
{
    vector<char>A(n+1, true);
    A[0] = A[1] = false;
    for(int i = 2;i <= sqrt(n); ++i) 
    {
        if(A[i] == true) 
        {
            for(int j = i*i;j <= n;j+=i)
                A[j] = false;
        }   
    }
    return A;
}

bool is_prime(const vector<char>& A, int x)
{
    return A[x];
}

int main()
{
    int n = 150;
    auto A = soe(n);
    cout<<"The range of primes is: "; for(auto i : A) if(is_prime(A, i)) cout<<i<<" ";  
}

Q14:

void soe(const int& n)
{
    bool A[n + 1];
    memset(A, true, sizeof(A));
    //
    for(int i = 2; i <= sqrt(n); ++i) 
    {
        if(A[i]) 
        {
            for(int j = i*i;j <= n;j+=i)
                A[j] = false;
        }
    }
    // COUT
    for(int i = 2;i <= n;++i) if(A[i]) cout<<i<<" ";
}

int main()
{
    int n = 0;
    cout<<"Enter the input domain (n): "<<endl;
    cin>>n;
    cout<<"Range of prime numbers (p): "<<endl;
    soe(n);
}

Q15:

// Write a program to take the input value n and then finds the first n primes.

// Solution 1: Not great, but better than no solution.

bool is_prime(const int& x) 
{
    if(x == 1 || x == 0) return false;
    for(int i = 2;i < x;++i)
    {
        if(x % i == 0) return false;
        if(i * i > x) break;
    }
    return true;
}

void prime_sum(const int& x, const int& n)
{
    vector<int>A;
    for(int i = 2;i <= x;++i) 
    {
        if(is_prime(i))
            A.push_back(i);
    }
    A.resize(n);
    for(int i = 0;i < A.size();++i) cout<<A[i]<<" ";
}

int main()
{
    int x = 0;
    int n = 0; // prime count
    vector<int>A;
    cout<<"Enter the range size (n) and domain (x): ";
    cin>>n>>x;
    cout<<"Test is: ";
    for(int i = 2;i <= x;++i) if(is_prime(i)) cout<<i<<" ";cout<<endl;
    cout<<"Initial n number of primes: ";
    prime_sum(x, n);
}

// Solution 2: Much better

void is_prime(const int& x) //const int& n
{
    bool A[x+1];
    memset(A, true, sizeof(A));
    A[0] = A[1] = false;
    int prime_counter = 0;
    // input must be higher than two
    if(x == 1) error("Input must be higher than 1. x>1.");
    for(int i = 2;i <= x-2;++i) 
    {
        for(int j = 2; j < x; ++j) 
        {
            if(x % j == 0)  A[i] = false;
        }
    }
    //
    for(int i = 0;i <= x;++i) if(A[i]) cout<<i<<" ";
}

// I want to have an array of bool values of x length.
// 

void soe(const int& x, const int& n)
{
    bool A[x+1];
    memset(A, true, sizeof(A));
    vector<int>B;
    //
    for(int i = 2;i <= sqrt(x);++i) 
    {
        if(A[i]) 
        {
            for(int j = i*i;j <= x;j+=i)
                A[j] = false;
        }
    }
    for(int i = 2;i <= x;++i)
    {
        if(A[i]) 
        {
            B.push_back(i);
            if(B.size() == n) break;
        }
    }
    for(int i = 0;i < B.size();++i) cout<<B[i]<<" ";
}

int main()
{
    soe(100, 10);
}

// Solution 3: The best solution

vector<int>soe(const int& n)
{
    if(n < 6) {};
    int max = (n < 6) ? 15 : int(n * (log(n) + log(log(n))));
    //
    vector<char>A(max+1, true);
    A[0] = A[1] = false;
    for(int i = 2;i*i <= max;++i) 
    {
        if(A[i]) 
        {
            for(int j = i*i;j <= max;j+=i)
                A[j] = false;
        }
    }
    vector<int>B;
    for(int i = 2;i <= max && (int)B.size() < n;++i) 
    {
        if(A[i]) 
        {
            B.push_back(i);
        }
    }
    if((int)B.size() < n) {
        return soe(n+5);
    }
    return B;
}

int main()
{
    int n = 0;
    cout<<"Enter size of the range (n): ";
    cin>>n;
    vector<int>B = soe(n);
    cout<<"The range n: ";
    for(auto i : B) cout<<i<<" ";
}

Q16: 

int main()
{
    vector<int>xvals = {17, 7, 18, 6, 10, 10, 3, 2, 12, 15, 18, 16, 10, 5, 15, 2, 14, 1, 6, 16};
    size_t count;
    size_t most = 0;
    int temp, mode;
    //
    for(size_t i = 0;i < xvals.size();++i) 
    {
        temp = xvals[i];
        count = 1;
        for(size_t j = i+1;j < xvals.size();++j) 
        {
            if(xvals[j] == temp) {
                ++count;
            }
        }
        if(most < count) 
        {
            most = count;
            mode = xvals[i];
        }
    }
    cout<<mode;
}

Q17:

// Solution 1: O(n^2) It's gigantic, including an unecessary loop. Not too bad for a first try. 
// Ordered by the ASCII sum since it's more appropriate for max, min as they are quantitiative representations of values.

string mode_val(vector<string>& xvals)
{
    string temp, mode;
    size_t count;
    size_t most = 0;
    for(size_t i = 0;i < xvals.size();++i) 
    {
        temp = xvals[i];
        count = 1;
        for(int j = i+1;j < xvals.size();++j) 
        {
            if(xvals[j] == temp) {++count;}
        }
        if(most < count) 
        {
            most = count;
            mode = xvals[i];
        }
    }
    return mode; 
}

string max_val(vector<string>& xvals)
{
    vector<int>sums(xvals.size()); 
    for(size_t i = 0;i < xvals.size();++i) 
    {
        for(char c : xvals[i]) {sums[i]+=c;}
    }
    //
    int temp; size_t max = 0;
    string temp_string; string max_string;
    for(size_t i = 0;i < sums.size();++i) 
    {
        temp = sums[i];
        temp_string = xvals[i];
        for(size_t j = i+1;j < sums.size();++j) 
        {
            if(sums[j] > temp) 
            {
                temp = sums[j];
                temp_string = xvals[j]; 
            }     
        }
        if(max < temp) 
        {
            max = temp;
            max_string = temp_string;
        }         
    }
    return max_string;    
}

string min_val(vector<string>& xvals) 
{
    vector<int>sums(xvals.size());
    for(size_t i = 0;i < xvals.size(); ++i) 
    {
        for (char c : xvals[i]) 
        {
            sums[i]+=c;                         
        }        
    }
    int temp, min = INT_MAX;
    string temp_string, min_string; 
    for(size_t i = 0;i < sums.size(); ++i) 
    {
        temp = sums[i];
        temp_string = xvals[i];
        for(int j = i+1;j < sums.size();++j) 
        {
            if(sums[j] < temp) 
            {
                temp = sums[j];
                temp_string = xvals[j];
            }
        }
        if(temp < min) 
        {
            min = temp;
            min_string = temp_string;
        }
    }  
    return min_string;
}

int main()
{
    vector<string>xvals = {"gas", "lace", "pole", "storm", "reporter", "lane", "stimulation", "compound", "recommendation", "bathtub", "lace", "bus", "seminar"};
    string min = " ",max = " ", mode = " ";
    //
    max = max_val(xvals);min = min_val(xvals);mode = mode_val(xvals);
    cout<<"The sequence max: "<<max<<endl;
    cout<<"The sequence min: "<<min<<endl;
    cout<<"The sequence mode: "<<mode<<endl;
}

// Solution 2: This solution is an improvement compared to the previous one since min_val, max_val are now O(n) instead of O(n^2) since we removed the nested loops
// This solution is ordering string by their ASCII sum.

string min_val(vector<string>& xvals) // min_val
{
    vector<int>sums(xvals.size());
    for(size_t i = 0; i < sums.size();++i) {
        for(char c : xvals[i]) sums[i]+=c; 
    }
    int min_int = sums[0];
    string min_string = xvals[0];
    for(size_t i = 0;i < sums.size();++i) 
    {
        if(sums[i] < min_int) 
        {
            min_int = sums[i];
            min_string = xvals[i];
        } 
    } 
    return min_string;   
}

string max_val(vector<string>& xvals) 
{
    vector<int>sums(xvals.size());
    for(size_t i = 0;i < sums.size();++i)
        for(char c : xvals[i]) sums[i]+=c;
    
    int max_int = sums[0];
    string max_string = xvals[0];
    for(size_t i = 0;i < sums.size();++i) 
    {
        if(sums[i] > max_int) 
        {
            max_int = sums[i];
            max_string = xvals[i];
        }
    }
    return max_string;
}

string mode_val(vector<string>& xvals)
{
    unordered_map<string, size_t> freq;
    for(const string& s : xvals) {
        ++freq[s]; //  
    }
    string mode;
    size_t most = 0;
    for(const auto& pair : freq) 
    {
        if(pair.second > most) 
        {
            most = pair.second;
            mode = pair.first;
        }
    }
    return mode;
}

int main()
{
    vector<string>xvals = {"jam", "cake", "identification", "fear", "heat", "thinker", "wording", "relevance", "swim", "drain", "survivor", "drink", "candidate", "thinker", "slogan", "traffic", "sport", "differ", "bride", "button", "accurate", "cruelty", "marsh", "guideline", "finger"};
    string min = min_val(xvals), max = max_val(xvals), mode = mode_val(xvals);
    //
    cout<<"The smallest string: "<<min<<endl;
    cout<<"The largest string: "<<max<<endl;
    cout<<"The mode: "<<mode<<endl;
}

Q18:
// Quadratic formula  x = (-b +- sqrt(b^2 - 4(ac)))/2*a

pair<double, double> quadratic_expr(const double& a, const double& b, const double& c) 
{
    pair<double, double>result = {0.0, 0.0};
    double x1 = 0.0, x2 = 0.0;
    double disc = (b*b)  - 4*(a*c);
    x1 = (-b + sqrt(disc))/(2*a);
    x2 = (-b - sqrt(disc))/(2*a);
    result = {x1, x2};
    return result;
}

int main()
{
    double a, b, c; //quadratic constants
    cout<<"Bla bla bla bla: ";
    cin>>a>>b>>c;
    pair<double, double>x = quadratic_expr(a, b, c);
    cout<<x.first<<" "<<x.second<<" "<<endl; 
}

Q19:

int main()
{
    pair<string, int>input;
    vector<string>name;
    vector<int>scores;
    cout<<"Enter the user ID and score: "<<endl;
    while(cin>>input.first>>input.second && input.first != "No more") 
    {
        name.push_back(input.first);
        scores.push_back(input.second);
        
    }
    string temp;
    bool double_input = false;
    for(size_t i = 0;i < name.size();++i) 
    {
        temp = name[i];
        for(size_t j = i+1;j < name.size();++j) 
        {
            if(name[j] == temp) {
                double_input = true;break;}
        }
    }
    if(double_input) error("Duplicate input for name variable."); // Although it works this code is a disaster O(n^2) is the execution speed. Not great but keep for now
    //
    cout<<"Rankings: "<<endl;
    for(size_t i = 0;i < name.size();++i) 
    {
        cout<<name[i]<<" "<<scores[i]<<" "<<endl;
    }
}

Q20:

int main()
{
    pair<string, int>input;
    vector<string>names;
    vector<int>scores;
    //
    cout<<"Enter records: (Use 'No more' to exit prompt.): "<<endl;
    while(cin>>input.first>>input.second) 
    {
        for(string n : names) 
        {
            if(n == input.first) 
            {
                error("Duplicate input ", input.first);
            }
        }
        //
        names.push_back(input.first);
        scores.push_back(input.second);
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // Search
    string record_search;
    cout<<"Search records (or CTRL+Z to exit): "<<endl;
    while(cin>>record_search) 
    {
        bool found = false;
        for(size_t i = 0;i < names.size();++i) 
        {
            if(record_search == names[i]) 
            {
                cout<<"Score: "<<scores[i]<<endl;
                found = true;
                break;
            }
        }
        if(!found) cout<<"name not found"<<endl;
        cout<<"Search another (or CTRL+Z to exit): "<<endl;
    }
}

Q21:

int main()
{
    pair<string, int>input;
    vector<string>names;
    vector<int>scores;
    //
    cout<<"Enter records:"<<endl;
    while(cin>>input.first>>input.second) 
    {
        for(const string& n : names) 
        {
            if(n == input.first) {error("Double input.", input.first);}
        }
        //
        names.push_back(input.first);
        scores.push_back(input.second);
    }
    // Clear read prompt
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // We need to search the score;
    int record_search;
    cout<<"Search records: "<<endl;
    while(cin>>record_search) 
    {
        bool found = false;
        cout<<"Players with corresponding score(s): ";
        for(size_t i = 0;i < scores.size();++i) 
        {
            if(record_search == scores[i]) 
            {
                cout<<names[i]<<" ";
                found = true;
            }
        }
        cout<<endl;
        if(!found) cout<<"score not found"<<endl;
        cout<<"Look for another (or CTRL+Z to exit): "<<endl;
    }
}
    

Exercises Take 2:

Q2:

int main()
{
    vector<double>sequence = {14.8, 55.1, 56.1, 9.9, 23.8, 10.3, 3.8, 32.8, 54.8, 15.6, 20.4, 29.5, 39.3, 49.3, 56.9, 51.9, 17.1, 13.9, 44.6};
    double median;
    int n = sequence.size();
    //
    sort(sequence.begin(), sequence.end());
    if(n % 2 == 0) 
    {
        median = (sequence[n/2 - 1] + sequence[n/2]) / 2.0;
    }
    else 
    {
        median = sequence[n/2];
    }
    for(auto i : sequence) cout<<i<<" ";cout<<endl;
    cout<<median;
}

Q3: 

double sum(vector<double>& distances) 
{
    double sum;
    for(size_t i = 0;i < distances.size();++i) sum+=distances[i];
    
    return sum;
}

double min_val(vector<double>& distances) 
{
    double smallest = *min_element(distances.begin(), distances.end());
     
    return smallest;
}

double max_val(vector<double>& distances) 
{
    double greatest = *max_element(distances.begin(), distances.end());
    
    return greatest;
}

double mean_val(vector<double>& distances) 
{
    double mean, sum;
    int n;
    for(auto i : distances) sum+=i; 
    n = distances.size();
    mean = sum/n;

    return mean;
}


int main()
{
    vector<double>distances = {66442.88, 99649.74, 43487.98, 43085.33, 86825.17, 82010.81};
    double total, smallest, greatest, mean;
    total = sum(distances);
    smallest = min_val(distances);
    greatest = max_val(distances);
    mean = mean_val(distances);
    std::cout<<std::fixed<<setprecision(2)<<total<<endl
            <<smallest<<endl
            <<greatest<<endl
            <<mean<<endl;
}
 
Q5:

// r = a - b * floor(a/b);
double remainder_val(double& a, double& b) 
{
    double r;
    r = a - b * floor(a/b);

    return r;
}

int main()
{
    double xval1, xval2;
    char operation;
    cout<<"Enter an operation in standard format: ";
    while(cin>>xval1>>operation>>xval2)
    {
        switch(operation) 
        {
            case '+':
                cout<<"The sum of "<<xval1<<" and "<<xval2<<" is "<<xval1+xval2;
             case '-':
                cout<<"The difference of "<<xval1<<" and "<<xval2<<" is "<<xval1-xval2;
             case '*':
                cout<<"The product of "<<xval1<<" and "<<xval2<<" is "<<xval1*xval2;
             case '/':
                cout<<"The quotient of "<<xval1<<" and "<<xval2<<" is ";if(xval2 == 0) cout<<"NaN. Division by 0."; else xval1/xval2;
             case '%':
                cout<<"The remainder of "<<xval1<<" in "<<xval2<<" is "<<remainder_val(xval1, xval2);
        }

        cout<<endl;
        cout<<"Enter another operation (or CTRL+Z to exit): "<<endl;
    }
}

Q6:

int main()
{
    vector<string>xvals = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string input;
    cout<<"Enter any integer from 0-9 as either a string or an int:"<<endl;
    while(cin>>input) 
    {
        bool is_digit = true;
        for(char c : input) 
        {
            if(!isdigit(c)) is_digit = false; 
        }
        if(is_digit) 
        {
            int x = stoi(input);
            if(x <= xvals.size()) 
            {
                cout<<xvals[x]<<" "<<endl;
            }
            else cout<<"Invalid input domain."<<endl;            
        }
        else 
        {
            bool found = false;
            for(size_t i = 0;i < xvals.size();++i) 
            {
                if(input == xvals[i]) 
                {
                    cout<<i<<endl;
                    found = true;
                    break;
                }
            }
            if(!found) cout<<"Invalid input domain."<<endl; 
        };
        cout<<"Enter another (or CTRL+Z) to exit: ";
    }
}

Q7:


int main()
{
    vector<string>xvals = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string xval1, xval2;
    int val1, val2;
    char operation;
    //
    cout<<"Enter any operation in standard form (inputs are vals from 0-9 in int or string): "<<endl;
    while(cin>>xval1>>operation>>xval2) 
    {
        bool is_digit1 = true, is_digit2 = true;
        for(char c : xval1) 
        {
            if(!isdigit(c)) is_digit1 = false;
        }
        for(char c : xval2) 
        {
            if(!isdigit(c)) is_digit2 = false;
        }
        //
        if(is_digit1 && is_digit2) 
        {
             val1 = stoi(xval1);val2 = stoi(xval2);
             if(val1 < 0 || val1 >= xvals.size() || val2 < 0 || val2 >= xvals.size()) 
             {
                cout<<"Invalid input domain."<<endl;
                cout<<"Enter another (or CTRL+Z to exit): "<<endl;
                continue;
            }
        }
        else
        {
            val1 = -1, val2 = -1;
            for(size_t i = 0;i < xvals.size();++i) 
            {
                if(xval1 == xvals[i]) val1 = i;
                if(xval2 == xvals[i]) val2 = i;
                
                if(val1 != -1 && val2 != -1) break;
            }
            if(val1 == -1 || val2 == -1) 
            {
                cout<<"Invalid input domain."<<endl;
                cout<<"Enter another (or CTRL+Z to exit): "<<endl;
                continue;
            }
        }
        switch(operation) 
        {
            case '+':
                cout<<"The sum of "<<val1<<" and "<<val2<<" is "<<val1+val2<<endl;break;
            case '-':
                cout<<"The difference of "<<val1<<" and "<<val2<<" is "<<val1-val2<<endl;break;
            case '*':
                cout<<"The product of "<<val1<<" and "<<val2<<" is "<<val1*val2<<endl;break;
            case '/':
                cout<<"The quotient of "<<val1<<" and "<<val2<<" is ";
                    if(val2 == 0) cout<<"NaN. Division by zero."<<endl;
                    else cout<<val1/val2<<endl;
                    break;
            case '%':
                cout<<"The remainder of "<<val1<<" and "<<val2<<" is ";
                    if(val2 == 0) cout<<"NaN. Mod by zero."<<endl;
                    else cout<<val1%val2<<endl;
                    break;
            default:
                cout<<"Invalid operator."<<endl;
        }
        cout<<"Enter another (or CTRL+Z to exit): "<<endl;
    }
}

Q8-Q9:

// Option 1 (OK):
unsigned long long mmplier (const int & x)
{
    unsigned long long result = 1ULL;
    if(x == 1) return result;
    else 
    {
        for(size_t i = 2;i <= x; ++i) 
        {
            result*=2ULL;
        }
    }
    return result;
}


//Option 2 (Better):

unsigned long long mmplier(const int& x)
{
    unsigned long long result = 1ULL;
    if(x == 1) return result;
    if(x == 2) {result = 2;return result;}
    else if(x % 2 == 0) 
    {
        result = 2ULL;
        for(size_t i = 3;i <= x;i+=2) 
        {
            result*=4ULL;
        }
    }
    else if(x % 2 != 0)
    {
        for(size_t i = 3;i <= x;i+=2) 
        {
            result*=4ULL;
        }
    }
    return result;
}

// Option 3 (Best):

unsigned long long mmplier(const int& x) 
{
    unsigned long long result = 1;
    if(x == 1) return result;
    else
    {
        result = 1ULL << (x-1);
    }
    return result;
}

unsigned long long prev_squares(const int& squares) 
{
    unsigned long long result = 1;
    for(size_t i = 2;i < squares;++i) 
    {
        result+=mmplier(i);
    }
    return result;
}

unsigned long long threshold_squares(const int& squares, const int& threshold) 
{
    unsigned long long sum = 0ULL;
    int result = 0;
    for(size_t i = 1;i <= squares;++i) 
    {
        sum+=mmplier(i);
        if(sum >= threshold) {result = i;break;}
    }
    return result;
}

int main()
{
    int squares = 64;
    int threshold1 = 1000, threshold2 = 1000000, threshold3 = 1000000000;
    int squares_th1, squares_th2, squares_th3;
    //
    unsigned long long grains_on_current_square, grains_on_previous_squares; 
    //
    grains_on_current_square = mmplier(squares);
    grains_on_previous_squares = prev_squares(squares);
    squares_th1 = threshold_squares(squares, threshold1);
    squares_th2 = threshold_squares(squares, threshold2);
    squares_th3 = threshold_squares(squares, threshold3);
    // squares_th2 = threshold_squares(squares, threshold2);
    // squares_th3 = threshold_squares(squares, threshold3); 
    //
    // OUTPUT
    cout<<"The number of squares: "<<squares<<endl;
    cout<<"The number of grains per suqare: ";
        for(size_t i = 1;i <= squares; ++i) 
        {
            cout<<mmplier(i)<<" ";                       
        }
    cout<<endl;
    cout<<"The number of grains on the current square: "<<grains_on_current_square<<endl;
    cout<<"The number of grains on previous squares: "<<grains_on_previous_squares<<endl;
    cout<<"The number of squares for each treshold: "<<endl
        <<"Threshold 1: "<<squares_th1<<endl
        <<"Threshold 2: "<<squares_th2<<endl
        <<"Threshold 3: "<<squares_th3<<endl;
}

Q10:

string randomizer() 
{
    vector<string>options = {"rock", "paper", "scissors"};
    int random_pos = std::rand() % options.size();
    
    return options[random_pos];

}

string to_lowercase(string x)
{
    transform(x.begin(), x.end(), x.begin(),
            [] (unsigned char c) {return tolower(c);});
    return x;
}

int main()
{
    std::srand(std::time(0));
    string input;
    cout<<"Enter either rock, paper, or scissors: "<<endl;
    size_t wins = 0, losses = 0, draws = 0;
    double games = 0.0;
    while(cin>>input) 
    {
        input = to_lowercase(input);
        char input_char;
        if(input == "rock" || input == "r") input_char = 'R';
        else if(input == "paper" || input == "p") input_char = 'P';
        else if(input == "scissors" || input == "s") input_char = 'S';
        else {
            cout<<"Invalid input string."<<endl;
            cout<<"Enter another: (or CTRL+Z to exit):"<<endl;
            continue;
        }
    //    
        string computer = randomizer();
        switch (input_char) 
        {
            case 'R':
                if(computer == "scissors") {cout<<"You win!"<<endl;++wins;}
                if(computer == "rock") {cout<<"Draw!"<<endl;++draws;}
                if(computer == "paper") {cout<<"You lose!"<<endl;++losses;}
                break;
            case 'P':
                if(computer == "rock") {cout<<"You win!"<<endl;++wins;}
                if(computer == "paper") {cout<<"Draw!"<<endl;++draws;}
                if(computer == "scissors") {cout<<"You lose!"<<endl;++losses;}
                break;
            case 'S':
                if(computer == "paper") {cout<<"You win!"<<endl;++wins;}
                if(computer == "scissors") {cout<<"Draw!"<<endl;++draws;}
                if(computer == "rock") {cout<<"You lose!"<<endl;++losses;}
                break; 
        }
        ++games;
        cout<<"Enter another: (or CTRL+Z to exit): "<<endl;
    }
    double wr = (wins/games)*100;
    cout<<"Overall Stats: "<<endl
        <<"Wins: "<<wins<<endl
        <<"Draws: "<<draws<<endl
        <<"Losses: "<<losses<<endl;
        std::cout<<std::fixed<<std::setprecision(2)<<"Winrate: "<<wr<<endl;
}

Q11-Q12:

bool is_prime(const int& x, vector<int>primes)
{
    if(x == 1) return false;
    for(size_t i = 2;i < x;++i) 
    {
        if(x % i == 0) return false;
        if(i * i > x) break;
    }
    return true;    
}

int main()
{
    vector<int>primes;
    int max = 0;
    cout<<"Enter the maximum domain value of the prime alogrithm: "<<endl;
    cin>>max;
    for(size_t i = 1;i <= max;++i) if(is_prime(i, primes)) cout<<i<<" ";
}

Q13-Q14:

void soe(const int& x)
{
    vector<char>A(x+1, true);
    A[0] = A[1] = false;
    for(size_t i = 2;i*i <= x;++i) 
    {
        if(A[i]) 
        {
            for(size_t j = i*i;j <= x;j+=i) 
            {
                A[j] = false;
            }
        }
    }
    //
    for(size_t i = 2;i <= x;++i) if(A[i]) cout<<i<<" ";
}


int main()
{
    int max = 0;
    cout<<"Enter the max domain for prime search using SOE Algo.: "<<endl;
    cin>>max;
    cout<<"The primes are: ";soe(max);
}

Q15: 
*/

void soe(const int& n)
{
    int max = (n < 6) ? 15 : int(n * (log(n) + log(log(n))));
    vector<char>A(max, true);
    A[0] = A[1] = false;
    for(size_t i = 2;i*i <= max; ++i) 
    {
        if(A[i]) 
        {
            for(size_t j = i*i;j <= max;j+=i) 
            {
                A[j] = false;    
            }
        }
    }
    //
    vector<int>B;
    for(size_t i = 2;i <= max;++i) 
        if(A[i] && B.size() <= n) B.push_back(i);
    for (auto i : B) cout<<i<<" ";   
}

int main()
{
    int n = 20;
    cout<<"The first "<<n<<" primes are: "<<endl;soe(n);
}
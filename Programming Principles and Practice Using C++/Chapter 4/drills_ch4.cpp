#include "std_lib_facilities.h"

/*

int main()
{
    int a = 0;
    int b = 0;
    cout<<"Enter two integers: \n";
    cin>>a>>b;
    if(a > b)
        cout<<"max("<<a<<", "<<b<<") "<<"= "<<a<<"\n";
    else
        cout<<"max("<<a<<", "<<b<<") "<<"= "<<b<<"\n";
    
    cout<<"Thank you for using our program\n\n";

    keep_window_open();
    return(0);
}

Traffic lights:

int main()
{
    string traffic_light = " ";
    cout<<"Enter the color of the traffic light(current): \n";
    cin>>traffic_light;
    // IF statement
    if (traffic_light == "green")
        cout<<"RUN!"
    else if (traffic_light == "yellow")
        cout<<"W8!";
    else if (traffic_light == "red")
        cout<<"STOP!";
    else error("That color is not used in traffic lights");
}

Converting inches to centimeters:

int main()
{
    const double cm_per_inch = 2.54; // constant expression of lside cm_per_inch and rside double 2.5; 8 bytes
    double i = 0.0; // An object of type double with a name expression of i, standing for inches; 8 bytes
    double c = 0.0; // An object of type double with a name expression of c, standing for cm; 8 bytes
    double val = 0.0; // An object of type double with a name expression of val, standing for the value of input number; size 8 bytes
    char unit = ' '; // An object of type char with a name expression of "unit", standing for unit of measurement; 1 byte
    cout<<"Enter any value you'd like to convert followed by a unit(c or i): \n";
    cin>>val>>unit;
    if(unit == 'c') {
        i = val * cm_per_inch;
        cout<<"Value in inches (i): "<<i<<"\n\n";}
    else if(unit == 'i') {
        c = val * cm_per_inch;
        cout<<"Value in centimeters (c): "<<c<<"\n\n";}
    else error("Invalid unit measure. Please enter either c or i.");
    
    cout<<"Thank you for using our program!\n\n";

    keep_window_open();
    return(0);
}

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

Calculate and print a table of squares 0-99

int main()
{
    int i = 0; // A variable to keep track how many times we've ran through the loop.
    while(i<100) // A way to repeat some statement
                 // i<100, is a termination criterion
    { // This si the body of the while statement. In here, we tell the program to do something each time.
        cout<<i<<'\t'<<pow(i, 2)<<'\n'; // 
        i++;    // 
    }
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
  
Empty statement:

int main()
{
    int a = 0;
    int b = 0;
    cout<<"Enter any two integers: \n";
    cin>>a>>b;
    if (a<=b) {} // if a <= b then do nothing 
    else // If a => b then replace a with b
    {
        int t = a; 
        a = b;
        b = t;
    }
    cout<<"New values: "<<a<<' '<<b<<'\n';
}

Calculating and printing a table of squares 0-99 using a for statement

int main()
{
    for(int i = 0; i<100;++i)
        cout<<i<<'/t'<<pow(i, 2)<<'\n';
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

Write a function for square()

int square(int x) 
{
    return x*x;
}

int main()
{
    cout<<"2 * 2 = "<<square(2)<<'\n';
    cout<<"5 * 5 = "<<square(5)<<'\n';
}

void print_square(int v) // This function performs two logically separate actions: 1. Computes the square of an int; 2. Prints the square of an int.
{
    cout<<v<<'\t'<<v*v<<'\n';
}

int main()
{
    for(int i =0;i<100;++i) print_square(i);
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

// Definition of square function by addition with for-statement
int square(int x) 
{
    int result = 0;
    for(int i = 0; i < x; i++) {result += x;} // Remember to include the body of the for loop; Here you add += x to result each time i < x
    return result;
}

int main()
{
    cout<<square(9);
}

vector<int> v(6); // vector of 6 ints
v[0] = 5;
v[1] = 7;
v[2] = 6;
v[3] = 4;
v[4] = 1;
v[5] = 4;

vector<string> philosopher(4) // vector of 4 strings
philosopher[0] = "Kant";
philosopher[1] = "Kano";
philosopher[2] = "KaLu";
philosopher[3] = "Albert";

A numeric example:

int main()
{
    vector<int>temps;
    double temp = 0.0;
    cout<<"Enter the current temperature in any number of major cities across the globe (terminate the sequence with |): ";
    while(cin>>temp) {temps.push_back(temp);}
    // Mean
    double sum = 0.0;
    for(int i = 0;i < temps.size();++i) {sum += temps[i];}
    cout<<"The mean temperature is: "<<sum/temps.size()<<endl;
    // Median
    sort(temps.begin(), temps.end());
    cout<<"The median temperature is: "<< temps[temps.size()/2]<<endl;

    cout<<"Thank you for using our program!"<<endl;

    keep_window_open();
    return(0);
}

A text example:

int main()
{
    vector<string>words;
    string word;
    while(cin>>word) // read whitespace-separated words
        words.push_back(word); //store in the back of the vector
    cout<<"Number of words: "<<words.size()<<endl;
    sort(words.begin(), words.end()); // sort "from beginning to end"
    //
    for(int i = 0; i < words.size(); ++i) {
        if (i==0 || words[i - 1] != words[i]) // is this a new word?
            cout<<words[i]<<"\n";
    }    
}


TRY THIS 5: Write a program that "bleeps" out the word you don't like

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

Drill Section:

Q1:

int main()
{
    vector<int>xvals;
    int xval = 0;
    while(cin>>xval) {xvals.push_back(xval);}
    // Print out two integers at a time
    int i = 0;
    while(i < xvals.size()) 
    {
        cout<<xvals[i]<<" "; 
        if(i + 1 < xvals.size()) cout<<xvals[i+1]; 
        cout<<endl;i+=2;  // make sure you hit the operator sign correctly
    }
    cout<<endl;

    cout<<"Thank you for using our program!\n\n";
}

Q2:

int main()
{
    vector<int>xvals;
    int xval = 0;
    // 
    while(cin>>xval) {xvals.push_back(xval);}
    //
    int i = 0;
    while(i + 1 < xvals.size()) 
    {
        if(xvals[i] < xvals[i+1]){cout<<"The smaller value is: "<<xvals[i]<<" "<<"The larger value is: "<<xvals[i+1]<<endl;}
        else {cout<<"The smaller value is: "<<xvals[i+1]<<" "<<"The larger value is: "<<xvals[i+1]<<endl;};
        i+=2;
    } 
    if(i < xvals.size()) {cout<<"The value without a pair is: "<<xvals[i]<<endl;}
    cout<<endl;
    
    cout<<"Thank you for using our program!\n\n";
}

Q3:

int main()
{
    vector<int>xvals;
    int xval = 0;
    // 
    while(cin>>xval) {xvals.push_back(xval);}
    //
    int i = 0;
    while(i + 1 < xvals.size()) 
    {
        if(xvals[i] < xvals[i+1]) {cout<<"The smaller value is: "<<xvals[i]<<" "<<"The larger value is: "<<xvals[i+1]<<endl;}
        else if (xvals[i+1] < xvals[i]) {cout<<"The smaller value is: "<<xvals[i+1]<<" "<<"The larger value is: "<<xvals[i]<<endl;}
        else {cout<<"The line numbers are equal."<<endl;};
        i+=2;
    } 
    if(i < xvals.size()) {cout<<"The value without a pair is: "<<xvals[i]<<endl;}
    cout<<endl;
    
    cout<<"Thank you for using our program!\n\n";
}

Q4:

int main()
{
    vector<double>xvals;
    double xval = 0.0;
    // Read 
    while(cin>>xval) {xvals.push_back(xval);}
    // Output
    int i = 0;
    while(i + 1 < xvals.size()) 
    {
        if(xvals[i] < xvals[i+1]) {cout<<"The smaller value is: "<<xvals[i]<<" | "<<" "<<"The larger value is: "<<xvals[i+1]<<endl;}
        else if(xvals[i+1] < xvals[i]) {cout<<"The smaller value is: "<<xvals[i+1]<<" | "<<"The larger value is: "<<xvals[i]<<endl;}
        else {cout<<"The numbers are equal."<<endl;};
        i+=2;
    }

    if(i < xvals.size()) {cout<<"The value without a pair is: "<<xvals[i]<<endl;}

    cout<<endl;
    cout<<"Thank you for using our program!\n\n";
}

Q5:

int main()
{
    vector<double>xvals;
    double xval = 0;
    // Read
    while(cin>>xval) {xvals.push_back(xval);}
    // Output
    double i = 0.0;
    double threshold = 1.0/10000000.0; // When you are doing operations within a double facilitator make sure you write numbers accordingly
    while(i + 1 < xvals.size()) 
    {   
        if(xvals[i] < xvals[i+1]) {cout<<"The smaller value is: "<<xvals[i]<<" | "<<"The larger value is: "<<xvals[i+1]; if(abs(xvals[i] - xvals[i+1]) < threshold) {cout<<" | "<<"The numbers are almost equal.";}; cout<<endl;}
        else if(xvals[i+1] < xvals[i]) {cout<<"The smaller value is: "<<xvals[i+1]<<" | "<<"The larger value is: "<<xvals[i]; if(abs(xvals[i+1] - xvals[i]) < threshold) {cout<<" | "<<"The numbers are almost equal.";}; cout<<endl;}
        else {cout<<"The numbers are equal."<<endl;};
        i+=2;
    }
    if(i < xvals.size()) {cout<<"The value without a pair is: "<<xvals[i]<<endl;}
    
    cout<<endl;
    cout<<"Thank you for using our program!\n\n";
}

Q6:
*/
int main()
{
    vector<double>xvals; 
    double xval = 0.0;
    // Read
    while(cin>>xval) {xvals.push_back(xval);}
    // Output
    int i = 0;
    double smallest = 0.0;
    double largest = 0.0;
    while(i < xvals.size()) 
    {
        cout<<xvals[i]<<endl<<xvals[i+1];
        i+=2;
    }        
    cout<<endl;
    cout<<"Thank you for using our program!\n\n";
}

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

int main()
{
    vector<double>xvals;
    double xval = 0.0;
    while(cin>>xval) {xvals.push_back(xval);}
    //
    double smallest = xvals[0];
    double largest = xvals[0];
    // 
    for(int i = 0;i < xvals.size(); ++i) 
    {
        if (i == 0) {cout<<xvals[i]<<' '<<"the first value";}
        else if (xvals[i] < smallest) {smallest = xvals[i]; cout<<smallest<<' '<<"the smallest so far";} 
        else if (xvals[i] > largest) {largest = xvals[i]; cout<<largest<<' '<<"the largest so far";}
        else {cout<<xvals[i];};
        cout<<endl;
    }
    //
    cout<<endl;
    cout<<"The smallest overall: "<<smallest<<" | "<<"The largest overall: "<<largest<<endl;
    cout<<endl;
    cout<<"Thank you for using our program!";
}

int main()
{
    vector<double>xvals;
    double xval = 0.0;
    while(cin>>xval) {xvals.push_back(xval);}
    //
    double smallest = xvals[0];
    double largest = xvals[0];
    int i = 0;
    while(i < xvals.size()) 
    {
        if(i == 0) {cout<<xvals[i]<<' '<<"the first value";}
        else if(xvals[i] < smallest) {smallest = xvals[i];cout<<smallest<<' '<<"the smallest so far";}
        else if(xvals[i] > largest) {largest = xvals[i];cout<<largest<<' '<<"the largest so far";}
        else {cout<<xvals[i];};
        cout<<endl;
        ++i;
    }
    //
    cout<<endl;
    cout<<"The smallest overall: "<<smallest<<" | "<<"The largest overall: "<<largest<<endl;
    cout<<endl;
    cout<<"Thank you for using our program!";
}

Q7:

int main()
{
   vector<std::pair<double, string>>xvals;
   double xval = 0.0;
   string unit = "";
   const double m_in_cm = 100.0, in_in_cm = 2.54, ft_in_inch = 12.0;
   //
   while(cin>>xval>>unit && unit != "stop") {xvals.push_back(std::make_pair(xval, unit));}
   //
   for(int i = 0; i < xvals.size();++i)  
   {
    cout<<xvals[i].first<<xvals[i].second<<" = ";
    //
    if(xvals[i].second == "m") {cout<<xvals[i].first * m_in_cm<<"cm";}
    else if(xvals[i].second == "in") {cout<<xvals[i].first * in_in_cm<<"cm";}
    else if(xvals[i].second == "ft") {cout<<xvals[i].first * ft_in_inch<<"in";}
    else cout<<xvals[i].first<<"cm";
    cout<<endl;       
   }
   cout<<endl;
   cout<<"Thank you for using our program!";
}

Q8:

int main()
{
    vector<std::pair<double, string>>xvals;
    double xval = 0.0;
    string unit = "";
    const double m_in_cm = 100, inch_in_cm = 2.54, ft_in_inch = 12; 
    vector<string>illegal_units = {" ", "y", "yard", "meter", "km", "gallons"};
    //
    while(cin>>xval>>unit && unit != "stop") {xvals.push_back({xval, unit});}
    //
    for(int i = 0; i < xvals.size();++i) 
    {
        cout<<xvals[i].first<<xvals[i].second<<" = ";
        if(xvals[i].second == "m") {cout<<xvals[i].first * m_in_cm<<"cm";}
        else if(xvals[i].second == "ft") {cout<<xvals[i].first * ft_in_inch<<"in";}
        else if(xvals[i].second == "in") {cout<<xvals[i].first * inch_in_cm<<"cm";}
        else if(xvals[i].second == "cm") {cout<<xvals[i].first<<"cm";}
        else error("The accepted values are: m, ft, in, cm.");
        cout<<endl;
    }
    
    cout<<endl;
    cout<<"Thank you for using our program!";
}

Q9:

T1

int main()
{
    vector<double>xvals;
    vector<string>units;
    double xval = 0.0;
    string unit = " ";
    while(cin>>xval>>unit) {xvals.push_back(xval); units.push_back(unit);}
    // Accepting only four units cm, m, in, ft
    const double cm_in_m = 0.01, inch_in_m = 0.0254, ft_in_m = 0.3048;  
    vector<string>legal_units = {"cm", "m", "in", "ft"}; 
    //
    double smallest = xvals[0], largest = xvals[0]; 
    for(int i = 0;i < xvals.size() && i < units.size(); ++i)
    {
        if(units[i] == "cm") {smallest = xvals[0] * cm_in_m; largest = xvals[0] * cm_in_m;}
        else if(units[i] == "in") {smallest = xvals[0] * inch_in_m;largest = xvals[0] * inch_in_m;}
        else if(units[i] == "ft") {smallest = xvals[0] * ft_in_m;largest = xvals[0] * ft_in_m;}
        else {smallest = xvals[0]; largest = xvals[0];}
    };
    //
    for(int i = 0;i < xvals.size() && i < units.size(); ++i)
    {
        if(units[i] == "cm" && xvals[i] * cm_in_m < smallest) {smallest = xvals[i] * cm_in_m;} else if (units[i] == "cm" && xvals[i] > largest) {largest = xvals[i] * cm_in_m;}
        if(units[i] == "m" && xvals[i] * 1 < smallest) {smallest = xvals[i] * 1;} else if (units[i] == "m" && xvals[i] > largest) {largest = xvals[i] * 1;}
        if(units[i] == "in" && xvals[i] * inch_in_m < smallest) {smallest = xvals[i] * inch_in_m;} else if (units[i] == "in" && xvals[i] > largest) {largest = xvals[i] * inch_in_m;}
        if(units[i] == "ft" && xvals[i] * ft_in_m < smallest) {smallest = xvals[i] * ft_in_m;} else if (units[i] == "ft" && xvals[i] > largest) {largest = xvals[i] * ft_in_m;} 
    };
    //
    double sum = 0.0;
    for(int i = 0;i < xvals.size() && i < units.size(); ++i) // fine 
    {
        if(units[i] == "cm") {sum += xvals[i] * cm_in_m;}
        else if (units[i] == "m") {sum += xvals[i] * 1;}
        else if (units[i] == "in") {sum += xvals[i]*inch_in_m;}
        else if (units[i] == "ft") {sum += xvals[i]*ft_in_m;}
    };
    //
    for (int i = 0; i < units.size();++i)
    {
        bool valid = false;
        for(int j = 0; j < legal_units.size();++j) 
        {
            if(units[i] == legal_units[j]) {valid = true; break;} // break = we stop searching once we find a match
        }
        if(!valid) error("The accepted units are: cm, m, in, ft.");
    }
    std::cout<<endl;
    cout<<"The smallest value is: "<<smallest<<endl;
    cout<<"The largest value is: "<<largest<<endl;
    cout<<"The count of values is: "<<xvals.size()<<endl;
    cout<<"The sum of values is: "<<sum<<endl;
    //
    cout<<endl;
    std::cout<<"Thank you for using our program!"; 
} 

T2

int main()
{
    vector<std::pair<double, string>>xvals;
    double xval = 0.0;
    string unit = "";
    vector<string>legal_values = {"cm", "in", "m", "ft"};
    const double cm_in_m = 0.01, ft_in_m = 0.3048, inch_in_m = 0.0254;
    //
    while(cin>>xval>>unit && unit != "|") {xvals.push_back({xval, unit});}
    //
    double smallest = xvals[0].first;
    double largest = xvals[0].first;
    // min/max
    for(int i = 0;i < xvals.size();++i) 
    {
        if(xvals[i].second == "in") {smallest = xvals[i].first*inch_in_m;largest = xvals[i].first*inch_in_m;}
        else if(xvals[i].second == "cm") {smallest = xvals[i].first*cm_in_m;largest = xvals[i].first*cm_in_m;}
        else if(xvals[i].second == "ft") {smallest = xvals[i].first*ft_in_m;largest = xvals[i].first*ft_in_m;}
        else smallest = xvals[i].first; largest = xvals[i].first;
    } 
    // sum
    double sum = 0.0;
    for(int i = 0;i < xvals.size();++i) 
    {
        if(xvals[i].second == "in") {sum+=xvals[i].first*inch_in_m;}
        else if(xvals[i].second == "cm") {sum+=xvals[i].first*cm_in_m;}
        else if(xvals[i].second == "ft") {sum+=xvals[i].first*ft_in_m;}
        else {sum+=xvals[i].first;}
    }
    //
    int count = xvals.size();
    //
    for(int i = 0;i < xvals.size();++i) 
    {
        bool valid = false;
        for(int j = 0;j < xvals.size();++j)
        {
            if(xvals[i].second == legal_values[j]) {valid = true; break;}
        }
        if(!valid) error("Valid units are: m, cm, in, and ft.");          
    }
    cout<<"The smallest value is: "<<smallest<<endl
        <<"The largest value is: "<<largest<<endl
        <<"The count of values is: "<<count<<endl
        <<"The sum of values is: "<<sum<<"m"<<endl;
    
    cout<<endl<<"Thank you for using our program!";
}

Q9:

pair<double, string> to_m(const pair<double, string> & xval)
{
    const double cm_in_m = 0.01, ft_in_m = 0.3048, inch_in_m = 0.0254;
    pair<double, string>result = xval;
    
    if(xval.second == "cm") {result.first = xval.first * cm_in_m;}
    else if(xval.second == "ft") {result.first = xval.first * ft_in_m;}
    else if(xval.second == "in") {result.first = xval.first * inch_in_m;}
    else if(xval.second == "m") {result.first = xval.first;}
    else error("The function does not perform specified unit conversions.");
    
    result.second = "m";
    return result;
}

int main()
{
    vector<std::pair<double, string>>xvals;
    double xval = 0.0;
    string unit = "";
    vector<string>legal_values = {"cm", "in", "m", "ft"};
    //
    while(cin>>xval>>unit && unit != "|") {xvals.push_back({xval, unit});}
    //
    pair<double, string>smallest;
    pair<double, string> largest;
    smallest = to_m(xvals[0]);
    largest = to_m(xvals[0]);
    pair<double, string> sum = {0.0, "m"};
    //
    for(int i = 0;i < xvals.size();++i) 
    {
        pair<double, string> xval_in_m = to_m(xvals[i]);
        sum.first+=xval_in_m.first;
        if(xval_in_m < smallest) smallest = xval_in_m;
        if(xval_in_m > largest) largest = xval_in_m;  
    } 
    //
    int count = xvals.size();
    //
    for(int i = 0;i < xvals.size();++i) 
    {
        bool valid = false;
        for(int j = 0;j < legal_values.size();++j)
        {
            if(xvals[i].second == legal_values[j]) {valid = true; break;}
        }
        if(!valid) error("Valid units are: m, cm, in, and ft.");          
    }
    cout<<"The smallest value is: "<<smallest.first<<smallest.second<<endl
        <<"The largest value is: "<<largest.first<<largest.second<<endl
        <<"The count of values is: "<<count<<endl
        <<"The sum of values is: "<<sum.first<<sum.second<<endl;
    
    cout<<endl<<"Thank you for using our program!";
}

Q9

pair<double, string>to_m(const pair<double, string> & xval)
{
    const double cm_in_m = 0.01, inch_in_m = 0.0254, ft_in_m = 0.3048;
    pair<double, string>result = xval;
    
    if(result.second == "cm") {result.first *= cm_in_m;}
    else if(result.second == "in") {result.first *= inch_in_m;}
    else if(result.second == "ft") {result.first *= ft_in_m;}
    else if(result.second == "m") {;}
    else error("The specified unit is not accepted. (Accepted units: cm, in, ft, m)");
    
    result.second = "m";
    return result;
}

int main()
{
    vector<pair<double, string>>xvals;
    double xval = 0.0;
    string unit = "";
    vector<string>legal_units = {"cm", "m", "in", "ft"};
    //
    while(cin>>xval>>unit && unit != "|") {xvals.push_back({xval, unit});}
    //
    pair<double, string>smallest = to_m(xvals[0]), largest = to_m(xvals[0]), sum = {0.0, "m"};
    int count = xvals.size();
    //
    for(int i = 0;i < xvals.size();++i) 
    {
        pair<double, string>xval_in_m = to_m(xvals[i]);
        sum.first+=xval_in_m.first;
        if(xval_in_m.first < smallest.first) smallest = xval_in_m;
        if(xval_in_m.first > largest.first) largest =xval_in_m;
    }
    //
    for(int i = 0;i < xvals.size();++i) 
    {
        bool valid = false;
        for(int j = 0;j < legal_units.size();++j) 
        {
            if(xvals[i].second == legal_units[j]) {valid = true; break;}
        }
        if(!valid) error("Accepted units are cm, m, in, and ft.");
    }

    cout<<"The smallest value is: "<<smallest.first<<smallest.second<<endl
        <<"The largest value is: "<<largest.first<<largest.second<<endl
        <<"The count of values is: "<<count<<endl
        <<"The sum of values is: "<<sum.first<<sum.second<<endl;

    cout<<endl<<"Thank you for using our program!";
}

Q10:

pair<double, string>to_m(const pair<double, string> & xval)
{
    const double cm_in_m = 0.01, inch_in_m = 0.0254, ft_in_m = 0.3048;
    pair<double, string>result = xval;
    
    if(result.second == "cm") {result.first *= cm_in_m;}
    else if(result.second == "in") {result.first *= inch_in_m;}
    else if(result.second == "ft") {result.first *= ft_in_m;}
    else if(result.second == "m") {}
    else error("The specified unit is not accepted. (Accepted units: cm, in, ft, m)");
    
    result.second = "m";
    return result;
}

int main()
{
    vector<pair<double, string>>xvals;
    double xval = 0.0;
    string unit = "";
    vector<string>legal_units = {"cm", "m", "in", "ft"};
    //
    while(cin>>xval>>unit && unit != "|") {xvals.push_back({xval, unit});}
    //
    pair<double, string>smallest = to_m(xvals[0]), largest = to_m(xvals[0]), sum = {0.0, "m"};
    int count = xvals.size();
    //
    for(int i = 0;i < xvals.size();++i) 
    {
        pair<double, string>xval_in_m = to_m(xvals[i]);
        sum.first+=xval_in_m.first;
        if(xval_in_m.first < smallest.first) smallest = xval_in_m;
        if(xval_in_m.first > largest.first) largest =xval_in_m;
    }
    //
    for(int i = 0;i < xvals.size();++i) 
    {
        bool valid = false;
        for(int j = 0;j < legal_units.size();++j) 
        {
            if(xvals[i].second == legal_units[j]) {valid = true; break;}
        }
        if(!valid) error("Accepted units are cm, m, in, and ft.");
    }

    cout<<"The smallest value is: "<<smallest.first<<smallest.second<<endl
        <<"The largest value is: "<<largest.first<<largest.second<<endl
        <<"The count of values is: "<<count<<endl
        <<"The sum of values is: "<<sum.first<<sum.second<<endl;

    cout<<endl<<"Thank you for using our program!";
}

Q10:

pair<double, string> dbl_to_m(const pair<double, string> & xval)
{
    const double cm_in_m = 0.01, inch_in_m = 0.0254, ft_in_m = 0.3048;
    pair<double, string>result = xval;
    
    if(result.second == "cm") {result.first *=cm_in_m;}
    else if(result.second == "in") {result.first *=inch_in_m;}
    else if(result.second == "ft") {result.first *=ft_in_m;}
    else if(result.second == "m") {;}
    else error("Invalid unit type. Accepted units are m, cm, ft, and in.");
    
    if (result.second != "m") result.second = "m";
    return result;
}

vector<pair<double, string>>vec_to_m(const vector<pair<double, string>> & xvals)
{
    const double cm_in_m = 0.01, inch_in_m = 0.0254, ft_in_m = 0.3048;
    vector<pair<double, string>>result = xvals;
    for(int i = 0;i<xvals.size();++i) 
    {
        if(xvals[i].second == "cm") {result[i].first *=cm_in_m;}
        else if(xvals[i].second == "in") {result[i].first *=inch_in_m;}
        else if(xvals[i].second == "ft") {result[i].first *=ft_in_m;}
        else if(xvals[i].second == "m") {;}
        else error("Invalid unit type. Accepted units are m, cm, ft, and in.");

        if(result[i].second != "m") {result[i].second = "m";};
    }   
    return result;
}

int main()
{
    vector<pair<double, string>>xvals;
    double xval = 0.0;
    string unit = "";
    //
    while(cin>>xval>>unit && unit != "|") {xvals.push_back({xval, unit});}
    //
    vector<pair<double, string>>converted;
    for(int i = 0; i < xvals.size();++i) 
    {
        vector<pair<double, string>>xvals_to_m;
        xvals_to_m = vec_to_m(xvals); 
        cout<<xvals_to_m[i].first<<xvals_to_m[i].second<<" ";
    }
}

Q11:

pair<double, string> dbl_to_m(const pair<double, string> & xval)
{
    const double cm_in_m = 0.01, inch_in_m = 0.0254, ft_in_m = 0.3048;
    pair<double, string>result = xval;
    
    if(result.second == "cm") {result.first *=cm_in_m;}
    else if(result.second == "in") {result.first *=inch_in_m;}
    else if(result.second == "ft") {result.first *=ft_in_m;}
    else if(result.second == "m") {;}
    else error("Invalid unit type. Accepted units are m, cm, ft, and in.");
    
    if (result.second != "m") result.second = "m";
    return result;
}

vector<pair<double, string>>vec_to_m(const vector<pair<double, string>> & xvals)
{
    const double cm_in_m = 0.01, inch_in_m = 0.0254, ft_in_m = 0.3048;
    vector<pair<double, string>>result = xvals;
    for(int i = 0;i<xvals.size();++i) 
    {
        if(xvals[i].second == "cm") {result[i].first *=cm_in_m;}
        else if(xvals[i].second == "in") {result[i].first *=inch_in_m;}
        else if(xvals[i].second == "ft") {result[i].first *=ft_in_m;}
        else if(xvals[i].second == "m") {;}
        else error("Invalid unit type. Accepted units are m, cm, ft, and in.");

        if(result[i].second != "m") {result[i].second = "m";};
    }   
    return result;
}

int main()
{
    vector<pair<double, string>>xvals;
    double xval = 0.0;
    string unit = "";
    vector<string>legal_units = {"cm", "m", "in", "ft"};
    //
    while(cin>>xval>>unit && unit != "|") {xvals.push_back({xval, unit});}
    //
    pair<double, string>smallest = dbl_to_m(xvals[0]), largest = dbl_to_m(xvals[0]), sum = {0.0, "m"};
    int count = xvals.size();
    //
    for(int i = 0;i < xvals.size();++i) 
    {
        pair<double, string>xval_in_m = dbl_to_m(xvals[i]);
        sum.first+=xval_in_m.first;
        if(xval_in_m.first < smallest.first) smallest = xval_in_m;
        if(xval_in_m.first > largest.first) largest = xval_in_m;
    }
    //
    vector<pair<double, string>>xvals_to_m;
    xvals_to_m = vec_to_m(xvals);
    sort(xvals_to_m.begin(), xvals_to_m.end(),
         [](const pair<double, string> & a, const pair<double, string> & b)
         {
            return a.first < b.first;
         });
    //
    for(int i = 0;i < xvals.size();++i) 
    {
        bool valid = false;
        for(int j = 0;j < legal_units.size();++j) 
        {
            if(xvals[i].second == legal_units[j]) {valid = true; break;}
        }
        if(!valid) error("Accepted units are cm, m, in, and ft.");
    }

    cout<<"The smallest value is: "<<smallest.first<<smallest.second<<endl
        <<"The largest value is: "<<largest.first<<largest.second<<endl
        <<"The count of values is: "<<count<<endl
        <<"The sum of values is: "<<sum.first<<sum.second<<endl;
    cout<<"The full length vector: ";
    for(int i = 0;i < xvals_to_m.size();++i) {cout<<xvals_to_m[i].first<<xvals_to_m[i].second<<" ";}
    cout<<endl;
    cout<<endl<<"Thank you for using our program!";
}

Drill Take 2

Q1:

int main()
{
    vector<int>xvals;
    int xval = 0;
    string input = "";
    while(cin>>input) {if(input == "|") break;xvals.push_back(stoi(input));}
    //
    int i = 0;
    while(i + 1 < xvals.size()) 
    {
        cout<<xvals[i]<<" "<<xvals[i+1]<<endl;
        i+=2;                    
    }
    //
    if(i < xvals.size()) {cout<<"The value without a pair is: "<<xvals[i];};
}

Q2-3:

int main ()
{
    vector<int>xvals;
    int xval = 0;
    string input = "";
    while(cin>>input) {if(input == "|") break;xvals.push_back(stoi(input));}
    //
    int i = 0;
    int smallest = 0, largest = 0;
    while(i + 1 < xvals.size()) 
    {
        if(xvals[i] < xvals[i+1]) {smallest = xvals[i];largest = xvals[i+1];cout<<"The smaller value is: "<<smallest<<" "<<"The largest value is: "<<largest<<endl;}
        else if(xvals[i] > xvals[i+1]) {smallest = xvals[i+1];largest = xvals[i];cout<<"The smaller value is: "<<smallest<<" "<<"The largest value is: "<<largest<<endl;}
        else {cout<<"The values are equal."<<endl;};
        i+=2;
    }
    if(i < xvals.size()) {cout<<"The value without a pair is: "<<xvals[i];}
}

Q4-5: 

int main()
{
    vector<double>xvals;
    string input = "";
    cout<<"Enter any number of floating-point values: ";
    while(cin>>input) {if(input == "|") break; xvals.push_back(stod(input));} // this is not necessary but its just practice
    //
    double threshold = 1.0/10000000;
    int i = 0;
    double smallest = 0.0, largest = 0.0;
    while(i + 1 < xvals.size()) 
    {
        if(xvals[i] < xvals[i+1]) {smallest = xvals[i];largest = xvals[i+1];cout<<"The smaller value is: "<<smallest<<" "<<"The larger value is: "<<largest;if(largest - smallest < threshold) cout<<" The numbers are almost equal";cout<<endl;}
        else if(xvals[i+1] < xvals[i]) {smallest = xvals[i+1];largest = xvals[i];cout<<"The smaller value is: "<<smallest<<" "<<"The larger value is: "<<largest;if(largest - smallest < threshold) cout<<" The numbers are almost equal";cout<<endl;}
        else{cout<<"The values are equal."<<endl;};
        i+=2;
    }
    if(i < xvals.size()) {cout<<"The value without a pair is: "<<xvals[i]<<endl;}
    cout<<endl<<"Thank you for using our program!";
}

Q6:
int main()
{
    vector<double>xvals;
    string input = "";
    cout<<"Enter any number of floating-point values: ";
    while(cin>>input) {if(input == "|") break; xvals.push_back(stod(input));}
    //
    double smallest = xvals[0], largest = xvals[0];
    int i = 0;
    while(i < xvals.size()) 
    {
        if(i == 0) {cout<<xvals[i]<<" The initial value.";}
        else if(xvals[i] < smallest) {smallest = xvals[i];cout<<smallest<< " smallest so far";}
        else if(xvals[i] > largest) {largest = xvals[i];cout<<largest<<" largest so far";}
        else {cout<<xvals[i];};
        cout<<endl;
        ++i;
    }
}

Q7-10:

pair<double, string>dbl_to_m(const pair<double, string> & xval) 
{
    const double cm_to_m = 0.01, in_to_m = 0.0254, ft_to_m = 0.3048;
    pair<double, string> result = {0.0, ""};result = xval;
    //
    if(result.second == "cm") {result.first *=cm_to_m;}
    else if(result.second == "in") {result.first *=in_to_m;}
    else if(result.second == "ft") {result.first *=ft_to_m;}
    else if(result.second == "m") {}
    else {error("The accepted inputs are: cm, m, in, and ft.");};

    if(result.second != "m") result.second = "m";
    return result;
}


int main()
{
    vector<pair<double, string>>xvals;
    double xval = 0.0;
    string unit = "";
    while(cin>>xval>>unit && unit != "|") {xvals.push_back({xval, unit});}
    //
    int count = xvals.size();
    pair<double, string> largest = xvals[0], smallest = xvals[0], sum = {0.0, ""};
    vector<pair<double, string>>vec_m;
    for(int i = 0; i < xvals.size();++i) 
    {
        pair<double, string>xval_to_m = dbl_to_m(xvals[i]);
        if(xval_to_m.first < smallest.first) {smallest = xval_to_m;}
        if(xval_to_m.first > largest.first) {largest = xval_to_m;};
        sum.first+=xval_to_m.first; sum.second = "m";
        vec_m.push_back(xval_to_m);
    }
    //
    sort(vec_m.begin(), vec_m.end(),
    [](const pair<double, string> & a, const pair<double, string> & b)
        {
            return a.first < b.first;
        });
    //
    cout<<"The smallest value is: "<<smallest.first<<smallest.second<<endl
    <<"The largest value is: "<<largest.first<<largest.second<<endl
    <<"The sum is: "<<sum.first<<sum.second<<endl
    <<"The count is: "<<count<<endl;
    for(int i = 0;i < vec_m.size();++i) {cout<<vec_m[i].first<<vec_m[i].second<<" ";}
}

*/

#include "std_lib_facilities.h"
/* Exercise 2:

// This program is used to convert miles to kilometers for the user.
int main() {
    double miles = 0; // Definition and initialization of an object (now variable) of type facility int
    double kilometers = 0; // Definition of a variable for kilometers
    double conv = 1.609; // How many km in miles
    cout<<"Enter the number of miles you would like to convert to kilometers:\n";
    cin>>miles;
    kilometers = miles * conv;
    cout<<"There are "<<kilometers<<" in "<<miles<<".\n";

    keep_window_open();
    return(0);
}

Exercise 3: 
int main() 
{
    int short = 0;
    int _foo = 0
}

Exercise 4:
int main()
{
    int val1 = 0; // Define and initialize val1 variable of type int facilitator
    int val2 = 0; // Define and initialize val2 variable of type int facilitator
    int smallest = 0;
    int largest = 0;
    int sum_val = 0;
    int diff_val = 0;
    int product = 0;
    double ratio_val = 0.0;
    cout<<"Enter two integer values:\n";
    cin>>val1>>val2;
    if(val1 == val2)error("Values must be different");
    if(val1 > val2)smallest = val2; else smallest = val1;
    if(val1 > val2)largest = val1; else largest = val2;
    sum_val = val1 + val2;
    diff_val = largest - smallest;
    product = val1 * val2;
    ratio_val = double(largest) / double(smallest);
    cout<<"Please find the summary of the relation between the two numbers:\n\n"
        <<"Smaller: "<<smallest<<'\n'
        <<"Larger: "<<largest<<'\n'
        <<"Sum: "<<sum_val<<'\n'
        <<"Difference: "<<diff_val<<'\n'
        <<"Product: "<<product<<'\n';
    if (smallest == 0)cout<<"Ratio: undefined (division by zero)\n"; else cout<<"Ratio: "<<ratio_val<<"\n\n";
        
    cout<<"Thank you for using the program! Ciao.\n";

    keep_window_open();
    return(0);
}

Exercise 5:

int main()
{
    double val1 = 0.0; // Define and initialize val1 variable of type double facilitator
    double val2 = 0.0; // Define and initialize val2 variable of type double facilitator
    double smallest = 0;
    double largest = 0;
    double sum_val = 0;
    double diff_val = 0;
    double product = 0;
    double ratio_val = 0.0;
    cout<<"Enter two floating-point values:\n";
    cin>>val1>>val2;
    if(val1 == val2)error("Values must be different"); // Optional
    if(val1 > val2)smallest = val2; else smallest = val1;
    if(val1 > val2)largest = val1; else largest = val2;
    sum_val = val1 + val2;
    diff_val = largest - smallest;
    product = val1 * val2;
    ratio_val = largest / smallest;
    cout<<"Please find the summary of the relation between the two numbers:\n\n"
        <<"Smaller: "<<smallest<<'\n'
        <<"Larger: "<<largest<<'\n'
        <<"Sum: "<<sum_val<<'\n'
        <<"Difference: "<<diff_val<<'\n'
        <<"Product: "<<product<<'\n';
    if (smallest == 0)cout<<"Ratio: undefined (division by zero)\n"; else cout<<"Ratio: "<<ratio_val<<"\n\n";
        
    cout<<"Thank you for using the program!\n";

    keep_window_open();
    return(0);
}

Exercise 6:

int main()
{
    int val1 = 0;
    int val2 = 0;
    int val3 = 0;
    int first = 0;
    int second = 0;
    int third = 0;
    cout<<"Enter 3 integers:";
    cin>>val1>>val2>>val3;
    if(val1 < val2 && val1 < val3) first = val1; if(val2 < val1 && val2 < val3) first = val2; if(val3 < val1 && val3 < val2) first = val3; // First (Smallest)
    if(val1 > val2 && val1 > val3) third = val1; if(val2 > val1 && val2 > val3) third = val2; if(val3 > val1 && val3 > val2) third = val3; // Third (Largest) 
    if(val1 > val2 && val1 < val3) second = val1; if(val1 < val2 && val1 > val3) second = val1; // Second, val1
    if(val2 > val1 && val2 < val3) second = val2; if(val2 < val1 && val2 > val3) second = val2; // Second, val2
    if(val3 > val1 && val3 < val2) second = val3; if(val3 < val1 && val3 > val2) second = val3; // Second, val3
    if(val1 == val2 && val1 > val3) {second = val1; third = val2;}; if(val1 == val3 && val1 > val2) {second = val1; third = val3;}; // Equal order, val1  
    if(val2 == val1 && val2 > val3) {second = val2; third = val1;}; if(val2 == val3 && val2 > val1) {second = val2; third = val3;}; // Equal order, val2
    if(val3 == val1 && val3 > val2) {second = val3; third = val1;}; if(val3 == val2 && val3 > val1) {second = val3; third = val2;}; // Equal order, val3
    if(val1 == val2 && val2 == val3) first = second = third = val1; // If all are equal
    cout<<"Please find the sequence of integers: \n\n"
        <<first<<", "<<second<<", "<<third<<'.'<<"\n\n";
    cout<<"Thank you for using the program!\n";

    keep_window_open();
    return(0);
}

Exercise 6: Simpler method

int main()
{
    int val1 = 0;
    int val2 = 0;
    int val3 = 0;
    cout<<"Enter any three integers:";
    cin>>val1>>val2>>val3;
    // Define ordered pairs
    int smallest = val1;
    int middle = val2;
    int largest = val3;
    // Smallest
    if(val2 < smallest) val2 = smallest;
    if(val3 < smallest) val3 = smallest;
    // Largest
    if(val1 > largest) val1 = largest;
    if(val2 > largest) val2 = largest;
    // Middle
    if((val1 != smallest) && (val1 != largest)) val1 = middle;
    else if ((val2 != smallest) && (val2 != largest)) val2 = middle;
    else val3 = middle; // Handles repeating values
    // Output
    cout<<"Please find the ordered numbers:\n"
        <<smallest<<", "<<middle<<", "<<largest<<".\n";
    cout<<"Thank you for using the program!";

    keep_window_open();
    return(0);
}

Exercise 7

int main()
{
    string surname_1 = " "; // we initialize and define a new variable called surname_1 (1-first in the order)
    string surname_2 = " "; // second variable
    string surname_3 = " "; // third variable
    string first = " ";
    string second = " ";
    string third = " "; 
    cout<<"Enter three surnames:\n";
    cin>>surname_1>>surname_2>>surname_3;
    // Third
    if(surname_1 > surname_2 && surname_1 > surname_3) third = surname_1; if(surname_2 > surname_1 && surname_2 > surname_3) third = surname_2; if(surname_3 > surname_1 && surname_3 > surname_2) third = surname_3;
    // Second
    if(surname_1 > surname_2 && surname_1 < surname_3) second = surname_1; if(surname_1 < surname_2 && surname_1 > surname_3) second = surname_1;
    if(surname_2 > surname_1 && surname_2 < surname_3) second = surname_2; if(surname_2 < surname_1 && surname_2 > surname_3) second = surname_2;
    if(surname_3 > surname_1 && surname_3 < surname_2) second = surname_3; if(surname_3 < surname_1 && surname_3 > surname_2) second = surname_3;
    // First
    if(surname_1 < surname_2 && surname_1 < surname_3) first = surname_1; if(surname_2 < surname_1 && surname_2 < surname_3) first = surname_2; if(surname_3 < surname_1 && surname_3 < surname_2) first = surname_3;
    // Ordered
    if(surname_1 == surname_2 && surname_1 > surname_3) {first = surname_1; second = surname_2; third = surname_3;};
    if(surname_1 == surname_3 && surname_1 > surname_2) {first = surname_1; second = surname_3; third = surname_2;};
    if(surname_2 == surname_3 && surname_2 > surname_1) {first = surname_2; second = surname_3; third = surname_1;};
    // All equal
    if(surname_1 == surname_2 && surname_2 == surname_3) first = second = third = surname_1;
    cout<<"Please find the names in order:\n\n";
    cout<<"Longest: "<<first<<", "<<second<<", "<<third<<".\n";
    cout<<"Thank you for using the program!\n";
}

Exercise 7: Simpler way

int main()
{
    // Defining and initializing char strings for surnames
    string surname_1 = " ";
    string surname_2 = " ";
    string surname_3 = " ";
    // Reading the input and assigning to defined variables of type string
    cout<<"Enter three surnames:\n";
    cin>>surname_1>>surname_2>>surname_3;
    // Ordered pairs
    string smallest = surname_1;
    string middle = surname_2;
    string largest = surname_3;
    // Smallest
    if(surname_2 < smallest) surname_2 = smallest;
    if(surname_3 < smallest) surname_3 = smallest;
    // Largest
    if(surname_1 > largest) surname_1 = largest;
    if(surname_2 > largest) surname_2 = largest;
    // Middle
    if(surname_1 != smallest && surname_1 != largest) surname_1 = middle;
    else if (surname_2 != smallest && surname_2 != largest) surname_2 = middle;
    else middle = surname_3; // In case multiple are the same
    cout<<"Ordered words (Ascending):\n\n";
    cout<<smallest<<", "<<middle<<", "<<largest<<".\n\n";
    cout<<"Thank you for using the program!\n\n";
    
    keep_window_open();
    return(0);
}

Exercise 8:

int main()
{
    int val = 0;
    cout<<"Enter any integer value:";
    cin>>val;
    // Integer
    int even_val = 0; // even = 0
    int odd_val = 1; // odd = 1
    // Strings
    string even_string = "even";
    string odd_string = "odd";
    // Remainder - classification between even odd
    if(val % 2 == 0) {
        cout<<"The value "<<val<<" is an "<<even_string<<" number.\n\n";
    };
    if(val % 2 != 0) {
        cout<<"The value "<<val<<" is an "<<odd_string<<" number.\n\n";   
    };
    cout<<"Thank you for using the program!\n";

    keep_window_open();
    return(0);
}

int main()
 {
    string number = " "; // Variable of type string
    cout<<"Enter an integer from 0-4 in string form: ";
    cin>>number;
    int zero = 0; int one = 1; int two = 2; int three = 3; int four = 4; // Integers
    if(number == "zero") 
        cout<<zero<<"\n";
    else if(number == "one")
        cout<<one<<"\n";
    else if(number == "two")
        cout<<two<<"\n";
    else if(number == "three")
        cout<<three<<"\n";
    else if(number == "four")
        cout<<four<<"\n";
    else cout<<("not a number I know\n\n");
    cout<<"Thank you for using the program!\n\n";
    keep_window_open();
    return 0;
}

Exercise 10

int main()
{
    double val1 = 0;
    double val2 = 0;
    string operation = " ";
    // Statements
    cout<<"Please input two operands and the operation you would like the program to outline: \n";
    cin>>val1>>val2>>operation;
        if(operation == "+") {
            int x = val1;
            int y = val2;
            int result = x + y;
            cout<<"Operation: "<<x<<' '<<operation<<' '<<y<<'\n'<<"Result: "<<result<<"\n\n";
        }
        else if(operation == "-") {
            int x = val1;
            int y = val2;
            int result = x - y;
            cout<<"Operation: "<<x<<' '<<operation<<' '<<y<<'\n'<<"Result: "<<result<<"\n\n";
        }
        else if(operation == "*") {
            double x = val1;
            double y = val2;
            double result = x * y;
            cout<<"Operation: "<<x<<' '<<operation<<' '<<y<<'\n'<<"Result: "<<result<<"\n\n";
        }
        else if (operation == "/") {
            double x = val1;
            double y = val2;
            double result = x / y;
            cout<<"Operation: "<<x<<' '<<operation<<' '<<y<<'\n'<<"Result: "<<result<<"\n\n";
        };
    cout<<"Thank you for using the program!\n\n";

    keep_window_open();
    return(0);
}


Exercise 11

int main()
{
    // Whole values
    int pennies = 0; // 1 penny = 1 cents
    int nickels = 0; // 1 nickel = 5 cents 
    int dimes = 0; // 1 dime = 10 cents
    int quarters = 0; // 1 quarter = 25 cents
    int half_dollar = 0; // 1 half_dollar = 50 cents
    int dollar = 0; // 1 dollar = 100 cents
    int total_cents = 0; // the total cent amount
    int total_dollars = 0; // the total amount in dollars
    // Coins to cents
    int pennies_to_cents = 0;
    int nickels_to_cents = 0;
    int dimes_to_cents = 0;
    int quarters_to_cents = 0;
    int half_dollar_to_cents = 0;
    int dollar_to_cents = 0;
    // Input
    cout<<"How many pennies have you got?\n";cin>>pennies;
    cout<<"How many nickels have you got?\n";cin>>nickels;
    cout<<"How many dimes have you got?\n";cin>>dimes;
    cout<<"How many quarters have you got?\n";cin>>quarters;
    cout<<"How many half_dollar have you got?\n";cin>>half_dollar;
    cout<<"How many dollar have you got?\n";cin>>dollar;
    // Whole coints to cents or the cent value per coin type
     pennies_to_cents = 1 * pennies; // 1:1 ratio
     nickels_to_cents = 5 * nickels; // 5:1 ratio
     dimes_to_cents = 10 * dimes; // 10:1 ratio
     quarters_to_cents = 25 * quarters; // 25:1 ratio
     half_dollar_to_cents = 50 * half_dollar; // 50:1 ratio
     dollar_to_cents = 100 * dollar; // 100:1 ratio
    // Total cents & dollars
    total_cents = pennies_to_cents + nickels_to_cents + dimes_to_cents + quarters_to_cents + half_dollar_to_cents + dollar_to_cents;
    total_dollars = total_cents / 100; // 100:1 ratio
    // Output
    if(pennies == 1) cout<<"You have "<<pennies<<" penny"<<".\n\n"; else cout<<"You have "<<pennies<<" pennies"<<".\n\n";
    if(nickels == 1) cout<<"You have "<<nickels<<" nickel"<<".\n\n"; else cout<<"You have "<<nickels<<" nickels"<<".\n\n";
    if(dimes == 1) cout<<"You have "<<dimes<<" dime"<<".\n\n"; else cout<<"You have "<<dimes<<" dimes"<<".\n\n";    
    if(quarters == 1) cout<<"You have "<<quarters<<" quarter"<<".\n\n"; else cout<<"You have "<<quarters<<" quarters"<<".\n\n";
    if(half_dollar == 1) cout<<"You have "<<half_dollar<<" half dollar"<<".\n\n"; else cout<<"You have "<<half_dollar<<" half dollars"<<".\n\n";
    if(dollar == 1) cout<<"You have "<<dollar<<" dollar"<<".\n\n"; else cout<<"You have "<<dollar<<" dollars"<<".\n\n";
    if(total_cents == 1) cout<<"The value of all your coins is "<<total_cents<<" cent"<<".\n\n"; else cout<<"The value of all your coins is "<<total_cents<<" cents"<<".\n\n";
    if(total_dollars == 1) cout<<"The value of all your coins is "<<"$"<<total_dollars<<" dollar"<<".\n\n"; else cout<<"The value of all your coins is "<<"$"<<total_dollars<<" dollars"<<".\n\n"; 
    cout<<"Thank you for using our program!\n\n";

    keep_window_open();
    return(0);
}

Exercise 8: Redo

int main()
{
    int val = 0; // Variable of type int
    int result = 0;
    // Even
    cout<<"Enter any integer: ";
    cin>>val;
    result = val % 2;
    if(result == 0) cout<<"even"; else cout<<"odd";
}

Exercise 9: Redo
*/

int main()
{
    string number = " "; // Variable of type string for the number value
    cout<<"Enter an integer from 0-4 in string format: ";
    cin>>number;
    // String to integer (we want integer placeholders since the questions asks for digit value)
    int zero = 0; int one = 1; int two = 2; int three = 3; int four = 4;
    if(number == "zero") {
        zero;
        cout<<"The integer form: "<<zero<<".\n\n";
    }
    else if(number == "one") {
        one;
        cout<<"The integer form: "<<one<<".\n\n";
    }
    else if(number == "two") {
        two;
        cout<<"The integer form: "<<two<<".\n\n";
    }
    else if(number == "three") {
        three;
        cout<<"The integer form: "<<three<<".\n\n";
    }
    else if(number == "four") {
        four;
        cout<<"The integer form: "<<four<<".\n\n";
    }
    else cout<<"not a number I know.\n\n";

    cout<<"Thank you for using our program!\n\n";

    keep_window_open();
    return(0);
}

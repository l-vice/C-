#include "std_lib_facilities.h"

/*
Q1:

TRY THIS 1:

int main()
{
    int s3 = area(7);    
}

TRY THIS 2:

int area(const int& length, const int& width)
{
    if(length <= 0 || width <= 0) 
        throw invalid_argument("Invalid input parameters. The result is a non-positive area. Lenght or Width are equal to or less than 0.");
    return length*width;
}

const int frame_width = 2;
int framed_area(const int& length, const int& width)
{
    if(length - frame_width <= 0 || width - frame_width <= 0) 
        throw invalid_argument("Invalid input parameters. The result is a non-positive area. Lenght or Width are equal to or less than 0.");
    return area(length-frame_width,width-frame_width);
}

int main()
{
    int x = 3, y = 40, z = -3;
    //
    int area1 = area(x, y);
    int area2 = framed_area(7, z);
    int area3 = framed_area(y, z);
    double ratio = double(area1)/area3;
    //
    cout<<area1<<endl
        <<area2<<endl
        <<area3<<endl
        <<fixed<<setprecision(3)<<ratio;
}

TRY THIS 3:

bool is_int(const string& x)
{
    for(char c : x)
        if(isdigit(c))
            return true;
    return false;
}

TRY THIS 4:

class Surreal_temp{};

const double highest_recorded_temp_F = 134.0;
const double lowest_recorded_temp_F = -128.6; 

int main()
{
    vector<double>temps;
    double temp, sum = 0.0;
    double highest_temp = highest_recorded_temp_F;
    double lowest_temp = lowest_recorded_temp_F;
    //
    cout<<"Enter recorded temperatures in F: "<<endl;
    try 
    {
        while(cin>>temp)
            temps.push_back(temp);
        
        for(size_t i = 0; i < temps.size();++i) if(temps[i] > highest_recorded_temp_F || temps[i] < lowest_recorded_temp_F) throw Surreal_temp();
        highest_temp = temps[0];lowest_temp = temps[0];
        for(size_t i = 0;i < temps.size();++i)
        {
            if(temps[i] > highest_temp) highest_temp = temps[i];
            if(temps[i] < lowest_temp) lowest_temp = temps[i];
            sum+=temps[i];
        }
        
        cout<<"Highest Temperature: "<<highest_temp<<endl
            <<"Lowest Temperature: "<<lowest_temp<<endl
            <<"Average Temperature: "<<sum/temps.size()<<endl;
    }
    catch(exception& e)
    {
        cerr<<"error: "<<e.what()<<endl;
        keep_window_open();
        return 1;
    }
    catch(Surreal_temp) 
    {
        cout<<"The input value for temperature was not yet recorded on earth! If otherwise, please update the program."<<endl;
        keep_window_open(); // check why this does not function as intended.
        return 2;
    }
    catch(...)
    {
        cerr<<"Unknown exception!"<<endl;
        keep_window_open();
        return 3;
    }
}

TRY THIS 5:

double hexagon_area(const double& s)
{ // use: calculate the area of a hexagon
  // pre-condition/s: side must be positive (s>0)
  // post-condition: returns a positive value that is the are of a hexagon 
    if(s <= 0) throw invalid_argument("non-positive side.")
    double result = ((3 * sqrt(3))/2)*(s*s);

    return result;
}

int main()
{
    double s = 0.0;
    double A;
    cout<<"Enter the side of a hexagon: "<<endl;
    cin>>s;
    A = hexagon_area(s);
    cout<<fixed<<setprecision(2)<<A<<"cm"endl;
}


int main()
{
    // SPEED IN MPH
    const double driving_dist_NYC_DEN = 1778.0; // MPH
    const double est_driving_time_NYC_DEN_hrs = 25.10; // 25 hours and 6 minutes
    double avg_driving_speed_NYC_DEN = driving_dist_NYC_DEN/est_driving_time_NYC_DEN_hrs;
    // DISTANCE
    const double flying_dist_NYC_DEN = 1631.0;
    const double est_flying_time_NYC_DEN_hrs = 3.75; // 3 hours and 45 minutes
    double avg_flying_speed_NYC_DEN = flying_dist_NYC_DEN/est_flying_time_NYC_DEN_hrs; 
    // COUT
    cout<<"The average driving speed | NYC - DEN: "<<fixed<<setprecision(2)<<avg_driving_speed_NYC_DEN<<"mph"<<endl
        <<"The average flying speed | NYC - DEN: "<<avg_flying_speed_NYC_DEN<<"mph"<<endl;
}

TRY THIS 6:

int my_complicated_function(int a, int b, int c)
{
    //the arguments must be positive and a < b < c; -- STATE IN THE COMMENT WHAT THE FUNCTION REQUIRES OF ITS ARGUMENTS.
    if(!(0<a && a<b && b<c))
        error("bad arguments for mfc");
}

Q2:

double c_to_k(double c)
{// Use: Convert celsius into kelvin
 // pre-condition: None known so far other than that the input must be a double etc...
 // post-condition: Returns a temperature in kelvin in double format
    double k = c + 273.15;
    return k;
}

int main()
{
    double c = 0.0; //declare input variable
    cout<<"Enter the temperature in Celsius that you would like to convert to Kelvin: "<<endl;
    cin>>c; // retrive temperature to input variable
    double k = c_to_k(c); //convert temperature
    cout<<k<<" "<<endl; //print out temperature
}
// Errors:
//  1. int k must be double since the function returns a double type object
//  2. return int should be return k (double k)  
//  3. cin>>d; Should be cin>>c; since that is our input variable (defined in the previous line as c);
//  4. ctok("c") fn argument; Bad argument. We are adding a char type object into a function that requires a double type object
//  5. Cout<<k; We can borrow this one from the compiler himself: Stating that identifier "Cout" is undefined. We need "cout" which is a proper definition.
//  6. (Optional improvement) Initialize c to 0.0 instead of 0.

Q3:

class Bad_argument{};
const double abs_zero_temp_C = -273.15; //Lowest poss. temp in Celsius

double c_to_k(const double& c)
{
    double k = c + 273.15;
    return k;
}

int main()
{
    try
    {
        double c = 0.0;
        cout<<"Enter the temperature in Celsius that you would like to convert to Kelvin: "<<endl;
        cin>>c;
        if(c < abs_zero_temp_C)
            throw Bad_argument();
        double k = c_to_k(c);
        cout<<k<<" "<<endl;
    }
    catch(Bad_argument)
    {
        cerr<<"The input variable value is below absolute zero!"<<endl;
        keep_window_open();
        return 1;
    }
}

Q4:

const double abs_zero_temp_C = -273.15; //Lowest poss. temp in Celsius

double c_to_k(const double& c)
{
    if(c < abs_zero_temp_C)
        throw invalid_argument("The function arg value is below absolute zero!");
    double k = c + 273.15;
    return k;
}

int main()
{
    double c = 0.0;
    cout<<"Enter the temperature in Celsius that you would like to convert to Kelvin: "<<endl;
    cin>>c;
    double k = c_to_k(c);
    cout<<k<<" "<<endl;
}

Q5:

// Celsius = k - 273.15
const double abs_zero_temp_C = -273.15; //Lowest poss. temp in Celsius
const double abs_zero_temp_K = -546.3;

double c_to_k(const double& c)
{// Use: This program converts C to K;
 // Pre-condition: We must make sure that the program has double type objects as input args
 // Post-condition: Returns a value in Kelvin   
    if(c < abs_zero_temp_C)
        throw invalid_argument("The function arg value is below absolute zero!");
    double k = c + 273.15;
    return k;
}

double k_to_c(const double& k)
{
    if(k < abs_zero_temp_K)
        throw invalid_argument("The function arg value is below absolute zero!");
    double c = k - 273.15;
    return c; 
}

int main()
{
    pair<double, char>temp;
    //
    double k = 0.0, c = 0.0;
    cout<<"Enter the temp value followed by a unit in either Celsius or Kelvin (ex. 110 K): "<<endl;
    cin>>temp.first>>temp.second;
    temp.second = tolower(temp.second);
    switch(temp.second) 
    {
        case 'c':
            k = temp.first + 273.15;
            cout<<"The temperature in Kelvin is: "<<k<<endl;
            break;
        case 'k':
            c = temp.first - 273.15;
            cout<<"The temperature in Celsius is: "<<c<<endl;
            break;
    }
}

Q6:

// Celsius to deg. fahrenheit f = 9/5 * c + 32
// Fahrenheit to deg. celsius c = (f - 32) * 5/9
const double abs_zero_temp_C = -273.15;
const double abs_zero_temp_F = -459.67;

double c_to_f(const double& c)
{ // Use: This function converts celsius into fahrenheit.
  // Pre-condition: We must ensure that the minimum temp is not less than abs zero in Celsius and that inputs are objects of type double.
  // Post-condition: We recieve the temperature in degrees Fahreneheit.
    if(c < abs_zero_temp_C)
        throw invalid_argument("Input value for temp is below absolute zero!");
    double f = (c * 9/5) + 32;
    return f;
}

double f_to_c(const double& f)
{ // Use: This function converts fahreneheit into deg celsius.
  // Pre-condition: We must ensure that the temp is not below abs zero in deg fahrenheit and that input objects are of type double
  // Post-condition: We receive the value for temperature in degrees Celsius
    if(f < abs_zero_temp_F)
        throw invalid_argument("Input value for temp is below absolute zero!");
    double c = (f - 32) * 5/9;
    return c;   
}

int main()
{
    pair<double, char>temp;
    double c = 0.0, f = 0.0;
    //
    cout<<"Enter the temperature you'd like to convert in F or C (ex. 110 F): "<<endl;
    cin>>temp.first>>temp.second;
    temp.second = tolower(temp.second);
    //
    switch(temp.second)
    {
        case 'c':
            f = c_to_f(temp.first);
            cout<<"The temperature in degrees fahrenheit is: "<<f<<endl;
            break;
        case 'f':
            c = f_to_c(temp.first);
            cout<<"The temperature in degrees celsius is: "<<c<<endl;
            break;
    }
}

Q7:

// Quadratic equation form: ax^2 + bx + c = 0;

pair<double, double> quad_form(const double& a, const double& b, const double& c)
{// Use: This program returns the roots of a quadratic function using the quadratic formula.
 // Pre-conditions: We need to make sure that we have all the requirements (a, b, c as double type objects). And that the discriminant is not zero and a =! 0.
 // Post-condition: Returns the values of x1 and x2 which are the quadratic roots provided that the discriminant is not zero!
    if(a == 0) 
        throw domain_error("a  0. You don't need a quadratic formula.");
    double disc = (b*b) - 4*(a*c);
    if(disc < 0)
         throw domain_error("DISC < 0");
    double x1 = (-b + sqrt(disc))/(2*a);
    double x2 = (-b - sqrt(disc))/(2*a);
    //
    return {x1, x2};
}
int main()
{
    try
    {
        double a = 0.0, b = 0.0, c = 0.0;
        cout<<"Enter the quadratic constants: "<<endl;
        while(cin>>a>>b>>c) 
        {
            pair<double, double>quadr_result = quad_form(a, b, c);
            cout<<quadr_result.first<<" "<<quadr_result.second<<endl;
            cout<<"Enter another (or CTRL+Z to exit): "<<endl;
        }   
    }
    catch(exception& e)
    {
        cerr<<"error: "<<e.what()<<endl;
        keep_window_open();
        return 1;
    }
}

// Testing a = 2, b = 0, c = -3, by using estimation we get the correct x1, x2 vals. The catch(exception) works correctly as well.

Q8:

int summation(const int& sum_count, vector<int>& xvals)
{ // Use: Sums the value up to the nth int (sum_count)
  // Pre-condition: sum count must be < xvals.size()
  // Post-condition: Return the sum for the N (sum_count) specified values 
    if(sum_count > xvals.size())
        throw range_error("The search size is larger than the vector size.");
    int result = 0;
    for(size_t i = 0;i < sum_count;++i)
        result += xvals[i];
    return result;
}

int main()
{
    try
    {
        vector<int>xvals;
        int xval = 0, sum_count = 0, sum = 0;
        cout<<"Please enter some numbers (press '|' to stop): "<<endl;
        while(cin>>xval)
            xvals.push_back(xval);
        //
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"Please enter how many of the numbers you wish to sum, starting from the first: "<<endl;
        cin>>sum_count;
        sum = summation(sum_count, xvals);
        cout<<"The sum of the first "<<sum_count<<" numbers: ";for(size_t i = 0;i < sum_count-1;++i) cout<<xvals[i]<<", ";cout<<"and "<<xvals[sum_count-1];cout<<" is "<<sum;   
        //
        return 0;
    }
    catch(exception& e)
    {
        cerr<<"error: "<<e.what()<<endl;
        keep_window_open();
        return(1);
    }
    catch(...)
    {
        cerr<<"Program failed. Unknown errror!"<<endl;
        keep_window_open();
        return(2);
    }
}

Q9:

int summation(const int& sum_count, const vector<int>& xvals)
{
    int result = 0;
    if(sum_count > xvals.size())
        throw range_error("[std::range_error]: The sum count value is larger than the vector size.");
    for(size_t i = 0;i < sum_count;++i)
    {
        if(xvals[i] > 0 && result > INT_MAX - xvals[i])
            throw std::overflow_error("[std::overflow_error]: The result cannot be represented as an int.");
        if(xvals[i] < 0 && result < INT_MIN - xvals[i])
            throw std::overflow_error("[std::underflow_error]: The result cannot be represented as an int.");
        result+=xvals[i];    
    }
        
    return result;
}

void print(const int& sum,const int& sum_count, const vector<int>& xvals)
{
    cout<<"The sum of the first "<<sum_count<<" numbers: ";
    for(size_t i = 0;i < sum_count-1;++i) 
        cout<<xvals[i]<<", ";
    
    cout<<"and "<<xvals[sum_count-1]<<" is "<<sum<<endl; 
}

void main_program()
{
    vector<int>xvals;
    int xval, sum_count = 0,sum = 0;
    cout<<"Please enter some numbers (press '|' at prompt to stop):"<<endl;
    while(cin>>xval)
        xvals.push_back(xval);
    // 
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //
    cout<<"Please enter how many of the numbers you wish to sum, starting from the first: "<<endl;
    while(cin>>sum_count)
    {
        sum = summation(sum_count, xvals);
        print(sum, sum_count, xvals);
        cout<<"Enter another (or CTRL+Z to exit): "<<endl;
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

Q10:

double summation(const int& sum_count, const vector<double>& xvals)
{
    double result = 0;
    if(sum_count > xvals.size())
        throw std::range_error("[std::range_error]: The requested sum count value is larger than the vector size.");
    for(size_t i = 0;i < sum_count;++i)
    {
        if(xvals[i] > 0 && result > numeric_limits<double>::max() - xvals[i])
            throw std::overflow_error("[std::overflow_error]: The result cannot be expressed as a double.");
        if(xvals[i] < 0 && result < numeric_limits<double>::min() - xvals[i])
            throw std::underflow_error("[std::underflow_error]: The result cannot be expressed as a double.");
        result+=xvals[i]; 
    }
    return result;
}

vector<double>adj_diff(const vector<double>& xvals)
{
    if(xvals.size() < 2)
        throw std::range_error("[std::range_error]: The vector size is less than 2. Adjecent difference between vector values cannot be computed.");
    vector<double>yvals;
    int yvals_size = xvals.size()-1;
    for(size_t i = 0;i < yvals_size;++i)
    {
        yvals.push_back(xvals[i] - xvals[i+1]);
    }
    return yvals;
}

void print(const double& sum, const int& sum_count, const vector<double>& xvals, const vector<double>& yvals)
{
    // SUM FOR Nth VECTOR INDICES
    cout<<"The sum of the first "<<sum_count<<" numbers: ";
    for(size_t i = 0;i <sum_count-1;++i) 
        cout<<xvals[i]<<", ";
    cout<<"and "<<xvals[sum_count-1]<<" is "<<sum<<'.'<<endl;
    // ADJECENT DIFFERENCE INSIDE VECTOR X
    cout<<"The difference between adjecent values inside the vector is: "; 
    for(auto i : yvals) cout<<i<<" ";
    cout<<endl;
}

void main_program()
{
    vector<double>xvals;
    double xval, sum = 0.0;
    int sum_count = 0;
    cout<<"Enter some numbers (press '|' at prompt to stop): "<<endl;
    while(cin>>xval) 
        xvals.push_back(xval);
    //
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //
    vector<double>yvals = adj_diff(xvals);
    cout<<"Enter how many of the numbers you wish to sum, starting from the first: "<<endl;
    while(cin>>sum_count)
    {
        sum = summation(sum_count, xvals);
        print(sum, sum_count, xvals, yvals);
        cout<<"Enter another (or CTRL+Z to exit): "<<endl;
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

Q11:
// Fibonnaci Sequence can be described mathematically as follows: F(0) = 0, F(1) = 1; F(n) = f(n-1) + F(n-2) for n > 1

void fibonnaci(const int& n)
{
    if(n < 2)
        throw invalid_argument("[std::invalid_argument]: The function argument (n) must be sequential (n > 1).");
    if(n > 47)
        throw std::overflow_error("[std::overflow_error]: The result cannot be expressed as an int.");
    int a=0, b=1, c;
    cout<<a<<" "<<b<<" ";
    for(size_t i = 2;i < n;++i)
    {
        c = a+b;
        cout<<c<<" ";
        a=b;
        b=c;
    }
    cout<<endl;
}

void main_program()
{
    int n;
    cout<<"Enter the n for Fibonacci sequence: "<<endl;
    while(cin>>n)
    {
        fibonnaci(n);
        cout<<"Enter another (or CTRL+Z to exit): "<<endl;
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

Q12:
// Bullz and cowz
// Program function:
//  - Program stores a vector of 4 random ints from (0-9). ex. vector<int>VALUES = {1, 2, 8, 4}; 
//  - User is supposed to guess all values in order. ex. user input 1248;
//  - Score:
//      ^ Bull: One bull is awarded if the user guesses both the value and the position of the integer correctly.
//      ^ Cow: One cow is awarded if the user guesses only the value correctly and not the position. 
//  -End: The guessing continues until the user has 4 bulls, meaning that he correctly guessed all four numbers.
*/


bool cows(const int& x,const vector<int>& A)
{
    int occurence = count(A.begin(), A.end(), x);
    if(occurence > 0) 
        return true;
    //
    return false;
}

int bulls(const vector<int>& A, const vector<int>& B)
{
    int result = 0;
    for(size_t i = 0;i < A.size();++i)
    {
        if(B[i] == A[i]) ++result; 
    }
    //
    return result;
}

void main_program()
{
    // A = vector storing the result; B = vector storing the guesses;
    vector<int>A = {1, 4, 6, 8};
    int x;
    vector<int>B;
    int cowz = 0, bullz = 0;
    while(cin>>x)
        B.push_back(x);
    //
    beginning:
    bullz = bulls(A, B);
    for(size_t i = 0;i < B.size();++i)
    if(cows(B[i], A))
    ++cowz;
    if(bullz == A.size())
    {
        cout<<bullz<<" bull and "<<cowz<<" cow"<<endl;
        cout<<"Congratz you win!"<<endl;
    }
    else
    {
        bullz = 0;
        cowz = 0;
        goto beginning;
    }
}

int main()
{
    try
    {
        main_program();

    }
    catch(exception& e)
    {
        cerr<<e.what()<<endl;
        keep_window_open();
        return 0;
    }
}
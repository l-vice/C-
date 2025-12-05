#include "std_lib_facilities.h"
#include <random> // random number
#include <unordered_set> //unordered set
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
            throw std::underflow_error("[std::underflow_error]: The result cannot be represented as an int.");
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

int cows(vector<int>& A, vector<int>& B)
{
    int temp = 0, result = 0;
    for(size_t i = 0;i < B.size();++i)
    {
        temp = B[i];
        for(size_t j = 0;j < A.size();++j)
        {
            if(i == j) 
                continue;
            if(A[j] == B[i])
            {
                ++result;
                break;
            }
        }    
    }
    return result;            
}

int bulls(const vector<int>& A, const vector<int>& B)
{
    int result = 0;
    for(size_t i = 0;i < A.size();++i)
    {
        if(B[i] == A[i]) 
            ++result; 
    }
    //
    return result;
}

pair<int, int>parser(vector<int>& A, vector<int>& B)
{
    pair<int,int>result = {0, 0};
    int cowz = 0, bullz = 0;
    bullz = bulls(A, B); 
    // Bulls
    if(bullz == A.size()) 
        return result = {bullz, cowz};
    // Cows
    cowz = cows(A, B);
    // Return
    result = {bullz, cowz};
    return result;
}

int ctoi(const char c)
{
    int result = c - '0';
    return result;
}

vector<int>read_input(const string& s)
{
    vector<int>result;
    for(char c : s)
        if(isdigit(c))
        {
            result.push_back(ctoi(c));
        }
    return result;
}

void main_program()
{
    // A = vector storing the result; B = vector storing the guesses;
    vector<int>A = {1, 4, 6, 8};
    string x;
    vector<int>B;
    cout<<"Enter your guess:"<<endl;
    pair<int, int>result;
    while(cin>>x && x != "|")
    {
        B = read_input(x);
        //
        result = parser(A, B);
        if(result.first == A.size()) 
        {
            cout<<result.first<<" bull and "<<result.second<<" cow"<<endl;
            cout<<"Congrats! You guessed the correct number: ";for(auto i : A) cout<<i;
            break;
        }
        cout<<result.first<<" bull and "<<result.second<<" cow"<<endl;
        //
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"Enter another (or CTRL+Z to exit):"<<endl;    
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

Q13:
// A = Vector storing the result.
// B = Vector storing the guess.

std::mt19937 rng; //Mersenne Twister generator

void rng_seed(const long long int& seed)
{
    
    rng.seed(seed);
}

long long int rand_int(const int& max)
{
    std::uniform_int_distribution<long long int> dist(0, max-1);
    return dist(rng);
}

vector<int>randomizer(const int& size, const int& max, const int& seed)
{
    vector<int>result;
    rng_seed(seed);
    for(size_t i = 0;i < size;++i)
    {
        result.push_back(rand_int(max));
    }
    //
    return result;
}

int ctoi(const char c)
{
    int result = c - '0';
    return result;
}

vector<int>read_input(const string s)
{
    if(s.size() < 4 || s.size() > 4)
        throw invalid_argument("[std::invalid_argument]: non-conforming input length.");
    vector<int>result;
    for(char c : s)
    {
        if(isdigit(c))
            result.push_back(ctoi(c));
        else
            throw std::invalid_argument("[std::invalid_argument]: Input must be an integer.");
    }
    return result;
}

int count_bulls(const vector<int>& A, const vector<int>& B)
{//
    int result = 0;
    for(size_t i = 0;i < A.size();++i)
        if(B[i] == A[i])
            ++result;
    return result;
}

int count_cows(const vector<int>& A, const vector<int>& B)
{// Use: This function computes how many values inside vector B are also inside vector A. This excludes vector values in the same position.
 // Pre-condition: Vector's A and B must contain integers.
 // Post-condition: The output is the amount of values form vector B that are repeated in vector A, excluding values in the same position.
    int temp, result = 0;
    vector<char>isBull(A.size(), false);
    vector<char>matchedA(A.size(), false);
    //
    for(size_t i = 0;i < A.size();++i) 
    {
        if(B[i] == A[i])
        {
            isBull[i] = true;
            matchedA[i] = true;
        }
    }
    for(size_t i = 0;i < B.size();++i)
    {
        if(isBull[i])
            continue;
        temp = B[i];
        for(size_t j = 0;j < A.size();++j)
        {
            if(i == j || matchedA[j])
                continue;
            if(temp == A[j])
            {
                ++result;
                matchedA[j] = true;
                break;
            }
            // Two issue with this code:
                // 1. If there are repeated values inside B, the result will increase anyways. This will result in a wrong number of cows. 
                // 2. The position will be accounted by the result since we do not specify to skip counting an exact match. The bulls can be counted as cows.
        }
    }
    return result;
}

pair<int,int>parser(const vector<int>& A, const vector<int>& B)
{// Use: This function computes the number of bulls and cows. Another special purpose is that it resets the number of bulls and cows at each input iteration.
 // Pre-condition: Vector's storing the result and guess must be integers.
 // Post-condition: Outputs a pair variable of type int representing the number of cows and bulls per each iteration.
    int bulls = 0, cows = 0;
    bulls = count_bulls(A, B);
    if(bulls == A.size())
        return {bulls, cows};
    cows = count_cows(A, B); 
    //
    return {bulls, cows};
}

void main_program()
{
    // RESULT VECTOR [A]
    int max = 10, size = 4;
    long long int n;
    cout<<"Enter seed: "<<endl;
    cin>>n;    
    vector<int>A = randomizer(size, max, n);
    // GUESS VECTOR [B] 
    string x;
    vector<int>B;
    // PROGRAM [C]
    pair<int,int>result;
    cout<<"Enter your guess:"<<endl;
    while(cin>>x)
    {
        B = read_input(x);
        //
        result = parser(A, B);
        cout<<result.first<<" bulls and "<<result.second<<" cows"<<endl;
        //
        if(result.first == A.size())
        {
            cout<<"You correctly guessed the sequence."<<endl;
            return;
        }
        for(auto i : A) cout<<i<<" ";cout<<endl;
        cout<<"Enter another: "<<endl;
    }
}

int main()
{
    try
    {
        while(true)
        {
            main_program();
            
            cout<<"Play again? (y/n): ";
            char c;
            if(!(cin>>c)) 
                break;
            if(c == 'n' || c == 'N')
                break;
            // Clear
            cin.clear();
        }
        
    }
    catch(const exception& e)
    {
        cerr<<e.what()<<endl;
        keep_window_open();
        return 0;
    }
}

// This is OK but i feel like its a little messy. There must exist better logic loops than this.
// Let's redo this exercise again. However, this time, lets try to have a better output structure.

// HELPER FUNCTIONS

// RANDINT
std::mt19937 rng;// Marsenne Twister

void set_seed(const long long int& seed)
{
    rng.seed(seed);
}

int rand_int(const int& max)
{
    std::uniform_int_distribution<int>dist(0, max-1);
    return dist(rng);
}

// ANSWER VECTOR [A]
vector<int> randomizer(const long long int& seed, const int& size, const int& max)
{
    set_seed(seed);
    vector<int>A;
    for(size_t i = 0;i < size;++i)
        A.push_back(rand_int(max));
    
    return A;
}

// GUESS VECTOR [B]

vector<int>read_input(const string& x)
{
    vector<int>B;
    for(char c : x)
    {
        if(!isdigit(c))
            throw std::invalid_argument("[std::invalid_argument]: Guess sequence contains a non-integer value.");
        int i = c - '0';
        B.push_back(i);
    }
    return B;    
}

// PROCESS INPUT

int count_bulls(const vector<int>& A, const vector<int>& B)
{
    int result = 0;
    for(size_t i = 0;i < A.size();++i)
    {
        if(B[i] == A[i])
            ++result;
    }
    return result;
}

int count_cows(const vector<int>& A, const vector<int>& B)
{
    int temp, result = 0;
    vector<char>markedA(A.size(), false);
    vector<char>isBull(A.size(), false);
    for(size_t i = 0;i < A.size();++i)
    {
        if(B[i] == A[i])
        {
            isBull[i] = true;
            markedA[i] = true; // we prevent using the same value for both outputs (bulls, cows)
        }
    }
    for(size_t i = 0;i < B.size();++i)
    {
        if(isBull[i])
            continue;
        
        temp = B[i];
        for(size_t j = 0;j < A.size();++j)
        {
            if(i == j || markedA[j])
                continue;
            if(temp == A[j])
            {
                ++result;
                markedA[j] = true;
                break;
            }
        }
    }
    return result;
    // two things dont work. 1 being the fact that the function increses the result by 1 each time for each value that was already matched.
    // 2 being that the result increases for each value that is counted as a bull. Therefore, one value is counted twice, once as a bull and once as a cow.
    // To fix this, we mark those values using a vector with T/F values and use continue to skip the count. 
}

pair<int, int>parser(const vector<int>& A, const vector<int>& B)
{
    if(B.size() > A.size())
        throw invalid_argument("[std::invalid_argument]: The guess sequence is longer than the result.");
    if(B.size() < A.size())
        throw invalid_argument("[std::invalid_argument]: The guess sequence is shorter than the result.");
    int bulls = 0, cows = 0;
    bulls = count_bulls(A, B); if(bulls == A.size()) return {bulls, cows};
    cows = count_cows(A, B);
    //
    return {bulls, cows};
}

/// MAIN STRUCTURE

// SINGLE ROUND
void play_one_game()
{
    int max = 10, size = 4;
    long long int seed;
    cout<<"Enter the seed as an integer."<<endl;
    cin>>seed;
    if(cin.fail())
        throw std::invalid_argument("[std::invalid_argument]: Seed must be an integer.");
    vector<int>A = randomizer(seed, size, max);
    //
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<"Enter your guess (From 0-4, domain 0-9): "<<endl;
    string guess = " ";
    while(cin>>guess)
    {
        vector<int>B = read_input(guess);
        pair<int, int>result = parser(A, B);
        //
        cout<<"Bulls: "<<result.first<<" | "<<"Cows: "<<result.second<<endl;
        if(result.first == A.size()) 
        {
            cout<<"Congrats! You guessed the sequence A = [ ";for(auto i : A) cout<<i<<" ";cout<<"] correctly."<<endl;
            return;
        }
        cout<<"Secret answer: ";for(auto i : A) cout<<i<<" ";cout<<endl;
        cout<<"Enter another (or CTRL+Z to exit): "<<endl;
    }
}

// GAME
void game_loop()
{
    while(true)
    {
        play_one_game();
        //
        cout<<"Play another? (y/n):"<<endl;
        char c;
        cin>>c;
        if(c == 'y' || c == 'Y') {}
        else if(c == 'n' || c == 'N')
        {
            cout<<"Thanks for playing!"<<endl;
            cout<<"Exiting game..."<<endl;
            break;
        }
        else 
            break;
        cin.clear();
    }
}

int main()
{
    try
    {
        game_loop();
    }
    catch(const exception& e)
    {
        cerr<<e.what()<<endl;
        
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        keep_window_open();
        return 0;
    }
}

Q13 TAKE 3:

/// STRUCTURE
//  1. play_one_game
//  2. game_loop
//  3. main
//  4. HELPERS


// HELPERS [H]

// RANDINT [R]

std::mt19937 rng; // Mersenne Twister

void set_seed(const long long int seed)
{
    rng.seed(seed);
}

int rand_int(const int& max)
{
    std::uniform_int_distribution<int>dist(0, max-1);
    return dist(rng);
}

// CHECK INPUT [C]

string read(const string& x)
{
    for(char c : x)
        if(!isdigit(c))
            throw std::invalid_argument("[std::invalid_argument]: Seed must be a digit.");
    return x;
}

// LL OVERFLOW [LO]

long long int stoll_overflow(const string& s)
{
    try
    {   
        return stoll(s);        
    }
    catch(const std::out_of_range&)
    {
        if(!s.empty() && s[0] == '-')
            throw std::underflow_error("[std::underflow_error]: The seed is too small to be represented as an integer.");
        else
            throw std::overflow_error("[std::overflow_error]: The seed is too big to be represented as an integer.");
    }
}

// SOLUTION VECTOR [A] 
vector<int>randomizer(const long long int& seed, const int& size, const int& max)
{
    set_seed(seed);
    //
    vector<int>A;
    for(size_t i = 0;i < size;++i)
        A.push_back(rand_int(max));
    return A;
}

// GUESS VECTOR [B]

vector<int>read_input(const string& x)
{
    if(x.size() < 4)
        throw std::invalid_argument("[std::invalid_argument]: The guess sequence is shorter than the answer.");
    if(x.size() > 4)
        throw std::invalid_argument("[std::invalid_argument]: The guess sequence is larger than the answer.");
    vector<int>B;
    for(char c : x)
    {
        if(!isdigit(c))
            throw std::invalid_argument("[std::invalid_argument]: Guess must be an integer.");
        int i = c - '0';
        B.push_back(i);
    }
    return B;
}

// PARSER [P]

pair<int, int>parser(const vector<int>& A, const vector<int>& B)
{
    int n = A.size();
    int bulls = 0;
    for(size_t i = 0;i < n;++i)
        if(B[i] == A[i])
            ++bulls;
    if(bulls == n)
        return {bulls, 0};
    //
    int freqA[10] = {0};
    int freqB[10] = {0};
    for(size_t i = 0;i < n;++i)
    {
        ++freqA[A[i]];
        ++freqB[B[i]];
    }
    int matches = 0;
    for(size_t d = 0;d < 10;++d)
        matches+=std::min(freqA[d], freqB[d]);
    int cows = matches - bulls;
    //
    return {bulls, cows};
}

// SINGLE GAME [SG]
bool play_one_game()
{  
    int max = 10, size = 4;
    string seed;
    long long int int_seed = 0LL;
    //
    cout<<"Set seed: ";
    cin>>seed;
    if(cin.eof()) return false;
    seed = read(seed);
    int_seed = stoll_overflow(seed);
    
    //
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //
    vector<int>A = randomizer(int_seed, size, max);
    cout<<"Enter your guess: "<<endl;
    string guess;
    while(cin>>guess)
    {
        vector<int>B = read_input(guess);
        //
        pair<int,int>result = parser(A, B);
        cout<<result.first<<" bulls and "<<result.second<<" cows"<<endl;
        if(result.first == A.size())
        {
            cout<<"Congrats! You guessed the sequence correctly!"<<endl;
            return true;
        }

        cout<<"Enter another: "<<endl;
    }
    if(cin.eof()) return false; // user pressed CTRL+Z inside guess loop.
    
    return true;
} 

// GAME LOOP [GL]
void game_loop()
{
    while(true) 
    {
        bool finished = play_one_game();
        if(!finished)
        {
            cout<<"\nExiting game... (EOF detected)\n";
            break;
        }
        cout<<"Play another? (y/n)"<<endl;
        char c;
        cin>>c;
        if(c == 'y' || c == 'Y') {}
        else if(c == 'n' || c == 'N')
        {
            cout<<"Exiting game... Thanks for playing!"<<endl;
            break;
        }
        else 
            break;
    }
}

// MAIN [M]
int main()
{
    try
    {
        game_loop();
    }
    catch(const exception& e)
    {
        cerr<<e.what()<<endl;
        keep_window_open();
        return 1;
    }
}

Q13 TAKE 4:
Structure:
//  1. play_one_game
//  2. game_loop
//  3. main
//  4. helpers


// ------------------------ HELPERS [H] ------------------------

// RANDINT [R]

std::mt19937 rng; // Mersenne Twister

void set_seed(const int& n)
{
    rng.seed(n);
}

int rand_int(const int& max)
{
    std::uniform_int_distribution<int>dist(0, max-1);
    return dist(rng);
}

// SEED [S]

int read_seed(const string& s)
{
    if(s[0] == '-')
        throw std::invalid_argument("[std::invalid_argument]: The seed must be a positive number.");
    try
    {
        int result = stoi(s);
        return result;
    }
    catch(const std::out_of_range)
    {
        throw std::overflow_error("[std::overflow_error]: The seed cannot be represented as an integer.");
    }
}

// SOLUTION VECTOR [A]

vector<int>randomiser(const int& seed, const int& size, const int& max)
{
    set_seed(seed);
    
    vector<int>A;
    for(size_t i = 0;i < size;++i)
        A.push_back(rand_int(max));
        
    return A;
}

// GUESS VECTOR [B]

int ctoi(const char& c)
{
   int i = c - '0';
   return i; 
}

vector<int>read_input(const string& s)
{
    if(s.size() > 4)
        throw std::invalid_argument("[std::invalid_argument]: The guess sequence is larger than the solution.");
    if(s.size() < 4)
        throw std::invalid_argument("[std::invalid_argument]: The guess sequence is shorter than the solution.");
    vector<int>B;
    for(char c : s)
        B.push_back(ctoi(c));
    //
    return B;
}

// PARSER [P]

pair<int, int>parser(vector<int>& A, vector<int>& B)
{
    int n = A.size();
    int bulls = 0;
    //
    for(size_t i = 0;i < n;++i)
        if(B[i] == A[i])
            ++bulls;
    if(bulls == n)
        return{bulls, 0};
    //
    int freqA[10] = {0};
    int freqB[10] = {0};
    for(size_t i = 0;i < n;++i)
    {
        ++freqA[A[i]];
        ++freqB[B[i]];
    }
    //
    int matches = 0;
    for(size_t d = 0;d < 10;++d)
        matches += std::min(freqA[d], freqB[d]);
    int cows = matches - bulls;
    //
    return {bulls, cows};
}

// ------------------------ SINGLE GAME [SG] ------------------------
bool play_one_game()
{
    int max = 10, size = 4;
    cout<<"Enter seed:"<<endl;
    string seed;
    cin>>seed;
    if(cin.eof())
        return false;
    int seed_int = read_seed(seed);
    vector<int>A = randomiser(seed_int, size, max);
    //
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //
    cout<<"Enter your guess: "<<endl;
    string guess;
    while(cin>>guess)
    {
        vector<int>B = read_input(guess);
        pair<int,int>result = parser(A, B);
        //
        cout<<result.first<<" bulls and "<<result.second<<" cows."<<endl;
        if(result.first == A.size())
        {
            cout<<"Congrats! You've guessed the sequence correctly."<<endl;
            return true;
        }
    }
    if(cin.eof())
        return false;

    return true;
}

// ------------------------ GAME LOOP [GL] ------------------------
void game_loop()    
{
    try
    {
        while(true)
        {
            bool finished = play_one_game();
            if(!finished) 
            {
                cout<<"Exiting game... (EOF Detected)\n";
                break;
            }
            cout<<"Play another? (y/n):"<<endl;
            char c;
            cin>>c;
            if(c == 'y' || c == 'Y') {}
            else if(c == 'n' || c == 'N')
            {
                cout<<"Exiting game..."<<endl;
                break; 
            }
            else
                break;
        }
    }
    catch(const std::invalid_argument& e)
    {
        cerr<<e.what()<<endl;
        keep_window_open();
        return;
    }
    catch(const std::out_of_range& e)
    {
        cerr<<e.what()<<endl;
        keep_window_open();
        return;
    }
    catch(const std::overflow_error& e)
    {
        cerr<<e.what()<<endl;
        keep_window_open();
        return;
    }
}

// ------------------------ MAIN [M] ------------------------
int main()
{
    try
    {
        game_loop();
    }
    catch(const exception& e)
    {
        cerr<<e.what()<<endl;
        keep_window_open();
        return 0;
    }
}


//// TO USE LATER
else if(dow.first == "Wednesday")
                WE.push_back(dow.second);
            else if(dow.first == "Thursday")
                TH.push_back(dow.second);
            else if(dow.first == "Friday")
                FR.push_back(dow.second);
            else if(dow.first == "Saturday")
                TU.push_back(dow.second);
////
Q14:

void main_program()
{
    try
    {
        string day_of_the_week = " ";
        int value = 0;
        vector<int>MO, TU, WE, TH, FR, SA, SU;
        int sum_mo = 0, sum_tu = 0, sum_we = 0, sum_th = 0, sum_fr = 0, sum_sa = 0, sum_su = 0;
        int sum_total = 0, sum_wrong = 0;
        cout<<"Enter the days of the week and their values: "<<endl;
        //
        int ill_count = 0;  
        while(true) 
        {   
            if(!(cin>>day_of_the_week))
                break;
            if(day_of_the_week == "|")
                break;
            if(!(cin>>value))
            {
                cin.clear();
                cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
                throw std::invalid_argument("[std::invalid_argument]: The value must be an integer.");
            }
            if(day_of_the_week == "Monday" || day_of_the_week == "monday" || day_of_the_week == "Mon" || day_of_the_week == "mon")
            {
                MO.push_back(value);
                sum_mo+=value;
            }
            else if(day_of_the_week == "Tuesday" || day_of_the_week == "tuesday" || day_of_the_week == "Tue" || day_of_the_week == "tue")
            {
                TU.push_back(value);
                sum_tu+=value;
            }
            else if(day_of_the_week == "Wednesday" || day_of_the_week == "wednesday" || day_of_the_week == "Wed" || day_of_the_week == "wed")
            {
                WE.push_back(value);
                sum_we+=value;
            }
            else if(day_of_the_week == "Thursday" || day_of_the_week == "thursday" || day_of_the_week == "Thu" || day_of_the_week == "thu")
            {
                TH.push_back(value);
                sum_th+=value;
            }
            else if(day_of_the_week == "Friday" || day_of_the_week == "friday" || day_of_the_week == "Fri" || day_of_the_week == "fri" || day_of_the_week == "Fr" || day_of_the_week == "fr")
            {
                FR.push_back(value);
                sum_fr+=value;
            }
            else if(day_of_the_week == "Saturday" || day_of_the_week == "saturday" || day_of_the_week == "Sat" || day_of_the_week == "sat")
            {
                SA.push_back(value);
                sum_sa+=value;
            }
            else if(day_of_the_week == "Sunday" || day_of_the_week == "sunday" || day_of_the_week == "Sun" || day_of_the_week == "sun")
            {
                SU.push_back(value);
                sum_su+=value;    
            }
            else 
            {
                ++ill_count;
                sum_wrong+=value;
            }
            sum_total+=value;
        }
        //
        cout<<"The sum of the values of the seven day-of-the week vector: "<<endl
            <<"[Monday] "<<sum_mo<<endl
            <<"[Tuesday] "<<sum_tu<<endl
            <<"[Wednesday] "<<sum_we<<endl
            <<"[Thursday] "<<sum_th<<endl
            <<"[Friday] "<<sum_fr<<endl
            <<"[Saturday] "<<sum_sa<<endl
            <<"[Sunday] "<<sum_su<<endl
            <<"[Total] "<<sum_total-sum_wrong<<endl;
        cout<<"The number of rejected values: "<<ill_count<<endl;
    }
    catch(std::invalid_argument& e)
    {
        cerr<<e.what()<<endl;
        keep_window_open();
        return;
    }
    catch(std::out_of_range& e)
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

--------------------------------------------------------------------------------------------- EOC CH-5: TAKE 2 ---------------------------------------------------------------------------------------------
Q14:

// This is the proper solution utilizing vector indices

int day_to_index(string s)
{
    // lowercase the string
    for(char& c : s) 
        c = tolower(c);
    
    if(s == "monday" || s == "mon") return 0;
    if(s == "tuesday" || s == "tue") return 1;
    if(s == "wednesday" || s == "wed") return 2;
    if(s == "thursday" || s == "thu") return 3;
    if(s == "friday" || s == "fri") return 4;
    if(s == "saturday" || s == "sat") return 5;
    if(s == "sunday" || s == "sun") return 6;
    
    return -1; // illegal day
}


void main_program()
{
    vector<vector<int>> days(7);  // one vector for each day
    vector<string> names = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};

    int rejected = 0;

    cout << "Enter day-value pairs (type '|' to stop):\n";

    while(true)
    {
        string day;
        int value;

        if(!(cin >> day)) break;
        if(day == "|") break;

        if(!(cin >> value)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("Value must be an integer.");
        }

        int index = day_to_index(day);
        if(index == -1) {
            ++rejected;
        } else {
            days[index].push_back(value);
        }
    }

    cout << "\n--- Daily sums ---\n";

    for(int i = 0; i < 7; ++i) {
        int sum = 0;
        for(int x : days[i]) sum += x;
        cout << names[i] << ": " << sum << "\n";
    }

    cout << "Rejected values: " << rejected << "\n";
}


Q12-Q13:

// CONSTANT VALUES [CST]
int A_sz = 4;
int max = 10;

// HELPERS [H]

// RAND INT [R]

std::mt19937 rng; // Mersenne Twister

void set_seed(unsigned long long& seed)
{
    rng.seed(seed);
}

int rand_int(const int& max)
{
    std::uniform_int_distribution<int>dist(0, max-1);
    return dist(rng);
}

// RESPONSE VECTOR [A]

vector<int>randomiser(unsigned long long& seed, const int& max)
{
    set_seed(seed);

    vector<int>A;
    for(size_t i = 0;i < A_sz;++i)
        A.push_back(rand_int(max));
    
    return A;
}

// GUESS VECTOR [B]

vector<int>read_input(string& s)
{
    if(s.size() < A_sz)
        throw std::range_error("[std::range_error]: The guess sequence is shorter than the result.");
    if(s.size() > A_sz)
        throw std::range_error("[std::range_error]: The guess sequence is longer than the result.");
    vector<int>B;
    for(char& c : s)
    {
        int integer = c - '0';
        B.push_back(integer);
    }
    //
    return B;
}

// PARSER [P]

pair<int, int>parser(const vector<int>& A, const vector<int>& B, const int& max)
{
    int n = A.size();
    int bulls = 0;
    for(size_t i = 0;i < n;++i)
        if(B[i] == A[i])
            ++bulls;
    if(bulls == n)
        return {bulls, 0};
    
    int freqA[max] = {0};
    int freqB[max] = {0};
    for(int i = 0;i < n;++i)
    {
        ++freqA[A[i]];
        ++freqB[B[i]];
    }
    int matches = 0;
    for(int d = 0;d < max;++d)
        matches +=std::min(freqA[d], freqB[d]);
    int cows = matches - bulls;

    return{bulls, cows};
}

// SEED [S]

unsigned long long read_seed(string& s)
{
    for(char& c : s)
            if(!isdigit(c) && s[0] != '-')
                throw std::invalid_argument("[std::invalid_argument]: Seed must be an integer.");
    
    if(s[0] == '-')
        throw std::invalid_argument("[std::invalid_argument]: The seed must be a positive number.");
    try 
    {   
        unsigned long long result = stoull(s);
        return result;

    }
    catch(std::out_of_range& e)
    {
        throw std::overflow_error("[std::overflow_error]: The seed cannot be represented as an integer.");
    }
}

// SINGLE GAME [SG]
bool play_one_game()
{
    int A_sz = 4, max = 10;
    string seed;
    cout<<"Enter seed: "<<endl;
    cin>>seed;
    if(cin.eof())
        return false;
    unsigned long long ull_seed = read_seed(seed);
    

    vector<int>A = randomiser(ull_seed, max);
    
    //
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    // 
    string guess;
    cout<<"Enter your guess: "<<endl;
    while(cin>>guess)
    {   
        vector<int>B = read_input(guess);
        
        pair<int, int>result = parser(A, B, max);

        if(result.first == A.size())
        {
            cout<<result.first<<" bulls and "<<result.second<<" cows"<<endl;
            cout<<"Congrats you've guessed the sequence [A]: ";for(auto i : A) cout<<i<<" ";
            break;
        }
        
        cout<<result.first<<" bulls and "<<result.second<<" cows"<<endl;

        cout<<"[A] ";for(auto i : A) cout<<i<<" ";
        cout<<endl;
        cout<<"[B] ";for(auto i : B) cout<<i<<" ";
        cout<<endl;
        cout<<"Enter another (or CTRL+Z to exit): "<<endl;
    }
    if(cin.eof())
        return false;
    //
    return true;
}

// GAME LOOP [GL]

void game_loop()
{
    try
    {
        while(true)
        {
            bool isfinished = play_one_game();
            if(!isfinished)
            {
                cout<<"Exiting program (EOF Detected)...\n";
                break;
            }
            cout<<"\nPlay another? (y/n)\n";
            char c;
            cin>>c;
            if(c == 'Y' || c == 'y') {}
            else if(c == 'N' || c == 'n')
            {
                cout<<"Exiting program...\n";
                break;
            }    
            else 
                cout<<"Invalid input.\n";
        }

    }
    catch(const invalid_argument& e)
    {
        cerr<<e.what()<<endl;
        keep_window_open();
        return;
    }
    catch(const std::out_of_range& e)
    {
        cerr<<e.what()<<endl;
        keep_window_open();
        return;
    }
    catch(const std::range_error& e)
    {
        cerr<<e.what()<<endl;
        keep_window_open();
        return;
    }
    catch(const std::overflow_error& e)
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
        game_loop();
    }
    catch(const exception& e)
    {
        cerr<<e.what()<<endl;
        keep_window_open();
        return 0;
    }
}

Q11:

void range_check(const int& n)
{
    if(n < 2)
        throw std::invalid_argument("[std::invalid_argument]: n is too small to represent a sequence.");
    if(n > 47)
        throw std::overflow_error("[std::overflow_error]: Variable type does not support the sequence size.");
}

void fibonacci_sequence(const int& n)
{  
    size_t count = 0;    
    int a = 0, b = 1, c;
    cout<<a<<" "<<b<<" ";
    while(count < n-2)
    {
        c = a+b;
        cout<<c<<" ";
        a = b;
        b = c;
        ++count;
    }
}

void main_program()
{
    try
    {
        int n;
        cout<<"Enter the length of the Fibonacci Sequence: "<<endl;
        while(cin>>n)
        {
            range_check(n);
            cout<<"The Fibonacci Sequence for the n numbers: ";fibonacci_sequence(n);
            cout<<"\nEnter another(or CTRL+Z to exit): "<<endl;
        }
    }
    catch(const std::invalid_argument& e)
    {
        cerr<<e.what()<<endl;
        keep_window_open();
        return;
    }
    catch(const std::overflow_error& e)
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

Q8:

void print(const int& sum, const int& sum_count, const vector<long long>xvals)
{
    cout<<"The sum of the first "<<sum_count<<" numbers: ";
    for(size_t i = 0;i < sum_count-1;++i) cout<<xvals[i]<<", ";cout<<"and "<<xvals[sum_count-1]<<" is "<<sum;
}

int i_sum(const int& sum_count, const vector<long long>& xvals)
{
    int result = 0;
    if(sum_count > xvals.size())
        throw range_error("[std::range_error]: The sum count value is larger than the vector size.");
    for(size_t i = 0;i < sum_count;++i)
    {
        if(xvals[i] > 0 && result > LONG_LONG_MAX - xvals[i])
            throw std::overflow_error("[std::overflow_error]: The result cannot be represented as an int.");
        if(xvals[i] < 0 && result < LONG_LONG_MIN - xvals[i])
            throw std::underflow_error("[std::underflow_error]: The result cannot be represented as an int.");
        result+=xvals[i];    
    }

    return result;
}

bool isint(const string& s)
{
    if(s.empty()) return false;

    size_t i = 0;
    if(s[0] == '-' || s[0] == '+') i = 1;
    for(;i < s.size();++i)
        if(!isdigit(s[i])) 
            return false;
    
    return true;
}

long long read_input(string& s)
{
    try
    {
        return stoll(s);
    }
    catch(const std::out_of_range& e)
    {
        if(s[0] == '-')
        {   
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
            throw std::underflow_error("[std::underflow_error]: The value is too big to be represented as an integer.");
        }    
        else
            throw std::overflow_error("[std::overflow_error]: The value is too small to be represented as an integer.");
    }
    catch(const std::invalid_argument& e)
    {
        throw std::invalid_argument("[std::invalid_argument]: Input must be an integer.");
    }    
}

void main_program()
{
    try
    {
        string x;
        vector<long long>xvals;
        cout<<"Enter a series of numbers (press '|' at prompt to stop): "<<endl;
        while(cin>>x)
        {
            if(x == "|")
                break;
            if(!isint(x))
            {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw std::invalid_argument("[std::invalid_argument]: The input must be an integer.");
            }
            //
            long long ll_x = read_input(x);    
            xvals.push_back(ll_x);
        }
        //
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        //
        int sum = 0, sum_count;
        cout<<"Enter how many numbers you would like to sum, starting from the first: "<<endl;
        while(cin>>sum_count)
        {
            sum = i_sum(sum_count, xvals);
            print(sum, sum_count, xvals);
            cout<<"\nEnter another (or CTRL+Z to exit): "<<endl;
        }         
    }
    catch(const std::range_error& e)
    {
        cerr<<e.what()<<endl;
        keep_window_open();
        return;
    }
    catch(const std::overflow_error& e)
    {
        cerr<<e.what()<<endl;
        keep_window_open();
        return;
    }
    catch(const std::underflow_error& e)
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

Q9-Q10:

void print(const double& sum, const int& sum_count, const vector<double>& xvals, const vector<double>xvals_adj)
{
    cout<<"The sum of the first "<<sum_count<<" numbers: ";
    for(size_t i = 0;i < sum_count-1;++i) cout<<xvals[i]<<", ";cout<<"and "<<xvals[sum_count-1]<<" is "<<sum;
    //
    cout<<"\nThe adjecent difference: ";for(auto i : xvals_adj) cout<<i<<" ";
}

double i_sum(const int& sum_count, const vector<double>& xvals)
{
    double result = 0;
    if(sum_count > xvals.size())
        throw range_error("[std::range_error]: The sum count value is larger than the vector size.");
    for(size_t i = 0;i < sum_count;++i)
    {
        if(xvals[i] > 0 && result > std::numeric_limits<double>::max() - xvals[i])
            throw std::overflow_error("[std::overflow_error]: The result cannot be represented as an int.");
        if(xvals[i] < 0 && result < numeric_limits<double>::min() - xvals[i])
            throw std::underflow_error("[std::underflow_error]: The result cannot be represented as an int.");
        
        result+=xvals[i];
    }     
    //
    return result;
}

vector<double>adj_diff(vector<double>& xvals)
{
    vector<double>v_adj;
    int n = xvals.size()-1;
    for(size_t i = 0;i < n;++i)
    {
        v_adj.push_back(xvals[i] - xvals[i+1]);
    }
    return v_adj;
}

void main_program()
{
    try
    {
        double x;
        vector<double>xvals;
        cout<<"Enter a series of numbers (press '|' at prompt to stop): "<<endl;
        while(true)
        {
            if(!(cin>>x))
                break;
            xvals.push_back(x);
        }  
        //
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        //
        vector<double>xvals_adj = adj_diff(xvals);
        //
        double sum = 0;
        int sum_count;
        cout<<"Enter how many numbers you would like to sum, starting from the first: "<<endl;
        while(cin>>sum_count)
        {
            sum = i_sum(sum_count, xvals);
            print(sum, sum_count, xvals, xvals_adj);
            cout<<"\nEnter another (or CTRL+Z to exit): "<<endl;
        }
    }
    catch(const std::range_error& e)
    {
        cerr<<e.what()<<endl;
        keep_window_open();
        return;
    }
    catch(const std::overflow_error& e)
    {
        cerr<<e.what()<<endl;
        keep_window_open();
        return;
    }
    catch(const std::underflow_error& e)
    {
        cerr<<e.what()<<endl;
        keep_window_open();
        return;
    }
}
//
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

Q7:

pair<double, double>quadratic_expr(const double& a, const double& b, const double& c)
{
    if(a == 0)
        throw std::domain_error("[std::domain error]: The quadratic coefficient a is 0. If indeed true, you should not use the quadratic function!");
    double disc = (b*b) - 4*(a*c);
        if(disc < 0)
            throw std::domain_error("[std::domain_error]: The discriminant is negative!");
    double x1 = (-b + sqrt(disc))/(2*a);
    double x2 = (-b - sqrt(disc))/(2*a);
    //
    return {x1, x2}; 
}

void main_program()
{
    try
    {
        double a, b, c;
        cout<<"Enter the quadratic constants (a, b, c)\n";
        while(cin>>a>>b>>c)
        {
            if(cin.eof())
                break;
            pair<double, double>result = quadratic_expr(a, b, c);
            double x1 = result.first;
            double x2 = result.second;
            cout<<"The quadratic function: "<<a<<"x^2"<<" + "<<b<<"x"<<" + "<<c<<endl;
            cout<<"Has two solutions: "<<"x1 = "<<x1<<" | x2 = "<<x2<<endl;
            
            cout<<"\nEnter another (or CTRL+Z to exit): "<<endl;
        }
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
        main_program();
    }
    catch(const exception& e)
    {
        cerr<<e.what()<<endl;
        keep_window_open();
        return 0;
    }

}

Q6: C TO K
// F = (C * 1.8) + 32
// C = (F - 32) / 1.8

const double abs_zero_C = -273.15;
const double abs_zero_F = -459.67;
//
double ftoc(const double& f)
{
    if(f < abs_zero_F)
        throw std::invalid_argument("[std::invalid_argument]: The value in Fahrenheit is below absolute zero! [-459.67]");
    
    double c = (f - 32) / 1.8;

    return c;
}

double ctof(const double& c)
{
    if(c < abs_zero_C)
        throw std::invalid_argument("[std::invalid_argument]: The value in Celsius is below absolute zero! [-273.15]");
    double f = (c * 1.8) + 32;

    return f;
}

void main_program()
{
    try
    {
        pair<double, char> x = {0.0, 'f'};
        cout<<"Enter the value followed by the unit (ex. 10 C)\n";
        
        while(cin>>x.first>>x.second)
        {
            x.second = tolower(x.second);
            switch(x.second)
            {
                case 'c':
                    cout<<x.first<<" Celsius is "<<ctof(x.first)<<" Fahrenheit."<<endl;
                    break;
                case 'f':
                    cout<<x.first<<" Fahrenheit is "<<ftoc(x.first)<<" Celsius."<<endl;
            }
        }
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
    catch(const exception& e)
    {
        cerr<<e.what()<<endl;
        keep_window_open();
        return 0;
    }
}

Q2-Q5
*/

const double abs_zero_C = -273.15;
const double abs_zero_K = 0;

double ctok(double& c)
{
    if(c < abs_zero_C)
        throw std::invalid_argument("[std::invalid_argument]: The temperature in Celsius is less than absolute zero.");
    double k = c + 273.15;
    return k;
}

double ktoc(double& k)
{
    if(k < abs_zero_K)
        throw std::invalid_argument("[std::invalid_argument]: The temperature in Kelvin is less than absolute zero.");
    double c = k - 273.15;

    return c;
}

void main_program()
{
    try
    {   
        pair<double, char>x;
        cout<<"Enter the temperature in either Kelvin or Celsius (ex. 20 C): "<<endl;
        while(cin>>x.first>>x.second)
        {
            x.second = tolower(x.second);
            switch(x.second) 
            {
                case 'c':
                    cout<<"The temperature in Kelvin is: "<<ctok(x.first)<<endl;
                    break;
                case 'k':
                    cout<<"The temperature in Celsius is: "<<ktoc(x.first)<<endl;
                    break;
            }

            cout<<"Enter another (or CTRL+Z to exit): "<<endl;
        }
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
    catch(const exception& e)
    {
        cerr<<e.what()<<endl;
        keep_window_open();
        return 0;
    }
}


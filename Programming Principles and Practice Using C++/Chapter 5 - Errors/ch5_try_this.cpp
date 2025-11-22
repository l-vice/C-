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

EXAMPLE: 
class Bad_area {}; // a type specifically for reporting errors from area()

// calculate area of a rectangle;
// throw a Bad_area exception in case of a bad argument
int area(int length, int width)
{
    if(length <= 0 || width <= 0) throw Bad_area(); // the notation Bad_area() means 
                                                    // "Make an object of type Bad_area," so throw Bad_area() 
                                                    // means "Make an object of type Bad_area and throw it."
    return length * width;
}


const int frame_width = 2;
class Bad_area{};

int area(const int& length, const int& width) 
{
    if(length <= 0 || width <= 0) throw Bad_area();
    return length*width; 
}

int framed_area(const int& length, const int& width) 
{
    return area(length - frame_width, width - frame_width);
}

int main()
{
    try 
    {
        int x = -1;
        int y = 2;
        int z = 4;
        //
        int area1 = area(x, y);
        int area2 = framed_area(1, z);
        int area3 = framed_area(y, z);
        double ratio = int(area1)/area3;
    }
    catch (Bad_area) 
    {
        cout<<"Oops! bad arguments to area()"<<endl;
    }
}

// Practice questions

int main()
{
    vector<int>v;
    int i;
    while(cin>>i) v.push_back(i);
    for(size_t i = 0;i < v.size();++i)
        cout<<"v["<<i<<"] == "<<v[i]<<endl;
}

int main()
{  
    vector<char>A;
    int i;
}

int main()
{
    vector<int>v(5, 10);
    int x[5];
    cout<<x<<endl;
    for(size_t i = 0;i<v.size();++i) cout<<v[i]<<" ";cout<<endl;

    keep_window_open();
    return(0);
}

int main()
{
    try 
    {
        vector<int>v;
        int x;
        while(cin>>x) 
        v.push_back(x);
        for(size_t i = 0;i <= v.size();++i)
            cout<<"v["<<i<<"] == "<<v[i]<<endl; 
    } catch(out_of_range) 
    {
        cerr<<"Oops! Range error"<<endl;
        return 1;    
    } catch(...) 
    {
        cerr<<"Exception: something went wrong"<<endl;
        return 2;
    }    
}

// Error handling

int main()
{
    double d = 0;
    cin>>d;
    if(cin) 
    {
        cout<<"Great"; 
    }   
    else 
    {
        cout<<"Terrible";
    }    
}

double some_function()
{
    double d = 0;
    cin>>d;
    if(!cin) error("couldn't read a double in 'some_function()'");
    // do something useful
}

bool is_int(const string& x) 
{
    for(char c : x) 
    {
        if(isdigit(c)) 
            return true;
    }
    return false;  
}

void error(string s1, string s2)
{
    throw runtime_error(s1+s2); // concatinate
}

int main()
{
    try 
    {
        string x = 0;
        cout<<"Enter a value to be multiplied by 3: "<<endl;
        cin>>x;
        if(is_int(x))
            cout<<"The result is: "<<stoi(x)*3;
        return 0; // 0 indicates success
    }
    catch(exception& e) // & "pass the exception by reference"  
    {
        cerr<<"error: "<<e.what()<<endl;
        keep_window_open();
        return 1; // 1 indicates failure
    }
    catch(...) 
    {
        cerr<<"Oops: unknown exception!"<<endl;
        keep_window_open();
        return 2;
    }
}

TRY THIS 3:

bool is_int(const string& x)
{
    for(char c : x)
        if(isdigit(c))
            return true;
    return false;
}

int main()
{
    try
    {
        string x = ""; 
        vector<int>xvals;
        cout<<"Enter anything: "<<endl;
        while(cin>>x && x != "|") 
        {
            if(is_int(x))
                xvals.push_back(stoi(x));
            else error("x is not an int! ", x);
        }  
        for(size_t i = 0;i < xvals.size();++i) cout<<xvals[i]<<" ";
        return 0;  
    }
    catch(exception& e)
    {
        cerr<<"error: "<<e.what()<<endl;
        keep_window_open();
        return 1;
    }
    catch(...)
    {
        cerr<<"Unknown exception!"<<endl;
        keep_window_open();
        return 2;
    }
}

int main()
{
    int x1 = narrow_cast<int>(2.9);
    int x2 = narrow_cast<int>(2.0);
    //char c1 = narrow_cast<char>(2);
    //char c2 = narrow_cast<char>(82);
    cout<<x1<<" "<<x2;
    // <int> these brackets are called "template argument". These specify a type, rather than a value.
    // we use narrow_cast() when we need to fit a value but are unsure whether it will fil or not.
}


int main()
{
    vector<double>temps;
    //
    double temp = 0.0;
    double sum = 0.0;
    double high_temp = __DBL_MIN__; 
    double low_temp = __DBL_MAX__; //error was due to a initialized zero
    cout<<"Enter any set of temps: "<<endl;
    while(cin>>temp) 
        temps.push_back(temp);

    for(size_t i = 0;i < temps.size();++i)
    {
        if(temps[i] > high_temp) high_temp = temps[i];
        if(temps[i] < low_temp) low_temp = temps[i];
        sum+=temps[i];
    }

    cout<<"Highest Temperature: "<<high_temp<<endl
        <<"Lowest Temperature: "<<low_temp<<endl
        <<"Average temperature: "<<sum/temps.size()<<endl;   
}

TRY THIS 3:
// Least amount of input is 1;

// Questions to ask yourself:
//    1. Is the answer to this particular problem plausible?
//    2. How would i recognize a plausible result?

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


TRY THIS 4:
// The result was wrong. The correct result is 10.39 for s = 2cm;
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

TRY THIS 5:
// Estimation

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


int my_complicated_function(int a, int b, int c)
{
    //the arguments must be positive and a < b < c; -- STATE IN THE COMMENT WHAT THE FUNCTION REQUIRES OF ITS ARGUMENTS.
    if(!(0<a && a<b && b<c))
        error("bad arguments for mfc");
}

class Bad_area{};

int area(const int& length, const int& width)
{
    if(length <= 0 || width <= 0) 
        throw Bad_area();
    
    return length*width;
}

// You can always be more specific. for example: 

int area(const int& length, const int& width)
{ // use: calculate area of a rectangle
  // pre-condition/s: length and width must be positivive
  // post-condition: returns area of a rectangle 
    if(length <= 0 || width <= 0) 
        throw Bad_area();
    
    return length*width;
}

*/
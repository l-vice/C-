#include "std_lib_facilities.h"
// 17.
int main()
{
    try
    {
        int i = 0;
        int j = 9;
        while(i<10)
            ++i;
        cout<<j<<""<<i;
        if(j<i) cout<<"Success!\n";
    }
    catch(exception& e) 
    {
        cerr<<"error: "<<e.what()<<endl;
        keep_window_open();
        return 1; // exception type error;
    }
    catch(...) 
    {
        cerr<<"Unknown exception!"<<endl;
        keep_window_open();
        return 2; // error with an unknown exception type;
    }
}

#include "std_lib_facilities.h"
// A program that allows the user to input his name
int main()
{
    cout<<"Enter the name of the person you want to write to:\n";
    cout<<"Enter the name of the other person of interest:\n";
    cout<<"Enter the 'm' if the person is male, otherwise 'f' if the person is female.\n";
    string first_name; // object of type string for first_name
    string friend_name; // object of type string for friend name
    char friend_sex = 0;
    cin>>first_name>>friend_name;
    cout<<"Dear "<<first_name<<",\n"
        <<"I hope they are feeding you in prison.\n"
        <<"I understand that it's been a long time since I wrote but nevertheless Im writing to you now.\n"
        <<"Please let me know how many bucks you want me to send, so you can buy yourself something in the commissary. (SO THAT FEEDIN' CAN BE GOOD)\n";
    while(cin>>friend_sex) {
        if(friend_sex == 'm')
            cout<<"If you see "<<friend_name<<" please ask him to write me.\n";   
        else
            cout<<"If you see "<<friend_name<<" please tell her to write me.\n"; 
            
    }
        cout<<"All the best,\n"
        <<"Lukasz.";
}
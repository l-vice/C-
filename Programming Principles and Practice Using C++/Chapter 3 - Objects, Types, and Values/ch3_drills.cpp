#include "std_lib_facilities.h"

// This program is a prompt for letter writing. With required inputs such as first_name, friend_name and age and friend_sex of variable friend_name.
int main()
{
    string first_name; // An object of type string where we verify the first name of the user.
    string friend_name; // An object of type string which we use to store the name of a friend.
    int age;
    char friend_sex = 0;
    int correct = 2;
    cout<<"Enter the name of person you want to write to and the friends name including the friends age and sex. Use m or f to indicate sex.\n";
    cin>>first_name>>friend_name>>age>>friend_sex;
    cout<<"Dear "<<first_name<<','<<"\n\n"
        <<"How are you? Is the penitentiary treating you well?\n\n"
        <<"I haven't wrote for sometime since I was busy with opening 5 new business... and I do apologize for that.\n\n"
        <<"I must say that they are successful so apart from checking in I am also writing to you to help me setup a system where I can send you money on the books each month.\n\n"
        <<"I also want to do this for "<<friend_name<<", have you seen him lately is he even still over there?"<<"\n\n";
        if (friend_sex == 'm')cout<<"If you see "<<friend_name<<" please ask him to call me.\n\n";
        if (friend_sex == 'f')cout<<"If you see "<<friend_name<<" please ask her to call me.\n\n";
        if (age <= 18)error("you're kidding!");
        if (age == 0)error("you're kidding!");
        if (age >= 110)error("you're kidding!");
        if (age > 18)cout<<"I hear you just had a birthday and you are "<<age<<" years old."<<"\n\n";
        if (age < 21)cout<<"Next year you will be "<<age+1<<"\n\n";
        if (age == 22)cout<<"Next year you will be able to drink alcohol.\n\n";
        if (age > 70)cout<<"I hope you are enjoying every moment of it.\n\n";
    cout<<"Yours sincerely,\n"
        <<"Lukasz";
}

#include "std_lib_facilities.h"
int main() // C++ Programs start by executing the function main
{
    cout<<"Hello Compiler are u working?!\n";// output "Hello, World" "Here we go!"
    cout<<"Here we go!\n"; // output in a new line "Here we go!"
    cout<<"I will feed you instructions on how to get to the toilet now. Are you ready dummy?\n";
    cout<<"Let's define certain motions that I will not have to explain later on\n";
    cout<<"S = step, this is the moving action so once you take a step you move 1 meter in a specifc direction, SF = step-forward, you take one step forward, SB = step-backward, you take one backward step, SL = you take one step to the left, SR = you take on step to the right, SU = You take an upward step(this will be useful when climbing stairs), SD = You take a downward step when climbing down the stairs\n";
    cout<<"T = turn, assume the directions as for S for T, so TL = turn left, TR = Turn right, etc...\n";
    cout<<"Let's define the staircase and stairs: A staircase is a sequence of stairs from (1, 8). Meaning there are 8 stairs in a staircase. Each stair has a length of 0.5 steps and width of 0.25 steps. So stair_length=S*0.50 and stair_width=S*0.25\n";
    cout<<"Let's define the climb up the stair command lets call it cup=SF*0.49 & (SU*0.27) & S*.01. So what you do here is take a forward step for 0.49 meters and then lift your foot up or SU by 0.27 and then move forward 0.01 to land on the start of the next stair. The .27 or the two extra serve as a cuchion for your landing since you will move your foot downward as well.\n";
    cout<<"Now we will define locations as integers, Living room = 0, Stairway = 1, Hall = 2, Bathroom = 3\n";
    cout<<"Your domain is from {(0, 1), (1, 2), (3, 4)} and range is (0, 4)\n";
    cout<<"We start at 0 taking 5 SF and 1 TR so we take 5 steps forward and turn right once\n";
    cout<<"Nowe we execute cup command in sequence 8 times to get to location 3 which is the hall.\n";
    cout<<"One we get to location 3 we are going to execute TR once, SF 8 times, TL once and SF once.\n";
    cout<<"Ta da!!! Location 4 (bathroom) reached succesfully\n";

    keep_window_open();// wait for a character to be entered
    return 0;       
}

/***********************************************
    ICS4U Tony Tam Dec.20, 2019
    This program takes in any number of disks
    and completes the tower of hanoi
    it displays all of the stacks as it
    is happening as well
    warning: more than 10 disks may cause lag
************************************************/
#include "Hanoi.h"
#include "Allegro.h"
#include "Stack.h"


MyStack Peg[4];
int main(int argc, char *argv[]){

    int n = 10;  //n rigs (up to 6)
    int s = 1;  //source: from post 1
    int d = 3;  //destination: to post 3
    int i = 2;  //intermediate: through post 2

    //asks the user how many disks they want to solve for
    cout << "How many Disks do you want?: ";
    cin >> n;
    fflush(stdin);

    //fills the first peg with the disks
    for (float i = n; i >= 1; i--){
        Peg[s].push(i);
    }

    //initializes allegro addons
    InitializeAllegro();

    //displays the screen and automatically starts solving towers of hanoi on the display
    DisplayTitle(Screen_H, Screen_W, n, s, d, i);

    return 0;
}

//the function that actually does the solving, and updates the display through the use of AllegroDisplay()
void hanoi(int n,int s,int d,int i){ // move n rings from s to d using i
    int p = 0;
    if (p == 0){
        Peg[1].AllegroDisplay(1);
        Peg[2].AllegroDisplay(2);
        Peg[3].AllegroDisplay(3);
        p++;
    }
    if (n > 0){
        hanoi(n-1,s,i,d); // move n-1 rings from s to i using d
        relocate(n,s,d);
        al_clear_to_color(BLACK);
        Peg[1].AllegroDisplay(1);
        Peg[2].AllegroDisplay(2);
        Peg[3].AllegroDisplay(3);
        hanoi(n-1,i,d,s);
    }
}

//Moves a disk from one stack to another
void relocate(int n, int s, int d){
    float temp = 0;
    temp = Peg[s].pop();
    Peg[d].push(temp);
}

//moves the cursor of the console (used while doing the text only version of this code
void Go(int x, int y){
    HANDLE outhand = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD c;

    c.X = x;
    c.Y = y;

    SetConsoleCursorPosition(outhand, c);

}

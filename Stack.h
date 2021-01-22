#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
//my stack class
using namespace std;

struct Node{
    float n;
    Node *next;
};

void Go(int x, int y);

class MyStack{
    public:
        MyStack();
        void push(float f);
        float pop();
        bool isEmpty();
        float getTop();
        void displayStack(int x, int y);
        void displayStack();
        int NodeCount();
        bool isEnough();
        void AllegroDisplay(int PegNum, int DiskNum = 1);
    private:
        Node *head;
};




#endif // STACK_H_INCLUDED

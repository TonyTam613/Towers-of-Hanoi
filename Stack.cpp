#include "Stack.h"
#include "Allegro.h"

//My stack class methods
MyStack::MyStack(){
    head = nullptr;
}

void MyStack::push(float f){
      Node *tempNode = new Node;
      tempNode->n = f;
      tempNode->next = head;
      head = tempNode;
}

float MyStack::pop(){
    float f = head->n;
    head = head->next;
    return f;
}

bool MyStack::isEmpty(){
    return !head;
}

void MyStack::displayStack(int x, int y){
    if (!isEmpty()){
        float temp = pop();
        Go(x, y);
        cout << temp << endl;
        displayStack(x, y += 1);
        push(temp);
    }
}

void MyStack::displayStack(){
    if (!isEmpty()){
        float temp = pop();
        cout << temp << endl;
        displayStack();
        push(temp);
    }
}

int MyStack::NodeCount(){
    int nodeNum = 0;
    Node *tempNode;
    tempNode = head;
    for (int i = 0; i < 1000; i++){
        if (tempNode){
            nodeNum++;
            tempNode = tempNode->next;
        }else{
            break;
        }
    }
    return nodeNum;
}

bool MyStack::isEnough(){
    if (head && head->next){
        return true;
    }else{
        return false;
    }
}

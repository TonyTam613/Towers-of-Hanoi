#ifndef HANOI_H_INCLUDED
#define HANOI_H_INCLUDED

#include <iostream>
#include <windows.h>
#include <stdio.h>

//my hanoi function declarations
using namespace std;

void hanoi(int n,int s,int d,int i);
void relocate(int n, int s, int d);

#endif // HANOI_H_INCLUDED

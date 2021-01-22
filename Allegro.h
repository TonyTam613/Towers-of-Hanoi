#ifndef ALLEGRO_H_INCLUDED
#define ALLEGRO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <string.h>
#include <cstdio>
#include <time.h>

using namespace std;

#define PINK        al_map_rgb(255, 0, 255)
#define BLACK       al_map_rgb(0, 0, 0)
#define WHITE       al_map_rgb(255, 255, 255)
#define SLATEGREY   al_map_rgb(112,128,144)
#define FOREGROUND al_map_rgb(0x3C, 0x64, 0x78)

const int Screen_H = 580;
const int Screen_W = 1200;

struct Graphics {
    int XCoord;
    int YCoord;
    int leftBoarder;
    int rightBoarder;
    int topBoarder;
    int bottomBoarder;
    ALLEGRO_BITMAP *picture;
};

struct Users {
    char userName[50];
    int userScore;
};

void DisplayTitle(int Screen_H,int Screen_W, int n , int s, int d, int i);
void InitializeAllegro();
void MoveUpdate(int peg, int num, int height);


#endif // ALLEGRO_H_INCLUDED

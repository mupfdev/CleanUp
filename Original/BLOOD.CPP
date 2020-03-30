#include <graphics.h>
#include <math.h>
#include "header.h"

Blood::Blood(int nx,int ny,int ang,int stcol,int endcol,double spd,int sc) {
 x = nx;
 y = ny;
 Angle = ang;
 Color = stcol;
 EndColor = endcol;
 Speed = spd;
 SubCol = sc;
}

Blood::~Blood() {
 Draw(COL_BACKGROUND);
}

void Blood::Draw(int d) {
 putpixel(x + 1,y + 1,d);
 putpixel(x - 1,y - 1,d);
 putpixel(x - 1,y + 1,d);
 putpixel(x + 1,y - 1,d);
 putpixel(x - 2,y,d);
 putpixel(x + 2,y,d);
 putpixel(x,y + 2,d);
 putpixel(x,y - 2,d);
 putpixel(x,y,d);
}

void Blood::Idle() {
 Draw(0);
 x += sin(Angle * M_PI / 180) * Speed;
 y += cos(Angle * M_PI / 180) * Speed;
 Angle += random(11) - 5;
 if ((Speed -= 0.2) < 0) Speed = 0;
 if (!random(SubCol)) Color--;
 Draw(Color);
}

int Blood::Dead() {
 return Color <= EndColor;
}
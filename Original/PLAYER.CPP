#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include "header.h"

Player::Player() {
 B12 = 0;
 B9 = 0;
 Add12 = 25;
 Add9 = 10;
 Cx = Mouse::GetX();
 Cy = Mouse::GetY();
 LoadTime = 0;
}

Player::~Player() {
 Draw(0);
}

void Player::Draw(int d) {
 char tst[128];
 int schl1;

 setcolor(d ? COL_HUD : COL_BACKGROUND);
 settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
 settextjustify(LEFT_TEXT,BOTTOM_TEXT);
 sprintf(tst,"bullets (12mm): %d",B12);
 outtextxy(0,MAXY,tst);
 settextjustify(RIGHT_TEXT,BOTTOM_TEXT);
 sprintf(tst,"bullets (9mm): %d",B9);
 outtextxy(MAXX,MAXY,tst);
 setcolor(d ? COL_CROSSHAIR : COL_BACKGROUND);
 setlinestyle(SOLID_LINE,0,1);
 for (schl1 = 0;schl1 < 360;schl1 += 90)
  line(
   Cx + sin((CH_Angle + schl1) * M_PI / 180) * 10,
   Cy + cos((CH_Angle + schl1) * M_PI / 180) * 10,
   Cx + sin((CH_Angle + schl1) * M_PI / 180) * 20,
   Cy + cos((CH_Angle + schl1) * M_PI / 180) * 20
  );
}

void Player::Idle() {
 int schl1;

 Draw(0);
 if (Add9) {
  if ((B9 += 5) > 25000) B9 = 25000;
  Add9--;
 }
 if (Add12) {
  if ((++B12) > 1200) B12 = 1200;
  Add12--;
 }
 Cx = Mouse::GetX();
 Cy = Mouse::GetY();
 if ((CH_Angle += 5) >= 360) CH_Angle %= 360;
 if (LoadTime)
  LoadTime--;
 else {
  if (Mouse::GetKey(1))
   if (B12) {
    int tst = random(360);

    for (schl1 = 0;schl1 < 10;schl1++)
     Game::MainGroup -> AddObject(new Blood(Cx,Cy,tst + random(41) - 20,COL_FLOOR,COL_BLOOD + 1));
    for (schl1 = 0;schl1 < 20;schl1++)
     Game::MainGroup -> Attack(Cx - 5,Cy - 5,Cx + 5,Cy + 5);
    B12--;
    LoadTime = 20;
   }
  if (Mouse::GetKey(2))
   if (B9) {
    Game::MainGroup -> AddObject(new Blood(Cx,Cy,random(360),COL_FLOOR,COL_BLOOD + 1));
    Game::MainGroup -> Attack(Cx - 10,Cy - 10,Cx + 10,Cy + 10);
    B9--;
   }
 }
 Draw(1);
}

int Player::Dead() {
 return 0;
}

void Player::Message(int ms) {
 switch(ms) {
  case MSG_ENEMYDEAD:
   Draw(0);
   Add12 = 20;
   Add9 = 20;
 }
}
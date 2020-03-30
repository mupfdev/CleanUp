#include <graphics.h>
#include "header.h"

Enemy::Enemy() {
 x = random(MAXX + 1);
 y = random(MAXY + 1);
 Health = 20;
}

Enemy::~Enemy() {
 Draw(0);
}

void Enemy::Draw(int d) {
 setcolor(d ? COL_ENEMY : 0);
 setfillstyle(SOLID_FILL,getcolor());
 fillellipse(x,y,5,5);
}

void Enemy::Idle() {
 Draw(0);
 Draw(1);
}

int Enemy::Dead() {
 if (!Health) Game::MainGroup -> Message(MSG_ENEMYDEAD);
 return !Health;
}

void Enemy::Attack(int x1,int y1,int x2,int y2) {
 if (x >= x1)
  if (y >= y1)
   if (x <= x2)
    if (y <= y2) {
     int schl1;

     for (schl1 = 0;schl1 < 5;schl1++)
      Game::MainGroup -> AddObject(new Blood(x1 + x2 >> 1,y1 + y2 >> 1));
     Game::MainGroup -> AddObject(new Gib(x1 + x2 >> 1,y1 + y2 >> 1));
     if (Health) Health--;
    }
}
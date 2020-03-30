#include <math.h>
#include "header.h"

Gib::Gib(int nx,int ny,int ang) {
 x = nx;
 y = ny;
 Speed = random(100) / 10.0;
 Angle = ang;
 Health = 50;
}

void Gib::Idle() {
 Game::MainGroup -> AddObject(new Blood(x,y));
 if (Speed) {
  x += sin(Angle * M_PI / 180) * Speed;
  y += cos(Angle * M_PI / 180) * Speed;
  if ((Speed -= 0.2) < 0) Speed = 0;
 }
 Angle += 2;
 if (Health) Health--;
}

int Gib::Dead() {
 return !Health;
}
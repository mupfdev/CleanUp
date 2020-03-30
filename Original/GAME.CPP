#include <graphics.h>
#include <time.h>
#include "header.h"

Actor *Game::MainGroup = 0;

void game_initpal() {
 int schl1;

 for (schl1 = 1;schl1 <= 15;schl1++)
  setrgbpalette(schl1,schl1 * 1.25,0,0);
 for (schl1 = 0;schl1 <= 15;schl1++)
  setrgbpalette(schl1 + 16,schl1,schl1,schl1);
 setrgbpalette(COL_CROSSHAIR,63,7,0);
 setrgbpalette(COL_ENEMY,47,47,47);
 setrgbpalette(COL_HUD,31,31,31);
}

void Game::Init() {
 randomize();
 Mouse::Init();
 game_initpal();
 MainGroup = new Group();
}

void Game::Run() {
 clock_t tcl;

 MainGroup -> AddObject(new Player());
 while(Keyboard::GetKey() != KB_ESC) {
  tcl = clock();
  Keyboard::Idle();
  Mouse::Idle();
  if (!random(50)) MainGroup -> AddObject(new Enemy());
  MainGroup -> Idle();
  while(tcl == clock());
 }
}

void Game::Done() {
 delete MainGroup;
}
#include <graphics.h>
#include <stdio.h>
#include <bgi.h>
#include "header.h"

int huge gvm() {
 return 4;
}

int main() {
 int gd = DETECT,gm;

 installuserdriver("vesa",gvm);
 registerfarbgidriver(vesa_bgi);
 initgraph(&gd,&gm,"");
 Game::Init();
 Game::Run();
 Game::Done();
 closegraph();
 puts("MasterMind CleanUp");
 puts("written in Borland C++ 2.0 by Freak, MasterMind.\n");
 puts("MasterMind");
 puts(" Ertugrul \"Freak\" Soeylemez");
 puts(" Kemal \"SHOOTER\" Urgancioglu");
 return 0;
}
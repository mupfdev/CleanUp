#include <mouse.h>
#include "header.h"

int Mouse::xPos = 0;
int Mouse::yPos = 0;
int Mouse::Keys = 0;

void Mouse::Init() {
 m_test();
 m_setwindow(0,0,2046,767);
 m_setcursor(MAXX >> 2,MAXY >> 1);
}

void Mouse::Idle() {
 xPos = m_posx() >> 1;
 yPos = m_posy();
 Keys = m_key();
}

int Mouse::GetX() { return xPos; }
int Mouse::GetY() { return yPos; }
int Mouse::GetKey(int k) { return Keys & k; }
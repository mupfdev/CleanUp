#include <conio.h>
#include "header.h"

int Keyboard::Key = 0;

int kb_getkey() {
 asm MOV AH,0
 asm INT 16H
 asm MOV AL,AH
 asm MOV AH,0
 return _AX;
}

void Keyboard::Idle() {
 if (kbhit())
  Key = kb_getkey();
}

void Keyboard::Destruct() {
 Key = 0;
}

int Keyboard::GetKey() {
 return Key;
}
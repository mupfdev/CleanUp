#include "header.h"

Actor::Actor() {
 Next = 0;
}

Actor::~Actor() {}
void Actor::Idle() {}
int Actor::Dead() { return 1; }
void Actor::Message(int) {}
void Actor::AddObject(Actor *) {}
void Actor::Attack(int,int,int,int) {}
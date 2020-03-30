#include "header.h"

Group::Group() {
 Items = 0;
 Destructing = 0;
}

void Group::FreeList() {
 Actor *delent = Items;
 Actor *tmpent = (Items ? Items -> Next : 0);

 Destructing = 1;
 while(delent) {
  delete delent;
  delent = tmpent;
  if (tmpent) tmpent = tmpent -> Next;
 }
 Destructing = 0;
}

Group::~Group() {
 FreeList();
}

void Group::Idle() {
 Actor *tmpent = Items;
 Actor *last = 0;

 while(tmpent) {
  tmpent -> Idle();
  if (tmpent -> Dead())
   if (last) {
    last -> Next = tmpent -> Next;
    delete tmpent;
    tmpent = last -> Next;
    continue;
   } else {
    Items = Items -> Next;
    delete tmpent;
    tmpent = Items;
    continue;
   }
  last = tmpent;
  tmpent = tmpent -> Next;
 }
}

int Group::Dead() {
 return (Items ? 0 : 1);
}

void Group::Message(int ct) {
 Actor *tmpent = Items;

 while(tmpent) {
  tmpent -> Message(ct);
  tmpent = tmpent -> Next;
 }
}

void Group::AddObject(Actor *nw) {
 if (Destructing) return;

 Actor *tmpent = Items;

 if (!tmpent) {
  Items = nw;
  return;
 }
 while(tmpent -> Next)
  tmpent = tmpent -> Next;
 tmpent -> Next = nw;
}

void Group::Attack(int x1,int y1,int x2,int y2) {
 Actor *tmpent = Items;

 while(tmpent) {
  tmpent -> Attack(x1,y1,x2,y2);
  tmpent = tmpent -> Next;
 }
}
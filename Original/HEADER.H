#ifndef __PROJECT_CLEANUP_HEADER
#define __PROJECT_CLEANUP_HEADER

#include <stdlib.h>

class Actor;
class Group;
class Game;
class Keyboard;
class Mouse;

enum {
 MSG_ENEMYDEAD
};

enum {
 COL_BACKGROUND,
 COL_BLOOD = 15,
 COL_FLOOR = 31,
 COL_CROSSHAIR = 128,
 COL_ENEMY,
 COL_HUD
};

#define MAXX 1023
#define MAXY 767

#define KB_ESC 1

class Actor {
 friend Group;

 protected:
  Actor *Next;

 public:
  Actor();
  virtual ~Actor();
  virtual void Idle();
  virtual int Dead();
  virtual void Message(int);
  virtual void AddObject(Actor *);
  virtual void Attack(int,int,int,int);
};

class Group:public Actor {
 protected:
  Actor *Items;
  int Destructing;

  void FreeList();

 public:
  Group();
  ~Group();
  void Idle();
  int Dead();
  void Message(int);
  void AddObject(Actor *);
  void Attack(int,int,int,int);
};

class Player:public Actor {
 protected:
  int Cx,Cy;
  int B12;
  int B9;
  int LoadTime;
  int CH_Angle;
  int Add12,Add9;

  void Draw(int);

 public:
  Player();
  ~Player();
  void Idle();
  int Dead();
  void Message(int);
};

class Blood:public Actor {
 protected:
  double x,y;
  double Speed;
  int Angle;
  int Color;
  int EndColor;
  int SubCol;

  void Draw(int);

 public:
  Blood(int,int,int = random(360),int = COL_BLOOD,int = 0,double = random(100) / 30.0,int = 3);
  ~Blood();
  void Idle();
  int Dead();
};

class Enemy:public Actor {
 protected:
  double x,y;
  int Health;

  void Draw(int);

 public:
  Enemy();
  ~Enemy();
  void Idle();
  int Dead();
  void Attack(int,int,int,int);
};

class Gib:public Actor {
 protected:
  double x,y;
  double Speed;
  int Angle;
  int Health;

 public:
  Gib(int,int,int = random(360));
  void Idle();
  int Dead();
};

class Mouse {
 protected:
  static int xPos,yPos;
  static int Keys;

 public:
  static void Init();
  static void Idle();
  static int GetX();
  static int GetY();
  static int GetKey(int);
};

class Keyboard {
 protected:
  static int Key;

 public:
  static void Idle();
  static void Destruct();
  static int GetKey();
};

class Game {
 public:
  static Actor *MainGroup;

  static void Init();
  static void Run();
  static void Done();
};

#endif
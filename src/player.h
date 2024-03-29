#ifndef player_h
#define player_h

#include <Arduboy2.h>
#include "utils.h"
#include "gameobject.h"

const unsigned char PROGMEM PLAYER_SPRITE[] =
{
// width, height,
8, 8,
0x30, 0x48, 0x84, 0x82, 0x82, 0x84, 0x48, 0x30, 
};



class Player : public GameObject
{
private:
  Vector direction;

public:
  Player(Vector _position, Vector _direction) : GameObject(_position)
  {
    direction = _direction;
  }

  void update(Arduboy2 ab);
};

#endif
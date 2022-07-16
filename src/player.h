#ifndef player_h
#define player_h

#include <Arduboy2.h>
#include "utils.h"


class Player
{
private:
  Vector position;
  Vector direction;

public:
  Player(Vector _position, Vector _direction)
  {
    position = _position;
    direction = _direction;
  }

  void update(Arduboy2 ab);
  void setPosition(Vector _position);
  Vector *getPosition();
};

#endif
#ifndef ball_h
#define ball_h

#include <Arduboy2.h>
#include "utils.h"


class Ball
{
  private:
    Vector position;
    Vector direction;

  public:
    Ball(Vector _position, Vector _direction);
    void update(Arduboy2 ab);
    Vector *getPosition();
};

#endif
#ifndef ball_h
#define ball_h

#include <Arduboy2.h>
#include "utils.h"
#include "gameobject.h"


class Ball : public GameObject
{
  private:
    Vector direction;

  public:
    Ball(Vector _position, Vector _direction);
    void update(Arduboy2 ab);
};

#endif
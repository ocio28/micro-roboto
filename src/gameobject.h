#ifndef gameobject_h
#define gameobject_h

#include "utils.h"


class GameObject
{
  private:
    Vector position;

  public:
    GameObject(Vector _position);
    Vector *getPosition();
    void setPosition(Vector _position);
    void setX(int8_t _x);
    void setY(int8_t _y);
};

#endif
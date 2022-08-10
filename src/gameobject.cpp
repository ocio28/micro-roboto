#include "gameobject.h"


GameObject::GameObject(Vector _position)
{
  position = _position;
}

Vector *GameObject::getPosition()
{
  return &position;
}

void GameObject::setPosition(Vector _position)
{
  position = _position;
}

void GameObject::setX(int8_t _x)
{
  position.x = _x;
}

void GameObject::setY(int8_t _y)
{
  position.y = _y;
}
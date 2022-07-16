#include "ball.h"



Ball::Ball(Vector _position, Vector _direction)
{
  position = _position;
  direction = _direction;
}

void Ball::update(Arduboy2 ab)
{
  if (position.x < 0)
  {
    direction.x = 1;
  }
  if (position.x > 122)
  {
    direction.x = -1;
  }
  if (position.y < 0)
  {
    direction.y = 1;
  }
  if (position.y > 58)
  {
    direction.y = -1;
  }

  if (direction.x > 0)
  {
    position.x += 1;
  }
  else
  {
    position.x -= 1;
  }

  if (direction.y > 0)
  {
    position.y += 1;
  }
  else
  {
    position.y -= 1;
  }

  ab.fillRect(position.x, position.y, 6, 6, WHITE);
}

Vector *Ball::getPosition()
{
  return &position;
}
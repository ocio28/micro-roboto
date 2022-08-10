#include "player.h"



void Player::update(Arduboy2 ab)
{
  Vector *position = getPosition();

  if (ab.pressed(LEFT_BUTTON))
  {
    setX(position->x - 1);
  }

  if (ab.pressed(RIGHT_BUTTON))
  {
    setX(position->x + 1);
  }

  if (ab.pressed(UP_BUTTON))
  {
    setY(position->y - 1);
  }

  if (ab.pressed(DOWN_BUTTON))
  {
    setY(position->y + 1);
  }

  if (position->x < 0)
  {
    setX(0);
  }
  if (position->x > 120)
  {
    setX(120);
  }
  if (position->y < 0)
  {
    setY(0);
  }
  if (position->y > 56)
  {
    setY(56);
  }

  Sprites::drawOverwrite(position->x, position->y, PLAYER_SPRITE, 0);
}
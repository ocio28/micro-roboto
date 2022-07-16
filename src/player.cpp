#include "player.h"



const unsigned char PROGMEM player[] =
{
// width, height,
8, 8,
0x30, 0x48, 0x84, 0x82, 0x82, 0x84, 0x48, 0x30, 
};

void Player::update(Arduboy2 ab)
{
  if (ab.pressed(LEFT_BUTTON))
  {
    position.x -= 1;
  }

  if (ab.pressed(RIGHT_BUTTON))
  {
    position.x += 1;
  }

  if (ab.pressed(UP_BUTTON))
  {
    position.y -= 1;
  }

  if (ab.pressed(DOWN_BUTTON))
  {
    position.y += 1;
  }

  if (position.x < 0)
  {
    position.x = 0;
  }
  if (position.x > 120)
  {
    position.x = 120;
  }
  if (position.y < 0)
  {
    position.y = 0;
  }
  if (position.y > 56)
  {
    position.y = 56;
  }

  Sprites::drawOverwrite(position.x, position.y, player, 0);
}

Vector* Player::getPosition()
{
  return &position;
}

void Player::setPosition(Vector _position)
{
  position = _position;
}
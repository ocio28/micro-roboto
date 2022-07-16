#include <Arduboy2.h>

#include "src/player.h"
#include "src/ball.h"


Arduboy2 ab;

int game_state = 0;

Player player = Player({60, 50}, {1, 1});
Ball b1 = {{50, 20}, {1, 1}};
Ball b2 = {{10, 60}, {1, -1}};


void setup() {
  ab.begin();
  ab.setFrameRate(60);
  ab.clear();
}

void loop() {
  ab.clear();
  
  //Prevent the Arduboy from running too fast
  if (!ab.nextFrame()) {
    return;
  }

  switch (game_state) {
    case 0:
      title();
      break;

     case 1:
      gameplay();
      break;

     case 2:
      gameover();
      break;
  }
  
  ab.display();
}

void title()
{
  ab.setCursor(0, 0);
  ab.print("    micro roboto");
  ab.print("\n\n presiona un boton");

  if (ab.pressed(A_BUTTON) || ab.pressed(B_BUTTON))
  {
    game_state = 1;
    player.setPosition({60, 50});
    b1 = {{50, 20}, {1, 1}};
    b2 = {{10, 60}, {1, -1}};
  }
}

void gameplay()
{
  b1.update(ab);
  b2.update(ab);
  player.update(ab);

  Vector *position = player.getPosition();
  Vector *b1pos = b1.getPosition();
  Vector *b2pos = b2.getPosition();
  
  if (overlap(position->x, position->y, 8, 8, b1pos->x, b1pos->y, 6, 6) || overlap(position->x, position->y, 8, 8, b2pos->x, b2pos->y, 6, 6))
  {
    game_state = 2;
  }  
}

void gameover() {
  ab.setCursor(30, 30);
  ab.print("game over");

  if (ab.pressed(A_BUTTON) || ab.pressed(B_BUTTON)) {
    game_state = 0;
  }
}

bool overlap(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2)
{
  return (
      x1 < x2 + w2 &&
      x1 + w1 > x2 &&
      y1 < y2 + h2 &&
      y1 + h1 > y2);
}
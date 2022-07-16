#include <Arduboy2.h>

#include "src/utils.h"
#include "src/player.h"


struct Item {
   Vector pos;
   Vector dir;
};


Arduboy2 ab;

int game_state = 0;

Player player = Player({60, 50}, {1, 1});

Item ball;
Item ball2;


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
    ball_init(&ball, 50, 20, 1, 1);
    ball_init(&ball2, 10, 60, 1, -1);
  }
}

void gameplay()
{
  ball_update(&ball);
  ball_update(&ball2);

  player.update(ab);

  Vector *position = player.getPosition();
  //if (posx < ball_posx + 6 && posx + 8 > ball_posx && posy < ball_posy + 6 && posy + 8 > ball_posy) {
  if (overlap(position->x, position->y, 8, 8, ball.pos.x, ball.pos.y, 6, 6) || overlap(position->x, position->y, 8, 8, ball2.pos.x, ball2.pos.y, 6, 6))
  {
    game_state = 2;
  }

  ab.fillRect(ball.pos.x, ball.pos.y, 6, 6, WHITE);
  ab.fillRect(ball2.pos.x, ball2.pos.y, 6, 6, WHITE);
  
}

void gameover() {
  ab.setCursor(30, 30);
  ab.print("game over");

  if (ab.pressed(A_BUTTON) || ab.pressed(B_BUTTON)) {
    game_state = 0;
  }
}

void ball_init(struct Item *v, int8_t x, int8_t y, int8_t dirx, int8_t diry)
{
  v->pos = {x, y};
  v->dir = {dirx, diry};
}

void ball_update(struct Item *v) {
  if (v->pos.x < 0) {
    v->dir.x = 1;
  }
  if (v->pos.x > 122) {
    v->dir.x = -1;
  }
  if (v->pos.y < 0) {
    v->dir.y = 1;
  }
  if (v->pos.y > 58) {
    v->dir.y = -1;
  }

  if (v->dir.x > 0) {
    v->pos.x += 1;
  } else {
    v->pos.x -= 1;
  }

  if (v->dir.y > 0) {
    v->pos.y += 1;
  } else {
    v->pos.y -= 1;
  }
}

bool overlap(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2) {
  return (
    x1 < x2 + w2 &&
    x1 + w1 > x2 &&
    y1 < y2 + h2 &&
    y1 + h1 > y2
  );
}

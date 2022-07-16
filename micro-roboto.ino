#include <Arduboy2.h>

const unsigned char PROGMEM player[] =
{
// width, height,
8, 8,
0x30, 0x48, 0x84, 0x82, 0x82, 0x84, 0x48, 0x30, 
};

struct Vector {
  int8_t x = 0;
  int8_t y = 0;
};

struct Item {
   Vector pos;
   Vector dir;
};


Arduboy2 ab;

int game_state = 0;

int posx = 60;
int posy = 50;

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

void title() {
  ab.setCursor(0, 0);
  ab.print("    micro collect");
  ab.print("\n\n presiona un boton");

  if (ab.pressed(A_BUTTON) || ab.pressed(B_BUTTON)) {
    game_state = 1;
    posx = 60;
    posy = 50;
    ball_init(&ball, 50, 20, 1, 1);
    ball_init(&ball2, 10, 60, 1, -1);
  }
}

void gameplay() {
  if (ab.pressed(LEFT_BUTTON)) {
    posx -= 1;
  }

  if (ab.pressed(RIGHT_BUTTON)) {
    posx += 1;
  }

  if (ab.pressed(UP_BUTTON)) {
    posy -= 1;
  }

  if (ab.pressed(DOWN_BUTTON)) {
    posy += 1;
  }

  if (posx < 0) {
    posx = 0;
  }
  if (posx > 120) {
    posx = 120;
  }
  if (posy < 0) {
    posy = 0;
  }
  if (posy > 56) {
    posy = 56;
  }

  ball_update(&ball);
  ball_update(&ball2);

  //if (posx < ball_posx + 6 && posx + 8 > ball_posx && posy < ball_posy + 6 && posy + 8 > ball_posy) {
  if (overlap(posx, posy, 8, 8, ball.pos.x, ball.pos.y, 6, 6) || overlap(posx, posy, 8, 8, ball2.pos.x, ball2.pos.y, 6, 6)) {
    game_state = 2;
  }

  ab.fillRect(ball.pos.x, ball.pos.y, 6, 6, WHITE);
  ab.fillRect(ball2.pos.x, ball2.pos.y, 6, 6, WHITE);
  Sprites::drawOverwrite(posx, posy, player, 0);
}

void gameover() {
  ab.setCursor(30, 30);
  ab.print("game over");

  if (ab.pressed(A_BUTTON) || ab.pressed(B_BUTTON)) {
    game_state = 0;
  }
}

void ball_init(struct Item *v, int x, int y, int dirx, int diry) {
    v->pos.x = x;
    v->pos.y = y;
    v->dir.x = dirx;
    v->dir.y = diry;
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

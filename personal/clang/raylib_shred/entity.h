#ifndef ENTITY
#define ENTITY

#include "raylib.h"
#include <stdlib.h>

typedef struct EntityBase {
  Vector2 position;
  int size;
  int speed;
  int health;
} EntityBase;

typedef struct Enemy {
  EntityBase base;
} Enemy;

typedef struct Player {
  EntityBase base;
} Player;

Player *init_player();
Enemy* spawn_enemy();

#endif

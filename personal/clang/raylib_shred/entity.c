#include "entity.h"
Player *init_player() {
  Player *player = (Player *)malloc(sizeof(Player));
  player->base.position.x = 0;
  player->base.position.y = 0;
  player->base.speed = 500;
  player->base.health = 10;
  player->base.size = 20;

  return player;
}

Enemy* spawn_enemy() {

}


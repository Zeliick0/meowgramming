#include <raylib.h>
#include <stdio.h>
#include "list.h"

void handle_input(Player *player, float frameDelta) {
  Vector2 *pos = &player->base.position;
  int speed = player->base.speed;

  if (IsKeyDown(KEY_D)) {
    pos->x += (int)(speed * frameDelta);
  }

  if (IsKeyDown(KEY_A)) {
    pos->x -= (int)(speed * frameDelta);
  }

  if (IsKeyDown(KEY_W)) {
    pos->y -= (int)(speed * frameDelta);
  }

  if (IsKeyDown(KEY_S)) {
    pos->y += (int)(speed * frameDelta);
  }
}

void draw_player(Player *player) {
  EntityBase base = player->base;
  DrawRectangle(base.position.x, base.position.y, base.size, base.size, BLACK);
}

int main(void) {
  InitWindow(800, 600, "rekt");

  int monitorWidth = GetMonitorWidth(0);
  int monitorHeight = GetMonitorHeight(0);

  int screenWidth = (int)(monitorWidth * 0.8f);
  int screenHeight = (int)(monitorHeight * 0.8f);

  int windowPositionX = (int)(monitorWidth / 2 - screenWidth / 2);
  int windowPositionY = (int)(monitorHeight / 2 - screenHeight / 2);

  SetWindowSize(screenWidth, screenHeight);
  SetWindowPosition(windowPositionX, windowPositionY);

  SetTargetFPS(60);

  Player *player = init_player();

  while (!WindowShouldClose()) {
    float frameDelta = GetFrameTime();
    handle_input(player, frameDelta);

    BeginDrawing();

    ClearBackground(RAYWHITE);
    draw_player(player);

    EndDrawing();
  }

  CloseWindow(); // Close window and OpenGL context
  free(player);
  return 0;
}

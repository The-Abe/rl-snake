#include "gamestate.h"

#include <raylib.h>

#include "input.h"
#include "ui.h"

namespace snake {
void GameState::run_game() {
  InitWindow(800, 600, "Snake");
  SetTargetFPS(60);

  GameState gs = {.pause = true,
                  .processed_input = false,
                  .high_score = 0,
                  .score = 0,
                  .last_time = 0,
                  .snake = Snake::initialize_snake()};
  gs.foods.push_back(gs.spawn_food());
  while (!WindowShouldClose()) {
    // GetTime returns time in seconds, convert to milliseconds
    int time = static_cast<int>(GetTime() * 1000);
    Input::process_input(gs);
    gs.snake.move(gs, time);
    gs.snake.detect_collision(gs);
    Food::detect_eating(gs);

    // Draw
    BeginDrawing();
    ClearBackground(RAYWHITE);

    UI::draw_score(gs);
    UI::draw_explanation();
    UI::draw_grid();

    UI::draw_cross(gs.snake);
    gs.snake.draw();
    Food::draw(gs);

    if (gs.pause)
      UI::draw_pause();

    EndDrawing();
  }
}

void GameState::reset_score() {
  if (this->score > this->high_score) {
    this->high_score = this->score;
  }
  this->score = 0;
  this->foods = {this->spawn_food()};
  this->pause = true;
}

Food GameState::spawn_food() {
  // Check if there is space left for food.
  // Required because otherwise the recursion could run forever if the snake
  // fills the screen.
  if (this->snake.length >= 38 * 25) {
    return Food{-1, -1};
  }

  int x = GetRandomValue(0, 37);
  int y = GetRandomValue(0, 24);
  for (int i = this->snake.length - 1; i >= 0; i--) {
    if (x == this->snake.segments[i].x && y == this->snake.segments[i].y) {
      // If food spawns on the snake, try again
      return this->spawn_food();
    }
  }
  return Food{x, y};
}
} // namespace snake

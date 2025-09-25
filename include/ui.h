#pragma once

#include "snake.h"

namespace snake {
// Static UI related functions
class UI {
public:
  // Draw the current and high score
  static void draw_score(GameState &gs);

  // Draw the key bindings explanation
  static void draw_explanation();

  // Draw the pause screen if the game is paused
  static void draw_pause();

  // Draw the grid to make it easier to see the snake's movement
  static void draw_grid();

  // Draw a cross at the head of the snake to easily see the direction
  static void draw_cross(Snake &snake);
};
} // namespace snake

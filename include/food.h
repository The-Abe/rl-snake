#pragma once

namespace snake {
struct GameState;

// Represents a food item on the grid.
// Increases the score multiplier and the snake length when eaten.
class Food {
public:
  int x;
  int y;

  // Draw all food items on the screen.
  static void draw(GameState &gs);

  // Detect if the snake has eaten any food.
  // Spawn new food and increase snake length if so.
  static void detect_eating(GameState &gs);
};
} // namespace snake

#pragma once

#include <raylib.h>

#include "gamestate.h"

namespace snake {
// Helper enum for directions.
// Provides an easy way to map keys to directions.
enum class Direction { NONE, UP, RIGHT, DOWN, LEFT };

// Static class for handling user input.
class Input {
public:
  // Translates a key press to a Direction.
  // Allows multiple keys to map to the same direction.
  // Returns Direction::NONE if the key does not map to a direction.
  static Direction keymap(int key);

  // Returns the opposite direction of the given direction.
  // Makes it easy to prevent the snake from reversing into itself.
  static Direction opposite(Direction dir);

  // Processes input and updates the game state accordingly.
  static void process(GameState &gs);
};
} // namespace snake

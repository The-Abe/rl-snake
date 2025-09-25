#pragma once

#include <vector>

#include "food.h"
#include "snake.h"

namespace snake {
// Saves the state of the game.
// Has functions to run and reset the game .
class GameState {
public:
  bool pause = true; // Start the game paused
  bool processed_input = false; // To prevent multiple inputs in one frame
  // TODO: save high score to file
  int high_score = 0;
  int score = 0;
  int last_time = 0; // To control if the state should update yet
  Snake snake;
  // TODO: Spawn multiple foods for certain modes/events/scores
  std::vector<Food> foods{};

  // Initialize the game and run the game loop.
  static void run_game();

  // Reset the score and set the high score if needed.
  void reset_score();

  // Attempt to spawn food at a random location.
  // Takes the snake into account to avoid spawning food inside the snake.
  // Returns Food{-1, -1} if there is no space left (congratulations, you won!)
  Food spawn_food();
};
} // namespace snake

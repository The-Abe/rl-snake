#pragma once

namespace snake {
// A part of the snake's body
// x and y are the coordinates on the grid, not pixels
struct SnakeSegment {
  int x;
  int y;
};

// Forward declarations to prevent circular dependencies
enum class Direction;
struct GameState;

// The snake itself, contains segments, length, and direction
class Snake {
public:
  SnakeSegment segments[38*25]; // Can never be longer than the grid size
  int length; // Must be updated when segments change!
  Direction direction; // Current direction of movement

  // Build the initial snake at it's initial length and direction
  static Snake initialize_snake();

  // Draw the snake to the screen
  void draw();

  // Move the snake in the current direction if enough time has passed
  // Can be called every frame, but will only move the snake at a set interval
  void move(GameState &gs, int time);

  // Detect if the snake has collided with itself or the walls
  // Collision with food is handled in food.h
  void detect_collision(GameState &gs);
};

} // namespace snake

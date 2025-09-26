#include "snake.h"

#include <raylib.h>

#include "globals.h"
#include "input.h"
#include "ui.h"

namespace snake {
Snake Snake::initialize_snake() {
  Snake snake;
  snake.length = 5;
  snake.direction = Direction::RIGHT; // moving right
  for (int i = 0; i < snake.length; i++) {
    snake.segments[i].x = 5 - i;
    snake.segments[i].y = 12;
  }
  return snake;
}

void Snake::draw() {
  for (int i = 0; i < this->length; i++) {
    Color color = (i == 0) ? DARKGREEN : GREEN;
    DrawRectangle(18 + this->segments[i].x * grid_size,
                  50 + this->segments[i].y * grid_size, grid_size, grid_size,
                  color);
  }
}

void Snake::move(GameState &gs, int time) {
  if (gs.pause)
    return;

  if (time - gs.last_time < speed)
    return;

  gs.last_time = time;

  // Allow input to happen again after a move
  gs.processed_input = false;

  // Move the segments over 1 spot to keep the head as the first element
  for (int i = this->length - 1; i > 0; i--) {
    this->segments[i] = this->segments[i - 1];
  }
  switch (this->direction) {
  case Direction::UP:
    this->segments[0].y -= 1;
    break;
  case Direction::RIGHT:
    this->segments[0].x += 1;
    break;
  case Direction::DOWN:
    this->segments[0].y += 1;
    break;
  case Direction::LEFT:
    this->segments[0].x -= 1;
    break;
  default:
    break;
  }

  // Score is length - 4, so the initial length of 5 gives a score of 1
  gs.score += this->length - 4;
}

void Snake::detect_collision(GameState &gs) {
  SnakeSegment head = this->segments[0];
  if (head.x < 0 || head.x >= 38 || head.y < 0 || head.y >= 25) {
    // Reset snake position on collision with wall
    gs.snake = initialize_snake();
    gs.reset_score();
  }

  // We only check collision with itself from segment 1 onwards, so the head
  // doesn't collide with itself.
  for (int i = this->length - 1; i > 0; i--) {
    if (head.x == this->segments[i].x && head.y == this->segments[i].y) {
      // Reset snake position on collision with itself
      gs.snake = initialize_snake();
      gs.reset_score();
    }
  }
}

} // namespace snake

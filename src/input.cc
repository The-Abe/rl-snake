#include "input.h"

#include <raylib.h>

#include "snake.h"
#include "gamestate.h"

namespace snake {
Direction Input::keymap(int key) {
  switch (key) {
  case KEY_UP:
    return Direction::UP;
  case KEY_RIGHT:
    return Direction::RIGHT;
  case KEY_DOWN:
    return Direction::DOWN;
  case KEY_LEFT:
    return Direction::LEFT;
  case KEY_W:
    return Direction::UP;
  case KEY_D:
    return Direction::RIGHT;
  case KEY_S:
    return Direction::DOWN;
  case KEY_A:
    return Direction::LEFT;
  default:
    return Direction::NONE;
  }
}

Direction Input::opposite(Direction dir) {
  switch (dir) {
  case Direction::UP:
    return Direction::DOWN;
  case Direction::RIGHT:
    return Direction::LEFT;
  case Direction::DOWN:
    return Direction::UP;
  case Direction::LEFT:
    return Direction::RIGHT;
  default:
    return Direction::NONE;
  }
}

void Input::process(GameState &gs) {
  // Allow only one input per movement
  // move_snake will reset this flag
  if (gs.processed_input)
    return;

  Direction direction = keymap(GetKeyPressed());
  Direction opposite_direction = opposite(gs.snake.direction);
  if (direction == Direction::NONE || direction == opposite_direction)
    return;

  gs.snake.direction = direction;
  gs.pause = false;
  gs.processed_input = true;
}
} // namespace snake

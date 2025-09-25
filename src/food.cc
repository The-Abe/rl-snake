#include "food.h"

#include <raylib.h>
#include <vector>

#include "snake.h"
#include "globals.h"
#include "gamestate.h"

namespace snake {

void Food::draw_food(GameState &gs) {
  for (const auto &food : gs.foods) {
    DrawRectangle(18 + food.x * grid_size, 50 + food.y * grid_size, grid_size,
                  grid_size, RED);
  }
}

void Food::detect_eating(GameState &gs) {
  SnakeSegment head = gs.snake.segments[0];
  for (size_t i = 0; i < gs.foods.size(); i++) {
    if (head.x == gs.foods[i].x && head.y == gs.foods[i].y) {
      gs.snake.length += 1;
      // Add new segment at the position of the last segment
      // The segment position will be corrected in the next move update
      gs.snake.segments[gs.snake.length - 1] = gs.snake.segments[gs.snake.length - 2];
      
      gs.foods.erase(gs.foods.begin() + i);
      gs.foods.push_back(gs.spawn_food());
    }
  }
}
} // namespace snake

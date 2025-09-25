#include "ui.h"

#include <raylib.h>

#include <string>

#include "gamestate.h"
#include "globals.h"

namespace snake {
void UI::draw_score(GameState &gs) {
  auto score_text = "Score: " + std::to_string(gs.score) +
                    " Best: " + std::to_string(gs.high_score);
  DrawText(score_text.c_str(), 20, 17, 20, LIGHTGRAY);
}

void UI::draw_explanation() {
  const char *explanation = "Use arrow keys or WASD to move the snake";
  int x = 20;
  int y = 600 - 34;
  int width = MeasureText(explanation, 20);
  DrawText(explanation, 800 - width - 20, y, 20, LIGHTGRAY);
}

void UI::draw_pause() {
  const char *pause_text = "Press any arrow key or WASD to start";
  int width = MeasureText(pause_text, 20);
  DrawRectangle(grid_area.x, grid_area.y, grid_area.width, grid_area.height,
                Fade(BLACK, 0.2));
  DrawText(pause_text, (800 - width) / 2, (600 - 20) / 2, 20, RAYWHITE);
}
void UI::draw_grid() {
  DrawRectangleLinesEx(grid_area, 3.0, LIGHTGRAY);
  // Draw a checkerboard pattern
  for (int x = 0; x < 38; x++) {
    for (int y = 0; y < 25; y++) {
      if ((x + y) % 2 == 0) {
        DrawRectangle(18 + x * grid_size, 50 + y * grid_size, grid_size,
                      grid_size, Fade(LIGHTGRAY, 0.5));
      }
    }
  }
}

void UI::draw_cross(Snake &snake) {
  int x = snake.segments[0].x;
  int y = snake.segments[0].y;

  DrawRectangle(grid_area.x, grid_area.y + y * grid_size, grid_area.width,
                grid_size, Fade(BLUE, 0.2));
  DrawRectangle(grid_area.x + x * grid_size, grid_area.y, grid_size,
                grid_area.height, Fade(BLUE, 0.2));
}

} // namespace snake

// TODO: Move more magic numbers here.
#include <raylib.h>
namespace snake {
const int grid_size = 20; // Size of a cell in pixels.
const int speed = 100; // Delay between movement in milliseconds

// This area fits nicely in a 800x600 window with some padding for score text.
const Rectangle grid_area = {18, 50, grid_size * 38, grid_size * 25};
} // namespace snake

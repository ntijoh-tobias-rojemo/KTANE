#ifndef KTANE_MAZE_TICK
#define KTANE_MAZE_TICK

#include "global.h"

void resetMazePosition() {
  KTANE::currentMazePosition[0] = KTANE::finalModifiedValue / 100 % 10;
  KTANE::currentMazePosition[1] = KTANE::finalModifiedValue / 10 % 10;
}

#endif
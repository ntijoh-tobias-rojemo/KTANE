#include "global.h"

// 128x64 pixels

// Define a function for each pattern
// Functions are used over images to save space
bool horizontalLines(int x, int y) {
  if ((x/4)%2 == 0) {
    return true;
  }
  return false;
}
bool verticalLines(int x, int y) {
  if ((y/4)%2 == 0) {
    return true;
  }
  return false;
}
bool squareGrid(int x, int y) {
  if (x%8 == 0 || y%8 == 0) {
    return true;
  }
  return false;
}
bool diagonalLines(int x, int y) {
  if (((x-y)/4)%2 == 0) {
    return true;
  }
  return false;
}
bool concentricCircles(int x, int y) {
  const double xpart = 64-x; 
  const double ypart = 32-y;
  const int dist = sqrt(pow(xpart, 2) + pow(ypart, 2));
  if ((dist/4)%2 == 0) {
    return true;
  }
  return false;
}
bool squareWaves(int x, int y) {
  if (x%8 == 0) {
    if (y <= 44 && y >= 20) {
      return true;
    }
  }
  else if (((x/8)%2 == 0 && y == 44) || ((x/8)%2 == 1 && y == 20)) {
    return true;
  }
  return false;
}
bool concentricSquares(int x, int y) {
  return false;
}
bool checkerboard(int x, int y) {
  if (((x/4)%2-(y/4)%2)%2 == 0) {
    return true;
  }
  return false;
}
// The current position of the player in the maze
static MazePos currentMazePos;

// An array with all 7 waypoints
static MazePos waypoints[7];

#define f false // Wall
#define t true  // Open
// Array of maze (Up, Down, Left, Right)
static const bool mazeMap[10][10][4] = {
  {{f, t, t, f}, {t, f, f, t}, {f, t, t, f}, {f, f, f, t}, {t, f, t, t}, {f, t, t, f}, {t, t, f, t}, {f, f, t, f}, {f, t, f, f}, {f, t, f, t}},
  {{t, t, f, t}, {f, f, t, t}, {t, t, t, t}, {f, t, t, t}, {f, f, t, t}, {t, t, t, f}, {t, f, f, t}, {f, t, t, f}, {t, f, f, t}, {f, f, t, f}},
  {{t, t, f, f}, {f, t, f, f}, {t, t, f, f}, {t, f, f, t}, {f, t, t, f}, {t, f, f, t}, {f, t, t, t}, {t, t, t, t}, {f, t, t, f}, {t, t, f, f}},
  {{t, f, t, t}, {t, t, t, t}, {t, f, t, t}, {f, t, t, t}, {t, f, t, t}, {f, f, t, t}, {t, t, t, f}, {t, t, f, f}, {t, f, f, t}, {t, f, t, t}},
  {{f, t, f, t}, {t, t, t, f}, {f, t, f, t}, {t, f, t, t}, {f, f, t, f}, {f, t, f, f}, {t, t, f, t}, {t, f, t, t}, {f, t, t, f}, {f, t, f, f}},
  {{t, t, f, f}, {t, t, f, f}, {t, t, f, t}, {f, t, t, f}, {f, t, f, t}, {t, f, t, t}, {t, f, t, f}, {f, t, f, t}, {t, f, t, t}, {t, t, f, t}},
  {{t, t, t, f}, {t, t, f, t}, {t, f, t, f}, {t, t, f, t}, {t, f, t, t}, {f, t, t, f}, {f, t, f, t}, {t, t, t, f}, {f, t, f, t}, {t, f, t, t}},
  {{t, t, f, f}, {t, f, f, f}, {f, t, f, t}, {t, f, t, f}, {f, t, f, f}, {t, f, f, t}, {t, t, t, f}, {t, t, f, t}, {t, t, t, f}, {f, t, f, f}},
  {{t, f, f, t}, {f, f, t, t}, {t, t, t, f}, {f, t, f, t}, {t, f, t, f}, {f, t, f, t}, {t, t, t, t}, {t, f, t, f}, {t, f, f, t}, {t, f, t, f}},
  {{f, f, t, t}, {f, t, t, t}, {t, f, t, t}, {t, f, t, f}, {f, t, f, t}, {t, f, t, f}, {t, t, f, t}, {f, f, t, t}, {f, f, t, t}, {f, f, t, t}}
};

// The values of each colour
static const int waypointColourValues[6] = {3, 1, 6, 2, 4, 7};

// Calculates where the 7 waypoints are in the maze
void determineWaypoints() {
  for (int i = 1; i < 8; i++) { // The fake group is where i = 0, so we only run the loop for 1 through 7
    int value = 0;
    for (int j = 0; j < 3; j++) {
      value += waypointColourValues[ringRGB[(decoyGroupStart + i * 3 + j) % NEO_PIXEL_LENGTH]];
    }
    value += theValue % 10;
    waypoints[i].x = value / 10 % 10;
    waypoints[i].y = value % 10;
  }
}

// Resets the player to the start position in the maze, and resets all waypoints
void resetMazeProgress() {
  currentMazePos.x = theValue / 100 % 10;
  currentMazePos.y = theValue / 10 % 10;
  mazeStatus.wp0 = 0;
  mazeStatus.wp1 = 0;
  mazeStatus.wp2 = 0;
  mazeStatus.wp3 = 0;
  mazeStatus.wp4 = 0;
  mazeStatus.wp5 = 0;
  mazeStatus.wp6 = 0;
}

// Updates the players position in the maze
void updateMazePos() {
  // The position of the player before moving
  MazePos prevMazePos;
  prevMazePos.x = currentMazePos.x;
  prevMazePos.y = currentMazePos.y;

  // Move if button is pressed
  // If trying to move into a wall, set waypoint 0 status to 2 as that has the same effect as a variable to not accept completion if a wall has been hit
  if (buttonStatus.up == RISING) {
    if (mazeMap[currentMazePos.y][currentMazePos.x][UP]) {
      currentMazePos.y--;
    } else {
      mazeStatus.wp0 = 2;
    }
  } else if (buttonStatus.down == RISING) {
    if (mazeMap[currentMazePos.y][currentMazePos.x][DOWN]) {
      currentMazePos.y++;
    } else {
      mazeStatus.wp0 = 2;
    }
  } else if (buttonStatus.left == RISING) {
    if (mazeMap[currentMazePos.y][currentMazePos.x][LEFT]) {
      currentMazePos.x--;
    } else {
      mazeStatus.wp0 = 2;
    }
  } else if (buttonStatus.right == RISING) {
    if (mazeMap[currentMazePos.y][currentMazePos.x][RIGHT]) {
      currentMazePos.x++;
    } else {
      mazeStatus.wp0 = 2;
    }
  }

  // Correct position if warp
  currentMazePos.x = (currentMazePos.x + 10) % 10;
  currentMazePos.y = (currentMazePos.y + 10) % 10;

  // Update waypoints if moved
  if (prevMazePos.x != currentMazePos.x || prevMazePos.y != currentMazePos.y) {
    // For each waypoint
    for (int i = 0; i < 7; i++) {
      if (waypoints[i].x == currentMazePos.x && waypoints[i].y == currentMazePos.y) {
        switch (i) {
          case 0: if (mazeStatus.wp0 == 0) {
              mazeStatus.wp0 = 1;
            } else {
              mazeStatus.wp0 = 2;
            }
            break;
          case 1: if (mazeStatus.wp1 == 0) {
              mazeStatus.wp1 = 1;
            } else {
              mazeStatus.wp1 = 2;
            }
            break;
          case 2: if (mazeStatus.wp2 == 0) {
              mazeStatus.wp2 = 1;
            } else {
              mazeStatus.wp2 = 2;
            }
            break;
          case 3: if (mazeStatus.wp3 == 0) {
              mazeStatus.wp3 = 1;
            } else {
              mazeStatus.wp3 = 2;
            }
            break;
          case 4: if (mazeStatus.wp4 == 0) {
              mazeStatus.wp4 = 1;
            } else {
              mazeStatus.wp4 = 2;
            }
            break;
          case 5: if (mazeStatus.wp5 == 0) {
              mazeStatus.wp5 = 1;
            } else {
              mazeStatus.wp5 = 2;
            }
            break;
          case 6: if (mazeStatus.wp6 == 0) {
              mazeStatus.wp6 = 1;
            } else {
              mazeStatus.wp6 = 2;
            }
            break;
        }
      }
    }
  }

  // Check if all waypoints have been passed exactly once
  if (mazeStatus.wp0 == 1 &&
      mazeStatus.wp1 == 1 &&
      mazeStatus.wp2 == 1 &&
      mazeStatus.wp3 == 1 &&
      mazeStatus.wp4 == 1 &&
      mazeStatus.wp5 == 1 &&
      mazeStatus.wp6 == 1
     ) {
    mazeStatus.solved = true;
  }
}

#include <iostream>
using namespace std;

struct MazeSpace {
  bool up : 1;
  bool down : 1;
  bool left : 1;
  bool right : 1;
};

struct DoubleMazeSpace {
  bool up0 : 1;
  bool down0 : 1;
  bool left0 : 1;
  bool right0 : 1;
  bool up1 : 1;
  bool down1 : 1;
  bool left1 : 1;
  bool right1 : 1;
};

/*
struct MazeRow {
  MazeSpace s0;
  MazeSpace s1;
  MazeSpace s2;
  MazeSpace s3;
  MazeSpace s4;
  MazeSpace s5;
  MazeSpace s6;
  MazeSpace s7;
  MazeSpace s8;
  MazeSpace s9;
};
*/

struct MazeRow {
  DoubleMazeSpace s0;
  DoubleMazeSpace s2;
  DoubleMazeSpace s4;
  DoubleMazeSpace s6;
  DoubleMazeSpace s8;
};

struct MazeMap {
  MazeRow r0;
  MazeRow r1;
  MazeRow r2;
  MazeRow r3;
  MazeRow r4;
  MazeRow r5;
  MazeRow r6;
  MazeRow r7;
  MazeRow r8;
  MazeRow r9;
};

int main() {
  cout << sizeof mazeMap << endl;
}



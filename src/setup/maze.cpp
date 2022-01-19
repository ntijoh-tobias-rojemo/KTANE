#include "global.h"

#define f false
#define t true
// Array of maze (Up, Down, Left, Right)
static const bool mazeMap[10][10][4] = {
  {{f,t,t,f},{t,f,f,t},{f,t,t,f},{f,f,f,t},{t,f,t,t},{f,t,t,f},{t,t,f,t},{f,f,t,f},{f,t,f,f},{f,t,f,t}},
  {{t,t,f,t},{f,f,t,t},{t,t,t,t},{f,t,t,t},{f,f,t,t},{t,t,t,f},{t,f,f,t},{f,t,t,f},{t,f,f,t},{f,f,t,f}},
  {{t,t,f,f},{f,t,f,f},{t,t,f,f},{t,f,f,t},{f,t,t,f},{t,f,f,t},{f,t,t,t},{t,t,t,t},{f,t,t,f},{t,t,f,f}},
  {{t,f,t,t},{t,t,t,t},{t,f,t,t},{f,t,t,t},{t,f,t,t},{f,f,t,t},{t,t,t,f},{t,t,f,f},{t,f,f,t},{t,f,t,t}},
  {{f,t,f,t},{t,t,t,f},{f,t,f,t},{t,f,t,t},{f,f,t,f},{f,t,f,f},{t,t,f,t},{t,f,t,t},{f,t,t,f},{f,t,f,f}},
  {{t,t,f,f},{t,t,f,f},{t,t,f,t},{f,t,t,f},{f,t,f,t},{t,f,t,t},{t,f,t,f},{f,t,f,t},{t,f,t,t},{t,t,f,t}},
  {{t,t,t,f},{t,t,f,t},{t,f,t,f},{t,t,f,t},{t,f,t,t},{f,t,t,f},{f,t,f,t},{t,t,t,f},{f,t,f,t},{t,f,t,t}},
  {{t,t,f,f},{t,f,f,f},{f,t,f,t},{t,f,t,f},{f,t,f,f},{t,f,f,t},{t,t,t,f},{t,t,f,t},{t,t,t,f},{f,t,f,f}},
  {{t,f,f,t},{f,f,t,t},{t,t,t,f},{f,t,f,t},{t,f,t,f},{f,t,f,t},{t,t,t,t},{t,f,t,f},{t,f,f,t},{t,f,t,f}},
  {{f,f,t,t},{f,t,t,t},{t,f,t,t},{t,f,t,f},{f,t,f,t},{t,f,t,f},{t,t,f,t},{f,f,t,t},{f,f,t,t},{f,f,t,t}}
};
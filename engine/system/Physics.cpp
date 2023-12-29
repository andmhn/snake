#include "Physics.h"

bool DoBoxesIntersect(cBoundingBox * a, cBoundingBox * b) {
  int deltax = abs(a->x - b->x);
  int deltay = abs(a->y - b->y);
  return (deltax * 2 < (a->width + b->width)) &&
         (deltay * 2 < (a->height + b->height));
}

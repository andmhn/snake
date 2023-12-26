#include "Physics.h"

bool DoBoxesIntersect(cBoundingBox a, cBoundingBox b) {
  int deltax = abs(a.x - b.x);
  return (deltax * 2 < (a.width + b.width)) &&
         (deltax * 2 < (a.height + b.height));
}

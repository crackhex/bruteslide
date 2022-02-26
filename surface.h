#ifndef BRUTESLIDE_SURFACE_H
#define BRUTESLIDE_SURFACE_H

#include "types.h"
int ptInTriangle(f32 p[3], s16 p0[3], s16 p1[3], s16 p2[3]);
struct Surface *read_surface_data(s16 **vertexData[], s16 triNum);
struct Surface * check_mario_surface(f32 mPos[3], s16 **vertexData[], s16 numTris);
#endif //BRUTESLIDE_SURFACE_H

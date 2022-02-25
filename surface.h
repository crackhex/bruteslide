#ifndef BRUTESLIDE_SURFACE_H
#define BRUTESLIDE_SURFACE_H

#include "types.h"
int ptInTriangle(f32 p[3], s16 *p0, s16 *p1, s16 *p2);
struct Surface * read_surface_data(s16 **vertexData[], s16 triNum);
#endif //BRUTESLIDE_SURFACE_H

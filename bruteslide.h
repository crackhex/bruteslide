#ifndef BRUTESLIDE_BRUTESLIDE_H
#define BRUTESLIDE_BRUTESLIDE_H

#include "types.h"

int ptInTriangle(f32 p[3], f32 p0[3], f32 p1[3], f32 p2[3]);
void update_sliding_angle(struct MarioState *m, f32 accel, f32 lossFactor);
s32 update_sliding(struct MarioState *m, f32 stopSpeed);
#endif //BRUTESLIDE_BRUTESLIDE_H

#ifndef BRUTESLIDE_BRUTESLIDE_H
#define BRUTESLIDE_BRUTESLIDE_H

#include "types.h"

void update_sliding_angle(struct MarioState *m, f32 accel, f32 lossFactor);
s32 update_sliding(struct MarioState *m, f32 stopSpeed);
#endif //BRUTESLIDE_BRUTESLIDE_H

#ifndef BRUTESLIDE_MARIO_H
#define BRUTESLIDE_MARIO_H

#include "types.h"

void mario_set_forward_vel(struct MarioState *m, f32 forwardVel);
void update_mario_joystick_inputs(struct MarioState *m);
s32 perform_ground_quarter_step(struct MarioState *m, f32 nextPos[3]);
s32 perform_ground_step(struct MarioState *m);
#endif //BRUTESLIDE_MARIO_H

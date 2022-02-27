#include "types.h"
#include "maths.h"
#include <math.h>
#include "surface.h"

void mario_set_forward_vel(struct MarioState *m, f32 forwardVel) {
    m->forwardVel = forwardVel;

    m->slideVelX = sins(m->faceAngle[1]) * m->forwardVel;
    m->slideVelZ = coss(m->faceAngle[1]) * m->forwardVel;

    m->vel[0] = (f32) m->slideVelX;
    m->vel[2] = (f32) m->slideVelZ;
}

void update_mario_joystick_inputs(struct MarioState *m) {
    struct Controller *controller = m->controller;
    controller->stickMag = sqrtf(controller->stickX * controller->stickX + controller->stickY * controller->stickY);
    f32 mag = ((controller->stickMag / 64.0f) * (controller->stickMag / 64.0f)) * 64.0f;


    m->intendedMag = mag / 2.0f;


    if (m->intendedMag > 0.0f) {
        m->intendedYaw = atan2s(-controller->stickY, controller->stickX) + (s16) 8192; //! make camera diagonal for best sliding opportunities
    } else {
        m->intendedYaw = m->faceAngle[1];
    }
}

s32 perform_ground_quarter_step(struct MarioState *m, f32 nextPos[3]) {
    //UNUSED struct Surface *lowerWall;
    struct Surface *upperWall;
    struct Surface *ceil;
    struct Surface *floor;
    f32 ceilHeight;
    f32 floorHeight;
    f32 waterLevel;

    floor = m->floor;
    floorHeight = find_floor_height(floor, (s32) nextPos[0], (s32) nextPos[1], (s32) nextPos[2]);
    // ceilHeight = vec3f_find_ceil(nextPos, floorHeight, &ceil);

    // waterLevel = find_water_level(nextPos[0], nextPos[2]);

    // m->wall = upperWall;


    if (nextPos[1] > floorHeight + 100.0f) {
        vec3f_copy(nextPos,m->pos);
        m->floor = floor;
        m->floorHeight = floorHeight;
        return 0;
    }


    vec3f_set(m->pos, nextPos[0], floorHeight, nextPos[2]);
    m->floor = floor;
    m->floorHeight = floorHeight;


    return 1;
}

s32 perform_ground_step(struct MarioState *m) {
    s32 i;
    u32 stepResult;
    f32 intendedPos[3];

    for (i = 0; i < 4; i++) {
        intendedPos[0] = m->pos[0] + m->floor->normal.y * (m->vel[0] / 4.0f);
        intendedPos[2] = m->pos[2] + m->floor->normal.y * (m->vel[2] / 4.0f);
        intendedPos[1] = m->pos[1];

        stepResult = perform_ground_quarter_step(m, intendedPos);
        if (stepResult == 0 /*|| stepResult == GROUND_STEP_HIT_WALL_STOP_QSTEPS*/ ) {
            break;
        }
    }
    return stepResult;
}
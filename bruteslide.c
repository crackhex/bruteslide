#include "types.h"
#include "trig_table.inc.c"

void update_sliding_angle(struct MarioState* m, float accel, float lossFactor) {
    int newFacingDYaw;
    int facingDYaw;

    struct Surface* floor = m->floor;
    int slopeAngle = atan2(floor->normal.z, floor->normal.x);
    float steepness = sqrtf(floor->normal.x * floor->normal.x + floor->normal.z * floor->normal.z);
    float normalY = floor->normal.y;

    m->slideVelX += accel * steepness * sin(slopeAngle);
    m->slideVelZ += accel * steepness * cos(slopeAngle);

    m->slideVelX *= lossFactor;
    m->slideVelZ *= lossFactor;

    m->slideYaw = atan2(m->slideVelZ, m->slideVelX);

    facingDYaw = m->faceAngle[1] - m->slideYaw;
    newFacingDYaw = facingDYaw;

    //! -0x4000 not handled - can slide down a slope while facing perpendicular to it
    if (newFacingDYaw > 0 && newFacingDYaw <= 0x4000) {
        if ((newFacingDYaw -= 0x200) < 0) {
            newFacingDYaw = 0;
        }
    }
    else if (newFacingDYaw > -0x4000 && newFacingDYaw < 0) {
        if ((newFacingDYaw += 0x200) > 0) {
            newFacingDYaw = 0;
        }
    }
    else if (newFacingDYaw > 0x4000 && newFacingDYaw < 0x8000) {
        if ((newFacingDYaw += 0x200) > 0x8000) {
            newFacingDYaw = 0x8000;
        }
    }
    else if (newFacingDYaw > -0x8000 && newFacingDYaw < -0x4000) {
        if ((newFacingDYaw -= 0x200) < -0x8000) {
            newFacingDYaw = -0x8000;
        }
    }
}
int update_sliding(struct MarioState* m, float stopSpeed) {
    float lossFactor;
    float accel;
    float oldSpeed;
    float newSpeed;

    int stopped = 0;

    int intendedDYaw = m->intendedYaw - m->slideYaw;
    float forward = cos(intendedDYaw);
    float sideward = sin(intendedDYaw);

    //! 10k glitch
    if (forward < 0.0 && m->forwardVel >= 0.0) {
        forward *= 0.5 + 0.5 * m->forwardVel / 100.0;
    }


    accel = 7.0f;
    lossFactor = m->intendedMag / 32.0f * forward * 0.02f + 0.92f;


    oldSpeed = sqrt(m->slideVelX * m->slideVelX + m->slideVelZ * m->slideVelZ);

    //! This is attempting to use trig derivatives to rotate Mario's speed.
    // It is slightly off/asymmetric since it uses the new X speed, but the old
    // Z speed.
    m->slideVelX += m->slideVelZ * (m->intendedMag / 32.0f) * sideward * 0.05f;
    m->slideVelZ -= m->slideVelX * (m->intendedMag / 32.0f) * sideward * 0.05f;

    newSpeed = sqrtf(m->slideVelX * m->slideVelX + m->slideVelZ * m->slideVelZ);

    if (oldSpeed > 0.0f && newSpeed > 0.0f) {
        m->slideVelX = m->slideVelX * oldSpeed / newSpeed;
        m->slideVelZ = m->slideVelZ * oldSpeed / newSpeed;
    }

    update_sliding_angle(m, accel, lossFactor);


    return stopped;
}

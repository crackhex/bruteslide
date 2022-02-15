#ifndef TYPES_H
#define TYPES_H

struct Surface {
    int Vertex1[3];
    int Vertex2[3];
    int Vertex3[3];
    struct {
        float x;
        float y;
        float z;
    } normal;
    /*0x28*/ float originOffset;
    /*0x2C*/ struct Object* object;
};
struct MarioState {
    float mPos[3];
    int intendedYaw;
    int slideYaw;
    float forwardVel;
    float intendedMag;
    float slideVelX;
    float slideVelZ;
    struct Surface* floor;
    int faceAngle[3];
};

#endif
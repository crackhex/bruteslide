#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "bruteslide.h"
#include "mario.h"
#include "surface.h"
//! Define triangle points   (CHANGE)

//s16 tri1[3][3] = { {6144, 1024, 6144}, {7168, 2458, 8192}, {6144, 1024, -1535} };
s16 tri1[3][3] = {{-5375,0,6464},{-5842,128,6248},{-6015,0,6464}};
s16 tri2[3][3] = { {4144, 1024, 6144}, {4168, 2458, 8192}, {6144, 1024, -1535} };
s16 numTris = 2;
s16 *triList[3][3];




//! Number of frames for sliding   (CHANGE)
int frames = 10;

//! Define Mario's position and hspd    (CHANGE)
f32 mPos[3] = {-5841.02685546875f, 55.1111145019531f, 6371.7158203125f};//{6309, 1255, 1336};
f32 vel = 0.0f;//50.131f;
s16 faceAngle = 23159;//14;


int main() {
    //! Defining structs
    struct MarioState *m;
    m = malloc(sizeof(struct MarioState));
    struct Surface *surfList[numTris];
    struct Surface *surface;
    struct Controller *controller;
    //surface = read_surface_data((s16 ***) **triList, 0);

    //! add tris to list

    *triList[0] = *tri1;// *triList[1] = *tri2;
    for (int i = 0; i < numTris; i++) {

        //numSurfaces = sizeof vertexData / sizeof *vertexData;
        surfList[i] = read_surface_data((s16 ***) **triList, i);

        //surface->type = surfaceType;
    }    //m->floor = surface;


    //! Set mario's variables to starting
    m->pos[0] = mPos[0]; m->pos[1] = mPos[1]; m->pos[2] = mPos[2];
    mario_set_forward_vel(m, vel);
    m->faceAngle[1] = faceAngle;
    //! Testing if mario is in triangle
    //printf("%f\n", m->forwardVel);
    for ( int i = 0; i < frames; i++) {
        m->intendedMag = 0.0f;
        m->intendedYaw = 0;
        //m->controller->stickMag = 0.0f;
        //m->controller->stickX = 0.0f;
        //m->controller->stickY = 0.0f;


        //printf("%f\n", m->pos[0]);
        surface = check_mario_surface(mPos, surfList, numTris);
        //printf("%i\n", ptInTriangle(m->pos, surface->vertex1, surface->vertex2, surface->vertex3));
        m->floor = surface;
        //printf("%f\n", m->intendedMag);
        update_sliding(m, 4.0f);
        perform_ground_step(m);
        printf("%f\n", m->pos[2]);
        //printf("%i\n", m->floor->vertex2[0]);
        //printf("%i\n", m->slideYaw);
        //update_sliding_angle(m, 2, 2);

        //update_sliding(m, 0);
        //printf("%f\n", m->pos[0]);

    }

}

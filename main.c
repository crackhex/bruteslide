#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "bruteslide.h"
#include "surface.h"
//! Define the struct


//! Define triangle points

s16 tri1[3][3] = { {6144, 1024, 6144}, {7168, 2458, 8192}, {6144, 1024, -1535} };
s16 tri2[3][3] = { {4144, 1024, 6144}, {4168, 2458, 8192}, {6144, 1024, -1535} };
s16 numTris = 2;
s16 *triList[3][3];


//! Number of frames for sliding
int frames = 10;

//! Define Mario's position and hspd
f32 mPos[3] = {6309, 1255, 1336};



int main() {
    //! add tris to lis
    *triList[0] = *tri1; *triList[1] = *tri2;


    //! Defining structs
    struct MarioState *m;
    m = malloc(sizeof(struct MarioState));
    struct Surface *surface;
    //surface = read_surface_data((s16 ***) **triList, 0);

    //m->floor = surface;


    //! Set mario's variables to starting
    m->pos[0] = mPos[0]; m->pos[1] = mPos[1]; m->pos[2] = mPos[2];

    //! Testing if mario is in triangle

    int i;

    for ( i = 0; i < frames; i++) {
        surface = check_mario_surface(mPos, (s16 ***) **triList, numTris);
        //printf("%i\n", ptInTriangle(mPos, surface->vertex1, surface->vertex2, surface->vertex3));
        m->floor = surface;
        //printf("%i\n", m->floor->vertex2[0]);
        //printf("%i\n", m->slideYaw);
        //update_sliding_angle(m, 2, 2);

        //update_sliding(m, 0);
        //printf("%f\n", m->pos[0]);

    }

}

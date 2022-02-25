#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "bruteslide.h"
#include "surface.h"
//#include "surface.c"
//! Define the struct


//! Define triangle points

s16 tri1[3][3] = { {6144, 1024, 6144}, {7168, 2458, 8192}, {6144, 1024, -1535} };
s16 tri2[3][3] = { {6144, 1024, 6144}, {7168, 2458, 8192}, {6144, 1024, -1535} };
s16 *triList[];

s16 triNum = 0;

//! Number of frames for sliding
int frames = 10;

//! Define Mario's position and hspd
f32 mPos[3] = {6255, 1245, 7833};


int main() {

    triList[0] = *tri1; triList[1] = *tri2;
    //! Defining structs
    struct MarioState *m = malloc(sizeof(struct MarioState));;
    struct Surface *surface;
    surface = read_surface_data((s16 **) *triList, triNum);
    m->floor = surface;


    //! Set mario's coordinates to desired
    m->pos[0] = mPos[0]; m->pos[1] = mPos[1]; m->pos[2] = mPos[2];

    //! Testing if mario is in triangle

    int i;
    for ( i = 0; i < frames; i++) {

        if (ptInTriangle(mPos, &triList[0][0], &triList[0][1], &triList[0][2]) == 1) {
            //! Set triangle points as mario's floor
            surface->vertex1[0] = tri1[0][0]; surface->vertex1[1] = tri1[0][1]; surface->vertex1[2] = tri1[0][2];
            surface->vertex2[0] = tri1[1][0]; surface->vertex2[1] = tri1[1][1]; surface->vertex2[2] = tri1[1][2];
            surface->vertex3[0] = tri1[2][0]; surface->vertex3[1] = tri1[2][1]; surface->vertex3[2] = tri1[2][2];
        }

    }

}

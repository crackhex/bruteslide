#include <stdio.h>
//#include "types.h"
#include "maths.h"
#include "bruteslide.h"

//! Define the struct


//! Define triangle points
int p1[3] = { 6144, 1024, 6144 };
int p2[3] = { 7168, 2458, 8192 };
int p3[3] = { 6144, 1024, -1535 };

//! Number of frames for sliding
int frames = 10;

//! Define Mario's position and hspd
int mPos[3] = {6255, 1245, 7833};


int main() {

    //! Defining structs
    struct MarioState* m;
    struct Surface* tri = m->floor;

    //! Set mario's coordinates to desired
    m->pos[0] = mPos[0]; m->pos[1] = mPos[1]; m->pos[2] = mPos[2];

    //! Testing if mario is in triangle
    if (ptInTriangle(mPos, p1, p2, p3) == 0) {

    }

    //! Set triangle points as mario's floor, may be moved in a loop at some point
    tri->vertex1[0] = p1[0]; tri->vertex1[1] = p1[1]; tri->vertex1[2] = p1[2];
    tri->vertex2[0] = p2[0]; tri->vertex2[1] = p2[1]; tri->vertex2[2] = p2[2];
    tri->vertex3[0] = p3[0]; tri->vertex3[1] = p3[1]; tri->vertex3[2] = p3[2];


}

#include <stdio.h>
//#include "types.h"
#include "maths.h"
//#include "bruteslide.c"

int main() {
    s16 x = atan2s(1111.10, 1230.10);
    printf("%i \n", x);//
    int p1[3] = { 6144, 1024, 6144 };
    int p2[3] = { 7168, 2458, 8192 };
    int p3[3] = { 6144, 1024, -1535 };
    struct MarioState* ns;
    struct Surface* tri = ns->floor;
    tri->vertex1[0] = p1[0]; tri->vertex1[1] = p1[1]; tri->vertex1[2] = p1[2];
    tri->vertex2[0] = p2[0]; tri->vertex2[1] = p2[1]; tri->vertex2[2] = p2[2];
    tri->vertex3[0] = p3[0]; tri->vertex3[1] = p3[1]; tri->vertex3[2] = p3[2];

    ns->mPos[0] = 3;

}

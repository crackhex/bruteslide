#include <stdio.h>
#include "bruteslide.c"

int main() {
    int p1[3] = { 6144, 1024, 6144 };
    int p2[3] = { 7168, 2458, 8192 };
    int p3[3] = { 6144, 1024, -1535 };
    struct MarioState* ns;
    struct Surface* tri = ns->floor;
    tri->Vertex1[0] = p1[0]; tri->Vertex1[1] = p1[1]; tri->Vertex1[2] = p1[2];
    tri->Vertex2[0] = p2[0]; tri->Vertex2[1] = p2[1]; tri->Vertex2[2] = p2[2];
    tri->Vertex3[0] = p3[0]; tri->Vertex3[1] = p3[1]; tri->Vertex3[2] = p3[2];

    ns->mPos[0] = 3;
}

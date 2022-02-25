#include "types.h"
#include <math.h>
#include <stdlib.h>

struct Surface * read_surface_data(s16 vertexData[][3][3], s16 triNum) {
    struct Surface *surface = malloc(sizeof(struct Surface)); ;
    s32 x1, y1, z1;
    s32 x2, y2, z2;
    s32 x3, y3, z3;
    s32 maxY, minY;
    f32 nx, ny, nz;
    f32 mag;

    x1 = vertexData[triNum][0][0];
    y1 = vertexData[triNum][0][1];
    z1 = vertexData[triNum][0][2];

    x2 = vertexData[triNum][0][0];
    y2 = vertexData[triNum][1][1];
    z2 = vertexData[triNum][1][2];

    x3 = vertexData[triNum][2][0];
    y3 = vertexData[triNum][2][1];
    z3 = vertexData[triNum][2][2];

    // (v2 - v1) x (v3 - v2)
    nx = (y2 - y1) * (z3 - z2) - (z2 - z1) * (y3 - y2);
    ny = (z2 - z1) * (x3 - x2) - (x2 - x1) * (z3 - z2);
    nz = (x2 - x1) * (y3 - y2) - (y2 - y1) * (x3 - x2);

    mag = sqrtf(nx * nx + ny * ny + nz * nz);
    // Could have used min_3 and max_3 for this...
    minY = y1;
    if (y2 < minY) {
        minY = y2;
    }
    if (y3 < minY) {
        minY = y3;
    }

    maxY = y1;
    if (y2 > maxY) {
        maxY = y2;
    }
    if (y3 > maxY) {
        maxY = y3;
    }

    // Checking to make sure no DIV/0
    if (mag < 0.0001) {
        return NULL;
    }

    mag = (f32)(1.0 / mag);
    nx *= mag;
    ny *= mag;
    nz *= mag;
    //surface = alloc_surface();
    surface->vertex1[0] = x1;
    surface->vertex2[0] = x2;
    surface->vertex3[0] = x3;

    surface->vertex1[1] = y1;
    surface->vertex2[1] = y2;
    surface->vertex3[1] = y3;

    surface->vertex1[2] = z1;
    surface->vertex2[2] = z2;
    surface->vertex3[2] = z3;

    surface->normal.x = nx;
    surface->normal.y = ny;
    surface->normal.z = nz;

    surface->originOffset = -(nx * x1 + ny * y1 + nz * z1);

    surface->lowerY = minY - 5;
    surface->upperY = maxY + 5;

    return surface;

}

static struct Surface *load_surfaces(s16 *vertexData[], s16 triNum) {
    s32 i;
    s32 numSurfaces;
    struct Surface *surface;

    s8 room = 0;

    //numSurfaces = sizeof vertexData / sizeof *vertexData;
    //surface = read_surface_data(vertexData, triNum);
    //surface->type = surfaceType;

    return 0;


}


int ptInTriangle(const f32 p[3], const s16 p0[3], const s16 p1[3], const s16 p2[3]) {

    if ((p0[2] - p[2]) * (p1[0] - p0[0]) - (p0[0] - p[0]) * (p1[2] - p0[2]) < 0) {

        if ((p1[2] - p[2]) * (p2[0] - p1[0]) - (p1[0] - p[0]) * (p2[2] - p1[2]) < 0) {

            if ((p2[2] - p[2]) * (p0[0] - p2[0]) - (p2[0] - p[0]) * (p0[2] - p2[2]) < 0) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

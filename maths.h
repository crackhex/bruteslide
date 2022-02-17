#ifndef MATHS_H
#define MATHS_H

#include "types.h"

extern s16 atan2s(f32 y, f32 x);
#define sins(x) sin_table[(u16) (x) >> 4]
#define coss(x) sin_table[(u16) ((x) + 0x4000) >> 4]
#endif //MATHS_H

#pragma once

#define DSGM_3D_RENDERER (void *)3

#define glVertex3fv(v) glVertex3f(v[0], v[1], v[2])
#define glNormal3fv(n) glNormal3f(n[0], n[1], n[2])

inline u64 DSGM_Distance3D(s32 x1, s32 y1, s32 z1, s32 x2, s32 y2, s32 z2);

void DSGM_GetPositionMatrix(struct m4x4 *m);

void DSGM_DrawCube(float x, float y, float z, float width, float height, float depth);

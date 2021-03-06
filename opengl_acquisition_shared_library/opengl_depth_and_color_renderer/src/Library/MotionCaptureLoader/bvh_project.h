#ifndef BVH_PROJECT_H_INCLUDED
#define BVH_PROJECT_H_INCLUDED

#include "bvh_loader.h"
#include "bvh_transform.h"


#include "../../../../../tools/AmMatrix/simpleRenderer.h"

void bvh_cleanTransform(
                       struct BVH_MotionCapture * mc,
                       struct BVH_Transform     * bvhTransform
                      );

int bvh_projectTo2D(
                     struct BVH_MotionCapture * mc,
                     struct BVH_Transform     * bvhTransform,
                     struct simpleRenderer    * renderer,
                     unsigned int               occlusions
                   );

#endif // BVH_PROJECT_H_INCLUDED

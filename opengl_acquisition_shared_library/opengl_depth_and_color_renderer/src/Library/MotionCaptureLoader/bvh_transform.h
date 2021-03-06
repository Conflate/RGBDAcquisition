#ifndef BVH_TRANSFORM_H_INCLUDED
#define BVH_TRANSFORM_H_INCLUDED

#include "bvh_loader.h"

/*
   0  1  2  3
   4  5  6  7
   8  9 10 11
  12 13 14 15
*/

struct rectangle3DPointsArea
{
  float x1,y1,z1;
  float x2,y2,z2;
  float x3,y3,z3;
  float x4,y4,z4;
};


struct rectangle2DPointsArea
{
  char calculated;
  float x1,y1;
  float x2,y2;
  float x3,y3;
  float x4,y4;

  float x,y,width,height;
};


struct rectangleArea
{
  char exists,point1Exists,point2Exists,point3Exists,point4Exists;
  int jID[4];
  float averageDepth;
  struct rectangle2DPointsArea rectangle2D;
  struct rectangle3DPointsArea rectangle3D;
};


struct BVH_TransformedJoint
{
  double localToWorldTransformation[16];
  double chainTransformation[16];
  double dynamicTranslation[16];
  double dynamicRotation[16];

  //Position as X,Y,Z
  //-----------------
  double pos3D[4];

  //Position as 2D X,Y
  //-----------------
  char pos2DCalculated;
  char isBehindCamera;
  char isOccluded;
  double pos2D[2];
};


struct BVH_Transform
{
  struct rectangleArea torso;
  struct BVH_TransformedJoint joint[MAX_BVH_JOINT_HIERARCHY_SIZE];
  double centerPosition[3];
  unsigned int jointsOccludedIn2DProjection;
};



struct BVH_RendererConfiguration
{
  //Intrinsics
  float fX,fY,cX,cY;
  //Distortion
  float k1,k2,k3,p1,p2;
  //----------
  float R[9];
  float T[3];
  float projection[16];
  float viewport[4];
};



void create4x4RotationBVH(double * matrix,int rotationType,double degreesX,double degreesY,double degreesZ);


int bvh_loadTransformForFrame(
                               struct BVH_MotionCapture * bvhMotion ,
                               BVHFrameID fID ,
                               struct BVH_Transform * bvhTransform
                               //,float * rotationOffset
                             );

int bvh_populateRectangle2DFromProjections(
                                           struct BVH_MotionCapture * mc ,
                                           struct BVH_Transform * bvhTransform,
                                           struct rectangleArea * area
                                          );

int bvh_loadTransformForMotionBuffer(
                                     struct BVH_MotionCapture * bvhMotion ,
                                     float * motionBuffer,
                                     struct BVH_Transform * bvhTransform
                                    );

int bvh_loadTransformForFrameProjectTo2D(
                                         struct BVH_MotionCapture * bvhMotion ,
                                         struct BVH_Transform * bvhTransform
                                        );

#endif // BVH_TRANSFORM_H_INCLUDED

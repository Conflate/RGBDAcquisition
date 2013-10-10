#include <stdio.h>
#include <stdlib.h>

#include "NetworkAcquisition.h"


#include "../acquisition/Acquisition.h"

#include <string.h>
#include <math.h>


#define PRINT_COMMENTS 1
#define PRINT_DEBUG_EACH_CALL 0

#define DEFAULT_FOCAL_LENGTH 120.0
#define DEFAULT_PIXEL_SIZE 0.1052


#define BUILD_NETWORK 1

#if BUILD_NETWORK

struct NetworkVirtualDevice networkDevice[MAX_NETWORK_DEVICES]={0};

/*
   This library is unique in the sense that instead of only having the regular calls all the other plugin acquisition modules have
   it has the following three calls that allow it to "broadcast" and not only "receive" input from an aquisition source..
*/


//This call creates a FrameServer that binds to the IP and port given and from there on starts to
//service the clients that connect to it by sending frames to them..
int networkBackbone_startPushingToRemote(char * ip , int port)
{
  fprintf(stderr,"networkBackbone_startPushingToRemote(%s,%u) called \n",ip,port);
  StartFrameServer(0,ip,port);
  return 0;
}

int networkBackbone_stopPushingToRemote(int frameServerID)
{
  StopFrameServer(0);
  return 0;
}

//This call pushes an image to be made available to the clients connected to our frameserver

int networkBackbone_pushImageToRemote(int frameServerID, int streamNumber , void* pixels , unsigned int width , unsigned int height , unsigned int channels , unsigned int bitsperpixel)
{
  if (streamNumber==0) //Color
  {
      networkDevice[0].okToSendColorFrame=0;
      networkDevice[0].colorWidth=width;
      networkDevice[0].colorHeight=height;
      networkDevice[0].colorChannels=channels;
      networkDevice[0].colorBitsperpixel=bitsperpixel;
      networkDevice[0].colorFrame = (char*) pixels;

      networkDevice[0].okToSendColorFrame=1;


      while (networkDevice[0].okToSendColorFrame==1)
       {
         usleep(100000);
         fprintf(stderr,"Cf.");
       }
  }
   else
 if (streamNumber==1) //Depth
  {
      networkDevice[0].okToSendDepthFrame=0;
      networkDevice[0].depthWidth=width;
      networkDevice[0].depthHeight=height;
      networkDevice[0].depthChannels=channels;
      networkDevice[0].depthBitsperpixel=bitsperpixel;
      networkDevice[0].depthFrame = (char*) pixels;

      networkDevice[0].okToSendDepthFrame=1;


      while (networkDevice[0].okToSendDepthFrame==1)
       {
         usleep(100000);
         fprintf(stderr,"Df.");
       }
  }

  return 0;
}




















double getNetworkColorPixelSize(int devID)   { return DEFAULT_PIXEL_SIZE; }
double getNetworkColorFocalLength(int devID)
{
   return DEFAULT_FOCAL_LENGTH;
}

double getNetworkDepthFocalLength(int devID) {  return DEFAULT_FOCAL_LENGTH; }
double getNetworkDepthPixelSize(int devID) { return DEFAULT_PIXEL_SIZE; }



int getNetworkColorCalibration(int devID,struct calibration * calib) { return 1; }
int getNetworkDepthCalibration(int devID,struct calibration * calib) { return 1; }
int setNetworkColorCalibration(int devID,struct calibration * calib) { return 1; }
int setNetworkDepthCalibration(int devID,struct calibration * calib) {     return 1; }





int startNetworkModule(unsigned int max_devs,char * settings)
{
    return 1;
}




int getNetworkNumberOfDevices() { return 1; }

int stopNetworkModule() {    return 1; }

int createNetworkDevice(int devID,char * devName,unsigned int width,unsigned int height,unsigned int framerate) { return 0; }
int destroyNetworkDevice(int devID) { return 1; }
int seekNetworkFrame(int devID,unsigned int seekFrame) { return 1; }
int snapNetworkFrames(int devID) { return 1; }

//Color Frame getters
unsigned long getLastNetworkColorTimestamp(int devID) { return networkDevice[devID].lastColorTimestamp; }
int getNetworkColorWidth(int devID)        { return networkDevice[devID].colorWidth; }
int getNetworkColorHeight(int devID)       { return networkDevice[devID].colorHeight; }
int getNetworkColorDataSize(int devID)     { return networkDevice[devID].colorWidth * networkDevice[devID].colorHeight * 3; }
int getNetworkColorChannels(int devID)     { return 3; }
int getNetworkColorBitsPerPixel(int devID) { return 8; }

// Frame Grabber should call this function for color frames
char * getNetworkColorPixels(int devID)    { return networkDevice[devID].colorFrame; }




   //Depth Frame getters
unsigned long getLastNetworkDepthTimestamp(int devID) { return networkDevice[devID].lastDepthTimestamp; }
int getNetworkDepthWidth(int devID)    { return networkDevice[devID].depthWidth; }
int getNetworkDepthHeight(int devID)   { return networkDevice[devID].depthHeight; }
int getNetworkDepthDataSize(int devID) { return networkDevice[devID].depthWidth * networkDevice[devID].depthHeight; }
int getNetworkDepthChannels(int devID)     { return 1; }
int getNetworkDepthBitsPerPixel(int devID) { return 16; }

// Frame Grabber should call this function for depth frames
char * getNetworkDepthPixels(int devID) { return (char *) networkDevice[devID].depthFrame; }

#else
//Null build
int startNetworkModule(unsigned int max_devs,char * settings)
{
    fprintf(stderr,"startNetworkModule called on a dummy build of NetworkAcquisition!\n");
    fprintf(stderr,"Please consider enabling #define BUILD_NETWORK 1 on acquisition/acquisition_setup.h\n");
    return 0;
  return 1;
}
#endif
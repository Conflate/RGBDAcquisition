#ifndef ACQUISITION_H_INCLUDED
#define ACQUISITION_H_INCLUDED

#ifdef __cplusplus
extern "C"
{
#endif

enum Acquisition_Possible_Modules
{
    NO_ACQUISITION_MODULE = 0,
    V4L2_ACQUISITION_MODULE ,
    FREENECT_ACQUISITION_MODULE ,
    OPENNI1_ACQUISITION_MODULE  ,
    OPENNI2_ACQUISITION_MODULE  ,
    OPENGL_ACQUISITION_MODULE  ,
    TEMPLATE_ACQUISITION_MODULE  ,
   //--------------------------------------------
    NUMBER_OF_POSSIBLE_MODULES
};

typedef unsigned int ModuleIdentifier;
typedef unsigned int DeviceIdentifier;


int acquisitionGetModulesCount();
char * getModuleStringName(ModuleIdentifier moduleID);
int acquisitionIsModuleLinked(ModuleIdentifier moduleID);

int acquisitionStartModule(ModuleIdentifier moduleID,unsigned int maxDevices);
int acquisitionStopModule(ModuleIdentifier moduleID);
int acquisitionGetModuleDevices(ModuleIdentifier moduleID);
int acquisitionOpenDevice(ModuleIdentifier moduleID,DeviceIdentifier devID,unsigned int width,unsigned int height,unsigned int framerate);
int acquisitionCloseDevice(ModuleIdentifier moduleID,DeviceIdentifier devID);

int acquisitionSnapFrames(ModuleIdentifier moduleID,DeviceIdentifier devID);
char * acquisitionGetColorFrame(ModuleIdentifier moduleID,DeviceIdentifier devID);
char * acquisitionGetDepthFrame(ModuleIdentifier moduleID,DeviceIdentifier devID);
int acquisitionGetColorFrameDimensions(ModuleIdentifier moduleID,DeviceIdentifier devID,unsigned int * width , unsigned int * height , unsigned int * channels , unsigned int * bitsperpixel );
int acquisitionGetDepthFrameDimensions(ModuleIdentifier moduleID,DeviceIdentifier devID,unsigned int * width , unsigned int * height , unsigned int * channels , unsigned int * bitsperpixel );

int acquisitionSaveColorFrame(ModuleIdentifier moduleID,DeviceIdentifier devID,char * filename);
int acquisitionSaveDepthFrame(ModuleIdentifier moduleID,DeviceIdentifier devID,char * filename);

double acqusitionGetColorFocalLength(ModuleIdentifier moduleID,DeviceIdentifier devID);
double acqusitionGetColorPixelSize(ModuleIdentifier moduleID,DeviceIdentifier devID);

double acqusitionGetDepthFocalLength(ModuleIdentifier moduleID,DeviceIdentifier devID);
double acqusitionGetDepthPixelSize(ModuleIdentifier moduleID,DeviceIdentifier devID);

int acquisitionMapDepthToRGB(ModuleIdentifier moduleID,DeviceIdentifier devID);

#ifdef __cplusplus
}
#endif

#endif // ACQUISITION_H_INCLUDED

#ifndef TEMPLATEACQUISITIONHELPER_H_INCLUDED
#define TEMPLATEACQUISITIONHELPER_H_INCLUDED


#define NORMAL   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */


#define MAX_DIR_PATH 1024

int makeFrameNoInput(unsigned char * frame , unsigned int width , unsigned int height , unsigned int channels);
int FileExists(char * filename);
unsigned char * ReadPNM(unsigned char * buffer , char * filename,unsigned int *width,unsigned int *height,unsigned long * timestamp);
int flipDepth(unsigned short * depth,unsigned int width , unsigned int height );

unsigned int retreiveDatasetDeviceIDToReadFrom(unsigned int devID , unsigned int cycle , char * readFromDir , char * extension);

unsigned int findLastFrame(int devID, char * readFromDir , char * extension);

void getFilenameForCurrentImage(char * filename , unsigned int maxSize , unsigned int isColor , unsigned int devID , unsigned int cycle, char * readFromDir , char * extension );

#endif // TEMPLATEACQUISITIONHELPER_H_INCLUDED
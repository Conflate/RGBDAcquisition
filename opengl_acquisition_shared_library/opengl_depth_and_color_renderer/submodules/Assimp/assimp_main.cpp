#include <stdio.h>
#include "../../src/ModelLoader/model_loader_tri.h"
#include "assimp_loader.h"

int main (int argc, char *argv[])
{
 if (argc<3)   { fprintf(stderr,"Not enough arguments , use as : \nassimpTester source.dae target.tri \n"); return 0; }


 fprintf(stderr,"assimpTester %s %s \n",argv[1],argv[2]);
 struct TRI_Model flatModel={0};
 struct TRI_Model originalModel={0};

 testAssimp(argv[1],&flatModel,&originalModel);

 saveModelTri(argv[2], &originalModel);

 freeModelTri(&flatModel);
 freeModelTri(&originalModel);

 return 0;

}

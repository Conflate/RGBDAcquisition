#ifndef MATRIX3X3TOOLS_H_INCLUDED
#define MATRIX3X3TOOLS_H_INCLUDED


void print3x3DMatrix(char * str , double * matrix4x4);
void copy3x3Matrix(double * out,double * in);
void create3x3IdentityMatrix(double * m);

int transpose3x3MatrixD(double * mat);

int upscale3x3to4x4(double * mat3x3,double * mat4x4);

double det3x3Matrix(double * mat);
int invert3x3MatrixD(double * mat,double * result);

int multiplyTwo3x3Matrices(double * result , double * matrixA , double * matrixB);

#endif // MATRIX3X3TOOLS_H_INCLUDED

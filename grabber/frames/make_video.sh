#!/bin/bash 

STARTDIR=`pwd`
#Switch to this directory
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd "$DIR"

DATASET=""
EXTENSION="pnm"

if (( $#<2 ))
then 
 echo "Please provide arguments first argument is dataset ,  second is file format ( i.e. boxNew jpg ) "
 exit 1
else
 DATASET=$1
 EXTENSION=$2
fi

echo "Dataset is $DATASET and extension is $EXTENSION"
 
THEDATETAG=`date +"%y-%m-%d_%H-%M-%S"` 

cd $DATASET 
ffmpeg -i colorFrame_0_%05d.$EXTENSION -y -r 20 -threads 8 -b:v 30000k  ../outHD-$DATASET-$THEDATETAG.mp4  #-s 640x480 
cd ..

cd $STARTDIR 
exit 0


#!/bin/bash

rm gl3Multi
gcc -o gl3Multi glx3.c glx_testMultiViewport.c ../Rendering/ShaderPipeline/shader_loader.c ../Rendering/ShaderPipeline/render_buffer.c ../Rendering/downloadFromRenderer.c ../Tools/save_to_file.c ../Tools/tools.c ../../../../tools/AmMatrix/matrix4x4Tools.c ../../../../tools/AmMatrix/matrixOpenGL.c -lm -lGL -lGLU -lX11 -lGLEW
./gl3Multi

exit 0
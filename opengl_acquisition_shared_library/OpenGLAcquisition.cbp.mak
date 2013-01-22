#------------------------------------------------------------------------------#
# This makefile was generated by 'cbp2make' tool rev.137                       #
#------------------------------------------------------------------------------#


WORKDIR = `pwd`

CC = gcc
CXX = g++
AR = ar
LD = g++
WINDRES = windres

INC = 
CFLAGS =  -Wall -fexceptions -fPIC
RESINC = 
LIBDIR = 
LIB =  -lGL -lX11
LDFLAGS = 

INC_DEBUG =  $(INC)
CFLAGS_DEBUG =  $(CFLAGS) -g
RESINC_DEBUG =  $(RESINC)
RCFLAGS_DEBUG =  $(RCFLAGS)
LIBDIR_DEBUG =  $(LIBDIR)
LIB_DEBUG = $(LIB)
LDFLAGS_DEBUG =  $(LDFLAGS)
OBJDIR_DEBUG = obj/Debug
DEP_DEBUG = 
OUT_DEBUG = libOpenGLAcquisition.so

INC_RELEASE =  $(INC)
CFLAGS_RELEASE =  $(CFLAGS) -O2
RESINC_RELEASE =  $(RESINC)
RCFLAGS_RELEASE =  $(RCFLAGS)
LIBDIR_RELEASE =  $(LIBDIR)
LIB_RELEASE = $(LIB)
LDFLAGS_RELEASE =  $(LDFLAGS) -s
OBJDIR_RELEASE = obj/Release
DEP_RELEASE = 
OUT_RELEASE = libOpenGLAcquisition.so

OBJ_DEBUG = $(OBJDIR_DEBUG)/opengl_depth_and_color_renderer/src/tools.o $(OBJDIR_DEBUG)/opengl_depth_and_color_renderer/src/shader_loader.o $(OBJDIR_DEBUG)/opengl_depth_and_color_renderer/src/scene.o $(OBJDIR_DEBUG)/opengl_depth_and_color_renderer/src/save_to_file.o $(OBJDIR_DEBUG)/opengl_depth_and_color_renderer/src/model_loader_obj.o $(OBJDIR_DEBUG)/opengl_depth_and_color_renderer/src/model_loader.o $(OBJDIR_DEBUG)/opengl_depth_and_color_renderer/src/main.o $(OBJDIR_DEBUG)/opengl_depth_and_color_renderer/src/glx.o $(OBJDIR_DEBUG)/main.o

OBJ_RELEASE = $(OBJDIR_RELEASE)/opengl_depth_and_color_renderer/src/tools.o $(OBJDIR_RELEASE)/opengl_depth_and_color_renderer/src/shader_loader.o $(OBJDIR_RELEASE)/opengl_depth_and_color_renderer/src/scene.o $(OBJDIR_RELEASE)/opengl_depth_and_color_renderer/src/save_to_file.o $(OBJDIR_RELEASE)/opengl_depth_and_color_renderer/src/model_loader_obj.o $(OBJDIR_RELEASE)/opengl_depth_and_color_renderer/src/model_loader.o $(OBJDIR_RELEASE)/opengl_depth_and_color_renderer/src/main.o $(OBJDIR_RELEASE)/opengl_depth_and_color_renderer/src/glx.o $(OBJDIR_RELEASE)/main.o

all: debug release

clean: clean_debug clean_release

before_debug: 
	test -d $(OBJDIR_DEBUG)/opengl_depth_and_color_renderer/src || mkdir -p $(OBJDIR_DEBUG)/opengl_depth_and_color_renderer/src
	test -d $(OBJDIR_DEBUG) || mkdir -p $(OBJDIR_DEBUG)

after_debug: 

debug: before_debug out_debug after_debug

out_debug: $(OBJ_DEBUG) $(DEP_DEBUG)
	$(LD) -shared $(LDFLAGS_DEBUG) $(LIBDIR_DEBUG) $(OBJ_DEBUG) $(LIB_DEBUG) -o $(OUT_DEBUG)

$(OBJDIR_DEBUG)/opengl_depth_and_color_renderer/src/tools.o: opengl_depth_and_color_renderer/src/tools.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c opengl_depth_and_color_renderer/src/tools.c -o $(OBJDIR_DEBUG)/opengl_depth_and_color_renderer/src/tools.o

$(OBJDIR_DEBUG)/opengl_depth_and_color_renderer/src/shader_loader.o: opengl_depth_and_color_renderer/src/shader_loader.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c opengl_depth_and_color_renderer/src/shader_loader.c -o $(OBJDIR_DEBUG)/opengl_depth_and_color_renderer/src/shader_loader.o

$(OBJDIR_DEBUG)/opengl_depth_and_color_renderer/src/scene.o: opengl_depth_and_color_renderer/src/scene.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c opengl_depth_and_color_renderer/src/scene.c -o $(OBJDIR_DEBUG)/opengl_depth_and_color_renderer/src/scene.o

$(OBJDIR_DEBUG)/opengl_depth_and_color_renderer/src/save_to_file.o: opengl_depth_and_color_renderer/src/save_to_file.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c opengl_depth_and_color_renderer/src/save_to_file.c -o $(OBJDIR_DEBUG)/opengl_depth_and_color_renderer/src/save_to_file.o

$(OBJDIR_DEBUG)/opengl_depth_and_color_renderer/src/model_loader_obj.o: opengl_depth_and_color_renderer/src/model_loader_obj.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c opengl_depth_and_color_renderer/src/model_loader_obj.c -o $(OBJDIR_DEBUG)/opengl_depth_and_color_renderer/src/model_loader_obj.o

$(OBJDIR_DEBUG)/opengl_depth_and_color_renderer/src/model_loader.o: opengl_depth_and_color_renderer/src/model_loader.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c opengl_depth_and_color_renderer/src/model_loader.c -o $(OBJDIR_DEBUG)/opengl_depth_and_color_renderer/src/model_loader.o

$(OBJDIR_DEBUG)/opengl_depth_and_color_renderer/src/main.o: opengl_depth_and_color_renderer/src/main.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c opengl_depth_and_color_renderer/src/main.c -o $(OBJDIR_DEBUG)/opengl_depth_and_color_renderer/src/main.o

$(OBJDIR_DEBUG)/opengl_depth_and_color_renderer/src/glx.o: opengl_depth_and_color_renderer/src/glx.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c opengl_depth_and_color_renderer/src/glx.c -o $(OBJDIR_DEBUG)/opengl_depth_and_color_renderer/src/glx.o

$(OBJDIR_DEBUG)/main.o: main.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c main.cpp -o $(OBJDIR_DEBUG)/main.o

clean_debug: 
	rm -f $(OBJ_DEBUG) $(OUT_DEBUG)
	rm -rf $(OBJDIR_DEBUG)/opengl_depth_and_color_renderer/src
	rm -rf $(OBJDIR_DEBUG)

before_release: 
	test -d $(OBJDIR_RELEASE)/opengl_depth_and_color_renderer/src || mkdir -p $(OBJDIR_RELEASE)/opengl_depth_and_color_renderer/src
	test -d $(OBJDIR_RELEASE) || mkdir -p $(OBJDIR_RELEASE)

after_release: 

release: before_release out_release after_release

out_release: $(OBJ_RELEASE) $(DEP_RELEASE)
	$(LD) -shared $(LDFLAGS_RELEASE) $(LIBDIR_RELEASE) $(OBJ_RELEASE) $(LIB_RELEASE) -o $(OUT_RELEASE)

$(OBJDIR_RELEASE)/opengl_depth_and_color_renderer/src/tools.o: opengl_depth_and_color_renderer/src/tools.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c opengl_depth_and_color_renderer/src/tools.c -o $(OBJDIR_RELEASE)/opengl_depth_and_color_renderer/src/tools.o

$(OBJDIR_RELEASE)/opengl_depth_and_color_renderer/src/shader_loader.o: opengl_depth_and_color_renderer/src/shader_loader.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c opengl_depth_and_color_renderer/src/shader_loader.c -o $(OBJDIR_RELEASE)/opengl_depth_and_color_renderer/src/shader_loader.o

$(OBJDIR_RELEASE)/opengl_depth_and_color_renderer/src/scene.o: opengl_depth_and_color_renderer/src/scene.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c opengl_depth_and_color_renderer/src/scene.c -o $(OBJDIR_RELEASE)/opengl_depth_and_color_renderer/src/scene.o

$(OBJDIR_RELEASE)/opengl_depth_and_color_renderer/src/save_to_file.o: opengl_depth_and_color_renderer/src/save_to_file.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c opengl_depth_and_color_renderer/src/save_to_file.c -o $(OBJDIR_RELEASE)/opengl_depth_and_color_renderer/src/save_to_file.o

$(OBJDIR_RELEASE)/opengl_depth_and_color_renderer/src/model_loader_obj.o: opengl_depth_and_color_renderer/src/model_loader_obj.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c opengl_depth_and_color_renderer/src/model_loader_obj.c -o $(OBJDIR_RELEASE)/opengl_depth_and_color_renderer/src/model_loader_obj.o

$(OBJDIR_RELEASE)/opengl_depth_and_color_renderer/src/model_loader.o: opengl_depth_and_color_renderer/src/model_loader.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c opengl_depth_and_color_renderer/src/model_loader.c -o $(OBJDIR_RELEASE)/opengl_depth_and_color_renderer/src/model_loader.o

$(OBJDIR_RELEASE)/opengl_depth_and_color_renderer/src/main.o: opengl_depth_and_color_renderer/src/main.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c opengl_depth_and_color_renderer/src/main.c -o $(OBJDIR_RELEASE)/opengl_depth_and_color_renderer/src/main.o

$(OBJDIR_RELEASE)/opengl_depth_and_color_renderer/src/glx.o: opengl_depth_and_color_renderer/src/glx.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c opengl_depth_and_color_renderer/src/glx.c -o $(OBJDIR_RELEASE)/opengl_depth_and_color_renderer/src/glx.o

$(OBJDIR_RELEASE)/main.o: main.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c main.cpp -o $(OBJDIR_RELEASE)/main.o

clean_release: 
	rm -f $(OBJ_RELEASE) $(OUT_RELEASE)
	rm -rf $(OBJDIR_RELEASE)/opengl_depth_and_color_renderer/src
	rm -rf $(OBJDIR_RELEASE)

.PHONY: before_debug after_debug clean_debug before_release after_release clean_release


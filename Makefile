# Project: Prj_TeapotGL
# Makefile created by Dev-C++ 4.9.9.2

CPP  = g++.exe
CC   = gcc.exe
WINDRES = windres.exe
RES  = 
OBJ  = main.o cogl.o cglext.o cglsl.o cglscene.o cmesh.o csmooth.o cexplode.o cnode.o $(RES)
LINKOBJ  = $(OBJ) $(RES)
LIBS =  -mwindows  -lopengl32 -lglu32
INCS = 
CXXINCS = 
BIN  = Prj_TeapotGL.exe
CXXFLAGS = $(CXXINCS)   -std=gnu++11
CFLAGS = $(INCS)   -std=gnu++11
RM = rm -f

.PHONY: all all-before all-after clean clean-custom

all: all-before Prj_TeapotGL.exe all-after

run: $(BIN)
	$(BIN)

clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o "Prj_TeapotGL.exe" $(LIBS)

main.o: main.cpp
	$(CPP) -c main.cpp -o main.o $(CXXFLAGS)

cogl.o: cogl.cpp
	$(CPP) -c cogl.cpp -o cogl.o $(CXXFLAGS)

cglext.o: cglext.cpp
	$(CPP) -c cglext.cpp -o cglext.o $(CXXFLAGS)

cglsl.o: cglsl.cpp shaders.inl
	$(CPP) -c cglsl.cpp -o cglsl.o $(CXXFLAGS)

cglscene.o: cglscene.cpp
	$(CPP) -c cglscene.cpp -o cglscene.o $(CXXFLAGS)

cmesh.o: cmesh.cpp
	$(CPP) -c cmesh.cpp -o cmesh.o $(CXXFLAGS)

csmooth.o: csmooth.cpp
	$(CPP) -c csmooth.cpp -o csmooth.o $(CXXFLAGS)

cexplode.o: cexplode.cpp
	$(CPP) -c cexplode.cpp -o cexplode.o $(CXXFLAGS)

cnode.o: cnode.cpp
	$(CPP) -c cnode.cpp -o cnode.o $(CXXFLAGS)

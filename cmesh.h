#pragma once 

#include <iostream>
#include <fstream>
#include <vector>
#include "cVec3.h"

class cSmooth;

class cMesh
{
 public:
  friend class cSmooth;
  
  struct Vertex {
    cVec3<float> pos;
    cVec3<float> nor;
  };

  struct Face {
    unsigned short fac[3];
  };
    
 public:
  cMesh();
  ~cMesh();

  bool loadFromObj(const char*);
  int getVertexCount();
  int getFaceCount();
  int getTFaceCount();

  Vertex *getVertices();
  Face   *getFaces();
  Vertex *getTFaces();
  
  void resetTFaces();
  
 private:
  std::vector<Vertex> vertices;
  std::vector<Face>   faces;

 protected:
  std::vector<Vertex> tfaces;
};

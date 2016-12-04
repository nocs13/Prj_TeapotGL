#pragma once
#pragma once 
#include "cmesh.h"
#include "cvec3.h"
#include <list>

class cMesh;

class cSmooth
{
  private:
    struct Triangle {
      cVec3<float> v[3];
      cVec3<float> n;
      int id;
      bool used;
      bool e[3];
      bool p[3];
    };
    
    struct STriangle {
      Triangle base;
      Triangle split[4];
      int  id;
    };
  
  public:
    cSmooth();
    ~cSmooth();
    
    bool smooth(cMesh::Vertex* tfaces, int count);
    bool smooth(cMesh* mesh);
    bool smoothRoam(cMesh*, int);
    bool smooth001(cMesh*, int);
    cVec3<float> normal(cVec3<float>, cVec3<float>, cVec3<float>);
    STriangle split(Triangle &tr);
    void align(STriangle &t);
    
  private:
    void refresh(cMesh*);
    inline void subdivide(cVec3<float>, cVec3<float>, cVec3<float>, int, std::list<cSmooth::Triangle>&);
    
    bool isEqualEdge(cVec3<float> a1, cVec3<float> a2, 
                     cVec3<float> b1, cVec3<float> b2)
    {
      return ( (a1 == b1 && a2 == b2) || (a1 == b2 && a2 == b1) );
    }
    
  std::list<Triangle>  triangles;
  std::list<STriangle> smoothed;
};

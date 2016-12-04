#pragma once

#include <vector>
#include "cmesh.h"
#include "cvec3.h"

class cTeapot: public cMesh
{
  public:
    cTeapot();
    ~cTeapot();
    
    bool update();
    void setSmooth(int i);
    
  private:
    struct Point {
      cVec3<float> points[4];
    };
    
    int smooth;
    
    std::vector< cVec3<float> > lathe_1;  //cup
    std::vector< cVec3<float> > lathe_2;  //hat
    
    std::vector<Point> part_2;  //tube
    std::vector<Point> part_3;  //hand
};

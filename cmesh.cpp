#include "cmesh.h"
#include "cvec3.h"
#include <fstream>
#include <iostream>
#include <string.h>
#include <list>

cMesh::cMesh()
{
}

cMesh::~cMesh()
{
  vertices.clear();
  faces.clear();
}

int cMesh::getVertexCount()
{
  return vertices.size();
}

int cMesh::getFaceCount()
{
  return faces.size();
}

int cMesh::getTFaceCount()
{
  return tfaces.size();
}

cMesh::Vertex *cMesh::getVertices()
{
  return vertices.data();
}

cMesh::Face *cMesh::getFaces()
{
  return faces.data();
}

cMesh::Vertex *cMesh::getTFaces()
{
  return tfaces.data();
}

void cMesh::resetTFaces()
{
  int n = 0;
  
  tfaces.clear();

  tfaces.resize(3 * faces.size());
  
  for (Face fc: faces) {
    faces[n] = fc;
    
    Face ft = faces[n];
    
    tfaces[3 * n + 0].pos = vertices[fc.fac[0]].pos;
    tfaces[3 * n + 1].pos = vertices[fc.fac[1]].pos;
    tfaces[3 * n + 2].pos = vertices[fc.fac[2]].pos;

    Vertex vx1 = vertices[fc.fac[0]];
    Vertex vx2 = vertices[fc.fac[1]];
    Vertex vx3 = vertices[fc.fac[2]];
    
    cVec3<float> vc1(vx1.pos[0], vx1.pos[1], vx1.pos[2]);
    cVec3<float> vc2(vx2.pos[0], vx2.pos[1], vx2.pos[2]);
    cVec3<float> vc3(vx3.pos[0], vx3.pos[1], vx3.pos[2]);
    
    cVec3<float> d1 = vc2 - vc1;
    cVec3<float> d2 = vc3 - vc1;
    
    cVec3<float> nor = d1.cross(d2);
    nor.normalize();
        
    tfaces[3 * n + 0].nor = nor;
    tfaces[3 * n + 1].nor = nor;
    tfaces[3 * n + 2].nor = nor;
    
    n++;
  }
}

bool cMesh::loadFromObj(const char *path)
{
  std::fstream fs;

  if (path == NULL) {
    std::cout << "Wrong path for load model." << std::endl;
    return false;
  }

  fs.open(path, std::fstream::in);

  if (!fs.is_open()) {
    std::cout << "Cannot open file to load model." << std::endl;
    return false;
  }

  std::list<Vertex> v;
  std::list<Face>   f;
  std::list< cVec3<float> > vn;
  
  while (!fs.eof()) {
    std::string line;
    char        id;

    fs >> line;

    if (line == "v") {
      Vertex vx;
      fs >> vx.pos[0], fs >> vx.pos[1], fs >> vx.pos[2];
      v.push_back(vx);
    } else if (line == "f") {
      Face fc;
      fs >> fc.fac[0], fs >> fc.fac[1], fs >> fc.fac[2];
      fc.fac[0]--;
      fc.fac[1]--;
      fc.fac[2]--;
      f.push_back(fc);
    } else if (line == "vn") {
      float n[3];
      fs >> n[0], fs >> n[1], fs >> n[2];
      vn.push_back(cVec3<float>(n[0], n[1], n[2]));
    }
  }

  if (v.size() < 1 || f.size() < 1) {
    std::cout << "File not contain data or wrong format." << std::endl;
    fs.close();
    v.clear();
    f.clear();
    vn.clear();
    
    return false;
  }
    
  std::cout << "Mesh with V " << v.size() << " F " << f.size() 
            << " N " << vn.size() << std::endl;

  vertices.resize(v.size());
  faces.resize(f.size());
  tfaces.resize(3 * f.size());

  std::cout << "Mesh R with V " << vertices.size() << " F " << faces.size() << std::endl;

  int n = 0;
  
  for (std::list<Vertex>::iterator i = v.begin(); i != v.end(); ++i) {
    if (vn.size() == v.size()) {
      std::list < cVec3<float> >::iterator j = vn.begin();
      std::advance(j, n);
      (*i).nor[0] = (*j).x();
      (*i).nor[1] = (*j).y();
      (*i).nor[2] = (*j).z();
    }
    
    vertices[n] = (*i);
    
    n++;
  }

  n = 0;
  
  for (Face fc: f) {
    faces[n] = fc;
    
    Face ft = faces[n];
    
    tfaces[3 * n + 0].pos = vertices[fc.fac[0]].pos;
    tfaces[3 * n + 1].pos = vertices[fc.fac[1]].pos;
    tfaces[3 * n + 2].pos = vertices[fc.fac[2]].pos;

    //memcpy(tfaces[3 * n + 0].pos, vertices[fc.fac[0]].pos, sizeof(Vertex::pos));
    //memcpy(tfaces[3 * n + 1].pos, vertices[fc.fac[1]].pos, sizeof(Vertex::pos));
    //memcpy(tfaces[3 * n + 2].pos, vertices[fc.fac[2]].pos, sizeof(Vertex::pos));
    
    Vertex vx1 = vertices[fc.fac[0]];
    Vertex vx2 = vertices[fc.fac[1]];
    Vertex vx3 = vertices[fc.fac[2]];
    
    cVec3<float> vc1(vx1.pos[0], vx1.pos[1], vx1.pos[2]);
    cVec3<float> vc2(vx2.pos[0], vx2.pos[1], vx2.pos[2]);
    cVec3<float> vc3(vx3.pos[0], vx3.pos[1], vx3.pos[2]);
    
    cVec3<float> d1 = vc2 - vc1;
    cVec3<float> d2 = vc3 - vc1;
    
    cVec3<float> nor = d1.cross(d2);
    //nor.invert();
    nor.normalize();
        
    //float        fnor[3] = { nor.x(), nor.y(), nor.z() };

    tfaces[3 * n + 0].nor = nor;
    tfaces[3 * n + 1].nor = nor;
    tfaces[3 * n + 2].nor = nor;
    //memcpy(tfaces[3 * n + 0].nor, &nor, sizeof(Vertex::pos));
    //memcpy(tfaces[3 * n + 1].nor, &nor, sizeof(Vertex::pos));
    //memcpy(tfaces[3 * n + 2].nor, &nor, sizeof(Vertex::pos));
    
    n++;
  }
  

  fs.close();
  
  /*{
    std::fstream fs;
    fs.open("test.obj", std::fstream::out);
    unsigned short* f= (unsigned short*) faces.data();
    for (int i = 0; i < faces.size(); i++) {
      fs << "f " << f[3 * i + 0] << " " << f[3 * i + 1] << " " << f[3 * i + 2] << std::endl;
    }
    
    fs.close();
  }*/
  
  return true;
}

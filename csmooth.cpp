#include "csmooth.h"
#include <iostream>
#include <memory.h>

inline bool vecEqual(cVec3<float>& v1, cVec3<float>& v2, int s)
{
  int n = pow(10, 5);
  
  cVec3<float> c1(trunc(v1.x() * n), trunc(v1.y() * n), trunc(v1.z() * n));
  cVec3<float> c2(trunc(v2.x() * n), trunc(v2.y() * n), trunc(v2.z() * n));
  
  return (c1 == c2);
}

cSmooth::cSmooth()
{
}

cSmooth::~cSmooth()
{
}
    
cVec3<float> cSmooth::normal(cVec3<float> a, cVec3<float> b, cVec3<float> c)
{
  cVec3<float> v1 = b - a;
  cVec3<float> v2 = c - a;
  cVec3<float> cr = v1.cross(v2);
  
  cr.normalize();
  
  return cr;
}

void cSmooth::refresh(cMesh* mesh)
{
  if (!mesh)
    return;

  std::cout << "Mesh vertices " << mesh->getTFaceCount() << std::endl;
  
  mesh->tfaces.clear();  
  
  /*for(Triangle t: triangles) {
    cMesh::Vertex v;
    v.pos = t.v[0]; v.nor = t.n; mesh->tfaces.push_back(v);
    v.pos = t.v[1]; v.nor = t.n; mesh->tfaces.push_back(v);
    v.pos = t.v[2]; v.nor = t.n; mesh->tfaces.push_back(v);
  }
  return;*/
  
  for(STriangle t: smoothed) {
    cMesh::Vertex v;
    
    v.pos = t.split[0].v[0]; v.nor = t.split[0].n; mesh->tfaces.push_back(v);
    v.pos = t.split[0].v[1]; v.nor = t.split[0].n; mesh->tfaces.push_back(v);
    v.pos = t.split[0].v[2]; v.nor = t.split[0].n; mesh->tfaces.push_back(v);

    v.pos = t.split[1].v[0]; v.nor = t.split[1].n; mesh->tfaces.push_back(v);
    v.pos = t.split[1].v[1]; v.nor = t.split[1].n; mesh->tfaces.push_back(v);
    v.pos = t.split[1].v[2]; v.nor = t.split[1].n; mesh->tfaces.push_back(v);

    v.pos = t.split[2].v[0]; v.nor = t.split[2].n; mesh->tfaces.push_back(v);
    v.pos = t.split[2].v[1]; v.nor = t.split[2].n; mesh->tfaces.push_back(v);
    v.pos = t.split[2].v[2]; v.nor = t.split[2].n; mesh->tfaces.push_back(v);

    v.pos = t.split[3].v[0]; v.nor = t.split[3].n; mesh->tfaces.push_back(v);
    v.pos = t.split[3].v[1]; v.nor = t.split[3].n; mesh->tfaces.push_back(v);
    v.pos = t.split[3].v[2]; v.nor = t.split[3].n; mesh->tfaces.push_back(v);
  }  
  
  std::cout << "Update mesh vertices " << mesh->getTFaceCount() << std::endl;
}

bool cSmooth::smooth(cMesh* mesh)
{
  if (!mesh)
    return false;
    
  if (!smooth(mesh->getTFaces(), mesh->getTFaceCount()))
    return false;
  
  refresh(mesh);
  
  return true;
}

bool cSmooth::smoothRoam(cMesh* mesh, int vid)
{
  if (!mesh)
    return false;
    
  if (vid > 2)
    vid %= 3;
  
  if (vid > 2)
    vid = 0;
    
  std::list<Triangle>  triangles;
  
  int count = mesh->getFaceCount();
  cMesh::Vertex* tfaces = mesh->getTFaces();

  for (int i = 0; i < count; i += 3) {
    Triangle tr;
    
    cMesh::Vertex v;
    v = tfaces[i];
    tr.v[0] = v.pos;
    v = tfaces[i + 1];
    tr.v[1] = v.pos;
    v = tfaces[i + 2];
    tr.v[2] = v.pos;
    
    tr.n = normal(tr.v[0], tr.v[1], tr.v[2]);
    tr.n.normalize();
    
    tr.id = i / 3;
    tr.used = tr.e[0] = tr.e[1] = tr.e[2] = false;
    
    triangles.push_back(tr);
  }

  std::list<Triangle>  smoothed;

  for(Triangle& t: triangles) {
    cVec3<float> e[2];
    int          edge = -1;
    
    switch(vid)
    {
      case 0:
        e[0] = t.v[1], e[1] = t.v[2];
        edge = 1;
        break;
      case 1:
        e[0] = t.v[2], e[1] = t.v[0];
        edge = 2;
        break;
      case 2:
        e[0] = t.v[0], e[1] = t.v[1];
        edge = 0;
        break;
    }
    
    if (t.e[edge])
      continue;
    
    float d = e[0].distance(e[1]); 
    
    Triangle *ne = NULL;
    int       neid = 3;
    int       nevid = 3;
    
    /*for (Triangle& te: triangles) {
      if (!te.e[0] && isEqualEdge(e[0], e[1], te.v[0], te.v[1])) {
        ne = &te;
        neid = 0;
        nevid = 2;
        
        break;
      } else if (!te.e[1] && isEqualEdge(e[0], e[1], te.v[1], te.v[2])) {
        ne = &te;
        neid = 1;
        nevid = 0;
        
        break;
      } else if (!te.e[2] && isEqualEdge(e[0], e[1], te.v[2], te.v[0])) {
        ne = &te;
        neid = 2;
        nevid = 1;
        
        break;
      }
    }*/
    
    cVec3<float> n = t.n;
    
    if (ne != NULL) {
      n = n + ne->n;
      
      n.normalize();
      ne->e[neid] = true;
    }
    
    cVec3<float> pt = (e[0] + e[1]) * 0.5f;// + n * d * 0.5f;
    
    t.e[edge] = true;
    
    Triangle ta;
    
    //current
    ta.v[0] = t.v[vid], ta.v[1] = e[0], ta.v[1] = pt;
    ta.n = normal(ta.v[0], ta.v[1], ta.v[2]); ta.n.normalize();
    smoothed.push_back(ta);

    ta.v[0] = t.v[vid], ta.v[1] = pt, ta.v[1] = e[1];
    ta.n = normal(ta.v[0], ta.v[1], ta.v[2]); ta.n.normalize();
    smoothed.push_back(ta);
    
    //neighbour
    /*if (ne != NULL) {
      ta.v[0] = ne->v[nevid], ta.v[1] = e[(nevid==2)?(0):(nevid+1)], ta.v[1] = pt;
      ta.n = normal(ta.v[0], ta.v[1], ta.v[2]); ta.n.normalize();
      smoothed.push_back(ta);

      ta.v[0] = t.v[vid], ta.v[1] = pt, ta.v[1] = e[1];
      ta.v[0] = ne->v[nevid], ta.v[1] = pt, ta.v[1] = e[(nevid==2)?(0):(nevid+1)];
      ta.n = normal(ta.v[0], ta.v[1], ta.v[2]); ta.n.normalize();
      smoothed.push_back(ta);
    }*/
  }

  mesh->tfaces.clear();
    
  for(Triangle t: smoothed) {
    cMesh::Vertex v;
    
    v.pos = t.v[0]; v.nor = t.n; mesh->tfaces.push_back(v);
    v.pos = t.v[1]; v.nor = t.n; mesh->tfaces.push_back(v);
    v.pos = t.v[2]; v.nor = t.n; mesh->tfaces.push_back(v);
  }  
      
  return true;
}

inline void cSmooth::subdivide(cVec3<float> v1, cVec3<float> v2, cVec3<float> v3, int depth, std::list<cSmooth::Triangle>& smoothed) {
  cVec3<float> v12, v23, v31;
  
  if (depth == 0) {
    Triangle tr;
    
    tr.v[0] = v1;
    tr.v[1] = v2;
    tr.v[2] = v3;
    
    smoothed.push_back(tr);
    
    return;
  }
  
  v12 = (v1 + v2) * 0.5f;
  v23 = (v2 + v3) * 0.5f;
  v31 = (v3 + v1) * 0.5f;
  
  //v12.normalize();
  //v23.normalize();
  //v31.normalize();
  
  subdivide(v1,  v12, v31, depth - 1, smoothed);
  subdivide(v2,  v23, v12, depth - 1, smoothed);
  subdivide(v3,  v31, v23, depth - 1, smoothed);
  subdivide(v12, v23, v31, depth - 1, smoothed);
}

bool cSmooth::smooth001(cMesh* mesh, int depth)
{
  if (!mesh)
    return false;
    
  std::list<Triangle>  triangles;
  
  int count = mesh->getFaceCount();
  cMesh::Vertex* tfaces = mesh->getTFaces();
      
  for (int i = 0; i < count; i += 3) {
    Triangle tr;
    
    cMesh::Vertex v;
    v = tfaces[i];
    tr.v[0] = v.pos;
    v = tfaces[i + 1];
    tr.v[1] = v.pos;
    v = tfaces[i + 2];
    tr.v[2] = v.pos;
    
    //tr.n = normal(tr.v[0], tr.v[1], tr.v[2]);
    //tr.n.normalize();
    
    //tr.id = i / 3;
    //tr.used = tr.e[0] = tr.e[1] = tr.e[2] = false;
    
    triangles.push_back(tr);
  }

  std::list<Triangle>  smoothed;
  
  for(Triangle& t: triangles) {
    subdivide(t.v[0], t.v[1], t.v[2], depth, smoothed);
  }
    
  mesh->tfaces.clear();
    
  for(Triangle t: smoothed) {
    cMesh::Vertex v;
    
    v.pos = t.v[0]; v.nor = t.v[0]; mesh->tfaces.push_back(v);
    v.pos = t.v[1]; v.nor = t.v[1]; mesh->tfaces.push_back(v);
    v.pos = t.v[2]; v.nor = t.v[2]; mesh->tfaces.push_back(v);
  }  
      
  return true;
}

bool cSmooth::smooth(cMesh::Vertex* tfaces, int count)
{
  if (!tfaces || count < 0)
    return false;
    
  triangles.clear();
  smoothed.clear();
  
  for (int i = 0; i < count; i += 3) {
    Triangle tr;
    
    cMesh::Vertex v;
    v = tfaces[i];
    tr.v[0] = v.pos;
    v = tfaces[i + 1];
    tr.v[1] = v.pos;
    v = tfaces[i + 2];
    tr.v[2] = v.pos;
    
    tr.n = normal(tr.v[0], tr.v[1], tr.v[2]);
    
    tr.id = i / 3;
    tr.used = false;
    
    triangles.push_back(tr);
  }

  int i = 0;
  
  for (Triangle& t: triangles) {
    STriangle str = split(t);

    str.id = i++;

    smoothed.push_back(str);
  }
  
  for (STriangle& t: smoothed) {
    align(t);
  }
  
  return true;
}

cSmooth::STriangle cSmooth::split(Triangle& tr)
{
  STriangle str;
  
  str.base = tr;

  tr.n.normalize();
  
  str.split[0].v[0] = (tr.v[0] + tr.v[1]) * 0.5f;
  str.split[0].v[1] = (tr.v[1] + tr.v[2]) * 0.5f;
  str.split[0].v[2] = (tr.v[2] + tr.v[0]) * 0.5f;
  str.split[0].n    = normal(str.split[0].v[0], str.split[0].v[1], str.split[0].v[2]);
  str.split[0].n.normalize();
  str.split[0].p[0] = str.split[0].p[1] = str.split[0].p[2] = false;
    
  return str;
}

void cSmooth::align(STriangle &t)
{
  for (int i = 0; i < 3; i++) {    
    if (t.split[0].p[i]) 
      continue;
            
    std::list< cVec3<float>* > points;
    std::list< bool* >         bpoints;

    cVec3<float> n = t.split[0].n;
    float        d = 0.1f * t.split[0].v[0].distance(t.split[0].v[1]);

    t.split[0].p[i] = true;
    
    for (STriangle& st: smoothed) {
      if (st.id <= t.id)
        continue;
          
      if (vecEqual(t.split[0].v[i], st.split[0].v[0], 5)) {
        n = n + st.split[0].n;
        points.push_back(&st.split[0].v[0]);
        bpoints.push_back(&st.split[0].p[0]);          
      } else if (vecEqual(t.split[0].v[i],st.split[0].v[1], 5)) {
        n = n + st.split[0].n;
        points.push_back(&st.split[0].v[1]);
        bpoints.push_back(&st.split[0].p[1]);          
      } else if (vecEqual(t.split[0].v[i], st.split[0].v[2], 5)) {
        n = n + st.split[0].n;
        points.push_back(&st.split[0].v[2]);
        bpoints.push_back(&st.split[0].p[2]);          
      }
    }

    n.normalize();

    cVec3<float> vo = t.split[0].v[i];      
    
    cVec3<float> vu = t.split[0].v[i] - n * d;

    t.split[0].v[i] = vu;
    t.split[0].p[i] = true;
    
    for (auto p: points) {
      *p = vu;
    }

    for (auto b: bpoints) {
      *b = true;
    }
    
    points.clear();
    bpoints.clear();
  }
    
  t.split[0].n    = normal(t.split[0].v[0], t.split[0].v[1], t.split[0].v[2]);
  t.split[0].n.normalize();
  
  t.split[1].v[0] = t.base.v[0];
  t.split[1].v[1] = t.split[0].v[0];
  t.split[1].v[2] = t.split[0].v[2];
  t.split[1].n    = normal(t.split[1].v[0], t.split[1].v[1], t.split[1].v[2]);
  t.split[1].n.normalize();

  t.split[2].v[0] = t.split[0].v[0];
  t.split[2].v[1] = t.base.v[1];
  t.split[2].v[2] = t.split[0].v[1];
  t.split[2].n    = normal(t.split[2].v[0], t.split[2].v[1], t.split[2].v[2]);
  t.split[2].n.normalize();

  t.split[3].v[0] = t.split[0].v[1];
  t.split[3].v[1] = t.base.v[2];
  t.split[3].v[2] = t.split[0].v[2];
  t.split[3].n    = normal(t.split[3].v[0], t.split[3].v[1], t.split[3].v[2]);
  t.split[3].n.normalize();
}

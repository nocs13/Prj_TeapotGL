#include "cexplode.h"
#include "cvec3.h"

cExplode::cExplode(cMesh* m)
{
  if (!m)
    return;
    
  int faces = m->getTFaceCount();
  
  chunks.resize(faces);
  
  Vertex* v = m->getTFaces();
  
  for (int i = 0; i < faces; i++)
    chunks[i] = v[i];
    
  speed.resize(faces / 3);
  
  //change to control explode speed. it should be 
  //depend on FPS. but now not realised.
  
  const int sss = 3.0;
  
  for(int i = 0; i < speed.size(); i++) {
    speed[i] = sss * (float)rand() / (float) RAND_MAX;
  }
}

cExplode::~cExplode()
{
  speed.clear();
  chunks.clear();
}  

void cExplode::simulate()
{
  for (int i = 0; i < speed.size(); i++) {
    int j = i * 3;
    
    float cspeed = speed[i];
    
    Vertex v[3] = {chunks[j], chunks[j + 1], chunks[j + 2]};
    cVec3<float> nor(v[0].nor[0], v[0].nor[1], v[0].nor[2]);
    cVec3<float> v1(v[0].pos[0], v[0].pos[1], v[0].pos[2]),
                 v2(v[1].pos[0], v[1].pos[1], v[1].pos[2]),
                 v3(v[2].pos[0], v[2].pos[1], v[2].pos[2]);
                 
                 
    v1 = v1 + nor * cspeed;
    v2 = v2 + nor * cspeed;
    v3 = v3 + nor * cspeed;
    
    chunks[j].pos      = v1;
    chunks[j + 1].pos  = v2;
    chunks[j + 2].pos  = v3;
    //memcpy(chunks[j].pos,     &v1, 3 * sizeof(float));
    //memcpy(chunks[j + 1].pos, &v2, 3 * sizeof(float));
    //memcpy(chunks[j + 2].pos, &v3, 3 * sizeof(float));
  }
}
    
cMesh::Vertex* cExplode::getChunks()
{
  return chunks.data();
}

int cExplode::getChunkCount()
{
  return chunks.size();
}


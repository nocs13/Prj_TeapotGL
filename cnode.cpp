#include <iostream>
#include "cnode.h"
#include "cmesh.h"
#include "cexplode.h"

cNode::cNode()
{
  mesh = NULL;
  type = Type_None;
  
  valid   = true;
  visible = true;
}

cNode::~cNode()
{
  if (type == Type_Explode && explode)
    delete explode;
}
  
void cNode::setMesh(cMesh* m)
{
  if (mesh) {
    std::cout << "Node initilized" << std::endl;
    
    return;
  }
  
  mesh = m;
  type = Type_Mesh;
}
  
void cNode::setExplode(cExplode* e)
{
  if (explode) {
    std::cout << "Node initilized" << std::endl;
    
    return;
  }
  
  explode = e;
  type = Type_Explode;
}
  
void cNode::setPosition(float x, float y, float z)
{
  pos = cVec3<float>(x, y, z);
}

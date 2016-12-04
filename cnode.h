#include <iostream>
#include "cvec3.h"

class cMesh;
class cExplode;

class cNode
{
  public:
  
  enum Type {
    Type_None,
    Type_Mesh,
    Type_Explode
  };
  
  public:
    cNode();
    ~cNode();
  
    void setMesh(cMesh*);
    void setExplode(cExplode*);
    void setPosition(float x, float y, float z);
    
    cVec3<float> position() const
    {
      return pos;
    }
    
    cMesh* getMesh() const
    {
      if (type != Type_Mesh)
        return NULL;
        
      return mesh;
    }
    
    cExplode* getExplode() const
    {
      if (type != Type_Explode)
        return NULL;
        
      return explode;
    }
    
    void show() {
      visible = true;
    }
    
    void hide() {
      visible = false;
    }
    
    bool visibility() const {
      return visible;
    }
    
    Type getType() const {
      return type;
    }
    
    bool isValid() const {
      return valid;
    }
    
    void remove() {
      valid = false;
    }
  
  private:
    union {
      cMesh *mesh;
      cExplode *explode;
    };
    
    cVec3<float> pos;
    
    bool visible;
    bool valid;
    
    Type type;
};

#include "cmesh.h"

class cExplode: public cMesh
{
  public:
    cExplode(cMesh*);
    ~cExplode();
    
    void simulate();
    
    Vertex* getChunks();
    int     getChunkCount();
    
  private:
    std::vector<Vertex> chunks;
    std::vector<float>  speed;
};

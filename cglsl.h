#pragma once 

enum ShaderId
{
  Shader_0,
  Shader_1
};

class cGLSL
{
  public:
    cGLSL();
    ~cGLSL();
        
    void link();
    void unlink();
    
    bool prepare(ShaderId);
    
    void setVec3(const char*, float*);
    
    int getLocation(const char *);
    
  private:
    bool load(const char *, const char *);
  
  private:
    void* program;
};

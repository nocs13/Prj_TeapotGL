#include <iostream>
#include "cglsl.h"
#include "cglext.h"

#include "shaders.inl"

#define GL_OBJECT_COMPILE_STATUS      0x8B81

cGLSL::cGLSL()
{
  program = NULL;
}

cGLSL::~cGLSL()
{
  if (program) {
    cGLExt::glUseProgramObject(0);
    cGLExt::glDeleteObject((GLhandleARB) program);
    
    program = NULL;
  }
}

bool cGLSL::prepare(ShaderId id)
{
  char *v = NULL;
  char *f = NULL;
  
  switch(id)
  {
    case Shader_0:
      v = (char*) v_shaders[0];
      f = (char*) f_shaders[0];
    break;
    case Shader_1:
    break;
  }
  
  return load((const char*) v, (const char*) f);
}

bool cGLSL::load(const char *v, const char *f)
{
  if (!v || !f) {
    std::cout << "Invalid shader source." << std::endl;
    return false;
  }
  
  int size = strlen(v);
  int stat[] = {0};
  
  char info[255];
  
  GLhandleARB hv = cGLExt::glCreateShaderObject(GL_VERTEX_SHADER);
  cGLExt::glShaderSource(hv, 1, (const GLcharARB**)&v, &size);
  cGLExt::glCompileShader(hv);
  cGLExt::glGetObjectParameteriv(hv, GL_OBJECT_COMPILE_STATUS, stat);
  
  if (stat[0] == GL_FALSE) {
    cGLExt::glGetInfoLog(hv, 256, &size, info);
      
    std::cout << "VShader error: " << (char*)info << std::endl;

    cGLExt::glDeleteObject(hv);
    
    return false;
  }
    
  size = strlen(f); 
  
  GLhandleARB hf = cGLExt::glCreateShaderObject(GL_FRAGMENT_SHADER);
  cGLExt::glShaderSource(hf, 1, (const GLcharARB**)&f, &size);
  cGLExt::glCompileShader(hf);
  cGLExt::glGetObjectParameteriv(hf, GL_OBJECT_COMPILE_STATUS, stat);
  
  if (stat[0] == GL_FALSE) {
    cGLExt::glGetInfoLog(hf, 256, &size, info);
      
    std::cout << "FShader error: " << (char*)info << std::endl;

    cGLExt::glDeleteObject(hv);
    cGLExt::glDeleteObject(hf);
    
    return false;
  }
    
  program = (void*) cGLExt::glCreateProgramObject();

  if(GL_NO_ERROR != glGetError())
  {
    std::cout << "Error while create program object: " 
              << glGetError() << std::endl;

    cGLExt::glDeleteObject(hv);
    cGLExt::glDeleteObject(hf);
    
    program = NULL;
    
    return false;
  }
  
  cGLExt::glAttachObject((GLhandleARB) program, hv);
  cGLExt::glAttachObject((GLhandleARB) program, hf);
  cGLExt::glLinkProgram((GLhandleARB) program);
  
  cGLExt::glDeleteObject(hv);
  cGLExt::glDeleteObject(hf);
  
  cGLExt::glBindAttribLocation((GLhandleARB)program, 0, "a_Vertex");
  cGLExt::glBindAttribLocation((GLhandleARB)program, 1, "a_Normal");

    
  return true;
}

int cGLSL::getLocation(const char *id)
{
  if (!program)
    return -1;
    
  return cGLExt::glGetAttribLocation((GLhandleARB) program, id);
}

void cGLSL::link()
{
  cGLExt::glUseProgramObject((GLhandleARB) program);
}

void cGLSL::unlink()
{
  cGLExt::glUseProgramObject(0);
}

void cGLSL::setVec3(const char *id, float *val)
{
  if (program) {
    GLint location = cGLExt::glGetUniformLocation((GLhandleARB) program, id);
    cGLExt::glUniform3fv(location, 1, val);
    //std::cout << "location is " << location << std::endl;
  }
}



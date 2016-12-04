#include "cglext.h"

#define GLEXT_FN(func, type) func = (type)wglGetProcAddress(#func); \
                             if(!func) return false;

PFNGLVERTEXPOINTERARBPROC        cGLExt::glVertexPointer = NULL;
PFNGLNORMALPOINTERARBPROC        cGLExt::glNormalPointer = NULL;

PFNGLCREATEPROGRAMOBJECTARBPROC  cGLExt::glCreateProgramObject = NULL;
PFNGLCREATESHADEROBJECTARBPROC   cGLExt::glCreateShaderObject = NULL;
PFNGLDELETEOBJECTARBPROC         cGLExt::glDeleteObject = NULL;
PFNGLSHADERSOURCEARBPROC         cGLExt::glShaderSource = NULL;
PFNGLCOMPILESHADERARBPROC        cGLExt::glCompileShader = NULL;
PFNGLATTACHOBJECTARBPROC         cGLExt::glAttachObject = NULL;
PFNGLDETACHOBJECTARBPROC         cGLExt::glDetachObject = NULL;
PFNGLLINKPROGRAMARBPROC          cGLExt::glLinkProgram = NULL;
PFNGLVALIDATEPROGRAMARBPROC      cGLExt::glValidateProgram = NULL;
PFNGLUSEPROGRAMOBJECTARBPROC     cGLExt::glUseProgramObject = NULL;
PFNGLGETOBJECTPARAMETERFVARBPROC cGLExt::glGetObjectParameterfv = NULL;
PFNGLGETOBJECTPARAMETERIVARBPROC cGLExt::glGetObjectParameteriv = NULL;
PFNGLGETINFOLOGARBPROC           cGLExt::glGetInfoLog = NULL;
PFNGLGETUNIFORMLOCATIONARBPROC   cGLExt::glGetUniformLocation = NULL;
PFNGLUNIFORM1IARBPROC            cGLExt::glUniform1i = NULL;
PFNGLUNIFORM1IVARBPROC           cGLExt::glUniform1iv = NULL;
PFNGLUNIFORM2IVARBPROC           cGLExt::glUniform2iv = NULL;
PFNGLUNIFORM3IVARBPROC           cGLExt::glUniform3iv = NULL;
PFNGLUNIFORM4IVARBPROC           cGLExt::glUniform4iv = NULL;
PFNGLUNIFORM1FVARBPROC           cGLExt::glUniform1fv = NULL;
PFNGLUNIFORM2FVARBPROC           cGLExt::glUniform2fv = NULL;
PFNGLUNIFORM3FVARBPROC           cGLExt::glUniform3fv = NULL;
PFNGLUNIFORM4FVARBPROC           cGLExt::glUniform4fv = NULL;
PFNGLUNIFORMMATRIX2FVARBPROC     cGLExt::glUniformMatrix2fv = NULL;
PFNGLUNIFORMMATRIX3FVARBPROC     cGLExt::glUniformMatrix3fv = NULL;
PFNGLUNIFORMMATRIX4FVARBPROC     cGLExt::glUniformMatrix4fv = NULL;
PFNGLBINDATTRIBLOCATIONARBPROC   cGLExt::glBindAttribLocation = NULL;
PFNGLGETUNIFORMFVARBPROC         cGLExt::glGetUniformfv = NULL;
PFNGLGETATTRIBLOCATIONARBPROC    cGLExt::glGetAttribLocation = NULL;
PFNGLDISABLEVERTEXATTRIBARRAYARBPROC cGLExt::glDisableVertexAttribArray = NULL;
PFNGLENABLEVERTEXATTRIBARRAYARBPROC  cGLExt::glEnableVertexAttribArray = NULL;


bool cGLExt::init()
{
  GLEXT_FN(glVertexPointer, PFNGLVERTEXPOINTERARBPROC);
  GLEXT_FN(glNormalPointer, PFNGLNORMALPOINTERARBPROC);
  
  GLEXT_FN(glCreateProgramObject, PFNGLCREATEPROGRAMOBJECTARBPROC);
  GLEXT_FN(glCreateShaderObject, PFNGLCREATESHADEROBJECTARBPROC);
  GLEXT_FN(glDeleteObject, PFNGLDELETEOBJECTARBPROC);
  GLEXT_FN(glShaderSource, PFNGLSHADERSOURCEARBPROC);
  GLEXT_FN(glCompileShader, PFNGLCOMPILESHADERARBPROC);
  GLEXT_FN(glAttachObject, PFNGLATTACHOBJECTARBPROC);
  GLEXT_FN(glDetachObject, PFNGLDETACHOBJECTARBPROC);
  GLEXT_FN(glLinkProgram, PFNGLLINKPROGRAMARBPROC);
  GLEXT_FN(glValidateProgram, PFNGLVALIDATEPROGRAMARBPROC);
  GLEXT_FN(glUseProgramObject, PFNGLUSEPROGRAMOBJECTARBPROC);
  GLEXT_FN(glGetObjectParameterfv, PFNGLGETOBJECTPARAMETERFVARBPROC);
  GLEXT_FN(glGetObjectParameteriv, PFNGLGETOBJECTPARAMETERIVARBPROC);
  GLEXT_FN(glGetInfoLog, PFNGLGETINFOLOGARBPROC);
  GLEXT_FN(glGetUniformLocation, PFNGLGETUNIFORMLOCATIONARBPROC);
  GLEXT_FN(glUniform1i, PFNGLUNIFORM1IARBPROC);
  GLEXT_FN(glUniform1iv, PFNGLUNIFORM1IVARBPROC);
  GLEXT_FN(glUniform2iv, PFNGLUNIFORM2IVARBPROC);
  GLEXT_FN(glUniform3iv, PFNGLUNIFORM3IVARBPROC);
  GLEXT_FN(glUniform4iv, PFNGLUNIFORM4IVARBPROC);
  GLEXT_FN(glUniform1fv, PFNGLUNIFORM1FVARBPROC);
  GLEXT_FN(glUniform2fv, PFNGLUNIFORM2FVARBPROC);
  GLEXT_FN(glUniform3fv, PFNGLUNIFORM3FVARBPROC);
  GLEXT_FN(glUniform4fv, PFNGLUNIFORM4FVARBPROC);
  GLEXT_FN(glUniformMatrix2fv, PFNGLUNIFORMMATRIX2FVARBPROC);
  GLEXT_FN(glUniformMatrix3fv, PFNGLUNIFORMMATRIX3FVARBPROC);
  GLEXT_FN(glUniformMatrix4fv, PFNGLUNIFORMMATRIX4FVARBPROC);
  GLEXT_FN(glBindAttribLocation, PFNGLBINDATTRIBLOCATIONARBPROC);
  GLEXT_FN(glGetUniformfv, PFNGLGETUNIFORMFVARBPROC);
  GLEXT_FN(glGetAttribLocation, PFNGLGETATTRIBLOCATIONARBPROC);
  GLEXT_FN(glDisableVertexAttribArray, PFNGLDISABLEVERTEXATTRIBARRAYARBPROC);
  GLEXT_FN(glEnableVertexAttribArray, PFNGLENABLEVERTEXATTRIBARRAYARBPROC);
  
  return true;
}

void cGLExt::clear()
{
}

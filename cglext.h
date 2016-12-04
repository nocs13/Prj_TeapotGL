#pragma once

//#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#include <GL/glext.h>

typedef unsigned int GLu32;

typedef void (APIENTRY * PFNGLVERTEXPOINTERARBPROC) (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
typedef void (APIENTRY * PFNGLNORMALPOINTERARBPROC) (GLenum type, GLsizei stride, const GLvoid *pointer);

typedef GLhandleARB (APIENTRYP PFNGLCREATEPROGRAMOBJECTARBPROC) (void);
typedef void (APIENTRYP PFNGLDELETEOBJECTARBPROC) (GLhandleARB obj);
typedef GLhandleARB (APIENTRYP PFNGLGETHANDLEARBPROC) (GLenum pname);
typedef void (APIENTRYP PFNGLDETACHOBJECTARBPROC) (GLhandleARB containerObj, GLhandleARB attachedObj);
typedef GLhandleARB (APIENTRYP PFNGLCREATESHADEROBJECTARBPROC) (GLenum shaderType);
typedef void (APIENTRYP PFNGLSHADERSOURCEARBPROC) (GLhandleARB shaderObj, GLsizei count, const GLcharARB* *string, const GLint *length);
typedef void (APIENTRYP PFNGLCOMPILESHADERARBPROC) (GLhandleARB shaderObj);
typedef GLhandleARB (APIENTRYP PFNGLCREATEPROGRAMOBJECTARBPROC) (void);
typedef void (APIENTRYP PFNGLATTACHOBJECTARBPROC) (GLhandleARB containerObj, GLhandleARB obj);
typedef void (APIENTRYP PFNGLLINKPROGRAMARBPROC) (GLhandleARB programObj);
typedef void (APIENTRYP PFNGLUSEPROGRAMOBJECTARBPROC) (GLhandleARB programObj);
typedef void (APIENTRYP PFNGLVALIDATEPROGRAMARBPROC) (GLhandleARB programObj);
typedef void (APIENTRYP PFNGLUNIFORM1FARBPROC) (GLint location, GLfloat v0);
typedef void (APIENTRYP PFNGLUNIFORM2FARBPROC) (GLint location, GLfloat v0, GLfloat v1);
typedef void (APIENTRYP PFNGLUNIFORM3FARBPROC) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void (APIENTRYP PFNGLUNIFORM4FARBPROC) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
typedef void (APIENTRYP PFNGLUNIFORM1IARBPROC) (GLint location, GLint v0);
typedef void (APIENTRYP PFNGLUNIFORM2IARBPROC) (GLint location, GLint v0, GLint v1);
typedef void (APIENTRYP PFNGLUNIFORM3IARBPROC) (GLint location, GLint v0, GLint v1, GLint v2);
typedef void (APIENTRYP PFNGLUNIFORM4IARBPROC) (GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
typedef void (APIENTRYP PFNGLUNIFORM1FVARBPROC) (GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORM2FVARBPROC) (GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORM3FVARBPROC) (GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORM4FVARBPROC) (GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORM1IVARBPROC) (GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLUNIFORM2IVARBPROC) (GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLUNIFORM3IVARBPROC) (GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLUNIFORM4IVARBPROC) (GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2FVARBPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3FVARBPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4FVARBPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLGETOBJECTPARAMETERFVARBPROC) (GLhandleARB obj, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETOBJECTPARAMETERIVARBPROC) (GLhandleARB obj, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETINFOLOGARBPROC) (GLhandleARB obj, GLsizei maxLength, GLsizei *length, GLcharARB *infoLog);
typedef void (APIENTRYP PFNGLGETATTACHEDOBJECTSARBPROC) (GLhandleARB containerObj, GLsizei maxCount, GLsizei *count, GLhandleARB *obj);
typedef GLint (APIENTRYP PFNGLGETUNIFORMLOCATIONARBPROC) (GLhandleARB programObj, const GLcharARB *name);
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMARBPROC) (GLhandleARB programObj, GLu32 index, GLsizei maxLength, GLsizei *length, GLint *size, GLenum *type, GLcharARB *name);
typedef void (APIENTRYP PFNGLGETUNIFORMFVARBPROC) (GLhandleARB programObj, GLint location, GLfloat *params);
typedef void (APIENTRYP PFNGLGETUNIFORMIVARBPROC) (GLhandleARB programObj, GLint location, GLint *params);
typedef void (APIENTRYP PFNGLGETSHADERSOURCEARBPROC) (GLhandleARB obj, GLsizei maxLength, GLsizei *length, GLcharARB *source);
typedef void (APIENTRYP PFNGLBINDATTRIBLOCATIONARBPROC) (GLhandleARB programObj, GLu32 index, const GLcharARB *name);
typedef GLint (APIENTRYP PFNGLGETATTRIBLOCATIONARBPROC) (GLhandleARB programObj, const GLcharARB *name);
typedef void (APIENTRYP PFNGLENABLEVERTEXATTRIBARRAYARBPROC) (GLuint index);
typedef void (APIENTRYP PFNGLDISABLEVERTEXATTRIBARRAYARBPROC) (GLuint index);

struct cGLExt
{
  static PFNGLVERTEXPOINTERARBPROC        glVertexPointer;
  static PFNGLNORMALPOINTERARBPROC        glNormalPointer;
  
  static PFNGLCREATEPROGRAMOBJECTARBPROC  glCreateProgramObject;
  static PFNGLCREATESHADEROBJECTARBPROC   glCreateShaderObject;
  static PFNGLDELETEOBJECTARBPROC         glDeleteObject;
  static PFNGLSHADERSOURCEARBPROC         glShaderSource;
  static PFNGLCOMPILESHADERARBPROC        glCompileShader;
  static PFNGLATTACHOBJECTARBPROC         glAttachObject;
  static PFNGLDETACHOBJECTARBPROC         glDetachObject;
  static PFNGLLINKPROGRAMARBPROC          glLinkProgram;
  static PFNGLVALIDATEPROGRAMARBPROC      glValidateProgram;
  static PFNGLUSEPROGRAMOBJECTARBPROC     glUseProgramObject;
  static PFNGLGETOBJECTPARAMETERFVARBPROC glGetObjectParameterfv;
  static PFNGLGETOBJECTPARAMETERIVARBPROC glGetObjectParameteriv;
  static PFNGLGETINFOLOGARBPROC           glGetInfoLog;
  static PFNGLGETUNIFORMLOCATIONARBPROC   glGetUniformLocation;
  static PFNGLUNIFORM1IARBPROC            glUniform1i;
  static PFNGLUNIFORM1IVARBPROC           glUniform1iv;
  static PFNGLUNIFORM2IVARBPROC           glUniform2iv;
  static PFNGLUNIFORM3IVARBPROC           glUniform3iv;
  static PFNGLUNIFORM4IVARBPROC           glUniform4iv;
  static PFNGLUNIFORM1FVARBPROC           glUniform1fv;
  static PFNGLUNIFORM2FVARBPROC           glUniform2fv;
  static PFNGLUNIFORM3FVARBPROC           glUniform3fv;
  static PFNGLUNIFORM4FVARBPROC           glUniform4fv;
  static PFNGLUNIFORMMATRIX2FVARBPROC     glUniformMatrix2fv;
  static PFNGLUNIFORMMATRIX3FVARBPROC     glUniformMatrix3fv;
  static PFNGLUNIFORMMATRIX4FVARBPROC     glUniformMatrix4fv;
  static PFNGLBINDATTRIBLOCATIONARBPROC   glBindAttribLocation;
  static PFNGLGETUNIFORMFVARBPROC         glGetUniformfv;
  
  static PFNGLGETATTRIBLOCATIONARBPROC        glGetAttribLocation;
  static PFNGLDISABLEVERTEXATTRIBARRAYARBPROC glDisableVertexAttribArray;
  static PFNGLENABLEVERTEXATTRIBARRAYARBPROC  glEnableVertexAttribArray;
  
  static bool init();
  static void clear();
};

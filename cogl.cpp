#include <windows.h>
#include <iostream>
#include "cogl.h"
#include "cglext.h"

cOGL::cOGL()
{
  PIXELFORMATDESCRIPTOR pfd = {
    sizeof(PIXELFORMATDESCRIPTOR),
      1,
      PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
      PFD_TYPE_RGBA,            
      32,                       
      0, 0, 0, 0, 0, 0,
      0,
      0,
      0,
      0, 0, 0, 0,
      24,                       
      8,                        
      0,                        
      PFD_MAIN_PLANE,
      0,
      0, 0, 0
  };
  
  pfd_   = pfd;
  hdc_   = NULL;
  hglrc_ = NULL;
}

cOGL::~cOGL()
{
  wglDeleteContext(hglrc_);
}

bool cOGL::open(HWND hwnd)
{
  if (hwnd == NULL || hwnd == INVALID_HANDLE_VALUE) {
    std::cerr << "no valid widnow" << std::endl;
    return false;
  }
    
  if (hglrc_) {
    std::cerr << "GL context already exist" << std::endl;
    return false;
  }
    
  hdc_ = GetDC(hwnd);
  
  int chooseFormat = ChoosePixelFormat(hdc_, &pfd_);
  SetPixelFormat(hdc_, chooseFormat, &pfd_);
  
  hglrc_ = wglCreateContext(hdc_);
  wglMakeCurrent(hdc_, hglrc_);
  
  //MessageBoxA(0,(char*)glGetString(GL_VERSION), "OPENGL VERSION",0);
  std::cout << "OPENGL VERSION: " <<  (char*)glGetString(GL_VERSION) << std::endl;

  return true;
}

void cOGL::swap()
{
  SwapBuffers(hdc_);
}

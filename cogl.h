// Class automatically generated by Dev-C++ New Class wizard
#pragma once

#ifndef COGL_H
#define COGL_H

#include <windows.h>
#include <GL/GL.h>

/*
 * No description
 */
class cOGL
{
 public:
  // class constructor
  cOGL();
  // class destructor
  ~cOGL();
  
  bool open(HWND hwnd);
  void close();
  void swap();
  
 private:
  PIXELFORMATDESCRIPTOR pfd_;
  HDC                   hdc_;
  HGLRC                 hglrc_;
};

#endif // COGL_H

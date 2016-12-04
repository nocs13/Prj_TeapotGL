#pragma once
#include <math.h>

template <class T> class cVec3
{
  public:
  cVec3()
  {
    v[0] = v[1] = v[2] = T(0);  
  }
  
  cVec3(T x, T y, T z)
  {
    v[0] = x, v[1] = y, v[2] = z;  
  }
  
  cVec3<T> operator+(cVec3<T> v)
  {
    return cVec3<T>(x() + v.x(), y() + v.y(), z() + v.z());
  }
  
  cVec3<T> operator-(cVec3<T> v)
  {
    return cVec3<T>(x() - v.x(), y() - v.y(), z() - v.z());
  }
  
  cVec3<T> operator*(T t)
  {
    return cVec3<T>(x() * t, y() * t, z() * t);
  }
  
  cVec3<T> operator*=(T t)
  {
    v[0] *= t;
    v[1] *= t;
    v[2] *= t;
    
    return cVec3<T>(x(), y(), z());
  }
  
  T& operator[](int i)
  {
    return v[i];
  }
  
  bool operator==(cVec3<T> v) {
    return (x() == v.x() && y() == v.y() && z() == v.z());
  }
  
  T length()
  {
    return sqrt(x() * x() + y() * y() + z() * z());
  }
  
  T distance(cVec3<T> v)
  {
    T cx = v.x() - x();
    T cy = v.y() - y();
    T cz = v.z() - z();

    return sqrt(cx * cx + cy * cy + cz * cz);
  }
  
  T x()
  {
    return v[0];
  }
  
  T y()
  {
    return v[1];
  }
  
  T z()
  {
    return v[2];
  }
  
  T dot(const cVec3<T>& v) {
    return (x() * v.x() + y() * v.y() + z() * v.z());
  }
  
  cVec3<T> cross(cVec3<T> v) {
    return cVec3<T>(y() * v.z() - z() * v.y(), 
                    z() * v.x() - x() * v.z(), 
                    x() * v.y() - y() * v.x());
  }
  
  void normalize() {
    T l = length();
    
    if (l == T(0))
      return;
      
    v[0] /= l;
    v[1] /= l;
    v[2] /= l;
  }

  void invert() {
    v[0] = -v[0];
    v[1] = -v[1];
    v[2] = -v[2];
  }
  
  private:
    T v[3];
};

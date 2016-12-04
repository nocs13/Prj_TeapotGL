#include "cvec3.h"

#define CMTX4_ROW1 0
#define CMTX4_ROW2 1
#define CMTX4_ROW3 2
#define CMTX4_ROW4 3

template <class T> class cMtx4
{
  public:
    cMtx4()
    {
      memset(m, T(0), sizeof(T))
    }
    
    cMtx4<T> operator+(const cMtx4<T> a)
    {
      cMtx4<T> r;
      
      for (int i = 0; i < 16; i++)
        r.m[i] = m[i] + a.m[i];
      
      return r;
    }
    
    void setRow(int row, T a, T b, T c, T d)
    {
      if (row < CMTX_ROW1 || row > CMTX4_ROW4)
        return;
        
      m[row * 4 + 0] = a;
      m[row * 4 + 1] = b;
      m[row * 4 + 2] = c;
      m[row * 4 + 3] = d;
    }
      
  private:
    T m[16];
};

#include "cteapot.h"

#define MIN_SMOOTH 1
#define MAX_SMOOTH 10

cTeapot::cTeapot()
{
  smooth = MIN_SMOOTH;  
}

cTeapot::~cTeapot()
{
}
    
bool cTeapot::update()
{
  if (tfaces.size() > 0)
    tfaces.clear();
    
  return true;
}

void cTeapot::setSmooth(int i)
{
  if (i < MIN_SMOOTH)
    smooth = MIN_SMOOTH;
  else if (i > MAX_SMOOTH)
    smooth = MAX_SMOOTH;
  else
    smooth = i;
}

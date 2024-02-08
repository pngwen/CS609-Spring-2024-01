///////////////////////////////////////////////////////////////////////////
// File: octagon.h
// Purpose: A drawable which draws an hour glass
// Author: Kapil < kcheemarla1s@semo.edu >
// Author: Sai Kumar < sboreddy1s@semo.edu >
// Author: Venu Mamidi < vmamidi1s@semo.edu >
// Author: Yash Barot < ybarot1s@semo.edu >
// Author: Vamsi Krishna < vswarna1s@semo.edu >
// Author: Mahesh Munna < mmunna1s@semo.edu >
// Author: KrishnaSai Kavuri < saikavuri5566@gmail.com >
///////////////////////////////////////////////////////////////////////////
#ifndef OCTAGON_H
#define OCTAGON_H

#include "drawable.h"

class Octagon : public Drawable {
public:
  Octagon(int x, int y, int size);
  virtual void draw(Canvas *canvas) override;

private:
  int _x;
  int _y;
  int _size; 
};

#endif 

#pragma once
#include "SFML/Graphics.hpp"
class Enemy1
{
 public:
  Enemy1(float xpos, float ypos);
 ~Enemy1();
  
 float xpos;
 float ypos;
 float xmove;
 float xr;
 float xl;
 void update();
 
 private:

};

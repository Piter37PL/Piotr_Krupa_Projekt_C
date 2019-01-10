#pragma once
#include "SFML/Graphics.hpp"
class Enemy2
{
 public:
  Enemy2(float xpos, float ypos);
 ~Enemy2();
  
 float xpos;
 float ypos;
 float ymove;
 float yu;
 float yd;
 void update();
 
 private:

};

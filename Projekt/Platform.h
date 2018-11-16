#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

class Platform
{
 public:
  Platform(int &rosx, int &rosy);
  ~Platform();

  int arrayP[20][20];
  sf::Texture TextureBlock;
  sf::Sprite spriteBlock[20];

  void drawGround(sf::RenderWindow &window);

 private:
  
  
};

#pragma once
#include "SFML/Graphics.hpp"

class Ground
{
 public:
  Ground();
  ~Ground();

  void drawGround(sf::RenderWindow &window); 

 private:
  sf::Texture textureGround;
  sf::Sprite  spriteGround;
  int rosxG;
  int rosyG;
  int blocX;
  int blocY;

};

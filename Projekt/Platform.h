#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

class Platform
{
 public:
  Platform(int x, int y, int nx, int ny);
  ~Platform();
  
  Player objFplayer;
 
  void drawPlatform(sf::RenderWindow &window);    //Metoda rysująca platformy - testowa
  void collisionPlatform();

 private:
  sf::Texture textureBlock;                       //Tekstura bloczku platformy
  sf::Sprite spritePlatform;                      //Sprite bloczku platformy
  int rosxB;                                      //rozmiar ekranu oś x
  int rosyB;                                      //rozmiar ekranu oś y
  int blocX;                                      //rozmiar bloczka oś x
  int blocY;                                      //rozmiar bloczka oś y
  int x;
  int y;
  int nx;
  int ny;
 
};

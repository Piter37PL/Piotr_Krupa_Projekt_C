#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

class Platform
{
 public:
  Platform(int &rosx, int &rosy);                 //Pobranie od main rozdzielczości ekranu
  ~Platform();
  
  void drawGround(sf::RenderWindow &window);      //Metoda rysująca "podłogę" - testowa
  void drawPlatform(sf::RenderWindow &window);    //Metoda rysująca platformy - testowa

 private:
  sf::Texture textureBlock;                       //Tekstura bloczku
  sf::Sprite spriteBlock;                         //Sprite bloczku
 
  int rosxB;                                      //rozmiar ekranu oś x
  int rosyB;                                      //rozmiar ekranu oś y
  int blocX;                                      //rozmiar bloczka oś x
  int blocY;                                      //rozmiar bloczka oś y
  
};

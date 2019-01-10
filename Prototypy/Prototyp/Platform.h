#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
class Platform
{
 public:
  Platform(int x, int y, int nx, int ny);
  ~Platform();

  void drawPlatform(sf::RenderWindow &window);    //Metoda rysująca platformy - testowa
  
  int GetX();                                     //Pobieranie wartości x
  int GetY();                                     //Pobieranie wartości y
  int GetNX();                                    //Pobieranie wartości nx
  int GetNY();                                    //Pobieranie wartości ny
  int GetBlocX();                                 //Pobieranie wartości blocX
  int GetBlocY();                                 //Pobieranie wartości blocY

 private:
  sf::Texture textureBlock;                       //Tekstura bloczku platformy
  sf::Sprite spritePlatform;                      //Sprite bloczku platformy
  int rosxB;                                      //rozmiar ekranu oś x
  int rosyB;                                      //rozmiar ekranu oś y
  int blocX;                                      //rozmiar bloczka oś x
  int blocY;                                      //rozmiar bloczka oś y
  int x;                                          //współrzędna x pierwszego bloczka
  int y;                                          //współrzędna y pierwszeho bloczka
  int nx;                                         //ile ma rysować bloczków w osi x
  int ny;                                         //ile ma rysować bloczków w osi y

 
};

#pragma once
//Biblioteki
#include "SFML/Graphics.hpp"

class Ground
{
 public:
  Ground();
  ~Ground();

  void drawGround(sf::RenderWindow &window);          //Rysowanie ziemi
  int GetYMin();                                      //Pobieranie wartości granicy ziemi w y
  
 private:
  sf::Texture textureGround;                         //Tekstura ziemi
  sf::Sprite  spriteGround;                          //Sprite   ziemi
  int rosyG;                                         //Rozmiar ekranu w osi y
  int blocX;                                         //Rozmiar bloczka w osi x
  int blocY;                                         //Rozmiar bloczka w osi y


};

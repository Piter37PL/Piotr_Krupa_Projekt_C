#pragma once
//Biblioteki
#include "SFML/Graphics.hpp"

class Platform
{
 public:
  Platform(int x, int y, int nx);
  ~Platform();

  void drawPlatform(sf::RenderWindow &window);    //Metoda rysująca platformy 
  
  int GetX();                                     //Pobieranie wartości x
  int GetY();                                     //Pobieranie wartości y
  int GetNX();                                    //Pobieranie wartości nx
  int GetBlocX();                                 //Pobieranie wartości blocX
  int GetBlocY();                                 //Pobieranie wartości blocY
 private:
  sf::Texture textureBlock;                       //Tekstura bloczku platformy
  sf::Sprite spritePlatform;                      //Sprite bloczku platformy
  int blocX;                                      //rozmiar bloczka oś x
  int blocY;                                      //rozmiar bloczka oś y
  int x;                                          //współrzędna x pierwszego bloczka
  int y;                                          //współrzędna y pierwszeho bloczka
  int nx;                                         //ile ma rysować bloczków w osi x

 
};

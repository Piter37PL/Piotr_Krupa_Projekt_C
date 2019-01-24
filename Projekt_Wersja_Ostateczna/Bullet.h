#pragma once
//Biblioteki
#include "SFML/Graphics.hpp"

class Bullet
{
 public:
 Bullet(sf::Vector2f size); //Rozmiar bullet
 ~Bullet();

 void fire(int speed);      //Ruch Bullet(prędkość ruchu)
 void draw(sf::RenderWindow &window); //Rysowanie Bullet
 void setPos(sf::Vector2f newPos);    //Ustawienie pozycji Bullet
 float GetPosX();                      //Pobieranie wartości
 float GetPosY();
 
 private:
  sf::RectangleShape bullet;         //bullet jako prostokąt
};



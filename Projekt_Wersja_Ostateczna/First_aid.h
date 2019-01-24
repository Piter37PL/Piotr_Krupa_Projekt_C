#pragma once

class First_aid
{
 public:
 First_aid(int xpos, int ypos);
 ~First_aid();
 
 int GetPosX();               //Pobieranie pozycji x apteczki
 int GetPosY();               //Pobieranie pozycji y apteczki
  
 sf::Sprite SpriteFirst_aid;  //Sprite Apteczki

 private:
 sf::Texture textureFirst_aid; //Tekstura apteczki
 float x;                      //Pozycja x apteczki
 float y;                      //Pozycja y apteczki
};

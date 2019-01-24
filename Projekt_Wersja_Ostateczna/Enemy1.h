#pragma once
#include "SFML/Graphics.hpp"
class Enemy1
{
 public:
  Enemy1(float xpos, float ypos);
 ~Enemy1();
  
 float xpos;                    //Pozycja x Enemy
 float ypos;                    //Pozycja y Enemy
 float xmove;                   //Prędkość Enemy
 float xr;                      //Prawa granica ruchu Enemy
 float xl;                      //Lewa  granica ruch  Enemy
 void update();                 //Ruch Enemy

 float GetPosX();              //Pobieranie wartości
 float GetPosY();
 
 sf::Sprite spriteEnemy;       //Sprite Enemy

 private:
 sf::Texture textureEnemy;    //Sprite Enemy

};

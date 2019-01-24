#include "Enemy1.h"

Enemy1::Enemy1(float xpos, float ypos)
{
 float xr = xpos+100;
 float xl = xpos-100;
 float xmove = 0.5f;

 this->xr = xr;
 this->xl = xl;

 this->xpos = xpos;
 this->xmove = xmove;
 
 textureEnemy.loadFromFile("Textures/Enemy/E1L.png");
 sf::Sprite sE(textureEnemy);
 spriteEnemy = sE;
 
}

Enemy1::~Enemy1()
{

}

void Enemy1::update() //Ruch Enemy
{
 if(this->xpos >= xr)
   { 
    xmove = -0.5;
    textureEnemy.loadFromFile("Textures/Enemy/E1L.png");
   }
 if(this->xpos <= xl)
   { 
    xmove = 0.5;
    textureEnemy.loadFromFile("Textures/Enemy/E1R.png");
   }
 xpos += xmove;

}
//Pobieranie wartości
float Enemy1::GetPosX()
{
  sf::Vector2f v;
  v = this->spriteEnemy.getPosition();
  return v.x;
}

float Enemy1::GetPosY()
{
 sf::Vector2f v;
 v = this->spriteEnemy.getPosition();
 return v.y;
}

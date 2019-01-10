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
 
 textureEnemy.loadFromFile("testE.png");
 sf::Sprite sE(textureEnemy);
 spriteEnemy = sE;
 
}

Enemy1::~Enemy1()
{

}

void Enemy1::update()
{
 if(this->xpos >= xr)
   { xmove = -0.5;}
 if(this->xpos <= xl)
   { xmove = 0.5;}
 xpos += xmove;
 std::cout<<"xr: "<<xr<<std::endl;
 std::cout<<"xl: "<<xl<<std::endl;
 std::cout<<"xpos: "<<xpos<<std::endl;
}

float Enemy1::GetPosX()
{
  sf::Vector2f v;
  v = this->spriteEnemy.getPosition();
  return v.x;
}

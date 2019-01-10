#include "Enemy1.h"

Enemy1::Enemy1(float xpos, float ypos)
{
 float xr = xpos+100;
 float xl = xpos-100;
 float xmove = 0.5f;

 this->xr = xr;
 this->xl = xl;

 this->xpos = xpos;
 this->ypos = ypos;
 this->xmove = xmove;
 
}

Enemy1::~Enemy1()
{

}

void Enemy1::update()
{
 xpos += xmove;
 if(xpos >= xr)
   { xmove = -0.5;}
 if(xpos <= xl)
   { xmove = 0.5;}
/*
 std::cout<<"xpos.E = "<<xpos<<std::endl;
 std::cout<<"ypos.E = "<<ypos<<std::endl;
 std::cout<<"xr.E = "<<xr<<std::endl;
 std::cout<<"xl.E = "<<xl<<std::endl;		
*/
}

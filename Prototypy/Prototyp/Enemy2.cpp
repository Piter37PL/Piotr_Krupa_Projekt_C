#include "Enemy2.h"

Enemy2::Enemy2(float xpos, float ypos)
{
 float yu = ypos-100;
 float yd = ypos+100;
 float ymove = 0.5f;

 this->yu = yu;
 this->yd = yd;

 this->xpos = xpos;
 this->ypos = ypos;
 this->ymove = ymove;
 
}

Enemy2::~Enemy2()
{

}

void Enemy2::update()
{
 ypos += ymove;
 if(ypos >= yd)
   { ymove = -0.5;}
 if(ypos <= yu)
   { ymove = 0.5;}
/*
 std::cout<<"xpos.E = "<<xpos<<std::endl;
 std::cout<<"ypos.E = "<<ypos<<std::endl;
 std::cout<<"xr.E = "<<xr<<std::endl;
 std::cout<<"xl.E = "<<xl<<std::endl;		
*/
}

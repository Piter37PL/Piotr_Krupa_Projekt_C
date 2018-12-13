#include "Player.h"

Player::Player()
{
 //Public:
 xpos  = 0.f;
 ypos  = 480.f;
 xmove = 0.f;
 ymove = 0.f;
 //Private:
 right = false;
 left  = false;
 jump  = false;
 gravity = 0.04f;
}


Player::~Player()
{
}


void Player::control()
{
 //Czy wciśnięto / nie wciśnięto klawisz

 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))      right = true;
 if(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)))   right = false;

 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))       left = true;
 if(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))    left = false;

 if(jump_counter<800 && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
   {
      jump = true;
      jump_counter++;
      //std::cout<<"jump_counter:"<<jump_counter<<std::endl;
   }
 else
   {
    jump=false;
   }
 if(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)))
   {
     jump_counter=0;
     jump = false;
   }

  Player::update(right,left,jump);
}

void Player::update(bool right, bool left, bool jump)
{ 
  //Ruch jednostajny postaci lewo/prawo
  if(right) xmove =  0.75; 
  if(left)  xmove = -0.75; 
  if(!(right || left)) xmove = 0;
  xpos += xmove;
  
  //Skok postaci   
  if(jump){ ymove = 10.5f; jump=false; }
  else if(!jump) ymove = -10.5f;
  ypos -= ymove*gravity;
}

float Player::GetPosX()
{
  return this->xpos;
}

float Player::GetPosY()
{
  return this->ypos;
}
  

void Player::SetPosX(float X)
{
  this->xpos = X;
}  

void Player::SetPosY(float Y)
{
 this->ypos  = Y;
}



  

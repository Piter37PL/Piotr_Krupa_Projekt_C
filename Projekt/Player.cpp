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

 //hit = false;
}


Player::~Player()
{
}


void Player::control(sf::RenderWindow &window)
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
  if(right) xmove =  0.5; 
  if(left)  xmove = -0.5; 
  if(!(right || left)) xmove = 0;
  xpos += xmove;
  
  //Skok postaci   
  if(jump){ ymove = 5.0f; jump=false; }
  else if(!jump) ymove = -5.0f;
  ypos -= ymove*gravity;
   
  //Pseudokolizja z lewą krawędzią ekranu
  if(xpos < 0.f)
    {
      xmove = 0.f;
      xpos = 0.f;
    }
  //Pseudokolizja z 'ziemią' 
  if(ypos > 480.f)
    {
      ymove = 0.f;
      ypos = 480.f;
    }
}



  

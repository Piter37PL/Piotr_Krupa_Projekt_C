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

 texturePlayer.loadFromFile("test.png");         //Ładowanie tekstury Playera
 sf::Sprite sP(texturePlayer);                   //Sprite Playera
 spritePlayer = sP;

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
 
 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))      jump = true;
 if(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)))   jump = false;

  Player::update(right,left,jump);
}

void Player::update(bool right, bool left, bool jump)
{ 
  //Ruch jednostajny postaci lewo/prawo
  if(right) xmove =  0.25; 
  if(left)  xmove = -0.25; 
  if(!(right || left)) xmove = 0;
  
  //Skok postaci  
  if(jump) ymove  =-0.25;
  if(!jump) ymove = 0.25;
}

float Player::GetPosX()
{
  sf::Vector2f v;
  v = this->spritePlayer.getPosition();
  return v.x;
}

float Player::GetPosY()
{
  sf::Vector2f v;
  v = this->spritePlayer.getPosition();
  return v.y;

}


  

#include "Player.h"

Player::Player()
{
 //Public:                 //Ustawienie wartości
 xmove = 0.f;
 ymove = 0.f;
 
 hit = false;
 healing = false;
 
 //Private:
 right = false;
 left  = false;
 jump  = false;
 shoot = false;
 life = 100;
 shoot_counter = 0;
 jump_counter = 0;

 texturePlayer.loadFromFile("Textures/Player/Pneutral.png");         //załadowanie tekstury Playera
 spritePlayer.setTexture(texturePlayer);                             //załadowanie sprite Playera

 textureHealth_bar.loadFromFile("Textures/Health_bar/Hb_100.png");
 spriteHealth_bar.setTexture(textureHealth_bar);
}


Player::~Player()
{
}

//Sterowanie Playera
void Player::control()
{
 //Czy wciśnięto / nie wciśnięto klawisz

 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))      right = true;
 if(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)))   right = false; 

 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))       left = true;     
 if(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))    left = false;   

 if(jump_counter<350 && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))      
   {
    jump = true;
    jump_counter++;
   }
 else
   {
    jump = false;
   }
 if(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)))   
   {
    jump_counter = 0;
    jump = false;
   }

 if(shoot_counter<1 && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) 
   {
    shoot = true;
    shoot_counter++;
   }
 else
   {
    shoot = false;   
   }
 
 if(!(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))) 
   {
    shoot_counter = 0;
    shoot = false; 
   }

 Player::update(right,left,jump);
 Player::animation(right,left,jump,shoot);
}

//Ruch Playera
void Player::update(bool right, bool left, bool jump)
{ 
  //Ruch jednostajny postaci lewo/prawo
  if(right) xmove =  0.50; 
  if(left)  xmove = -0.50; 
  if(!(right || left)) xmove = 0;
  
  //Skok postaci  
  if(jump) ymove  =-0.50;
  if(!jump) ymove = 0.50;
}

//System Zdrowia Playera
void Player::health(sf::RenderWindow& window)
{
 if(hit == true)
   {
    life -= 25;
    hit = false;
   }
 if(healing == true)
   {
    if(life < 100)
      { 
       life += 25;
      }
    healing = false;
   }
 if(life == 0)
   {
    std::cout<<"I'm sorry, but this is game over! Are you trying again?"<<std::endl;
    window.close();
   }

 if(life <= 100 && life > 75) {textureHealth_bar.loadFromFile("Textures/Health_bar/Hb_100.png");}
 if(life <= 75  && life > 50) {textureHealth_bar.loadFromFile("Textures/Health_bar/Hb_75.png");}
 if(life <= 50  && life > 25) {textureHealth_bar.loadFromFile("Textures/Health_bar/Hb_50.png");}
 if(life <= 25  && life > 0)  {textureHealth_bar.loadFromFile("Textures/Health_bar/Hb_25.png");}

 window.draw(spriteHealth_bar);

 sf::Vector2f vh;
 vh = this->spritePlayer.getPosition();
 if(vh.x >= 350.f)
   {
    spriteHealth_bar.setPosition(vh.x-350.f,0);
   }

}

//Animacja Postaci
void Player::animation(bool right, bool left, bool jump, bool shoot)
{
 
 if(right == true && left == false)
   {
    texturePlayer.loadFromFile("Textures/Player/Pright.gif");
    if(jump == true)
      {
       texturePlayer.loadFromFile("Textures/Player/Pjump.png");
      }  
   }

 else if(right == false && left == true)
   {
    texturePlayer.loadFromFile("Textures/Player/Pleft.gif");
     if(jump == true)
      {
       texturePlayer.loadFromFile("Textures/Player/Pjump.png");
      } 
   }

 else if(right == false && left == false && jump == true) 
   {
    texturePlayer.loadFromFile("Textures/Player/Pjump.png");
   }

 else if(right == false && left == false && jump == false && shoot_counter==1)
   {
    texturePlayer.loadFromFile("Textures/Player/Pshoot.png");
   } 
 else
   {
    texturePlayer.loadFromFile("Textures/Player/Pneutral.png");  
   }

}


//Pobieranie wartości
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

bool Player::GetShoot()
{
 return shoot;
}



  

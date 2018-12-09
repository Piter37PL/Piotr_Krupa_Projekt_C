#include "Platform.h"

Platform::Platform(int x, int y, int nx, int ny)
{
  this->rosxB = 800;                      //Zapisanie wartości zmiennych
  this->rosyB = 600;
  this->blocX = 40;
  this->blocY = 30;

  this->x=x;
  this->y=y;
  this->nx=nx;
  this->ny=ny;
  
  xmove = player.xpos;

  textureBlock.loadFromFile("Bloc1.png"); //Załadowanie tekstury
  spritePlatform.setTexture(textureBlock); //Załadowanie Sprite platformy

  
}

Platform::~Platform()
{
}

void Platform::drawPlatform(sf::RenderWindow &window)
{

 for(int i=0; i<nx; i++) 
   {
    window.draw(spritePlatform);
    spritePlatform.setPosition(x + i*blocX, y);
   }
   std::cout<<xmove<<std::endl;
}

void Platform::collisionPlatform()
{
}




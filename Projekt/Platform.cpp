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

  textureBlock.loadFromFile("Bloc1.png"); //Załadowanie tekstury
  spritePlatform.setTexture(textureBlock); //Załadowanie Sprite platformy

}

Platform::~Platform()
{
}

void Platform::drawPlatform(sf::RenderWindow &window)  //Rysowanie Platform
{

 for(int i=0; i<nx; i++) 
   {
    window.draw(spritePlatform);
    spritePlatform.setPosition(x + i*blocX, y);
   }

}

int Platform::GetX()
{
 return this->x;	
}

int Platform::GetY()
{
 return this->y;
}

int Platform::GetNX()
{
 return this->nx;
}

int Platform::GetNY()
{
 return this->ny;
}

int Platform::GetBlocX()
{
 return this->blocX;	
}







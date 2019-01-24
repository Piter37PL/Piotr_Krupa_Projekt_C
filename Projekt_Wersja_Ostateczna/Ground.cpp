#include "Ground.h"

Ground::Ground()
{
  this->rosyG = 600;                      //Zapisanie wartości zmiennych
  this->blocX = 40;
  this->blocY = 30;

  textureGround.loadFromFile("Textures/Blocs/Bloc1.png"); //Załadowanie tekstury
  spriteGround.setTexture(textureGround);                 //Załadowanie Sprite 'ziemi'
}


Ground::~Ground()
{
}

void Ground::drawGround(sf::RenderWindow &window) //Rysowanie ziemi
{
 int yoffset[] = {30,60};
 for( int j=0; j<2; j++)
    {
      for(int i=0; i<=480; i++)
         {
           window.draw(spriteGround);
           spriteGround.setPosition(i*this->blocX,this->rosyG-yoffset[j]);
         } 
    }

}

//Pobieranie wartości
int Ground::GetYMin()
{
  return 480;
} 




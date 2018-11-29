#include "Platform.h"

Platform::Platform(int &rosx, int &rosy)
{
  int rosxB = rosx;                      //Zapisanie wartości zmiennych
  int rosyB = rosy;
  int blocX = 40;
  int blocY = 30;

  this->rosxB = rosxB;                 //Wskazanie na zmienne, które będą wywoływane przez metodę
  this->rosyB = rosyB; 
  this->blocX = blocX;
  this->blocY = blocY;

  textureBlock.loadFromFile("Bloc1.png"); //Załadowanie tekstury
  spriteBlock.setTexture(textureBlock);   //Załadowanie Sprite
}

Platform::~Platform()
{
}

void Platform::drawGround(sf::RenderWindow &window) 
{
 //Rysowanie pierwszych 20 bloczków od y = 600 do y = 570
 for(int i=0; i<=20; i++)
    {
      window.draw(spriteBlock);
      spriteBlock.setPosition(i*blocX,rosyB-30);
    } 
  //Rysowanie kolejnych 20 bloczków od y = 570 do y = 540  
  for(int i=0; i<=20; i++)
    {
      window.draw(spriteBlock);
      spriteBlock.setPosition(i*blocX,rosyB-60);
    }       
}


void Platform::drawPlatform(sf::RenderWindow &window)
{
  //Rysowanie pierwszej platformy - testowe
 for(int i=13; i<=17; i++)
    {
     window.draw(spriteBlock);
     spriteBlock.setPosition(i*blocX,rosyB-270);
    }
  //Rysowanie drugiej platformy - testowe
 for(int i=6; i<=10; i++)
    {
     window.draw(spriteBlock);
     spriteBlock.setPosition(i*blocX,rosyB-420);
    }

}





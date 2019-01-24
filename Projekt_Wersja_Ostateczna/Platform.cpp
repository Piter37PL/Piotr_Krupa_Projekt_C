#include "Platform.h"

Platform::Platform(int x, int y, int nx)
{
  this->blocX = 40;                                      //Rozmiar x Bloczka
  this->blocY = 30;                                      //Rozmiar y Bloczka

  this->x=x;                                             //Początkowa pozycja bloczka w x
  this->y=y;                                             //Początkowa pozycja bloczka w y
  this->nx=nx;                                           //Liczba bloczków w osi x

  textureBlock.loadFromFile("Textures/Blocs/Bloc2.png"); //Załadowanie tekstury
  spritePlatform.setTexture(textureBlock);               //Załadowanie Sprite platformy
}

Platform::~Platform()
{
}

void Platform::drawPlatform(sf::RenderWindow &window)  //Rysowanie Platform
{

 for(int i=0; i<nx; i++) //Pętla do rysowania i ustawiania spritetów
   {
    window.draw(spritePlatform);               
    spritePlatform.setPosition(x + i*blocX, y);
   }

}

//Pobieranie wartości
int Platform::GetX()  //Początkowa pozycja bloczka w x
{
 return this->x;	
}

int Platform::GetY() //Początkowa pozycja bloczka w y
{
 return this->y;
}

int Platform::GetNX() //Liczba bloczków w osi x
{
 return this->nx;
}

int Platform::GetBlocX() //Rozmiar x Bloczka
{
 return this->blocX;	
}

int Platform::GetBlocY() //Rozmiar y Bloczka
{
 return this->blocY;
}





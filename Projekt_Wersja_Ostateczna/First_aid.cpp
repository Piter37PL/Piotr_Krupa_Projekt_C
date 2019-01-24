#include "First_aid.h"

First_aid::First_aid(int xpos, int ypos)
{
 this->x = xpos; //Załadowanie wartości atrybutów
 this->y = ypos;

 textureFirst_aid.loadFromFile("Textures/First_aid/first_aid.png"); //Załadowanie tekstury
 SpriteFirst_aid.setTexture(textureFirst_aid);                      // Załadowanie Sprite
}

First_aid::~First_aid()
{

}

//Pobieranie wartości
int First_aid::GetPosX() 
{
 return this->x;
}

int First_aid::GetPosY()
{
 return this->y;
}

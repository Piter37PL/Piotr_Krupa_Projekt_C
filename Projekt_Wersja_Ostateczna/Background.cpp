#include "Background.h"


Background::Background(int rosx)
{
 this->xpos = 0;                                                               //Załadowanie wartości
 this->ypos = 0;
 this->rosx = rosx;

 TextureBackGroundStart.loadFromFile("Textures/Background/Start_level.png");   //Załadowanie tekstury
 TextureBackGroundMiddle.loadFromFile("Textures/Background/Middle_level.png"); 
 TextureBackGroundEnd.loadFromFile("Textures/Background/End_level.png");

 SpriteBackGroundStart.setTexture(TextureBackGroundStart);                     //Załadowanie Spritów
 SpriteBackGroundMiddle.setTexture(TextureBackGroundMiddle);
 SpriteBackGroundEnd.setTexture(TextureBackGroundEnd);
 
}

Background::~Background()
{

}

void Background::drawBackGround(sf::RenderWindow& window) //Rysowanie tła
{
 window.draw(SpriteBackGroundStart);
 SpriteBackGroundStart.setPosition(xpos,ypos);

 for(int i=1; i<=19; i++)
    {
     window.draw(SpriteBackGroundMiddle);
     SpriteBackGroundMiddle.setPosition(xpos+rosx*i,ypos);
    }
 window.draw(SpriteBackGroundEnd);
 SpriteBackGroundEnd.setPosition(xpos+rosx*20,ypos);
 
}



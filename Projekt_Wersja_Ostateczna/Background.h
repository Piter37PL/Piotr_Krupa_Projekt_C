#pragma once

class Background
{
 public:
 Background(int rosx);
 ~Background();

 void drawBackGround(sf::RenderWindow& window);   //Rysowanie Tła
 
 private:
 
 int xpos;                                       //Pozycja x elementu tła
 int ypos;                                       //Pozycja y elementu tła 
 int rosx;                                       //Rozmiar ekranu w x

                                                 //Tekstury
 sf::Texture TextureBackGroundStart;             //Początkowe tło
 sf::Texture TextureBackGroundMiddle;            //Dalsza część tła
 sf::Texture TextureBackGroundEnd;               //Koniec tła

                                                 //Sprite
 sf::Sprite SpriteBackGroundStart;               //Początkowe tło
 sf::Sprite SpriteBackGroundMiddle;              //Dalsza część tła
 sf::Sprite SpriteBackGroundEnd;                 //Koniec tła
 
};

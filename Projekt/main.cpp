#include "SFML/Graphics.hpp"

#include "Player.h"
#include "Platform.h"
#include "Ground.h"

#include "Player.cpp"
#include "Platform.cpp"
#include "Ground.cpp"

void checkGroundCollision(Player& player, Ground ground)
{
   //Pseudokolizja z lewą krawędzią ekranu
  if(player.GetPosX() < 0.f)
    {
      player.xmove = 0.f;
      player.SetPosX(0.f);
    }
  //Pseudokolizja z 'ziemią' 
  if(player.GetPosY() > ground.GetYMin())
    {
      player.ymove = 0.0;
      player.SetPosY(ground.GetYMin());
    }
}

void checkPlatformCollision(Player& player, Platform& platform)
{ 

 if(player.GetPosX() >= platform.GetX()-80 && player.GetPosX() <= platform.GetX()+4*40 
    && player.GetPosY() <= platform.GetY()+platform.GetNY()*platform.GetBlocX()) 
    {  
     player.SetPosY(platform.GetY()-50);
     player.ymove = 0;
    }
}

int main()
{
 int rosx = 800;                            //Rozmiar ekranu jako zmienne
 int rosy = 600; 

 sf::RenderWindow window(sf::VideoMode(rosx,rosy), "ProjektC++");
 
 sf::Texture texturePlayer;                      //Tekstura Playera
 texturePlayer.loadFromFile("test.png");         //Ładowanie tekstury Playera
 sf::Sprite spritePlayer(texturePlayer);         //Sprite Playera
 
 sf::View view1(sf::FloatRect(0.f, 0.f, 800.f, 600.f)); //KAMERA

 Player objPlayer;                               //obiekt Klasy Player
 Platform objPlatform1(400, 370, 4, 1);          //obiekt Klasy PLatform      
 Ground objGround;                               //obiekt Klasy Ground

 while(window.isOpen())
      {
        sf::Event event;
 
        while (window.pollEvent(event))
              {
                switch(event.type)
                      {
                        case sf::Event::KeyReleased:
                             switch(event.key.code)
                                   {
                                     case sf::Keyboard::Escape:
                                          window.close();

                                          break; 
                                   }
                             
                             break;                               
                        
                        case sf::Event::Closed:
                             window.close();

                             break;
 
                      } 
 
              }
     
          window.clear();
          objPlatform1.drawPlatform(window); //Rysowanie platformy

          objGround.drawGround(window);      //Rysowanie "ziemi"
          
          objPlayer.control();               //Sterowanie i ruch Playera
          window.draw(spritePlayer);         //Rysowanie Playera

          spritePlayer.setPosition(objPlayer.xpos, objPlayer.ypos);          //Pozycja Playera
          spritePlayer.move(sf::Vector2f(objPlayer.xmove, objPlayer.ymove)); //Ruch Playera

          checkGroundCollision(objPlayer, objGround);                //Kolizja Player - 'ziemia'
          checkPlatformCollision(objPlayer, objPlatform1);           //Kolizja Player - platforma

          //KAMERA 
          if(objPlayer.xpos > 350.f )   
            {
             view1.move(sf::Vector2f(objPlayer.xmove, 0));
            }
          window.setView(view1);
          
          window.display();
          

      }
return 0;
}

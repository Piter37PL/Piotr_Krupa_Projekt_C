#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Player.cpp"
#include "Platform.h"
#include "Platform.cpp"
#include "Ground.h"
#include "Ground.cpp"

int main()
{
 int rosx = 800;                            //Rozmiar ekranu jako zmienne
 int rosy = 600; 

 sf::RenderWindow window(sf::VideoMode(rosx,rosy), "ProjektC++");
 
 sf::Texture texturePlayer;                //Tekstura i sprite Playera
 texturePlayer.loadFromFile("test.png");
 sf::Sprite spritePlayer(texturePlayer);

 Player objPlayer;                               //obiekt Klasy Player
 Platform objPlatform1(100, 270, 4, 1);          //obiekt Klasy PLatform    
 Platform objPlatform2(200, 370, 4, 1);          //obiekt Klasy PLatform    
 Platform objPlatform3(300, 470, 4, 1);          //obiekt Klasy PLatform    
 Ground objGround;

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
          objPlatform1.drawPlatform(window);
          objPlatform2.drawPlatform(window);
          objPlatform3.drawPlatform(window);
          objGround.drawGround(window);
          
          objPlayer.control(window);

          window.draw(spritePlayer);
          spritePlayer.setPosition(objPlayer.xpos, objPlayer.ypos);
          spritePlayer.move(sf::Vector2f(objPlayer.xmove, objPlayer.ymove));
          
          
          
          window.display();
          

      }
return 0;
}

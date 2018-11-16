#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Player.cpp"
#include "Platform.h"
#include "Platform.cpp"

int main()
{
 int rosx = 800;
 int rosy = 600; 

 sf::RenderWindow window(sf::VideoMode(rosx,rosy), "ProjektC++");
 
 sf::Texture texturePlayer;
 texturePlayer.loadFromFile("test.png");
 sf::Sprite spritePlayer(texturePlayer);

 Player objPlayer;
 Platform objPlatform(rosx,rosy);
 
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
        
          
          
          objPlayer.control(window);

          window.draw(spritePlayer);
          spritePlayer.setPosition(objPlayer.xpos, objPlayer.ypos);
          spritePlayer.move(sf::Vector2f(objPlayer.xmove, objPlayer.ymove));
          
          objPlatform.drawGround(window);
          
          window.display();
          

      }
return 0;
}

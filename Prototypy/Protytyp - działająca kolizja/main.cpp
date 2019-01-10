#include "SFML/Graphics.hpp"

#include "Player.h"
#include "Player.cpp"
#include "Platform.h"
#include "Platform.cpp"
#include "Ground.h"
#include "Ground.cpp"
#include "Enemy1.h"
#include "Enemy1.cpp"

void checkGroundCollision(Player& player, Ground& ground)
{
  //Pseudokolizja z 'ziemią' 
  if(player.GetPosY() == ground.GetYMin() && player.ymove > 0)
    {
      player.ymove = 0.f;
    }
  if(player.GetPosX() <= 0.f && player.xmove < 0)
    {
      player.xmove = 0.f;
    }
}

void checkPlatformCollision(Player& player, Platform& platform)
{
 if(player.GetPosY() == platform.GetY() - platform.GetBlocY()*2 && 
    player.GetPosX() >= platform.GetX()-platform.GetBlocX()*2 && 
    player.GetPosX() <= platform.GetX()+platform.GetBlocX()*platform.GetNX()+1
    && player.ymove > 0)
   {
    player.ymove = 0.f;
   }

 if(player.GetPosY() == platform.GetY() + platform.GetBlocY() && 
    player.GetPosX() >= platform.GetX()-platform.GetBlocX()*2 && 
    player.GetPosX() <= platform.GetX()+platform.GetBlocX()*platform.GetNX()+1
    && player.ymove < 0)
   {
    player.ymove = 0.f;
   }
  
 if(player.GetPosX() == platform.GetX()-platform.GetBlocX()*2 &&
    player.GetPosY() <= platform.GetY() + platform.GetBlocY() &&
    player.GetPosY() >= platform.GetY() - platform.GetBlocY()*2 &&
    player.xmove > 0)
    {
     player.xmove = 0.f;
     std::cout<<"COLLISION!!"<<std::endl;
    }

  if(player.GetPosX() == platform.GetX()+platform.GetBlocX()*platform.GetNX()+1 &&
    player.GetPosY() <= platform.GetY() + platform.GetBlocY() &&
    player.GetPosY() >= platform.GetY() - platform.GetBlocY()*2 &&
    player.xmove < 0)
    {
     player.xmove = 0.f;
     std::cout<<"COLLISION!!"<<std::endl;
    }

}

int main()
{
 int rosx = 800;                            //Rozmiar ekranu jako zmienne
 int rosy = 600; 

 sf::RenderWindow window(sf::VideoMode(rosx,rosy), "ProjektC++");
 
 Player objPlayer;                               //obiekt Klasy Player
 Enemy1 objEnemy1(400.f, 480.f);
 
 objPlayer.spritePlayer.setPosition(0 , 480.f);
 objEnemy1.spriteEnemy.setPosition(400.f,480.f); 

 Platform objPlatform1(400, 370, 4, 1);
 Platform objPlatform2(400, 170, 4, 1);
 Platform objPlatform3(200, 270, 4, 1);
 
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
          
          window.draw(objPlayer.spritePlayer);         //Rysowanie Playera  
          
          window.draw(objEnemy1.spriteEnemy);
       
          objPlatform1.drawPlatform(window);
          objPlatform2.drawPlatform(window);
          objPlatform3.drawPlatform(window);

          objGround.drawGround(window); 

          objPlayer.control();
          objEnemy1.update();
          
          checkGroundCollision(objPlayer, objGround);
          checkPlatformCollision(objPlayer,objPlatform1);
          checkPlatformCollision(objPlayer,objPlatform2);
          checkPlatformCollision(objPlayer,objPlatform3);

          //sf::Vector2f v;
	  //v = objPlayer.spritePlayer.getPosition();
	  //std::cout << "sprite pos 1:\t" << v.x << "\t" << v.y << "\n";


          objPlayer.spritePlayer.move(objPlayer.xmove, objPlayer.ymove); //Ruch Playera
          objEnemy1.spriteEnemy.move(objEnemy1.xmove, 0); //Ruch Playera
          //v = objPlayer.spritePlayer.getPosition();
	  //std::cout << "sprite pos 2:\t" << v.x << "\t" << v.y << "\n";

          
          window.display();
          

      }
return 0;
}

#include "SFML/Graphics.hpp"

#include "Player.h"
#include "Platform.h"
#include "Ground.h"
#include "Enemy1.h"
#include "Enemy2.h"

#include "Player.cpp"
#include "Platform.cpp"
#include "Ground.cpp"
#include "Enemy1.cpp"
#include "Enemy2.cpp"

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

 if(player.GetPosX() >= platform.GetX()-80 && player.GetPosX() <= platform.GetX()+platform.GetNX()*platform.GetBlocX() 
    && player.GetPosY() <= platform.GetY()+platform.GetNY()*platform.GetBlocY() 
    && player.ymove < 0) 
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

 sf::Texture textureEnemy;                       //Tekstura Enemy
 textureEnemy.loadFromFile("testE.png");         //Ładowanie tekstury Enemy
 
 sf::Texture textureEnemy2;
 textureEnemy2.loadFromFile("testE2.png");

 sf::Sprite spriteEnemy1(textureEnemy);          //Sprite Enemy
 sf::Sprite spriteEnemy2(textureEnemy);
 sf::Sprite spriteEnemy3(textureEnemy);
 sf::Sprite spriteEnemy4(textureEnemy);
 
 sf::Sprite spriteEnemy2_1(textureEnemy2);
 
 sf::View view1(sf::FloatRect(0.f, 0.f, 800.f, 600.f)); //KAMERA

 Player objPlayer;                               //obiekt Klasy Player

 Enemy1 objEnemy1(900.f,480.f);                  //obiekty Klasy Enemy
 Enemy1 objEnemy2(2500.f,480.f);
 Enemy1 objEnemy3(950.f,155.f);
 Enemy1 objEnemy4(1875.f, 245.f);

 Enemy2 objEnemy2_1(300.f,200.f);

 Platform objPlatform1(400, 370, 4, 1);          //obiekty Klasy PLatform   
 Platform objPlatform2(800, 210, 8, 1);   
 Platform objPlatform3(1100, 400,5, 1);
 Platform objPlatform4(1400, 400,5, 1);
 Platform objPlatform5(1600, 500,5, 1); 
 Platform objPlatform6(1800, 300,5, 1);
 Platform objPlatform7(2500, 200,5, 1);
 Platform objPlatform8(2800, 200,9, 1);
 Platform objPlatform9(3100, 300,3, 1);
 Platform objPlatform10(3400,200,4, 1);
 Platform objPlatform11(3900,400,4, 1);
 Platform objPlatform12(4000,200,2, 1);
 Platform objPlatform13(4500,300,5, 1);
 Platform objPlatform14(5000,200,6, 1);

 Ground objGround;                               //obiekt Klasy Ground

 spritePlayer.setPosition(480.f , 0);

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
          objPlatform2.drawPlatform(window); 
          objPlatform3.drawPlatform(window);
          objPlatform4.drawPlatform(window);
          objPlatform5.drawPlatform(window);
          objPlatform6.drawPlatform(window);
          objPlatform7.drawPlatform(window);
          objPlatform8.drawPlatform(window);
          objPlatform9.drawPlatform(window);
          objPlatform10.drawPlatform(window);
          objPlatform11.drawPlatform(window);
          objPlatform12.drawPlatform(window);
          objPlatform13.drawPlatform(window);
          objPlatform14.drawPlatform(window);
          
          objGround.drawGround(window);      //Rysowanie "ziemi"

          objPlayer.control();               //Sterowanie i ruch Playera

          objEnemy1.update();                //ruch enemy
          objEnemy2.update();          
          objEnemy3.update();
          objEnemy4.update();
          objEnemy2_1.update();
          
          window.draw(spritePlayer);         //Rysowanie Playera
          
          window.draw(spriteEnemy1);          //Rysowanie Enemy
          window.draw(spriteEnemy2);
          window.draw(spriteEnemy3);
          window.draw(spriteEnemy4);

          window.draw(spriteEnemy2_1);
          
          spritePlayer.setPosition(objPlayer.xpos , objPlayer.ypos);  //Ustawienie pozycji - nie zbyt dobre - bez tego brak kolizji z ground 
          spritePlayer.move(objPlayer.xmove, objPlayer.ymove);        //Ruch Playera

          spriteEnemy1.setPosition(objEnemy1.xpos, objEnemy1.ypos);  //Ustawienie pozycji enemy
          spriteEnemy1.move(sf::Vector2f(objEnemy1.xmove,0.f));      //Ruch enemy

          spriteEnemy2.setPosition(objEnemy2.xpos, objEnemy2.ypos);  //Ustawienie pozycji enemy
          spriteEnemy2.move(sf::Vector2f(objEnemy2.xmove,0.f));      //Ruch enemy

          spriteEnemy3.setPosition(objEnemy3.xpos, objEnemy3.ypos);  //Ustawienie pozycji enemy
          spriteEnemy3.move(sf::Vector2f(objEnemy3.xmove,0.f));      //Ruch enemy
          
          spriteEnemy4.setPosition(objEnemy4.xpos, objEnemy4.ypos);  //Ustawienie pozycji enemy
          spriteEnemy4.move(sf::Vector2f(objEnemy4.xmove,0.f));      //Ruch enemy

          spriteEnemy2_1.setPosition(objEnemy2_1.xpos, objEnemy2_1.ypos);  //Ustawienie pozycji enemy
          spriteEnemy2_1.move(sf::Vector2f(0.f,objEnemy2_1.ymove));      //Ruch enemy
          
          checkGroundCollision(objPlayer, objGround);                //Kolizja Player - 'ziemia'

          checkPlatformCollision(objPlayer, objPlatform1);           //Kolizja Player - platforma1
          checkPlatformCollision(objPlayer, objPlatform2);           //Kolizja Player - platforma2
          checkPlatformCollision(objPlayer, objPlatform3);           //Kolizja Player - platforma3
          checkPlatformCollision(objPlayer, objPlatform4);           //Kolizja Player - platforma4
          checkPlatformCollision(objPlayer, objPlatform5);           //Kolizja Player - platforma5           
          checkPlatformCollision(objPlayer, objPlatform6);           //Kolizja Player - platforma6
          checkPlatformCollision(objPlayer, objPlatform7);           //Kolizja Player - platforma7
          checkPlatformCollision(objPlayer, objPlatform8);           //Kolizja Player - platforma8
          checkPlatformCollision(objPlayer, objPlatform9);           //Kolizja Player - platforma9
          checkPlatformCollision(objPlayer, objPlatform10);           //Kolizja Player - platforma10
          checkPlatformCollision(objPlayer, objPlatform11);           //Kolizja Player - platforma11
          checkPlatformCollision(objPlayer, objPlatform12);           //Kolizja Player - platforma12
          checkPlatformCollision(objPlayer, objPlatform13);           //Kolizja Player - platforma13
          checkPlatformCollision(objPlayer, objPlatform14);           //Kolizja Player - platforma14
          
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

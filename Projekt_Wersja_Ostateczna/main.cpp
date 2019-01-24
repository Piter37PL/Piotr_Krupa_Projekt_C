//Biblioteki
#include "SFML/Graphics.hpp"
#include <vector>

//Nagłówki Klas
#include "Player.h"
#include "Platform.h"
#include "Ground.h"
#include "Enemy1.h"
#include "Collision.h"
#include "Bullet.h"
#include "Background.h"
#include "First_aid.h"

//Metody i atrybuty klas
#include "Player.cpp"
#include "Platform.cpp"
#include "Ground.cpp"
#include "Enemy1.cpp"
#include "Collision.cpp"
#include "Bullet.cpp"
#include "Background.cpp"
#include "First_aid.cpp"

int main()
{
 float rosx = 800.f;                            
 float rosy = 600.f; 

 sf::RenderWindow window(sf::VideoMode(rosx,rosy), "ProjektC++"); //Okno gry
 window.setFramerateLimit(360);                                   //Klatki na sekunde

 sf::View view1(sf::FloatRect(0.f, 0.f, rosx, rosy));             //Tworzenie obiektu kamery

 Player objPlayer;                                                //Obiekt Player    
                         
 Enemy1 objEnemy1(700.f, 480.f);                                  //Obiekty Enemy
 Enemy1 objEnemy2(1600.f, 310.f); 
 Enemy1 objEnemy3(3200.f, 120.f); 
 Enemy1 objEnemy4(2500.f, 480.f);
 Enemy1 objEnemy5(2900.f, 480.f);
 Enemy1 objEnemy6(3300.f, 480.f);

 First_aid objFA1(2300.f,140.f);                                  //Obiekt Apteczki

 objPlayer.spritePlayer.setPosition(350.f , 480.f);               //Pozycja Sprite Playera

 objEnemy1.spriteEnemy.setPosition(700.f,480.f);                  //Pozycja Sprite Enemy
 objEnemy2.spriteEnemy.setPosition(1600.f,310.f);
 objEnemy3.spriteEnemy.setPosition(3200.f,120.f);
 objEnemy4.spriteEnemy.setPosition(2500.f,480.f);
 objEnemy5.spriteEnemy.setPosition(2900.f,480.f);
 objEnemy6.spriteEnemy.setPosition(3300.f,480.f);

 objFA1.SpriteFirst_aid.setPosition(2300.f,140.f);                //Pozycja Sprite Apteczki

 Platform objPlatform0(500, 450, 2);                              //Obiekty Platformy
 Platform objPlatform1(640, 370, 4);                              
 Platform objPlatform2(800, 270, 4);
 Platform objPlatform3(1100, 270, 4);
 Platform objPlatform4(1400, 370, 12);
 Platform objPlatform5(2000, 250, 2);
 Platform objPlatform6(2300, 200, 2);
 Platform objPlatform7(2500, 180, 1);
 Platform objPlatform8(2800, 180, 1);
 Platform objPlatform9(3000, 180, 9);
 Platform objPlatform10(3500, 280, 3);
 Platform objPlatform11(3700, 230, 4);
 Platform objPlatform12(4000, 370, 2);
 Platform objPlatform13(4200, 330, 19);
 Platform objPlatform14(5100, 250, 13);

 Background objBackGround(rosx);                                  //Obiekt  tła
 Ground objGround;                                                //Obiekt  Ziemi

 Collision objCollision;                                          //Obiekt kolizje

 std::vector<Bullet> BulletVec;                                   //Tworzenie wektora do rysowania bullet

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

          objBackGround.drawBackGround(window);        //Rysowanie Tła

          window.draw(objPlayer.spritePlayer);         //Rysowanie Playera  
          
          window.draw(objEnemy1.spriteEnemy);          //Rysowanie Przeciwników
          window.draw(objEnemy2.spriteEnemy);
          window.draw(objEnemy3.spriteEnemy);
          window.draw(objEnemy4.spriteEnemy); 
          window.draw(objEnemy5.spriteEnemy); 
          window.draw(objEnemy6.spriteEnemy); 

          objPlatform0.drawPlatform(window);          //Rysowanie Platform 
          objPlatform1.drawPlatform(window);           
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

          objGround.drawGround(window);                //Rysowanie Ziemi

          window.draw(objFA1.SpriteFirst_aid);         //Rysowanie Apteczek

          objPlayer.control();                         //Sterowanie Playera
          objPlayer.health(window);                    //System zdrowia Playera

          objEnemy1.update();                          //Ruch Enemy
          objEnemy2.update(); 
          objEnemy3.update();  
          objEnemy4.update();   
          objEnemy5.update();
          objEnemy6.update();        

          objCollision.checkPlayerFinishEdgeScreen(objPlayer, window);//Kolizja Player-Meta + Playera-Krańce mapy       
 
          objCollision.checkGroundCollision(objPlayer, objGround);     //Kolizja Player-Ziemia

          objCollision.checkPlatformCollision(objPlayer,objPlatform0); //Kolizja Player-Platforma
          objCollision.checkPlatformCollision(objPlayer,objPlatform1); 
          objCollision.checkPlatformCollision(objPlayer,objPlatform2);
          objCollision.checkPlatformCollision(objPlayer,objPlatform3);
          objCollision.checkPlatformCollision(objPlayer,objPlatform4); 
          objCollision.checkPlatformCollision(objPlayer,objPlatform5);
          objCollision.checkPlatformCollision(objPlayer,objPlatform6);
          objCollision.checkPlatformCollision(objPlayer,objPlatform7);
          objCollision.checkPlatformCollision(objPlayer,objPlatform8);
          objCollision.checkPlatformCollision(objPlayer,objPlatform9); 
          objCollision.checkPlatformCollision(objPlayer,objPlatform10);
          objCollision.checkPlatformCollision(objPlayer,objPlatform11);
          objCollision.checkPlatformCollision(objPlayer,objPlatform12);
          objCollision.checkPlatformCollision(objPlayer,objPlatform13);
          objCollision.checkPlatformCollision(objPlayer,objPlatform14);
 
          objCollision.checkPlayerEnemyCollision(objPlayer,objEnemy1);   //Kolizja Player-Enemy
          objCollision.checkPlayerEnemyCollision(objPlayer,objEnemy2);
          objCollision.checkPlayerEnemyCollision(objPlayer,objEnemy3);
          objCollision.checkPlayerEnemyCollision(objPlayer,objEnemy4);
          objCollision.checkPlayerEnemyCollision(objPlayer,objEnemy5);
          objCollision.checkPlayerEnemyCollision(objPlayer,objEnemy6);

          objCollision.checkFirst_aidPlayerCollision(objFA1, objPlayer); //Kolizja Player-Apteczka

          objPlayer.spritePlayer.move(objPlayer.xmove, objPlayer.ymove); //Ruch Playera

          objEnemy1.spriteEnemy.move(objEnemy1.xmove, 0);                //Ruch Enemy
          objEnemy2.spriteEnemy.move(objEnemy2.xmove, 0);
          objEnemy3.spriteEnemy.move(objEnemy3.xmove, 0);
          objEnemy4.spriteEnemy.move(objEnemy4.xmove, 0);
          objEnemy5.spriteEnemy.move(objEnemy4.xmove, 0);
          objEnemy6.spriteEnemy.move(objEnemy4.xmove, 0);

          //Strzelanie Playera
          if(objPlayer.GetShoot() == true)
            {
              Bullet ObjBullet(sf::Vector2f(25,5)); //Tworzenie obiektu Bullet + nadanie jej rozmiaru
              ObjBullet.setPos(sf::Vector2f(objPlayer.GetPosX()+80, objPlayer.GetPosY()+30 )); //Pozycja Bullet
              BulletVec.push_back(ObjBullet); //Dodanie obiektu Bullet do wektora służącego do rysowania
            }
               
         for(int i=0; i< BulletVec.size(); i++) //Pętla rysująca Bullet
            { 
             BulletVec[i].draw(window); //Rysowanie Bullet
             BulletVec[i].fire(1);      //Ruch Bullet
             objCollision.checkBulletEnemyCollision(BulletVec[i], objEnemy1); //Kolizja Bullet-Enemy
             objCollision.checkBulletEnemyCollision(BulletVec[i], objEnemy2);
             objCollision.checkBulletEnemyCollision(BulletVec[i], objEnemy3);
             objCollision.checkBulletEnemyCollision(BulletVec[i], objEnemy4);
             objCollision.checkBulletEnemyCollision(BulletVec[i], objEnemy5);
             objCollision.checkBulletEnemyCollision(BulletVec[i], objEnemy6);
            }

         if(objPlayer.GetPosX() >= 350.f )   //Kamera - ruch jej od zajęcia pozycji Playera
            {
             view1.move(sf::Vector2f(objPlayer.xmove, 0)); //Ruch Kamery
            }
          window.setView(view1);     //Inicjacja kamery
          
          window.display();          // Wyświetlenie wszystkiego w oknie
          
      }
return 0;
}

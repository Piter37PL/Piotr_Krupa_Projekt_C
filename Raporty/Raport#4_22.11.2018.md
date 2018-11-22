# ProjektC++
## Raport #4 - 22.11.2018
### Autor: Piotr Krupa ISSP rok II

#### Co zostało do tej pory wykonane:
 I. Udało mi się cześciowo rozwiązać kwestie z umieszczeniem większość instrukcji i funkcji (sterowanie) do klasy Player.
    Stworzyłem metodę Player::control typu void, która jest wywoływana w main.cpp (objPlayer.control()). Za pomocą metod
    isKeyPressed, Keyboard oraz instrukcji warunkowej if sprawdza czy wciśnięto/nie wciśnięto klawisz a następnie nadpisuję 
    wartość zmiennej logicznej typu bool (right, left, jump) i te wartości są podawane do wywoływania innej metody w klasie 
    Player - Player::update (ponieważ zmienne right, left i jump są wykorzystywane wyłącznie w klasie Player nadałem im
    prawo dostępu private).
    
    
 II. Do metody Player::update wprowadziłem:
   + dwie instrukcje if, które mają nie pozwolić obiektowi wyjść poza ekran z dołu i lewej strony.
     Jęśli wartość xpos i ypos przekroczą daną wartość, wtedy prędkość obiektu (xmove, ymove) 
     zostaje wyzerowana zaś pozycja obiektu (xpos, ypos) jest stała. Można to określić mianem
     "pseudokolizji"
   + Wprowadziłem równanie odpowiedzialne za skok postaci. Zasada działanie jest podobna do
     ruchu w lewo i prawo. Jęśli wciśnięto/nie wciśnięto klawisz spacji wartość zmiennej 
     logicznej jump zostaje nadpisana (true / false) i przekazana do wywołania metody
     Player::update. Zależności od wartości zmiennej jump zostaje nadana wartość prędkości 
     (ymove = 0.5f / -0.5f). W zmiennej pozycji obiektu (ypos) zostaje zsumowany iloczyn 
     prędkości z wartością przyspieszenia grawitacyjnego (float gravity). W ten sposób
     gdy wciśnięty zostanie klawisz postać unosi się do góry zaś gdy puścimy to spada.
     Dzięki grawitacji działa to wolniej. Jedyny szkopuł jest taki, że przytrzymanie
     spacji sprawia, że postać dalej się unosi coraz wyżej - zamiast skoku obiekt, zachowuje
     się jakby miał przy sobie jetpack.
     W tym miejscu przyszły mi dwie kwestie:
     1. Spróbować rozwiązać problem np. zastowaniem innej instrukcji obliczającej ypos
     2. Mogę to zostawić i oprzeć gameplay o ten element ( Przecież nie każda platformówka
        musi mieć skok).
     Przy okazji skoku tu przydatny jest if odpowiedzialny za "pseudo kolizje" obiektu
     z dolną krawędzią (czy miejscem gdzie będzie "ziemia"). Dzięki temu postać nie spada 
     cały czas w dół.
 
#### Co zamierzam wykonać do następnego tygodnia:
  I. Wprowadzenie pierwszej/pierwszych platform i kolizji z Playerem
  
  
  II. Zastanowienie się nad skokiem postaci 
  
  
  III. Zastanowienie się nad Klasą Player (rysowanie postaci i animacje)
  
  Kod:
  ##### Player.h
  ```
#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
// Definicje funkcji z instrukcjami dla postaci gracza
class Player
{
 public:
  
  Player();
  ~Player();
  
  float xpos;                                    //Pozycja w osi x
  float ypos;                                    //Pozycja w osi y
  float xmove;                                   //Prędkość w osi x
  float ymove;                                   //Prędkość w osi y
  
  void control();                                //Sprawdzenia Sterowania
  void update(bool right, bool left, bool jump); //Aktualizacji pozycji postaci 
 
 private:
  bool right;                                    //Czy wciśnieto klawisz Prawo - ruch w prawo
  bool left;                                     //Czy wciśnięto klawisz Lewo  - ruch w lewo

  bool jump;                                     //Czy wciśnięto klawisz Spacja - skok postaci
  float gravity;                                 //Stałe przyspieszenie grawitacyjne do skoku
  
};
  ```
  
  ##### Player.cpp
  ```
#include "Player.h"
Player::Player()
{
 //Public:
 xpos  = 0.f;
 ypos  = 480.f;
 xmove = 0.f;
 ymove = 0.f;
 //Private:
 right = false;
 left  = false;
 jump  = false;
 gravity = 0.05f;
}


Player::~Player()
{
}


void Player::control()
{
 //Czy wciśnięto / nie wciśnięto klawisz
 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))      right = true;
 if(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)))   right = false;

 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))       left = true;
 if(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))    left = false;

 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))      jump = true;
 if(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)))   jump = false;

 Player::update(right,left,jump);

}


void Player::update(bool right, bool left, bool jump)
{ 
  //Ruch jednostajny postaci lewo/prawo
  if(right) xmove =  0.5; 
  if(left)  xmove = -0.5; 
  if(!(right || left)) xmove = 0;
  xpos += xmove;
  
  //Skok postaci   
  if(jump) ymove = 5.0f;
  if(!jump) ymove = -5.0f;
  ypos -= ymove*gravity;
   
  //Pseudokolizja z lewą krawędzią ekranu
  if(xpos < 0.f)
    {
      xmove = 0.f;
      xpos = 0.f;
    }
  //Pseudokolizja z 'ziemią' 
  if(ypos > 480.f)
    {
      ymove = 0.f;
      ypos = 480.f;
    }
}

  ```
  
  ##### main.cpp
  ```
  #include "SFML/Graphics.hpp"
#include "Player.h"
#include "Player.cpp"


int main()
{
 sf::RenderWindow window(sf::VideoMode(800,600), "ProjektC++");
 
 sf::Texture texturePlayer;
 texturePlayer.loadFromFile("test.png");
 sf::Sprite spritePlayer(texturePlayer);

 Player objPlayer;
 
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
     
          objPlayer.control();

          window.clear();

          window.draw(spritePlayer);
          spritePlayer.setPosition(objPlayer.xpos, objPlayer.ypos);
          spritePlayer.move(sf::Vector2f(objPlayer.xmove, objPlayer.ymove));

          window.display();
          

      }
return 0;
}
  
  ```

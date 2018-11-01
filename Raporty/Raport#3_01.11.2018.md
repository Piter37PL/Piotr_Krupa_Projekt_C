# ProjektC++
## Raport #3 - 1.11.2018
### Autor: Piotr Krupa ISSP rok II

Na samym początku muszę przyznać, że nie jestem zbytnio dobry w planowaniu co robić. To co planuje zrobić ostatecznie
robie dopiero albo częściowo albo wcale. Praktycznie wciąż nie mam pewności jak to będzie planować. Powoli poznaje i staram się
opanować elementy języka C++ (ostatnio Klasy) oraz samej biblioteki SFML oraz jego możliwości.

#### Co zostało do tej pory wykonane:

I. Postanowiłem co do rozdzielczość okienka gry: 800x600 px
   Powód jest taki, że najłatwiej mi jest podzielić bloki 
   na takiej rozdzielczości by zmieściły się na okienku.
   Zdecydowałem też, że podstawowa platforma - podłoga
   będzie miała rozdzielczość 60px w wysokości ustawionego
   od 540 piksla do 600 piksla. Jeszcze nie wiem czy to 
   będzie jako jedna tekstura czy zbudowana z pojedynczych bloków.
   Platformy będą co najmiej w wysokość 30px - podobnie jak
   w przypadku podłogi nie jestem jeszcze zdecydowany co kształtu
   wyświetlenia. Natomiast postać będzie w rozmiarze 80x60 px by
   wpasować się i wyróżnić na tle platform. Przy ustalaniu platform
   zorientowałem się , że nie mogę stworzyć platformy, która wyjdzie
   poza 60px w wysokości (piksle są liczone od lewego górnego rogu ekranu). 
   Wszelkie elementy do grafiki stworze w programie GIMP.
   
II. Na osobnym pliku main.cpp ( tak by nie będąc pewny co do tego jak to wszystko złożyć do kupy nie zaśmiecać main.cpp z menu)
    Stworzyłem instrukcję odpowiedzialne za:
    -  Poruszanie postaci w lewo i prawo
    -  Wyświetlenie postaci na ekranie okna
    -  Sterowanie postacią.
    Stworzyłem klasę Player (Player.h i Player.cpp). Po przestudiowaniu poradników oraz zorientowaniu się co do Klas w C++
    chciałem w pierwotnym zamyśle umieścić instrukcje sterowania postacią za pomocą klawiszy (sf::Keyboard::isKeyPressed) nie
    w main.cpp a jako instrukcje w klasie Player (Player::control miało się nazywać). Ponadto chciałem, żeby zamiast wrzucać do 
    jednej funkcji w klasie rozbić na kilka funkcji (Player::draw i Player::update). Niestety nie chciało mi to działać.
    Instrukcję z update czy: 
    - o ile piksli ma się przesunąć postać (float xmove, float ymove)
    - na jakiej pozycji znajduję się postać czyli współrzędne x i y (float xpos, float ypos)
    Wrzuciłem do funkcji control i przy pomocy cout sprawdziłem, że działa. Ale problem pojawił się po stworzeniu postaci
    (test.png) i umieszczeniem go jako sprite sf::Sprite spritePlayer
    (przed załadowałem go jako tekstura sf::Texture texturePlayer). Mimo braku błędu (wszystkie funkcje zwracały void) postać 
    nie poruszała się wogóle. Własnie problem był z przekazaniem wartość między funkcjami by były powiązane. Mój pomysł na
    takie funkcje w klasie Player polegały na tym by ograniczyć mocno kod w main.cpp i zwiększyć czytelność - potrzebne
    instrukcje nie zalegały w pętli While event a zdefiniowane i wykonywane były by na osobny pliku. Narazie z tego pomysłu
    musiałem zrezygnować, ale nie ukrywam, że po konsultacji z prowadzącym zajęć (mgr. Maciej Lewicki) zamierzam do niego 
    wrócić. 
    
III. Instrukcje sprawdzające czy wciśnięty jest klawisz czy nie wrzuciłem poza switch(even.type) jako instrukcję 
     warunkowe if, które zwracają wartość zmiennych logicznych (bool) right i left jako true - klawisz wciśnięty
     false - klawisz nie jest wciśnięty. Oczywiście zadeklarowane zmienne mają wartość początkową false. Wartości
     zmiennych są wrzucane do funkcji update (klasa Player) gdzie sprawdzana jest wartość zmiennych logicznych i od
     ich wyniku zmienne typu float xmove i ymove są nadawane wartości 5 (-5 dla left 5 dla right). Wartość xmove są
     w czasie rzeczywistym zsumowane do zmiennej xpos i dzięki temu mam obecną wartość współrzędnej x dla Playera.
     przemieszczenie się postać jest odpowiedzialna wektor, który pobiera wartość zmiennych xpos, ypos 
     (sf::Vector2f - pobiera wartość zmiennych float dwóćh składowych)
     
#### Co zamierzam wykonać do następnego tygodnia:
I. Postaram się przemyśleć kwestie z budowaniem poziomu, instrukcjami dla klasy Player oraz skokiem postaci.

Narazie tylko tyle. Nie ukrywam, że tworzenie projektu C++ wygląda na improwizację, bo nie posiadam jeszcze dostatecznej
wiedzy na temat tworzenia elementów gry przy pomocy SFML a i planowanie też nie jest łatwe, bo nie wiem czy danych
element uda mi się wrzucić do mojego projektu. Staram się też grając w kilka platformówek szukać inspiracji do mojego projektu.
Na koniec podaje kod programu:
##### Player.h
```
#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
// Definicje funkcji z instrukcjami dla postaci gracza
class Player
{
 public:
  
  Player();
  ~Player();
  
  float xpos;
  float ypos; // narazie nic nie robi
  float xmove;
  float ymove;
  
  void update(bool right, bool left);  

 private:

};

```
##### Player.cpp
```
#include "Player.h"
Player::Player()
{
 xpos = 0;
 ypos = 0;
 xmove = 0;
 ymove = 0;

}


Player::~Player()
{
}


void Player::update(bool right, bool left)
{ 
  if(right) xmove =  5; 
  if(left)  xmove = -5; 
  
  if(!(right || left)) xmove = 0;

  xpos += xmove;
  std::cout<< xpos <<std::endl;
  
}


```
##### main.cpp
```
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Player.h"
#include "Player.cpp"


int main()
{
 sf::RenderWindow window(sf::VideoMode(800,600), "ProjektC++");
 
 bool right, left, up, down = false;
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
               if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))      right = true;
               if(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)))   right = false;

               if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))       left = true;
               if(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))    left = false;

          objPlayer.update(right,left);
          window.clear();
          window.draw(spritePlayer);
          spritePlayer.move(sf::Vector2f(objPlayer.xmove, objPlayer.ymove));
          window.display();
          

      }
return 0;
}

```

# ProjektC++
## Raport #2 - 25.10.2018
### Autor: Piotr Krupa ISSP rok II

#### Co zostało do tej pory wykonane:
I. Udało mi się rozwiązać problem z biblioteką SFML. Otóż zadecydowałem o zmianie środowiska. 
   Za sugestią prowadzącego (mgr. Maciej Lewicki) zdecydowałem o rezygnacji z Code::Blocks ze względu
   na problemy z konfiguracją SFML pod niego:
   - Dobranie odpowiedniej wersji Code::Blocksa oraz kompilatora
   - Dobór odpowiedniej wersji biblioteki SFML
   
   Zdecydowałem, że swój projekt będe wykonywał na systemie Ubuntu (Linux) ze względu na prostotę (w konfiguracji oraz tworzenia
   plików). Początkowo chciałem zainstalować subsystem Ubuntu na Windows 10, by pliki z projektem posiadać na Windowsie zaś kompilacja      miałaby się odbywać w terminalu Ubuntu. Problem polegał na tym, że pomimo instalacji windows Xserver vcxsrv po stronie Windowsa10        oraz modyfikacji pliku bashrc po stronie Ubuntu subsystem uruchamianie i testowanie napisanego kodu mogło być problematyczne 
   (Testy klawiszy, przycisków myszy).
   
   Więc za najlepsze rozwiązanie uznałem zainstalowanie obok Windowsa 10 system Ubuntu. Następnie wystarczyło wykorzystując terminal
   zainstalować kompilator (g++) oraz biblioteke SFML (-lsfmlib-dev).
   
II. Po konfiguracji Ubuntu wróciłem do protypu menu głównego gry i napisałem go od nowa:
    W Klasach istotną zmianą jest dołączenie do pliku głównego (main.cpp) prócz plików nagłówkowego (menu.h) także pliku klasy (menu.cpp).
   ##### main.cpp
    ```
       #include "SFML/Graphics.hpp"
       #include <iostream>
       #include "menu.h"
       #include "menu.cpp"
    
    ```
   
   Jęśli chodzi samo menu: 
   
   + to posiada trzy opcje: "Graj" , "Opcje", "Wyjście". Wyświetlane są w czcionce "arial.tff", którą musiałem       
    pobrać by z niej korzystać. Liczbę elementów w meni definiuje zmienna "#define MAX_NUMBER_OF_ITEM"
   + Kostruktor menu() pobiera tylko wartość "width" oraz "height" , którę są wykorzystywane do umieszczenia napisów w tle okna.
   + Do nawigacji, w której wykorzystywane są klawisze "Góra" i "Dół" odpowiedzialne są funkcję "MoveUp" i "MoveDown". Jako indeks
     wybranego elementów służy zmienna "int selectedIndexItem". Zmiana opcji polega na zmianie koloru nazwy opcji z białego na czerwony
     jako ten wybrany. Funkcja "GetPressedItem" zwraca wartość aktualną "selectedIndexItem" , która konieczna jest przy wywołaniu
     "eventu" wciśnięcia klawisza "ENTER". Wywołanie poszczególnych funkcji można znależć w main.cpp jako switche. Jedymi funkcjami
     są zamknięcie okna aplikacji ("Wyjście") oraz potwierdzenie wciśniecia klawisza jako komunikat w konsoli ("Graj" oraz "Opcję").
   ##### menu.h
   ```
#pragma once
#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 3

class menu
{
public:
    menu(float width, float height);
   ~menu();

    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem(); 

private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text text[MAX_NUMBER_OF_ITEMS];

};

   
   ```
   ##### menu.cpp
   ```
   #include "menu.h"


menu::menu(float width, float height)
{

 if (!font.loadFromFile("arial.ttf"))
    {
     // handle error
    }

  text[0].setFont(font);
  text[0].setColor(sf::Color::Red);
  text[0].setString("Graj");
  text[0].setPosition(sf::Vector2f(width/2, height/ (MAX_NUMBER_OF_ITEMS + 1) * 1)); 

  text[1].setFont(font);
  text[1].setColor(sf::Color::White);
  text[1].setString("Opcje");
  text[1].setPosition(sf::Vector2f(width/2, height/ (MAX_NUMBER_OF_ITEMS + 1) * 2));

  text[2].setFont(font);
  text[2].setColor(sf::Color::White);
  text[2].setString("Wyjscie");
  text[2].setPosition(sf::Vector2f(width/2, height/ (MAX_NUMBER_OF_ITEMS + 1) * 3)); 
 
  selectedItemIndex = 0;

}

menu::~menu()
{
}



void menu::draw(sf::RenderWindow &window)
{
 for(int i=0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
      window.draw(text[i]);

    }
}


void menu::MoveUp()
{

 if(selectedItemIndex - 1 >= 0)
   {
     text[selectedItemIndex].setColor(sf::Color::White);
     selectedItemIndex--;
     text[selectedItemIndex].setColor(sf::Color::Red);
   }


}


void menu::MoveDown()
{

 if(selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
   {
    text[selectedItemIndex].setColor(sf::Color::White);
    selectedItemIndex++;
    text[selectedItemIndex].setColor(sf::Color::Red);

   }

}


int menu::GetPressedItem()
{
  return selectedItemIndex;
}
   
   ```
   
   ##### main.cpp
   
   ```
#include "SFML/Graphics.hpp"
#include <iostream>
#include "menu.h"
#include "menu.cpp"

int main()
{
 sf::RenderWindow window(sf::VideoMode(600,600), "ProjektC++");

 menu menu(window.getSize().x, window.getSize().y);

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
                                     case sf::Keyboard::Up:
                                          menu.MoveUp();
                                          
                                          break;

                                     case sf::Keyboard::Down:
                                          menu.MoveDown();
                                          
                                          break;
                                     
                                      case sf::Keyboard::Return:
                                           switch(menu.GetPressedItem())
                                                 {
                                                   case 0:
                                                   std::cout<<"Graj!"<<std::endl;
                                                   break;

                                                   case 1:
                                                   std::cout<<"Opcję"<<std::endl;
                                                   break;
                                                   
                                                   case 2:
                                                   std::cout<<"Wyjście"<<std::endl;
                                                   window.close();
                                                   break;
                                                 }
 
                                   }
                             
                             break;                               
                        
                        case sf::Event::Closed:
                             window.close();

                             break;
 
                      } 
 
              }
          

          window.clear();
            
          menu.draw(window);

          window.display();


      }


   
   ```
   
   Niestety z powodu problemów z Code::Blocksem to narazie tyle co mogę pokazać i na dobrą sprawę dopiero teraz zaczyna się moja praca
   nad projektem.
#### Co zamierzam wykonać do następnego tygodnia:
 +  Rozpocząć wprowadzać elementy postaci, wrogów, plansz,
+   Zapoznanie się z wprowadzeniem animacji do postaci, grawitacji do skoków, poruszania się itd.

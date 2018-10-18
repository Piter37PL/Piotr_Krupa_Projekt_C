# ProjektC++
## Raport #1 - 18.10.2018
### Autor: Piotr Krupa ISSP rok II

#### Co zostało do tej pory wykonane:
I. W pierwszej kolejność skonfigurowałem Code::Blocks 17.12 w wersji 32-bitowej do pracy z SFML 2.4.2.
   Pobrałem i zainstalowałem:
   - codeblocks-17.12mingw-setup.exe z kompilatorem GNU GCC compiler
   - SFML 2.4.2 - GCC 4.9.2 TDM (SJLJ) - 32-bit
   
II. Zacząłem od zaprojektowania "prototypu" głównego menu gry. Do tego celu stworzyłem klasę main_menu.
    Niestety, gdy chciałem wyświetlić wynik kodu otrzymałem dwa błędy:
    
  ```
     undefined reference to '_imp___ZN2sf4Font12loadFromFileERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE'
     
     ld returned 1 exit status
  ```
    
 Problem wynika z linijki kodu , która sprawdza czy nie załadowano poprawnie lub wogóle czcionke sf::Font font w pliku main_menu.cpp:
 
 ```
    if(!font.loadFromFile("arial.ttf"))
      {
    // error...
      }
 ```
 
 Próbowałem zmienić standard kompilacji (C++11, C++14), modyfikować ustawienia w linkerach, ale żadnych efektów to nie dało. Dopóki tego 
 problemu nie rozwiąże nie będe mógł pójść dalej w pracach nad grą
 
 #### Co zamierzam wykonać do następnego tygodnia:
 I. Rozwiązać problem z powyższy problem z menu głównym gry.
 II. Rozpocząć wprowadzać elementy postać, poruszania się , grawitacji do skoków.
 III. Zapoznanie się z wprowadzeniem animacji do postaci - jęśli wykonam punkt I i II
 
 #### Na sam koniec podaje niedziałając kod do tej pory co udało mi się wykonać
 
 ##### main.cpp:
 
```
#include <SFML/Graphics.hpp>
#include "main_menu.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Platformer2d - Piotr Krupa");

    main_menu menu(window.getSize().x , window.getSize().y);

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            switch(event.type)
            {
            case sf::Event::Closed:
                window.close();

                break;
            }

        }

          window.clear();
          menu.draw(window);
          window.display();

    }

    return 0;
}
 
```
 ##### main_menu.h
 
 ```
 #include <SFML/Graphics.hpp>


class main_menu
{
    public:
        main_menu(float width, float height);
        ~main_menu();

        void draw(sf::RenderWindow &window);
        void MoveUp();
        void MoveDown();

    private:
        int selectedItemIndex;
        sf::Font font;
        sf::Text menu[MAX_NUMBER_OF_ITEMS];
};
 
 
 ```
 
 ##### main_menu.cpp
 
 ```
 #include "main_menu.h"

main_menu::main_menu(float width, float height)
{

    if(!font.loadFromFile("arial.ttf"))
      {
    // error...
      }

    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f(width/2, height/(MAX_NUMBER_OF_ITEMS+1)*1));

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Options");
    menu[1].setPosition(sf::Vector2f(width/2, height/(MAX_NUMBER_OF_ITEMS+1)*2));

    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Exit");
    menu[2].setPosition(sf::Vector2f(width/2, height/(MAX_NUMBER_OF_ITEMS+1)*3));
}

main_menu::~main_menu()
{
    //dtor
}



void main_menu::draw(sf::RenderWindow &window)
{
    for(int i=0; i<MAX_NUMBER_OF_ITEMS; i++)
    {
        window.draw(menu[i]);
    }
}
 
 
 ```
 

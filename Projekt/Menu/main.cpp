#include "SFML/Graphics.hpp"
#include <iostream>
#include "menu.h"
#include "menu.cpp"


int main()
{
 sf::RenderWindow window(sf::VideoMode(800,600), "ProjektC++");

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
                                                   case 1:
                                                   std::cout<<"Graj!"<<std::endl;
                                                   break;

                                                   case 2:
                                                   std::cout<<"Opcję"<<std::endl;
                                                   break;
                                                   
                                                   case 3:
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

}

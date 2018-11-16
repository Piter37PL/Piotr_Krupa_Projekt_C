#include "menu.h"
#include <iostream>

menu::menu(float width, float height)
{

 if (!font.loadFromFile("arial.ttf"))
    {
     std::cout<<"Błąd - nie można wczytać czcionki"<<std::endl;
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







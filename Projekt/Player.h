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
  
  void control(sf::RenderWindow &window);        //Sprawdzenia Sterowania
  void update(bool right, bool left, bool jump); //Aktualizacji pozycji postaci 
  
 
 private:
  bool right;                                    //Czy wciśnieto klawisz Prawo - ruch w prawo
  bool left;                                     //Czy wciśnięto klawisz Lewo  - ruch w lewo
  bool jump;                                     //Czy wciśnięto klawisz Spacja - skok postaci
  float gravity;                                 //Stałe przyspieszenie grawitacyjne do skoku
  
  int jump_counter;
  friend class Platform;
  
};

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
  
  float GetPosX();                               //Pobieranie wartości xpos
  float GetPosY();                               //Pobierania wartości ypos
  sf::Sprite spritePlayer;

 private:
  bool right;                                    //Czy wciśnieto klawisz Prawo - ruch w prawo
  bool left;                                     //Czy wciśnięto klawisz Lewo  - ruch w lewo
  bool jump;                                     //Czy wciśnięto klawisz Spacja - skok postaci
  int jump_counter;                              //Licznik skoków

  sf::Texture texturePlayer;

};

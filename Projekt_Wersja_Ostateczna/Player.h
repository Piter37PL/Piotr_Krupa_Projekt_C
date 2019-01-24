#pragma once

//Biblioteki
#include <iostream>
#include "SFML/Graphics.hpp"

class Player
{
 public:
  
  Player();
  ~Player();

  float xmove;                                   //Prędkość w osi x
  float ymove;                                   //Prędkość w osi y

  bool hit;                                      //Czy Player został trafiony
  bool healing;                                  //Czy Player został wyleczony
  
  void control();                                                      //Sprawdzenia Sterowania
  void update(bool right, bool left, bool jump);                       //Aktualizacji pozycji postaci 
  void health(sf::RenderWindow& window);                               //Licznik zdrowia
  void animation(bool right, bool left, bool jump, bool shoot);        //Animacja
  
  float GetPosX();                               //Pobieranie wartości
  float GetPosY();                               
  bool  GetShoot();                                       

  sf::Sprite spritePlayer;                       //Sprite Playera
  sf::Sprite spriteHealth_bar;                   //Sprite Health_bar

 private:
  bool right;                                    //Czy wciśnieto klawisz Prawo - ruch w prawo
  bool left;                                     //Czy wciśnięto klawisz Lewo  - ruch w lewo
  
  bool jump;                                     //Czy wciśnięto klawisz Spacja - skok postaci
  int jump_counter;                              //Licznik skoku
 
  bool shoot;                                    //Czy wciśnięto klawisz Lcontrol - strzał postaci
  int shoot_counter;                             //Licznik Strzału

  int life;                                      //Licznik zdrowia

  sf::Texture texturePlayer;                     //Tekstura Playera
  sf::Texture  textureHealth_bar;                 //Tekstura Health_bar
};

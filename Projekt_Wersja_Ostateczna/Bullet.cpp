#include "Bullet.h"


Bullet::Bullet(sf::Vector2f size)
{
 bullet.setSize(size);          //Ustawienie rozmiaru bullet
}

Bullet::~Bullet()
{

}

void Bullet::fire(int speed)
{
 bullet.move(speed, 0);       //Ruch bullet
}

void Bullet::draw(sf::RenderWindow &window)
{
 window.draw(bullet);                    //Rysowanie bullet
}

void Bullet::setPos(sf::Vector2f newPos)
{
 bullet.setPosition(newPos);            //Pozycja Bullet
}
//Pobieranie wartości
float Bullet::GetPosX()
{
 sf::Vector2f v;
 v = this->bullet.getPosition();
 return v.x;
}

float Bullet::GetPosY()
{
 sf::Vector2f v;
 v = this->bullet.getPosition();
 return v.y;
}

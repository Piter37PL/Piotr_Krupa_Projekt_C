#pragma once
#include <iostream>

#include "Player.h"
#include "Ground.h"
#include "Platform.h"
#include "Enemy1.h"
#include "Bullet.h"
#include "First_aid.h"

class Collision
{
 public:
 Collision();
 ~Collision();

 void checkPlayerFinishEdgeScreen(Player& player, sf::RenderWindow& window);

 void checkGroundCollision(Player& player, Ground& ground);
 void checkPlatformCollision(Player& player, Platform& platform); 

 void checkPlayerEnemyCollision(Player& player, Enemy1& enemy1);

 void checkBulletEnemyCollision(Bullet& bullet, Enemy1& enemy1);
 void checkFirst_aidPlayerCollision(First_aid& first_aid, Player& player);

 private:

};


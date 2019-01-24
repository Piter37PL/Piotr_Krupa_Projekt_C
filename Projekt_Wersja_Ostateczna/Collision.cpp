#include "Collision.h"

Collision::Collision()
{
}

Collision::~Collision()
{
}

void Collision::checkPlayerFinishEdgeScreen(Player& player, sf::RenderWindow& window)
{
  if(player.GetPosX() <= 0.f && player.xmove < 0)
    {
      player.xmove = 0.f;
    }
  if(player.GetPosX() >= 16720.f && player.xmove > 0)
    {
     player.xmove = 0.f;
    } 
  if(player.GetPosX() >= 16565.5 && player.GetPosY() >= 300.f && player.xmove > 0 )
    {
     window.close();
     std::cout<<"You win !!!"<<std::endl;
    }

}

void Collision::checkGroundCollision(Player& player, Ground& ground)
{
 
  if(player.GetPosY() == ground.GetYMin() && player.ymove > 0)
    {
      player.ymove = 0.f;
    }
}

void Collision::checkPlatformCollision(Player& player, Platform& platform)
{
 if(player.GetPosY() == platform.GetY() - platform.GetBlocY()*2 && 
    player.GetPosX() >= platform.GetX()-platform.GetBlocX()*2 && 
    player.GetPosX() <= platform.GetX()+platform.GetBlocX()*platform.GetNX()+1
    && player.ymove > 0)
   {
    player.ymove = 0.f;
   }

 if(player.GetPosY() == platform.GetY() + platform.GetBlocY() && 
    player.GetPosX() >= platform.GetX()-platform.GetBlocX()*2 && 
    player.GetPosX() <= platform.GetX()+platform.GetBlocX()*platform.GetNX()+1
    && player.ymove < 0)
   {
    player.ymove = 0.f;
   }
  
 if(player.GetPosX() == platform.GetX()-platform.GetBlocX()*2 &&
    player.GetPosY() <= platform.GetY() + platform.GetBlocY() &&
    player.GetPosY() >= platform.GetY() - platform.GetBlocY()*2 &&
    player.xmove > 0)
    {
     player.xmove = 0.f;
     
    }

  if(player.GetPosX() == platform.GetX()+platform.GetBlocX()*platform.GetNX()+1 &&
    player.GetPosY() <= platform.GetY() + platform.GetBlocY() &&
    player.GetPosY() >= platform.GetY() - platform.GetBlocY()*2 &&
    player.xmove < 0)
    {
     player.xmove = 0.f;
     
    }

}

void Collision::checkPlayerEnemyCollision(Player& player, Enemy1& enemy1)
{
 
  if(player.GetPosX()+80 >= enemy1.GetPosX()
     && player.GetPosY() <= enemy1.GetPosY() 
     && player.GetPosY()+60 >= enemy1.GetPosY()+60
     && player.GetPosX() <= enemy1.GetPosX()+80 
    )
    { 
      player.hit = true;
      player.ymove = -150;
    }

}

void Collision::checkBulletEnemyCollision(Bullet& bullet, Enemy1& enemy1)
{
 if(bullet.GetPosX() >= enemy1.GetPosX() &&
    bullet.GetPosX() <= enemy1.GetPosX()+80 &&
    bullet.GetPosY() <= enemy1.GetPosY()+60 &&
    bullet.GetPosY() >= enemy1.GetPosY()
   )
   {
    enemy1.spriteEnemy.setPosition(-2000,-6000);
   }
}


void Collision::checkFirst_aidPlayerCollision(First_aid& first_aid, Player& player)
{

 if(
    player.GetPosX() >= first_aid.GetPosX()-40*2 && 
    player.GetPosY() <= first_aid.GetPosY()+30 &&
    player.GetPosY() >= first_aid.GetPosY() - 30*2 &&
    player.xmove > 0
   )
   {
   player.healing = true;
   first_aid.SpriteFirst_aid.setPosition(30000,40000);
   }

 if(
    player.GetPosX() <= first_aid.GetPosX()+40*1 &&
    player.GetPosY() <= first_aid.GetPosY()+30 &&
    player.GetPosY() >= first_aid.GetPosY()-30*2 &&
    player.xmove < 0
   )
   {
   player.healing = true;
   first_aid.SpriteFirst_aid.setPosition(30000,40000);
   }

 if(player.GetPosY() >= first_aid.GetPosY()+30*2 &&
    player.GetPosX() >= first_aid.GetPosX()+40*1 &&
    player.GetPosX() <= first_aid.GetPosX()-40*2 && 
    player.ymove > 0)
   {
    player.healing = true;
    first_aid.SpriteFirst_aid.setPosition(30000,40000);
   }
 
 if(player.GetPosY() <= first_aid.GetPosY()-30*2 &&
    player.GetPosX() <= first_aid.GetPosX()+40*1 &&
    player.GetPosX() >= first_aid.GetPosX()-40*2 && 
    player.ymove < 0)
   {
    player.healing = true;
    first_aid.SpriteFirst_aid.setPosition(30000,40000);
   }
}

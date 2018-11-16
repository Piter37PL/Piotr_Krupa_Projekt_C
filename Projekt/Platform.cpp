#include "Platform.h"

Platform::Platform(int &rosx, int &rosy)
{
 
 for(int i=0; i<=19; i++)
    {
     for(int j=0; j<=19; j++)
        {
          arrayP[i][j] = 0;
        }
    }

  TextureBlock.loadFromFile("Bloc1.png");
  
  for(int i=0; i<=19; i++)
    {
     spriteBlock[i].setTexture(TextureBlock);
     spriteBlock[i].setPosition((rosx/20)*i, rosy);
    }


}

Platform::~Platform()
{
}

void Platform::drawGround(sf::RenderWindow &window)
{

 for(int i=0; i<=19; i++)
    {
     window.draw(spriteBlock[i]);
    }
 
}



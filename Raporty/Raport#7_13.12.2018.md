# ProjektC++
## Raport #7 - 13.12.2018
### Autor: Piotr Krupa ISSP rok II

#### Co zostało do tej pory wykonane:
1. Udało mi się stworzyć 'Kamere gry' (sf::View view1). Okazało się to wcale nie trudne jak się spodziewałem
Nie jest to zbyt skomplikowany kod. Umieściłem go w main.cpp. Warto zwrócić uwagę na warunek if - W większość grach
platformowych kamera zaczyna poruszać się w momencie gdy postać będzie znajdować się na środku odległości x okna.
Dlatego też umieściłem warunek, gdy pozycja x postaci (Player.xpos) będzie miała wartość większą niż 350 kamera
będzie się poruszać się z prędkością równą Player.xmove. Póki co planuje zrobić poziome mapy, więc kamera nie będzie poruszać
się w osi y:

main.cpp:
```
sf::View view1(sf::FloatRect(0.f, 0.f, 800.f, 600.f)); //KAMERA
....
 //KAMERA 
          if(objPlayer.xpos > 350.f )
            {
             view1.move(sf::Vector2f(objPlayer.xmove, 0));
            }
          window.setView(view1);


```

2. Stworzyłem Kolizje z Ground i cześciowo z Platform. 
   Obydwie funkcje umieściłem narazie w main.cpp. Wartości z pozycją Playera, Ground i Platform są
   pobierane poprzez metody Get ( i ustawiane w Set w przypadku Player do ustawienia jego pozycji na platformie czy ground).
   Get i Set znajdują się w klasach PLayer, Ground i Platform
   O ile dla kolizji Player-Ground działa bez zarzutu to w przypadku Player-Platform już nie zupełnie, ponieważ nie działa
   kolizja pod platformą oraz gdy postać znajduję się na platformie to nie może już skakać gdy jest pośrodku w niej.
```
void checkGroundCollision(Player& player, Ground ground)
{
   //Pseudokolizja z lewą krawędzią ekranu
  if(player.GetPosX() < 0.f)
    {
      player.xmove = 0.f;
      player.SetPosX(0.f);
    }
  //Pseudokolizja z 'ziemią' 
  if(player.GetPosY() > ground.GetYMin())
    {
      player.ymove = 0.0;
      player.SetPosY(ground.GetYMin());
    }
}

void checkPlatformCollision(Player& player, Platform& platform)
{

 if(player.GetPosX() >= platform.GetX()-80 && player.GetPosX() <= platform.GetX()+4*40
    && player.GetPosY() <= platform.GetY()+platform.GetNY()*platform.GetBlocX()) 
    {
     player.SetPosY(platform.GetY()-50);
     player.ymove = 0;
    }
}

```

#### Co zamierzam wykonać do następnego tygodnia: 
1. W tym tygodniu będę pokazywał prototyp gry.
2. Stworzenie przeciwników i poprawienie działania kolizji Postać-Platforma

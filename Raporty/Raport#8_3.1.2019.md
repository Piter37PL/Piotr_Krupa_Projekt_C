# ProjektC++
## Raport #8 - 3.1.2019
### Autor: Piotr Krupa ISSP rok II

#### Co zostało do tej pory wykonane:
1. Co do przeciwników - ustaliłem, że stworze kilka klas Enemy. Powód jest taki, że każda klasa będzie tworzyć przeciwnika
o innej charakterystyce (sposób poruszania się po planszy, ewentualnie inna forma ataku). Wymyśliłem na przykład, że jeden
przeciwnik będzie przesuwał się poziomo w lewo/prawo (ruch do przodu i do tyłu z perspektywy 2D), inny będzie biegł na wprost
gracza do końca inny będzie przesuwał się w góre i dół a jeszcze inny przesuwać się po okręgu. Stworzyłem przykładową klasę
Enemy1, która posiada jeszcze poprzedni system poruszania się po planszy (Enemy1::update). Stworzyłem też raczej gotowy sprite.

2. Ze względu na problemy z kolizją postać-platforma, nadal myśle nad zmianami w działaniu ruchu postać - update. Ustaliłem, że
SetPosition będzie służyło do ustawienia postać w pozycji początkowej, zaś move do ruchu postać. Narazie kolizja jest pokrzaniona
(Ground). Gdzieś nie nadaje wartość nowej dla Playera i nie można porównać wartośći, lub czegoś brakuje w funkcji kolizji lub
w metodach klasy Player.

#### Co zamierzam wykonać do następnego tygodnia: 
1. Stworzyć przeciwników
2. Na osobnym plikach testować ruch, kolizje, strzelanie
3. W następny czwartek pokazać prototyp - w końcu. (Pana mgr.Lewickiego musiał dopaść pech, że nie był obecny na dwóch zajęciach
 może tym razem do trzech razy sztuka).

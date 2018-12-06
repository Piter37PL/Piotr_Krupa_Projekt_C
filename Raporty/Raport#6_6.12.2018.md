# ProjektC++
## Raport #6 - 6.12.2018
### Autor: Piotr Krupa ISSP rok II

#### Co zostało do tej pory wykonane:
1. Przerobiłem sposób tworzenia platform.
   Stworzyłem klasy Ground, która rysuje 'ziemie' oraz zaś klasa Platform jest odpowiedzialna za rysowanie platform.
   Zmieniłem też metody odpowiedzialne za rysowanie obiektów mapy:
   + Klasie Platform każdy obiekt danej klasy to osobna platforma z :
     - x -> pozycja początkowa serii bloczków w osi x
     - y -> pozycja początkowa serii bloczków w osi y
     - nx -> liczba bloczków w osi x
     - ny -> liczba bloczków w osi y
  + Platformy są rysowane przy użyciu pętli for z ustawieniem ich pozycji na podstawie powyższy zmiennych
  + W Klasie Ground z dwóch pętli for przerobiłem metodę drawGround na jedną, która rysuje ziemie
2. Wprowadzając kolizje zacząłem od 'zaprzyjaźnienia' klasy Platform z Playerem. Narazie tylko tyle, gdyż nie 
   zdołałem jeszcze rozgryść jak wykorzystać dane z Player by wprowadzić kolizje z Platform
   (Chodzi o to by kolizje sprawdzić po przez porównanie pozycji Playera z Platformą)
   
#### Co zamierzam wykonać do następnego tygodnia: 
1. Kolizja Player - Platforma
2. Kamera gry - Przesuwanie ekranu względem Playera

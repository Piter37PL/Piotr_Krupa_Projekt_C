# ProjektC++
## Raport #5 - 29.11.2018
### Autor: Piotr Krupa ISSP rok II

#### Co zostało do tej pory wykonane:
1. Stworzyłem klasę Platform (Plaform.cpp i Platform.h), które jest odpowiedzialne za rysowanie planszy.
Plan tworzenia map zakłada podzielenie pojedynczego ekranu na siatke bloczków o rozmiarze 20x20 bloków.
Nie przypadkowo wybrałem rozdzielczość ekranu 800x600, ponieważ co prawda nie umieszaczam bloków w kształcie
kwadratów a w kształcie prostokątów, ale mimo to ilość możliwych do umieszczenia bloków na osi x jest taka
sama co na osi y. Jako bloczek testowy stworzyłem Bloc1.png przy pomocy programu GIMP 2.0. 

Póki co Klasa Platform jest traktowana przeze mnie jako klasa testowa by sprawdzić możliwości rysowania a później
do kolizji z innymi obiektami. Początkowo przy tworzeniu "podłogi" (Platform::drawGround(window)) 
sądziłem, że będe musiał stworzyć wektor lub tablice ze spritemi (sf::Sprite spriteBlock) do której każdej 
będzie załadowana tekstura (sf:Texture textureBlock) i będzie ona rysowana każda kolejna w pętli for z metody
Platform::drawGround. Niestety nie chciało mi rysować wogóle, więc musiałem zacząć wszystko od początku -
czyli w samym kodzie main.cpp stworzyłem teksture i sprite i funkcje do rysowania na ekranie. W gdy zacząłem sprawdzać
pętle for to zauważyłem, że wcale nie trzeba tworzyć tablicy czy wektor ze spritami - wystarczy by pętli for rysował
ten sam sprite ale przy użyciu setpostion ustawić jego pozycje na ekranie. I wcale (jak wcześniej myślałem) nie rysuje
tylko jednego sprite. Wróciłem więc do Klasy Platform dokonałem kilka modyfikacji. 

Pozwolę sobie na krótką charakterystykę klasy Platform:
- Przy tworzeniu obiektu (objPlatform) jest pobierana wartość rozmiaru ekranu (rosx, rosy)
  do konstruktora Platform::Platform
- Jako zmienne stworzyłem:
  + rosxB i rosyB, które przjmują wartość rosx i rosy
  + blocX i blocY, które przyjmują wartość rozmiaru pojedynczego bloczka (x = 30, y = 40)
  + textureBlock - zmienna do której załadowana jest tekstura Bloc1.png
  + spriteBLock - zmienna do której załadowana jest sprite z tekstury textureBlock
- Jako metody stworzyłem:
  + drawGround - pobiera wartość RenderWindow window i przy pomocy pętli for rysuje dwie warstwy podłogi
  + drawPlatform - pobiera wartość RenderWindow window i przy pomocy pętli for rysuje pojedyncze platformy
- Aby wykorzystywać zmienne zadeklarowane w konstruktorze w innych metodach klasy, ale bez zmiany ich wartość 
  oraz bez tworzenia nowych zmiennych użyłem wskaźnika this, która wskazuję na obiekty wywołane przez metode.
  (Przy okazji zacząłem rozumieć kolejny element w języku C++, którego nie potrafiłem wcześniej zrozumieć)
  
  2. Zacząłem do repezytorium tworzonego projektu umieszczać pliki oraz inne elementy z niego. Od teraz w raporcie nie 
  umieszczam kodu programu (chyba, że będzie oto poproszone przez prowadzącego w zastrzeżeniach lub z innych powodów).
  Wszystkie pliki projektu będą umieszczone w katalogu Projekt. Na koniec podaje pliki, które uległy modyfikacji:
  - main.cpp
  - Player.cpp
  - Player.h
  - Platform.cpp
  - Platform.h
  
   #### Co zamierzam wykonać do następnego tygodnia:
   1. Mam pomysł odnośnie rysowania plansz, ale muszę to przedyskutować z prowadzącym (mgr. Maciej Lewicki). Chodzi
   oto aby stworzyć klasę, która będzie w zależność od tego jaki gra zamierza załadować poziom wczyta plik txt z pozycjami
   x i y bloczków, które zostaną zapisane w zmiennych i będą rysowane przez petle. By to zrealizować będe musiał
   załatwić kwestie kolizji i przesuwania kamery - te elementy też przedyskutować
   
   2. Narysować postacie przy użyciu GIMPa
   
   3. Zastanowić się nad mechaniką strzelania i wspomnianymi na koniec punktu 1 elementami.
   
   

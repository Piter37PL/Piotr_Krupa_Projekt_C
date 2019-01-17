# ProjektC++
## Raport #9 i #10 - 10.1.2019 i 17.1.2019
### Autor: Piotr Krupa ISSP rok II

#### Co zostało do tej pory wykonane:
Z racji, że nienapisałem poprzedniego raportu w zeszłym tygodniu, ten będzie łączony - zawierać będzie to co wykonałem.
Dodatkowo przedstawiony prototyp został przyjęty.

1. Wykonałem cześćiowo system strzelania:
   + dodałem do klasy Player warunek czy wciśnięto klawisz lewy Control, oraz zmienną bool, która jej wartość jest
     wysyłana poprzez metode get.
   + Stworzyłem klasę Bullet, która przyjmuję pozycję początkową pocisku, rysowanie jako obiekt RectangleShaple,
     oraz ustaloną prędkość jaką się ma poruszać
   + Wykorzystałem vector Bullet by tworzyć i dodawać do niej nowe obiekty, mające te same właściwości. Następnie
     w pętli for obiekty w vectorze są rysowane i poruszają się z taką prędkością jaka została im nadana.
     
     Narazie brakuje kolizji oraz występuje błąd, w którym postać strzela ogniem ciągłym. 
     
2. Próbowałem stworzyć tablicę obiektów klasy Platform by nie tworzyć pojedyncze obiekty, a tylko w tablicach ustalić ich 
   współrzędne początkowe oraz ilość klocków w osi X. Udało mi się stworzyć w podobny sposób co rysowanie bullet, ale
   występują błędy z kolizją i też musiałem zmodyfikować klasę Platform by rysowała po konkretnej teksturze. Być może 
   to poprawię, ale narazie raczej będe tworzyć obiekty pojedyncze dla każdej platformy.
   
 3. Zacząłem rysować tło do poziomu by nie był z powodu czerni pusty.
 4. Zacząłem rysować pierwszych przeciwników. Być może dostaną swoje animację.
 
 5. Na podstawie tutoriala z :
    https://github.com/SFML/SFML/wiki/Tutorial:-Manage-different-Screens
    sprawdziłem jak zrobić by przełaczać się pomiędzy ekranami (menu -> gra). Działa. Potem wrzuciłem cześć kodu
    odpowiedzialnej za moją grę. Też działa, ale niestety prędkość gry spada, wręcz momentami zatrzymuję się. Ciężko powiedzieć,
    czy zdołam to zrobić do czwartku.
    
    
#### Co zamierzam wykonać do następnego tygodnia: 
     Za tydzień w czwartek będe prezentowane prace. Zdecydowałem, że póki co nie wykorzystam terminu awaryjnego - dopiero,
     gdy uznam, że mam problemy to go wykorzystam. Pracę prawdopodobnie będe prezentować na żywo , bez prezentacji.
     A oto lista rzeczy, które muszę wykonać do dokończenie projektu.
     V- duża szansa , że go wykonam               X - małe szanse na wykonanie
     
     1. Dokończenie strzelania i stworzenie system zdrowia - V
     2. Wykonanie textury postaci i animacji               - V
     3. Wykonanie tła do planszy                           - V
     4. Wykonanie przeciwników (3 lub 2 będzie typów) , kolizji i strzelanie - V 
     5. Rozwiązanie problemu z main menu                  - X
     6. Stworzenie Game over screen                       - X
     7. Rozwiązanie problemu z tablicą obiektów           - X

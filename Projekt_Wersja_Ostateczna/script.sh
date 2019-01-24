g++ -c main.cpp
if [ $? -eq 0 ]; then
	g++ main.o -o main -lsfml-graphics -lsfml-window -lsfml-system
	./main
else
	echo FAIL
fi

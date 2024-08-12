main: main.o
	g++ main.o -o app -lsfml-graphics -lsfml-window -lsfml-system -lGL

main.o: main.cpp
	g++ -c main.cpp

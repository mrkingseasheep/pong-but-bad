main: main.o game.o ball.o
	g++ main.o game.o ball.o -o app -lsfml-graphics -lsfml-window -lsfml-system -lGL

main.o game.o ball.o: src/main.cpp src/ball.cpp src/game.cpp
	g++ -c src/ball.cpp src/game.cpp src/main.cpp

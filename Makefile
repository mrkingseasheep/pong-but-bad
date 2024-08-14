main: main.o Ball.o GameManager.o
	g++ main.o Ball.o GameManager.o -o app -lsfml-graphics -lsfml-window -lsfml-system -lGL

main.o ball.o: src/main.cpp src/Ball.cpp src/GameManager.cpp
	g++ -c src/Ball.cpp src/main.cpp src/GameManager.cpp


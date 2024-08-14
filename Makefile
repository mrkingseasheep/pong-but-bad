main: main.o Ball.o GameManager.o Paddle.o
	g++ main.o Ball.o GameManager.o Paddle.o -o app -lsfml-graphics -lsfml-window -lsfml-system -lGL

build: src/main.cpp src/Ball.cpp src/GameManager.cpp src/Paddle.cpp
	g++ -c src/Paddle.cpp src/Ball.cpp src/main.cpp src/GameManager.cpp 

main: main.o  ball.o
	g++ main.o ball.o -o app -lsfml-graphics -lsfml-window -lsfml-system -lGL

main.o ball.o: src/main.cpp src/ball.cpp 
	g++ -c src/ball.cpp src/main.cpp

main: main.o Ball.o Paddle.o
	g++ main.o Ball.o Paddle.o -o app -lsfml-graphics -lsfml-window -lsfml-system -lGL

main.o Ball.o Paddle.o: main.cpp Ball.cpp Paddle.cpp
	g++ -c Ball.cpp main.cpp Paddle.cpp

clean:
	rm *.o

main: main.o Ball.o Paddle.o Powerup.o
	g++ main.o Ball.o Paddle.o Powerup.o -o app -lsfml-graphics -lsfml-window -lsfml-system -lGL -lsfml-audio

main.o Ball.o Paddle.o Powerup.o: main.cpp Ball.cpp Paddle.cpp Powerup.cpp
	g++ -c Ball.cpp main.cpp Paddle.cpp Powerup.cpp

clean:
	rm *.o

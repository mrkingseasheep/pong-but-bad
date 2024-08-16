main: main.o Ball.o 
	g++ main.o Ball.o -o app -lsfml-graphics -lsfml-window -lsfml-system -lGL

main.o Ball.o: main.cpp Ball.cpp
	g++ -c Ball.cpp main.cpp

clean:
	rm *.o

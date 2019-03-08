all: hello

hello: Figure.o Triangle.o Rectangle.o Quadrate.o SMassive.o Allocator.o main.o
	g++  Figure.o Triangle.o Rectangle.o Quadrate.o SMassive.o Allocator.o main.o -lpthread -o hello
	rm -rf *.o

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Figure.o: Figure.cpp
	g++ -std=c++11 -c Figure.cpp

SMassive.o: SMassive.cpp
	g++ -std=c++11 -c SMassive.cpp

Allocator.o: Allocator.cpp
	g++ -std=c++11 -c Allocator.cpp

Triangle.o: Triangle.cpp
	g++ -std=c++11 -c Triangle.cpp

Rectangle.o: Rectangle.cpp
	g++ -std=c++11 -c Rectangle.cpp

Quadrate.o: Quadrate.cpp
	g++ -std=c++11 -c Quadrate.cpp

clean:
	rm -rf *.o hello

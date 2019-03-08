all: hello

hello: Figure.o Triangle.o Rectangle.o Quadrate.o main.o
	g++  Figure.o Triangle.o Rectangle.o Quadrate.o main.o -o hello

main.o: main.cpp
	g++ -c main.cpp

Figure.o: Figure.cpp
	g++ -c Figure.cpp

Triangle.o: Triangle.cpp
	g++ -c Triangle.cpp

Rectangle.o: Rectangle.cpp
	g++ -c Rectangle.cpp

Quadrate.o: Quadrate.cpp
	g++ -c Quadrate.cpp

clean:
	rm -rf *.o hello

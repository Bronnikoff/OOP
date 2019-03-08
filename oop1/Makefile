all: hello

hello: main.o Triangle.o Rectangle.o Quadrate.o
	g++ main.o Triangle.o Rectangle.o Quadrate.o -o hello

main.o: main.cpp
	g++ -c main.cpp

Triangle.o: Triangle.cpp
	g++ -c Triangle.cpp

Rectangle.o: Rectangle.cpp
	g++ -c Rectangle.cpp

Quadrate.o: Quadrate.cpp
	g++ -c Quadrate.cpp

clean:
	rm -rf *.o hello

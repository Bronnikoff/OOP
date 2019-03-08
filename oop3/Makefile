all: hello

hello: main.o Figure.o Triangle.o Rectangle.o Quadrate.o Massive.o
	g++ main.o Figure.o Triangle.o Rectangle.o Quadrate.o Massive.o -o hello

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

Massive.o: Massive.cpp
	g++ -c Massive.cpp

clean:
	rm -rf *.o hello

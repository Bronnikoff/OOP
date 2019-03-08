all: hello

hello: main.o Triangle.o Massive.o
	g++ main.o Triangle.o Massive.o -o hello

main.o: main.cpp
	g++ -c main.cpp

Triangle.o: Triangle.cpp
	g++ -c Triangle.cpp

Massive.o: Massive.cpp
	g++ -c Massive.cpp

clean:
	rm -rf *.o hello

all: main
main: main.o class.o
	g++ -o main main.o class.o
main.o: main.cpp
	g++ -c main.cpp
class.o: class.cpp 
	g++ -c class.cpp
clean:
	rm -f *.o

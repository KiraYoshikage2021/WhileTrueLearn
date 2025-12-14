all: PQ

PQ: main.o PQ.o
	g++ -o PQ main.o PQ.o

main.o: main.cpp PQ.h
	g++ -c main.cpp

PQ.o: PQ.cpp PQ.h
	g++ -c PQ.cpp

clean:
	rm -f *.o PQ


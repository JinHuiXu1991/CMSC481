Driver.out: Driver.o Graph.o
	g++ -ansi -Wall Graph.o Driver.o -o Driver.out

Driver.o: Driver.cpp
	g++ -ansi -Wall -c Driver.cpp

Graph.o: Graph.h Graph.cpp
	g++ -ansi -Wall -c Graph.cpp

clean:
	rm -f *.o Driver.out *~ *.gch

run:
	./Driver.out $(FILE)
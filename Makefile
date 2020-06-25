run: main.o util.o heap.o graph.o
	g++ main.o util.o heap.o graph.o -o proj2

heap.o: heap.cpp heap.h
	g++ -c heap.cpp

graph.o: graph.cpp graph.h
	g++ -c graph.cpp

util.o: util.cpp util.h
	g++ -c util.cpp

main.o: main.cpp main.h
	g++ -c main.cpp

clean:
	rm *.o proj2

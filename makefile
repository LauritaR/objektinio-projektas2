vectorprog: fun.o
	g++ -fopenmp -o vectorprog vectorprog.cpp fun.o
fun:
	g++ -c fun.cpp
clean:
	rm*.o vectorprog
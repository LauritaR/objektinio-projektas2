vectorprog: fun.o
	g++ -o vectorprog vectorprog.cpp fun.o
fun:
	g++ -c fun.cpp
clean:
	rm*.o vectorprog
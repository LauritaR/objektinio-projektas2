vectorprog: fun.o
	g++ -o3 -o vectorprog vectorprog.cpp fun.o
fun:
	g++ -c fun.cpp
clean:
	rm*.o vectorprog
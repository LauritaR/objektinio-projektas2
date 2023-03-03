vectorprog: fun.o
	g++ -o vectorprog -o3 vectorprog.cpp fun.o
fun:
	g++ -c fun.cpp
clean:
	rm*.o vectorprog
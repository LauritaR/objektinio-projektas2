
main: fun.o
	g++ -O3 -o main main.cpp fun.o

fun.o:
	g++ -O3 -c fun.cpp

mytests: 
	g++ -std=c++11  -o mytests mytests.cpp fun.cpp

clean:
	rm -f *.o main mytests

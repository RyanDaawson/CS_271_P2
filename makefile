all: test usecase

test: test_minqueue.o
	g++ -std=c++11 -Wall -g -o test test_minqueue.o

usecase: main.o
	g++ -std=c++11 -Wall -g -o usecase main.o

test_minqueue.o: test_minqueue.cpp minqueue.cpp minqueue.h
	g++ -std=c++11 -c -g -Wall test_minqueue.cpp

main.o: main.cpp usecase.cpp
	g++ -std=c++11 -c -g -Wall main.cpp
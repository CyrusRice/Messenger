all:
	g++ -std=c++11 -Wall -g -o project3 *.cpp *.h

clean:
	rm project3 *.o

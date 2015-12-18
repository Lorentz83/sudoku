CXXFLAGS = -Wall -O2

all: sudoku

sudoku: main.o sudoku.o
	$(CXX) main.o sudoku.o -o sudoku

main.o: main.cpp sudoku.h
	$(CXX) $(CXXFLAGS) -c main.cpp

sudoku.o: sudoku.cpp sudoku.h
	$(CXX) $(CXXFLAGS) -c sudoku.cpp

test: sudoku PHONY
	test/testAll.sh

PHONY:

clean:
	$(RM) *.o 

forceclean: clean
	$(RM) sudoku

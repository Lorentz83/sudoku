all:sudoku

sudoku: main.o sudoku.o
	g++ -O -Wall main.o sudoku.o -o sudoku

main.o: main.cpp
	g++ -O -Wall -c main.cpp

sudoku.o: sudoku.cpp sudoku.h
	g++ -O -Wall -c sudoku.cpp

clean:
	rm -f *.o 

forceclean: clean
	rm -f sudoku

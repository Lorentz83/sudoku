#ifndef __SUDOKU_H
#define __SUDOKU_H

#include <string>
#include <iostream>

/**
 * Describes the status of a (possibly unsolved or invalid) sudoku.
 * @author Lorenzo Bossi
 */
class sudoku {
private:
  // indexes from 1 to 9
  int f[10][10]; 

protected:
  bool checkRow(int, int) const;
  bool checkCol(int, int) const;
  bool checkSubField(int, int) const;
  
public:
  sudoku();
  sudoku(const sudoku&);
  bool isValid() const;
  bool isFull() const;
  bool setVal(int, int, int);
  bool getFirstEmpty(int*, int*) const;

  friend std::ostream& operator<<(std::ostream& o, const sudoku &s);
  friend std::istream& operator>>(std::istream& i, sudoku &s);
};

#endif

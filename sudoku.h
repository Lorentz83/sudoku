#ifndef __SUDOKU_H
#define  __SUDOKU_H

#include<string>
#include<iostream>

/**
 * @author lorenzo bossi
 * descrive lo stato di un campo di sudoku
 */



class sudoku{
private:
  // gli indici validi vanno da 1 a 9
  int f[10][10]; 
protected:
  bool checkRow(int,int) const;
  bool checkCol(int,int) const;
  bool checkSubField(int,int) const;
  
public:
  sudoku();
  sudoku(const sudoku&);
  //std::string toString() const;
  bool isValid() const;
  bool isFull() const;
  bool setVal(int,int,int);
  bool getFirstEmpty(int*, int*) const;

  friend std::ostream& operator<<(std::ostream& o,const sudoku &s);
  friend std::istream& operator>>(std::istream& i,sudoku &s);
};


#endif

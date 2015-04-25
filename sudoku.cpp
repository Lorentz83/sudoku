#include "sudoku.h"

sudoku::sudoku() {
  int i, j;
  for ( i=1 ; i<10 ; i++ )
    for ( j=1 ; j<10 ; j++ )
      f[i][j] = 0;
}

sudoku::sudoku(const sudoku& s) {
  int i, j;
  for ( i=1 ; i<10 ; i++ )
    for ( j=1 ; j<10 ; j++)
      f[i][j] = s.f[i][j];
}

bool sudoku::isValid() const {
  int i, j;
  for ( j=1 ; j<10 ; j++ )
    for ( i=1 ; i<10 ; i++ ) {
      if ( !checkRow(i, j) )
	return false;
      if ( !checkCol(i, j) )
	return false;
    } 
  for ( j=1 ; j<10 ; j+=3 )
    for ( i=1 ; i<10 ; i+=3 )
      if ( !checkSubField(i, j) )
	return false;
  return true;
}

bool sudoku::isFull() const {
  int i, j;
  return !getFirstEmpty(&i, &j);
}

bool sudoku::checkRow(int i, int j) const {
  int val[10];
  int v;
  
  //check row
  for ( v=0 ; v<10 ; v++)
    val[v] = 0;
  
  for ( v=1 ; v<10 ; v++ ) {
    if( f[v][j] > 0 && val[f[v][j]]++ > 0 ) 
      return false;
  }
  return true;
}

bool sudoku::checkCol(int i, int j) const {
  int val[10];
  int v;
  
  //check col
  for ( v=0 ; v<10 ; v++ )
    val[v] = 0;

  for ( v=1 ; v<10 ; v++ ) {
    if( f[i][v] > 0 && val[f[i][v]]++ > 0 ) 
      return false;
  }
  return true;
}

bool sudoku::checkSubField(int i, int j) const{
  int val[10];
  int v;
  
  //check subfield
  for ( v=0 ; v<10 ; v++ )
    val[v] = 0;

  int ii = (i-1)/3*3+1;
  int jj = (j-1)/3*3+1;
  int a, b;
  for ( b=0 ; b<3 ; b++ )
    for ( a=0 ; a<3 ; a++ )
      if ( f[a+ii][b+jj] > 0 && val[f[a+ii][b+jj]]++ > 0 ) 
	return false;
  return true;
}

bool sudoku::getFirstEmpty(int *i, int *j) const {
  int ii, jj;
  for ( jj=1 ; jj<10 ; jj++ )
    for ( ii=1 ; ii<10 ; ii++ )
      if ( f[ii][jj]==0 ) {
	*i=ii;
	*j=jj;
	return true;
      }
  return false;
}

bool sudoku::setVal(int i, int j, int n) {
  if ( i<1 || i>9 || j<1 || j>9 )
    return false;
  if ( n<1 || n>9 )
    return false;
  
  int oldn = f[i][j];
  f[i][j] = n;
  if ( !checkRow(i,j) ) {
    f[i][j] = oldn;
    return false;
  }
  if ( !checkCol(i,j) ) {
    f[i][j] = oldn;
    return false;
  }
  if ( !checkSubField(i,j) ){
    f[i][j] = oldn;
    return false;
  }
  return true;
}

std::ostream& operator<<(std::ostream& o, const sudoku &s) {
  int i, j;
  o << '+';
  for ( i=1 ; i<10 ; i++ )
    o << "--";
  o << "+\n";
  for ( j=1 ; j<10 ; j++ ) {
    o << '|';
    for ( i=1 ; i<10 ; i++ ) {
      if ( s.f[i][j]>0 && s.f[i][j]<10 )
	o << s.f[i][j] << ' ';
      else
	o << "  ";
    }
    o << "|\n";
  }
  o << '+';
  for ( i=1 ; i<10 ; i++ )
    o << "--";
  o << '+';
  return o;
}

std::istream& operator>>(std::istream& is, sudoku &s){
  char c;
  int i, j;
  for ( j=1 ; j<10 ; j++ ) {
    for (i=1 ; i<10 ; ){
      is >> c;
      if ( c>='0' && c<='9' ) {
	s.f[i++][j] = c-'0';
      }
    }
  }
  return is;
}

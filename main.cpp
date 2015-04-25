#include <iostream>
#include "sudoku.h"
#include <list>

using namespace std;

int main(){
  sudoku s;
  int searched = 0;
  int found = 0;
  int dropped = 0;
  
  cout<<"enter the sudoku: " << endl <<
    " use 0 to mark empty cells, everything that is not a digit is ignored" << endl <<
    " (i.e. you can freely use spaces or newlines to separate blocks)" << endl;
  cin>>s;
  
  cout << "The sudoku is:" << endl << s << endl;
  cout << "is completed? " << ( s.isFull() ? "YES" : "NO") << endl;
  cout << "is valid? " << ( s.isValid() ? "YES" : "NO" ) << endl;

  list<sudoku> list;
  
  list.push_front(s);

  while( !list.empty() ){
    sudoku tmp(list.front());
    list.pop_front();
    searched++;
    if ( tmp.isFull() ) {
      cout << "Sudoku found:" << endl << tmp << endl;
      cout << "is completed? " << ( tmp.isFull() ? "YES" : "NO" ) << endl;
      cout << "is valid? "<< ( tmp.isValid() ? "YES" : "NO" ) << endl;
      found++;
    }
    int i,j;
    if ( tmp.getFirstEmpty(&i, &j) ) {
      for ( int n=1 ; n<=9 ; n++ ) {
	sudoku t2(tmp);
	if( t2.setVal(i,j,n) )
	  list.push_front(t2);
	else
	  dropped++;
      }
    }
  }
  cout << "Analysis ended." << endl;
  cout << " sudokus analyzed " << searched << endl;
  cout << " branches discarded " << dropped << endl;
  cout << " solutions found " << found << endl;
  
  return 0;
}

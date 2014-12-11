#include <iostream>
#include "sudoku.h"
#include<list>

using namespace std;

int main(){
  sudoku s;
  int searched=0;
  int found=0;
  int dropped=0;
  
  cout<<"inserisci il sudoku: "<<endl<<
    " usa 0 per indicare le celle vuote,"<<endl<<
    " tutto ciò che non è cifra viene ignorato"<<endl;
  cin>>s;
  
  cout<<"il sudoku è:"<<endl<<s<<endl;
  cout<<"è completo? "<< (s.isFull()?"SI":"NO")<<endl;
  cout<<"è valido? "<< (s.isValid()?"SI":"NO")<<endl;

  list<sudoku> list;
  
  list.push_front(s);

  while( !list.empty() ){
    sudoku tmp(list.front());
    list.pop_front();
    searched++;
    if (tmp.isFull()){
      cout<<"il sudoku trovato è:"<<endl<<tmp<<endl;
      cout<<"è completo? "<< (tmp.isFull()?"SI":"NO")<<endl;
      cout<<"è valido? "<< (tmp.isValid()?"SI":"NO")<<endl;
      found++;
    }
    int i,j;
    if(tmp.getFirstEmpty(&i, &j))
      for (int n=1;n<=9;n++){
	sudoku t2(tmp);
	if(t2.setVal(i,j,n))
	  list.push_front(t2);
	else
	  dropped++;
      }
    
  }
  cout<<"Fine analisi."<<endl;
  cout<<"sudoku analizzati "<<searched<<endl;
  cout<<"rami di ricerca scartati "<<dropped<<endl;
  cout<<"soluzioni trovate "<<found<<endl;
    
  return 0;
}

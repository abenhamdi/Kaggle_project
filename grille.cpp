#include"grille.h"
#include"cell.h"
#include<iostream>
using namespace std;
#define CHECK_BOUND(i,j,x,y)			\
  if(i>x || j > y){ \
  cerr<<"une ou les  valeur(s) depasse(nt) la dimension de la grille"<<endl; \
  }

Grille::Grille():dimensionX(5),dimensionY(5),tab(new Cell*[5]){
    for(size_t i=0;i<5;i++){
    tab[i]=new Cell[5];
  }
}


Grille::Grille(size_t dimX,size_t dimY):dimensionX(dimX),dimensionY(dimY),tab(new Cell*[dimX]){
  for(size_t i=0;i<dimX;++i){
    tab[i]=new Cell[dimY-1];
  }
}

Grille::~Grille(){
  size_t i=0;
  while(i<dimensionX){
    delete [] tab[i];
    i++;
  }
  delete tab;
}

 size_t Grille::getDimensionX()const{return dimensionX;}

 size_t Grille::getDimensionY()const{return dimensionY;}

 Cell& Grille::getCell(size_t x,size_t y)const{
   CHECK_BOUND(x,y,dimensionX,dimensionY);
  return tab[x][y];
}

void Grille::addVal(int val, size_t x,size_t y){
  CHECK_BOUND(x,y,dimensionX,dimensionY);
  tab[x][y].setCellNum(val);
  tab[x][y].setEtat(1);
  
}
void Grille::addEtat(int etat,size_t x,size_t y){
 CHECK_BOUND(x,y,dimensionX,dimensionY);
 tab[x][y].setEtat(etat);

}

void Grille::GrillePrint(){
  /* for(size_t i=0;i<dimensionX;i++){
    cout<<" +";
    }*/
  for(size_t k=0;k<dimensionX;k++){
    cout<<endl;
    //cout<<"+";
    for(size_t j=0;j<dimensionY;j++){
      tab[k][j].print();
      // cout<<"+";
    }
   
  }
  cout<<endl;
}

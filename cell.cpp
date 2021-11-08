#include"cell.h"
#include<iostream>
using namespace std;
Cell::Cell():etat(0),cellNum(0){}
Cell::Cell(int e,int c):etat(e),cellNum(c){}

int Cell::getEtat()const{ return etat;}

int Cell::getCellNum()const{ return cellNum;}

int Cell::getPosX()const{return posX;}

int Cell::getPosY()const{return posY;}

void Cell::setPosX(int pos){posX=pos;}

void Cell::setPosY(int pos){posY=pos;}

void Cell::setEtat(int e){ etat=e;}

void Cell::setCellNum(int cNum){cellNum=cNum;}

void Cell::print(){
  switch(etat){
  case 1:
    if(cellNum){
    cout<<"\033[30;47m"<<cellNum<<"\033[0m";
    }else{
      cout<<"\033[1;47m \033[0m";
    }
    break;
  case 0:
    cout<<"\033[1;44m \033[0m";
    break;
  case 2 :
    cout<<"\033[1;30m \033[0m";
    break;
  case 3:
    cout<<"\033[1;30m \033[0m";
    break;
 
  }
}

bool Cell::conflit(){return etat==3;}
    

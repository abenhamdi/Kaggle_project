#ifndef __GRILLE_H
#define __GRILLE_H
#include"cell.h"
#include<iostream>
class Grille{
 private:
  size_t dimensionX;
  size_t dimensionY;
  Cell ** tab;

 public:
  //constructeurs
  Grille();
  Grille(size_t dX,size_t dY);
  //destructeur
  ~Grille();
  //accesseur en lecture
  size_t getDimensionX()const;
  size_t getDimensionY()const;
  Cell& getCell(size_t,size_t)const;
  
  
  //methodes
  void random_init(size_t nb_cellules_numerotee);
  void GrillePrint();
  void addVal(int val,size_t x,size_t y);
  void addEtat(int etat,size_t,size_t);
};

#endif

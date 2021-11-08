#ifndef __CELL_H
#define __CELL_H

class Cell{

 private:
  int posX;
  int posY;
  int etat;
  int cellNum;
 public:
  Cell();
  Cell(int etat,int cellNum);
  //accesseur en lecture
  int getEtat()const;
  int getCellNum()const;
  int getPosX()const;
  int getPosY()const;

  //accesseur en ecriture
  void setEtat(int);
  void setCellNum(int);
  void setPosX(int);
  void setPosY(int);
  void print();

  bool conflit();


};
#endif

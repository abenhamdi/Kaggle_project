#ifndef __BLOCKCELL_H
#define __BLOCKCELL_H
#include "cell.h"
class BlockCell{
 private:
  Cell* cellPointer;
  BlockCell* nextBlock;
 public:
  //constructeurs

  BlockCell();
  BlockCell(Cell* c);

  BlockCell* getNextBlock()const;
  Cell* getCellPointer()const;

  void setNextBlockCell(BlockCell*);
  void setCellPointer(Cell*);
  void setEtatCell(int etat);
  int getEtatCell()const;
  int getCellNum()const;
  
  void printBlock()const;
  void printBlockListe()const;

};

#endif

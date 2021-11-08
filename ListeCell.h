#ifndef __LISTECELL_H
#define __LISTECELL_H
#include "BlockCell.h"

class ListeCell{
  
 private:
  BlockCell* head;
  size_t size;
  
 public:
  ListeCell();
  ListeCell(BlockCell* _head);

  size_t  getSize()const;
  
  BlockCell* getHead()const;
  
  //Methodes
  BlockCell* getSucc(BlockCell*)const;
  void addAfter(BlockCell* bc,BlockCell* cell);
  void fusion(BlockCell* bc,BlockCell* cell);
  bool est_Vide()const;
  void printListe()const;
};

#endif

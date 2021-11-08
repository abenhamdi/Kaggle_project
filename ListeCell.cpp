#include<iostream>
using namespace std;
#include"ListeCell.h"

ListeCell::ListeCell():head(NULL),size(0){}

ListeCell::ListeCell(BlockCell* bcell):head(bcell),size(1){}

/*void ListeCell::setNextBlock(BlockCell* thisBlock,BlockCell* NextBlock){
  thisBlock->setNextBlockCell(NextBlock);
}*/

size_t ListeCell::getSize()const{ return size;}

bool ListeCell::est_Vide()const{return size==0;}

BlockCell* ListeCell::getHead()const{ return head;}

BlockCell* ListeCell::getSucc(BlockCell* bc)const{ return bc->getNextBlock();}


void ListeCell::fusion(BlockCell* bc,BlockCell* blockC){
  if(getSucc(blockC) == NULL){
    if(getSucc(bc) == NULL){
      bc->setNextBlockCell(blockC);
      size++;
    } else {
      BlockCell* tmp = bc->getNextBlock();
      bc->setNextBlockCell(blockC);
      blockC->setNextBlockCell(tmp);
      size++;
     
    }
  } else {
    int buf = 0;
    if (getSucc(bc) != NULL) {
      BlockCell* tmp = bc->getNextBlock();
      BlockCell* tmp1 = blockC->getNextBlock();
      buf++;
      while (getSucc(tmp1) != NULL){
	tmp1 = tmp1->getNextBlock();
	buf++;
      }
      tmp1->setNextBlockCell(tmp);
      bc->setNextBlockCell(blockC);
      size = size + buf;
    } else {
      BlockCell* tmp = bc;
      BlockCell* tmp1 = blockC->getNextBlock();
      buf++;
      while (getSucc(tmp1) != NULL){
	tmp1 = tmp1->getNextBlock();
	buf++;
      }
      tmp1->setNextBlockCell(tmp);
      bc->setNextBlockCell(blockC);
      size = size + buf;
    }
  }
}


void ListeCell::printListe()const{
  
  std::cout<<"La liste de cellule est : [";
  BlockCell* tmp=getHead();
  while(getSucc(tmp)){
    tmp->printBlockListe();
    std::cout<<" | ";
    tmp=getSucc(tmp);
  }
  tmp->printBlockListe();
  std::cout<<"]"<<endl;
}


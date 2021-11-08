#include"grille.h"
#include<iostream>
#include"ListeCell.h"
#include"option.h"
#include<map>
#include<cstdlib>
using namespace std;


void getDataDimension(map<string,string>& data,string key,int &value){
  const char* k =data[key].c_str();
  value = atoi(k);
}
void initGrille(map<string,string>& data){
 int dimX;
 int dimY;
 getDataDimension(data,"dimensionX",dimX);
 getDataDimension(data,"dimensionY",dimY);
 Grille g(dimX,dimY);
 g.GrillePrint();

  BlockCell cell6(&(g.getCell(0,2)));
  BlockCell cell7(&(g.getCell(1,1)));
  BlockCell cell8(&(g.getCell(1,2)));

  ListeCell L1(&cell6);
  L1.fusion(L1.getHead(),& cell7);
  L1.printListe();
  L1.fusion(L1.getHead(),& cell8);
  L1.printListe();
    
}


void MyProgram(int argc,char** argv){
  map<string,string> data;
  Option tabOption[5]={Option(Option::HELP,Option::AUCUN,"-h","L'aide de Jeu et affichage des options"),
		       Option(Option::DIMENSION,Option::AUCUN,"-d","determiner les dimensions dimension de la grille"),
		       Option(Option::CONFIG,Option::STRING,"-cfg","Configurer les cellules en passant un ficher de config"),
		       Option(Option::VERSION,Option::AUCUN,"-v","Version de programme"),
  		       Option(Option::AUTHORS,Option::AUCUN,"-a","auteurs de Programme")};
  if(argc==1){
    data.insert(std::pair<string,string>("dimensionX","5"));
    data.insert(std::pair<string,string>("dimensionY","15"));
    initGrille(data);
    data.erase(data.begin(),data.end());
  }else{
    for(int i=1;i<argc;i++){
      for(int j=0;j<5;j++){
	
	if(argv[i][0]=='-'){
	  if(argv[i] == tabOption[j].getraccourci()){
	    launchOption(tabOption,tabOption[j],i,argv,data);
	  }
	}else{
	  
	  string s = ID2String(tabOption[j].getId());
	  
	  if(argv[i] == s ){
	    launchOption(tabOption,tabOption[j],i,argv,data);
	  }
	  
	}
	
      }
      
    } 
  }
  if(!data.empty()){
    initGrille(data);    
  }
}


int main(int argc,char** argv){
  MyProgram(argc,argv);
  return 0;
}

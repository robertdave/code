#include <stdio.h>
#include <math.h>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include "grafos2_matriz.h"


int main() {

	Grafo g =  Grafo(5);
	g.ad_aresta(1,2,5);
	g.ad_aresta(1,3,4);
	g.ad_aresta(2,4,3);
	g.ad_aresta(2,5,2);
	g.ad_aresta(3,4,8);
	g.ad_aresta(4,5,4);

			
	g.imprime_lista_adj();

	g.busca_largura(1);

	Fila<int> fila; 
	Pilha<int> pilha;
	
	cout << endl;
	cout << "Test Fila: " << endl;
	try {
	      int item =10;
	  	  fila.enfileira (item);
	      cout << "Enfileirou: " << item << endl;
	      int *item1 = fila.desenfileira ();
	      int i;
		  i= *item1;
	      cout << "Desenfileirou: " << i << endl;
	} catch (logic_error e) {
	     cout << e.what () << endl;  	
	}	

	cout << endl;
	cout << "Test Pilha: " << endl;
	try {
	      int item =10;
	  	  pilha.empilha(item);
	      cout << "Empilhou: " << item << endl;
	      int *item1 = pilha.desempilha();
	      //int i;
		  //i= *item1;
	      cout << "Desempilhou: " << *item1 << endl;
	} catch (logic_error e) {
	     cout << e.what () << endl;  	
	}	
	
	
	g.busca_profundidade(1);
	cout << endl;  	

	Grafo g1 =  Grafo(6);
	g1.ad_aresta(1,2,2);
	g1.ad_aresta(1,3,1);
	g1.ad_aresta(2,4,7);
	g1.ad_aresta(3,4,5);
	g1.ad_aresta(3,6,2);
	g1.ad_aresta(4,5,10);
	g1.ad_aresta(4,6,8);
	g1.ad_aresta(5,6,2);
			
	g1.imprime_lista_adj();
	cout << endl;  	

	g1.busca_largura(1);
	cout << endl;  	
	
	g1.busca_profundidade(1);
	
	cout << endl << "caminho minimo" << endl;
	
	Caminho_grafo cg1 = g1.caminho_min_bf(2);

	for (int i = 1 ;i< g1.num_vertices()+1;i++){
		cout << "  " << i << "-" << cg1.pred[i] ;	
	}
	cout << endl;
	for (int i =1 ;i< g1.num_vertices()+1;i++){
		cout << "  " << i << "-" << cg1.shortest[i];	
	}	
	
	
}


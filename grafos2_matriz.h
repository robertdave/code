#include <stdio.h>
#include <math.h>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include "autoreferencia/Fila.h"
#include "autoreferencia/Pilha.h"
using namespace std;
using ziviani::Fila;
using ziviani::Pilha;

const int V_MAX = 100;
const int MAX_INT = 9999;


string number2str(int n){
	string r;          
	ostringstream convert;  
	convert << n;      
	r = convert.str();	
	return r;
}


class Caminho_grafo {
	private:
		int z;
	public:
		int shortest[V_MAX];
		int pred[V_MAX];
	
};

// Grafo implementado em matriz de adjacencias
class Grafo {
	// inicializa matriz com zeros
	int matriz_adj[V_MAX][V_MAX]={};

	// admite vertices numerados de 1 a N

	Fila<int> fila; 
	Pilha<int> pilha;
	int numVertices;
	
	public:
		
		Grafo(int n);

		int num_vertices();
		
		void ad_aresta(int i, int j, int d);
		
		void imprime_lista_adj();
		
		void busca_largura(int v0);
		
		void busca_profundidade(int v0);
		
		// Algoritmo Bellman-Ford para caminho minimo
		Caminho_grafo caminho_min_bf(int s);
		
		// Algoritmo Dijkstra para caminho minimo
		Caminho_grafo caminho_min_dk(int s);
	
};

	Grafo::Grafo(int n){
		numVertices = n;
		//matriz_adj = int[n][n];
	}
	
	// Adiciona aresta e vertices ao grafo. Começa com 1.
	void Grafo::ad_aresta(int i, int j, int d){
		matriz_adj[i][j] = d;
		matriz_adj[j][i] = d;
	}


	// Imprime lista de adjacentes.
	void Grafo:: imprime_lista_adj(){
		
		for(int i=1;i<=numVertices;i++){
			
			cout << "V" << i;			
			cout << " -> ";

			string adjs("");
			for(int j=1;j<=numVertices;j++){
				if(matriz_adj[i][j] != 0){
					int vadj = j;
					string sv("");
					sv = number2str(vadj);
					adjs = adjs +  sv + " , ";
				}
			}	
			cout << adjs << endl;			
			
		}	
	}
	

	//BFS
	void Grafo:: busca_largura(int v0){
		int conta =1;
		int v,w;
		int dist[V_MAX]={};			

		dist[v0]=conta++;			
		fila.enfileira(v0);

		while (!fila.vazia()){
			int *pont_v = fila.desenfileira();
			v=*pont_v;
			for(w=1;w<=numVertices;w++){
				if(matriz_adj[v][w] != 0 && dist[w]==0){
						fila.enfileira(w);	
						dist[w]=conta++;			
									
				}
			}
		}
		cout << "Busca em largura " << endl;
		for (int i =1;i< conta;i++){
			cout << " " << dist[i] ;	
		}
		 
		
	}

	void Grafo:: busca_profundidade(int v0){
		int conta =1;
		int v,w;
		int dist[V_MAX]={};			

		dist[v0]=conta++;			
		pilha.empilha(v0);

		while (!pilha.vazia()){
			int *pont_v = pilha.desempilha();
			v=*pont_v;
			if(dist[v]==0){
				dist[v]=conta++;			
			}
				
			for(w=1;w<=numVertices;w++){
				if(matriz_adj[v][w] != 0 && dist[w]==0 ){
					pilha.empilha(w);	
				}
			}
		}
		//TODO proc ordenar caminho
		cout << endl << "Busca em Profundidade " << endl;
		for (int i =1;i< conta;i++){
			cout << "  " << i << "-" << dist[i] ;	
		}
		 
		
	}

	int Grafo:: num_vertices(){
		return numVertices;
	}
	
	
	Caminho_grafo Grafo:: caminho_min_bf(int s) {
		int shortest[V_MAX];
		int pred[V_MAX];
		for(int i=1; i<= numVertices ;i++){
			shortest[i]=MAX_INT;
			pred[i]=0; // ou -1			
		}
		
		shortest[s]= 0;
		
		for(int v=1;v <= numVertices;v++){			
			for(int w=1;w <= numVertices;w++){
				if(matriz_adj[v][w] != 0){
					int d = shortest[v] + matriz_adj[v][w];
					if(shortest[w] > d){
						shortest[w] = d;
						pred[w]=v;
					}
				}
			
			}
		}

		// Criação do objeto de retorno 
		Caminho_grafo cg;
		
		for (int i = 1 ;i<= num_vertices();i++){
			cg.pred[i] = pred[i];
		}
		for (int i =1 ;i<= num_vertices();i++){
			cg.shortest[i] = shortest[i];
		}
				
		return cg;
	}

	Grafo::Caminho_grafo caminho_min_dk(int s){

		//TODO

		Caminho_grafo cg;
		
		for (int i = 1 ;i<= num_vertices();i++){
			cg.pred[i] = pred[i];
		}
		for (int i =1 ;i<= num_vertices();i++){
			cg.shortest[i] = shortest[i];
		}
				
		return cg;
		
	}

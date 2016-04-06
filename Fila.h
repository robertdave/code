// http://www2.dcc.ufmg.br/livros/algoritmos/
#ifndef FILA_H_
#define FILA_H_
#include <stdexcept> 
using std::logic_error;
#include<iostream>
using std::cout;
using std::endl;
namespace ziviani {
  // @{\it Para utilizar a classe Fila<T> o tipo de dado fornecido no}@ 
  // @{\it lugar do par\^ametro de tipo T deve possuir um construtor de}@ 
  // @{\it c\'opia e os operadores << e = sobrecarregados.}@
	template <class T> class Fila {
	private:
		class Celula {	
		friend class Fila<T>;
		private: 
		  T *item; Celula *prox;
		  Celula () { item = 0; prox = 0; }
		  ~Celula () { if (item != 0) delete item; }
		};
	  Celula *frente, *tras;
	public:
		Fila (); // @{\it Cria uma Fila vazia}@
		void enfileira (const T& x);
		T *desenfileira () throw ( logic_error );
		bool vazia () const;
		void imprime () const;
		~Fila ();
	};	
	template <class T>
	Fila<T>::Fila () { // @{\it Cria uma Fila vazia}@
	  this->frente = new Celula ();
	  this->tras = this->frente; this->frente->prox = 0;
	}	
	template <class T>	
	void Fila<T>::enfileira (const T& x) {
	  this->tras->prox = new Celula ();
	  this->tras = this->tras->prox; this->tras->item = new T (x); 
	  this->tras->prox = 0;
	}	
	template <class T>	
	T *Fila<T>::desenfileira () throw ( logic_error ) {
	  if (this->vazia ()) throw logic_error ("Erro: A fila esta vazia");
	  Celula *aux = this->frente;
	  this->frente = this->frente->prox;
	  T *item = this->frente->item;
	  this->frente->item = 0; // @{\it transfere a posse da mem\'oria}@
	  delete aux;
	  return item;
	}		
	template <class T>
	bool Fila<T>::vazia () const {
		return (this->frente == this->tras);
	}	
	template <class T>	
	void Fila<T>::imprime () const {
	  Celula *aux = this->frente->prox;
	  while (aux != 0) {
	    cout << *(aux->item) << endl; aux = aux->prox;
	  }
	}	
	template <class T>	
	Fila<T>::~Fila () {		
	  Celula *aux = this->frente;
	  while (aux != 0) {
	  	this->frente = this->frente->prox; delete aux;
	    aux = this->frente;
	  }
	}
}
#endif 

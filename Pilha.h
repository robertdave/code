#ifndef PILHA_H_
#define PILHA_H_
#include <stdexcept> 
using std::logic_error;
namespace ziviani {
  // @{\it Para utilizar a classe Pilha<T> o tipo de dado fornecido no}@
  // @{\it lugar do par\^ametro de tipo T deve possuir um construtor de}@
  // @{\it c\'opia e o operador = sobrecarregado.}@
	template <class T> class Pilha {
	private:
		class Celula {
		friend class Pilha<T>;
		private:
		  T *item;
	    Celula *prox;
		  Celula () { item = 0; prox = 0; }
		  ~Celula () { if (item != 0) delete item; }
		};
	  Celula *topo; 
	  int tam; 
	public:
		Pilha (); // @{\it Cria uma Pilha vazia}@
		void empilha (const T& x);
		T *desempilha () throw ( logic_error );
		bool vazia () const;
		int tamanho () const;
		~Pilha ();
	};		
	template <class T> Pilha<T>::Pilha () { 
	  this->topo = 0; this->tam = 0;
	}	
	template <class T> void Pilha<T>::empilha (const T& x) {
	  Celula *aux = this->topo;
	  this->topo = new Celula ();
	  this->topo->item = new T (x);
	  this->topo->prox = aux; (this->tam)++;
	}	
	template <class T>	
	T *Pilha<T>::desempilha () throw ( logic_error ) {
	  if (this->vazia ()) throw logic_error ("Erro: A pilha esta vazia");
	  Celula *aux = this->topo; T *item = this->topo->item;
	  this->topo->item = 0; // @{\it transfere a posse da mem\'oria}@
	  this->topo = this->topo->prox; (this->tam)--; delete aux;
	  return item;
	}		
	template <class T>
	bool Pilha<T>::vazia () const {
		return (this->topo == 0);
	}	
	template <class T>	
	int Pilha<T>::tamanho () const {
		return this->tam;
	}	
	template <class T>	
	Pilha<T>::~Pilha () {		
		Celula *aux = topo;
		while (aux != 0) {
			topo = topo->prox; delete aux; aux = topo;
		}
	}
}
#endif

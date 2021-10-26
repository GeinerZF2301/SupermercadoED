#ifndef	NODOCAJERA_H
#define NODOCAJERA_H
#include<sstream>
#include "Cajera.h"
#include "PilaCarrito.h"
class NodoCajera {
private:
	NodoCajera* anterior;
	Cajera* cajera;
	NodoCajera* siguiente;
	PilaCarrito* pilacarrito;
public:
	NodoCajera() {
		this->anterior = NULL;
		this->cajera = new Cajera();
		this->pilacarrito = new PilaCarrito();
		this->siguiente = NULL;
	}
	NodoCajera(PilaCarrito* pilacarrito, Cajera* cajera) {
		this->anterior = NULL;
		this->cajera = cajera;
		this->pilacarrito = pilacarrito;
		this->siguiente = NULL;
	}
	NodoCajera(Cajera* cajera) {
		this->anterior = NULL;
		this->cajera = cajera;
		this->pilacarrito = pilacarrito;
		this->siguiente = NULL;
	}
	void setAnterior(NodoCajera* nodo) {
		this->anterior = nodo;
	}
	NodoCajera* getAnterior() {
		return this->anterior;
	}
	void setSiguiente(NodoCajera* nodo) {
		this->siguiente = nodo;
	}
	NodoCajera* getSiguiente() {
		return this->siguiente;
	}
	Cajera* getCajera() {
		return this->cajera;
	}
	PilaCarrito* getPilaCarrito() {
		return this->pilacarrito;
	}
	

};
#endif
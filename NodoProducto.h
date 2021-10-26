#ifndef	NODOPRODUCTO_H
#define NODOPRODUCTO_H
#include<sstream>
#include "Producto.h"
using namespace std;
class NodoProducto {
private:
	Producto* producto;
	NodoProducto* siguiente;
public:
	//Default constructor
	NodoProducto() {
		this->producto = NULL;
		this->siguiente = NULL;
	}
	NodoProducto(Producto* producto) {
		this->producto = producto;
		this->siguiente = NULL;
	}
	void setProducto(Producto* producto) {
		this->producto = producto;
	}
	Producto* getProducto() {
		return this->producto;
	}
	void setSiguiente(NodoProducto* nodoproducto) {
		this->siguiente = nodoproducto;
	}
	//obtiene el siguiente nodo
	NodoProducto* getSiguiente() {
		return this->siguiente;
	}

};
#endif

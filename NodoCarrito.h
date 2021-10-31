#ifndef NODOCARRITO_H
#define NODOCARRITO_H
#include<sstream>
#include<iostream>
using namespace std;
#include"Producto.h"
#include"Carrito.h"
#include"ListaSimpleProductos.h"
class NodoCarrito {
private:
	NodoCarrito* siguiente;
	Carrito* carrito;
	ListaSimpleProductos* listaProductos;
public:
	NodoCarrito() {
		this->siguiente = NULL;
		this->carrito = NULL;
	}
	NodoCarrito(Carrito* carrito) {
		this->siguiente = NULL;
		this->carrito = carrito;
	}
	void setSiguiente(NodoCarrito* nodocarrito) {
		this->siguiente = nodocarrito;
	}
	NodoCarrito* getSiguiente() {
		return this->siguiente;
	}
	ListaSimpleProductos* getListaproductos() {
		return this->listaProductos;
	}
	Carrito *getCarrito() {
		return this->carrito;
	}
	
};
#endif
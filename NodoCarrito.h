#ifndef NODOCARRITO_H
#define NODOCARRITO_H
#include<sstream>
#include<iostream>
using namespace std;
#include"Producto.h"
#include"Cajera.h"
class NodoCarrito {
private:
	NodoCarrito* siguiente;
	NodoCarrito* carrito;
	Cajera* cajera;
	int idCarrito;
	double montoTotal;
public:
	NodoCarrito() {
		this->siguiente = NULL;
		this->cajera = NULL;
		this->idCarrito = 0;
		this->montoTotal = 0.00;
	}
	NodoCarrito(int idcarrito) {
		this->idCarrito = idcarrito;
		this->siguiente = NULL;
		this->cajera = NULL;
		this->montoTotal = 0.00;
	}
	double getMonto() {
		return this->montoTotal;
	}
	void setIdCarrito(int id) {
		this->idCarrito = id;
	}
	int getIdCarrito() {
		return this->idCarrito;
	}
	void setSiguiente(NodoCarrito* nodocarrito) {
		this->siguiente = nodocarrito;
	}
	NodoCarrito* getSiguiente() {
		return this->siguiente;
	}
	NodoCarrito* getCarrito(){
		return this->carrito;
	}
	double calcMontoCarrito(double precioProducto1, double precioProducto2) {
		montoTotal = precioProducto1 + precioProducto2;
		return montoTotal;
		cout << "El monto de los producto es de: " << montoTotal;
	}
};
#endif
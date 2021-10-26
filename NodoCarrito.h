#ifndef NODOCARRITO_H
#define NODOCARRITO_H
#include<sstream>
#include<iostream>
using namespace std;
#include"ListaSimpleProductos.h"
class NodoCarrito {
private:
	NodoCarrito* siguiente;
	ListaSimpleProductos* lista;
	int idCarrito;
	double montoTotal;
public:
	NodoCarrito() {
		this->siguiente = NULL;
		this->lista = NULL;
		this->idCarrito = 0;
		this->montoTotal = 0.00;
	}
	NodoCarrito(ListaSimpleProductos* lista) {
		this->lista = lista;
		this->siguiente = NULL;
		this->idCarrito = 0;
		this->montoTotal = 0.00;
	}
	void setMonto(double monto) {
		this->montoTotal = monto;
	}
	double getMonto() {
		return montoTotal;
	}
	void setIdCarrito(int id) {
		this->idCarrito = id;
	}
	double getIdCarrito() {
		return idCarrito;
	}
	void setSiguiente(NodoCarrito* nodocarrito) {
		this->siguiente = nodocarrito;
	}
	NodoCarrito* getSiguiente() {
		return siguiente;
	}
	double calcMontoCarrito(double precioProducto1, double precioProducto2) {
		montoTotal = precioProducto1 + precioProducto2;
		return montoTotal;
		cout << "El monto de los producto es de: " << montoTotal;
	}
};
#endif
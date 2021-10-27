#ifndef	CARRITO_H
#define CARRITO_H
#include<iostream>
#include<sstream>
using namespace std;
class Carrito {
private:
	int idCarrito;
	double montoTotal;
public:
	Carrito() {
		this->idCarrito = 0;
		this->montoTotal = 0.00;
	}
	Carrito(int idcarrito) {
		this->idCarrito = idcarrito;
		this->montoTotal = 0.00;
	}
	double getMonto() {
		return this->montoTotal;
	}
	void setIdCarrito(int id) {
		this->idCarrito = id;
	}
	double getIdCarrito() {
		return this->idCarrito;
	}
	string toString() {
		std::stringstream out;
		out << "\t" << "ID CARRITO: " << idCarrito << endl;
		return out.str();
	}
	double calcMontoCarrito(double precioProducto1, double precioProducto2) {
		montoTotal = precioProducto1 + precioProducto2;
		return montoTotal;
		cout << "El monto de los producto es de: " << montoTotal;
	}
};
#endif
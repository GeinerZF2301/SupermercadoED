#ifndef PRODUCTO_H
#define PRODUCTO_H
#include<sstream>
using namespace std;
class Producto {
private:
	string nombreProducto;
	double Precio;
	int id;
public:
	Producto() {
		this->nombreProducto = " ";
		this->Precio = 0.00;
		this->id = 0;
	}
	Producto(string nombreproducto, int precio, int id) {
		this->nombreProducto = nombreproducto;
		this->Precio = precio;
		this->id = id;
		
	}
	void setNombreProducto(string nombre) {
		this->nombreProducto = nombre;
	}
	string getnombreProducto() {
		return this->nombreProducto;
	}
	void setPrecio(double precio) {
		this->Precio = precio;
	}
	double getPrecio() {
		return this->Precio;
	}
	int getIdProducto() {
		return this->id;
	}
	string toString() {
		std::stringstream out;
		out << "\t" << nombreProducto << " " << Precio << endl;
		return out.str();
	}
};
#endif

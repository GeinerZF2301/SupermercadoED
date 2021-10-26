#ifndef PRODUCTO_H
#define PRODUCTO_H
#include<sstream>
using namespace std;
class Producto {
private:
	string nombreProducto;
	double Precio;
public:
	Producto() {
		nombreProducto = " ";
		Precio = 0.00;
	}
	Producto(string nombreproducto, int precio) {
		nombreProducto = nombreproducto;
		Precio = precio;
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
	string toString() {
		std::stringstream out;
		out << "\t" << nombreProducto << " " << Precio << endl;
		return out.str();
	}
};
#endif

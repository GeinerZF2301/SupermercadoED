#ifndef	CAJERA_H
#define CAJERA_H

#include<sstream>
using namespace std;
class Cajera {
private:
	string nombreCajera;
	int idCajera;
public:
	Cajera() {
		nombreCajera = " ";
		idCajera = 0;
	}
	Cajera(string nombrecajera, int idcajera) {
		nombreCajera = nombrecajera;
		idCajera = idcajera;
	}
	void setNombreCajera(string nombre) {
		this->nombreCajera = nombre;
	}
	string getnombreCajera() {
		return this->nombreCajera;
	}
	void setIdCajera(int id) {
		this->idCajera = id;
	}
	char getIdCajera() {
		return this->idCajera;
	}
	string toString() {
		std::stringstream out;
		out << "\t" << "ID: " << idCajera << " " << "NOMBRE: " << nombreCajera << endl;
		return out.str();
	}
};
#endif

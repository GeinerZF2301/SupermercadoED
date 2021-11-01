#ifndef	COLACAJERA_H
#define COLACAJERA_H
#include<sstream>
#include<iostream>

#include"Cajera.h"
#include "NodoCajera.h"
#include "ListaSimpleProductos.h"
#include "PilaCarrito.h"

using namespace std;

class ColaCajera {
private:
	int contador;
	NodoCajera* frente;
	NodoCajera* fin;
public:
	ColaCajera() {
		this->contador = 0;
		this->frente = this->fin = NULL;
	}
	bool esVacia() {
		return (this->frente == NULL && this->fin == NULL);
	}
	NodoCajera* getFrente() {
		return this->frente;
	}

	NodoCajera* getFinal() {
		return this->fin;
	}

	void poner(NodoCajera* nodocajera) {
		if (esVacia()) {
			frente = fin = nodocajera;
		}
		else {
			fin->setSiguiente(nodocajera);
			nodocajera->setAnterior(fin);
			fin = nodocajera;
		}
		contador++;
	}
	
	void quitar() {
		NodoCajera* aux;
		if (!esVacia()) {
			aux = frente;
			if (frente == fin) {
				frente = fin = NULL;
			}
			else {
				frente = frente->getSiguiente();
				frente->setAnterior(NULL);
			}
			delete(aux);
			contador--;
		}
	}
	void imprimir() {
		NodoCajera* aux;
		if (!esVacia()) {
			aux = frente;
			cout << "Frente->" << endl;
			while (aux != NULL) {
				cout << aux->getCajera()->toString() << endl;
				aux = aux->getSiguiente();
			}
			cout << "-> NULL" << endl;
		}
		else {
			cout << "La cola esta vacia" << endl;
		}
	}

	void agregarCarritoPorCajera(string NombreCajera, NodoCarrito* nodo) {
		NodoCajera* aux;
		if (!esVacia()) {
			bool existe = false;
			aux = getCabeza();
			while (aux != NULL) {
				if (aux->getCajera()->getNombre() == Nombre) {
					existe = true;
					if (this->existeCarrito(Nombre, nodoCarrito) == false) {
						aux->getPilaCarrito()->apilar(nodoCarrito);
						cout << "Carrito exitosamente asignado a esta cajera." << endl;
					}
					else {
						cout << "Este carrito ya fue asignado a esta cajera." << endl;
					}
				}
				aux = aux->getSiguiente();
			}
			if (existe == false) {
				cout << "La Cajera no existe." << endl;
			}
		}
		else {
			cout << "La lista de cajeras está vacia." << endl;
		}
	}
};
#endif
#ifndef	LISTASIMPLEPRODUCTOS_H
#define LISTASIMPLEPRODUCTOS_H
#include<sstream>
#include<iostream>
using namespace std;
#include "NodoProducto.h"
class ListaSimpleProductos {
private:
	int contador;
	NodoProducto* cabeza;
public:
	ListaSimpleProductos() {
		contador = 0;
		cabeza = NULL;
	}
	NodoProducto* getCabeza() {
		return this->cabeza;
	}
	bool esVacia() {
		return cabeza == NULL;
	}
	void insertarInicio(NodoProducto* nodoproducto) {
		if (esVacia()) {
			cabeza = nodoproducto;
		}
		else {
			nodoproducto->setSiguiente(cabeza);
			cabeza = nodoproducto;
		}
		contador++;
	}
	void insertarFinal(NodoProducto* nodoproducto) {
		NodoProducto* aux;
		if (esVacia()) {
			cabeza = nodoproducto;
		}
		else {
			aux = getCabeza();
			while (aux->getSiguiente() != NULL) {
				aux = aux->getSiguiente();
			}
			aux->setSiguiente(nodoproducto);
		}
		contador++;
	}
	void eliminarUltimo() {
		if (!esVacia()) {
			NodoProducto* aux = getCabeza();
			if (aux->getSiguiente() == NULL) {
				this->cabeza = NULL;
				delete(aux);
			}
			else {
				NodoProducto* siguiente = aux->getSiguiente();
				while (siguiente->getSiguiente() != NULL) {
					aux = siguiente;
					siguiente = siguiente->getSiguiente();
				}
				aux->setSiguiente(NULL);
				delete(siguiente);
			}
		}
	}
	void imprimir() {
		NodoProducto* aux;
		if (esVacia()) {
			cout << "La lista esta vacia" << endl;
		}
		else {
			aux = getCabeza();
			cout << "Cabeza ->" << endl;
			while (aux != NULL) {
				cout << aux->getProducto()->toString();
				aux = aux->getSiguiente();
			}
			cout << "NULL" << endl;
		}
	}




};
#endif

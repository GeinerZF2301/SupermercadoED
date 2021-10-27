#ifndef	PILACARRITO_H
#define PILACARRITO_H

#include<sstream>
#include<iostream>
using namespace std;
#include"NodoCarrito.h"
#include"Producto.h"
#include"NodoProducto.h"
class PilaCarrito {
private:
	int contador;
	NodoCarrito* cabeza;
public:
	PilaCarrito() {
		this->contador = 0;
		this->cabeza = NULL;
	}
	int getContador() {
		return this->contador;
	}
	NodoCarrito* getCabeza() {
		return this->cabeza;
	}
	bool esVacia() {
		return cabeza == NULL;
	}
	void apilar(NodoCarrito* nodo) {
		if (esVacia()) {
			cabeza = nodo;
		}
		else {
			nodo->setSiguiente(cabeza);
			cabeza = nodo;
		}
		contador++;
	}
	void desapilar() {
		NodoCarrito* aux;
		if (!esVacia()) {
			aux = cabeza;
			cabeza = cabeza->getSiguiente();
			delete aux;
			contador--;
		}
	}
	void vaciar() {
		while (!esVacia()) {
			desapilar();
		}
	}
	void imprimirTodosCarritos() {
		NodoCarrito* aux;
		if (!esVacia()) {
			cout << "Cabeza->";
			aux = cabeza;
			while (aux != NULL) {
				cout << aux->getCarrito()->toString();
				aux = aux->getSiguiente();
			}
			cout << "NULL" << endl;
		}
		else {
			cout << "La pila de carritos esta vacia" << endl;
		}
	}
	
	/*bool buscarCarrito(int id) {
		NodoCarrito* aux;
		if (!esVacia()) {
			aux = getCabeza();
			while (aux != NULL && aux->getSiguiente()->getIdCarrito() != id) {
				aux = aux->getSiguiente();
			}
			if (aux != NULL) {		//Si existe el carrito en la pila
				cout << "Carrito Encontrado!: " << endl;
				return true;
			}
		}
		return false;
	}*/
	void imprimirProductosCarrito() {
		NodoCarrito* aux;
		Producto* aux1;
		if (!esVacia()) {
			cout << "Cabeza->";
			aux = cabeza;
			while (aux != NULL) {
				cout << aux->getSiguiente()<< "->";
				cout << aux1->toString();
				
				aux = aux->getSiguiente();
			}
			if (aux == NULL) {
				cout << "El carrito no fue encontrado!" << endl;
			}
		}
	}

	/*void agregarProductos(int id, NodoProducto* nodo) { //
		NodoProducto* aux;
		if (!esVacia()) {
			aux = getCabeza();
			while (aux != NULL && aux->getProducto()->getIdProducto() != id) {
				aux = aux->getSiguiente();
			}
			if (aux != NULL) { //Si existe
				aux->getListaMedicamento()->insertarFinal(nodo);
				cout << "Medicamento agregado a " << aux->getPaciente()->getNombre() << endl;
			}
			else {
				cout << "Paciente no encontrado " << id << endl;
			}
		}
	}
	*/

};
#endif


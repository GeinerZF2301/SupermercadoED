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
	
	NodoCarrito* buscarCarrito(int id) {
		NodoCarrito* aux, *nodo = NULL;
		if (!esVacia()) {
			aux = getCabeza();
			bool existe = false;
			while (aux != NULL) {
				if (aux->getCarrito()->getIdCarrito() == id) {
					nodo = aux;
				}
				aux = aux->getSiguiente();
			}
		}
		return nodo;
	}


	void imprimirCarritosconProducto() {
		NodoCarrito* aux;
		bool tieneProductos = false;
		if (!esVacia()) {
			aux = getCabeza();
			cout << endl << "PILA DE CARRITOS CON PRODUCTOS" << endl;
			while (aux != NULL) {
				if (aux->getListaproductos()->getContador() != 0) {
					cout << endl << "\tCarrito " << aux->getCarrito()->getIdCarrito() << endl << endl;
					aux->getListaproductos()->imprimir();
					tieneProductos = true;
				}
				aux = aux->getSiguiente();
			}
			if (tieneProductos == false) {
				cout << "No hay carritos con Productos." << endl;
			}

		}
	}
	
	//Metodo para verificar si existe un carrito antes de agregarlo
	bool existeCarrito(int idCarrito,NodoProducto* nodoproducto) {
		NodoCarrito* aux;
		if (!esVacia()) {
			string nombreproducto = nodoproducto->getProducto()->getnombreProducto();
			aux = getCabeza();
			while (aux != NULL) {
				if (aux->getCarrito()->getIdCarrito() == idCarrito) {

					if (aux->getListaproductos()->buscarProducto(nombreproducto) != NULL) {
						return true;
					}
				}
				aux = aux->getSiguiente();
			}
		}
	}
	void agregarProductosCarrito(int id, NodoProducto* nodoproducto) {
		NodoCarrito* aux;
		if (!esVacia()) {
			bool existe = false;
			aux = getCabeza();
			while (aux != NULL) {
				if (aux->getCarrito()->getIdCarrito() == id) {
					existe = true;
					if (this->existeCarrito(id, nodoproducto) == false) {
						aux->getListaproductos()->insertarInicio(nodoproducto);
						cout << "Producto agregado exitosamente! " << endl;
					}else {
						cout << "Este producto ya fue agregado anteriormente a este carrito " << id << endl;
					}
				}
				
			}
		if(existe==false) {
			cout << "El carrito al que desea agregar los productos no existe" << endl;
		}
		
		}else {
			cout << "Pila de carrito vacia" << endl;
		}
	}
	
}
#endif


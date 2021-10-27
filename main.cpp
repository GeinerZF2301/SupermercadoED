#include<iostream>
#include<cstdlib>
using namespace std;
#include "Producto.h"
#include "Cajera.h"
#include "NodoProducto.h"	/*añadimos las clases necesarias al main para su debida implementación*/
#include "ListaSimpleProductos.h"
#include "NodoCarrito.h"
#include "PilaCarrito.h"
#include"NodoCajera.h"
#include"ColaCajera.h"

int main(int argc, char* argv[]) {
	setlocale(LC_CTYPE, "Spanish");
	Cajera* cajera;
	Producto* producto;
	NodoCajera* nodocajera;
	NodoProducto* nodoproducto;
	NodoCarrito* nodocarrito;
	Carrito* carrito;
	ColaCajera* cola = new ColaCajera();
	PilaCarrito* pila = new PilaCarrito();
	ListaSimpleProductos* lista = new ListaSimpleProductos();

	string nombreCajera, nombreProducto;
	int id, idCarrito, opcSwitch = 0, opcDow = 0;
	double precioProducto;
	do {
		system("color F0");
		system("cls");
		cout << "\t\tMENU" << endl
			<< "=========================================" << endl
			<< "1.Registrar una cajera" << endl
			<< "2.Imprimir una lista de cajeras" << endl
			<< "3.Registrar un carrito" << endl
			<< "4.Imprimir una lista de carritos" << endl
			<< "5.Registrar un nuevo producto" << endl
			<< "6.Registrar un producto a un carrito" << endl
			<< "7.Imprimir carritos con productos asignados" << endl
			<< "0. Salir" << endl
			<< "=========================================" << endl
			<< "Elija?: ";
		cin >> opcSwitch;
		/*Cada caso del switch corresponde a las respectivas gestiones que se requiere segun el proyecto*/

		switch (opcSwitch) {
		case 1:
			system("cls");
			cout << "======================== Registro de cajeras ========================" << endl
				<< "\nDigite el nombre de la cajera a registrar" << endl;
			cin >> nombreCajera;
			cout << "Digite el id de la cajera" << endl;
			cin >> id;
			cajera = new Cajera(nombreCajera, id);
			nodocajera = new NodoCajera(cajera);
			cola->poner(nodocajera);
			break;
		case 2:
			system("cls");
			cola->imprimir();
			break;
		case 3:
			system("cls");
			cout << "======================== Registro de carritos========================" << endl
				<< "\nDigite el id del carrito a registrar" << endl;
			cin >> id;
			nodocarrito = new NodoCarrito();
			carrito = new Carrito();
			carrito->setIdCarrito(id);
			nodocarrito = new NodoCarrito(carrito);
			pila->apilar(nodocarrito);
			break;

		case 4:
			system("cls");
			nodocarrito = new NodoCarrito();
			nodocarrito->setSiguiente(nodocarrito);
			pila->imprimirTodosCarritos();
			break;
		case 5:
			system("cls");
			cout << "=====================Registro de productos ====================" << endl;
			cout << "Ingrese el nombre del producto que desea guardar: " << endl;
			cin >> nombreProducto;
				nodoproducto = lista->buscarProducto(nombreProducto);
			if (nodoproducto != NULL) {
				cout << "Ya existe un producto con ese nombre. " << endl;
			}
			else {
				cout << "Ingrese el precio del producto que desea guardar: " << endl;
				cin >> precioProducto;
				producto = new Producto();
				producto->setNombreProducto(nombreProducto);
				producto->setPrecio(precioProducto);
				lista->insertarInicio(new NodoProducto(producto));
				lista->imprimir();
			}
			system("pause");
			break;
		case 6:
			
			system("cls");
			cout << "Ingrese el id del carrito al que desea añadir productos: " << endl;
			cin >> idCarrito;
			cout << "Ingrese el nombre del producto que desea asignar: " << endl;
			cin >> nombreProducto;
			nodoproducto = lista->buscarProducto(nombreProducto);
			if (nodoproducto == NULL) {
				cout << "El producto que desea ingresar no existe!: " << endl;
				system("pause");
				break;
			}
			nodocarrito = pila->buscarCarrito(idCarrito);
			pila->agregarProductosCarrito(idCarrito, nodoproducto);
			break;

		case 7:
			system("cls");
			pila->imprimirCarritosconProducto();
		}
		cout << "\n\t\t\t\t\tDigite 0 para salir" << endl;
		cin >> opcDow;
	} while (opcDow != 0);
	return 0;
};

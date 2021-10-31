#include<iostream>
#include<cstdlib>
#include<conio.h>
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
		
		cout<< "\t\t\t----------------------------------------------------------------" << endl
			<< "\t\t\t                Sistema de Supermercados" << endl
			<< "\t\t\t----------------------------------------------------------------" << endl
			<< "\t\t\t                      Desarrolladores:                        " << endl
			<< "\t\t\tGeiner Zuñiga - Melany Lawson - Kriscia Campos - Maria del Mar Acón " << endl
			<< "\t\t\t----------------------------------------------------------------" << endl
			<< "\n\t\t\tMenú de opciones" << endl
			<< "\n\t\t\t1) Registrar una cajera" << endl
			<< "\t\t\t2) Imprimir una lista de cajeras" << endl
			<< "\t\t\t3) Registrar un carrito" << endl
			<< "\t\t\t4) Imprimir una lista de carritos" << endl
			<< "\t\t\t5) Registrar un nuevo producto" << endl
			<< "\t\t\t6) Registrar un producto a un carrito" << endl
			<< "\t\t\t7) Imprimir lista de Cajeras,Carritos y sus productos" << endl
			<< "\t\t\t8) Imprimir carritos con productos asignados" << endl
			<< "\t\t\t0) Salir" << endl
			<< "\t\t\t---------------------------------------------------------" << endl
			<< "\t\t\t           Digite la opción que desea : ";
		cin >> opcSwitch;
		/*Cada caso del switch corresponde a las respectivas gestiones que se requiere segun el proyecto*/

		switch (opcSwitch) {
		case 1:
			system("cls");
			cout << "------------------------------------------------- " << endl
				<< "                Registro de Cajeras:  " << endl
				 << "------------------------------------------------- " << endl
				 << "\nDigite el nombre de la cajera a registrar" << endl;
			cin >> nombreCajera;
			cout << "\nDigite el id de la cajera" << endl;
			cin >> id;
			cajera = new Cajera(nombreCajera, id);
			nodocajera = new NodoCajera(cajera);
			cola->poner(nodocajera);
			cout << "\n\nCajera ["<<nombreCajera<<"] agregada correctamente! " << endl;
			break;
		case 2:
			system("cls");
			cout << "------------------------------------------------- " << endl
				<< "                Lista de Cajeras:  " << endl
				<< "------------------------------------------------- " << endl;
			cola->imprimir();
			system("pause");
			
			break;
		case 3:
			system("cls");
			cout << "------------------------------------------------- " << endl
				<< "           Registro de Carritos:  " << endl
				<< "------------------------------------------------- " << endl
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
			cout << "------------------------------------------------- " << endl
				<< "                Lista de Carritos:  " << endl
				<< "------------------------------------------------- " << endl;
			nodocarrito = new NodoCarrito();
			nodocarrito->setSiguiente(nodocarrito);
			pila->imprimirTodosCarritos();
			break;
		case 5:
			system("cls");
			cout << "------------------------------------------------- " << endl
				<< "           Registro de Productos:  " << endl
				<< "------------------------------------------------- " << endl
				<< "Ingrese el nombre del producto que desea guardar: " << endl;
			cin >> nombreProducto;
			//nodoproducto = lista->buscarProducto(nombreProducto);
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
			cout << "------------------------------------------------- " << endl
				<< "           Registro de Productos a un Carrito:  " << endl
				<< "------------------------------------------------- " << endl;
			cout << "Ingrese el id del carrito al que desea añadir productos: " << endl;
			cin >> idCarrito;
			cout << "Ingrese el nombre del producto que desea asignar: " << endl;
			cin >> nombreProducto;
			nodoproducto = lista->buscarProducto(nombreProducto);
			if (nodoproducto != NULL) {
				cout << "El producto que desea ingresar no está disponible en el supermercado!: " << endl;
				break;
			}else {
				if( nodoproducto = pila->buscarCarrito(idCarrito))
				pila->agregarProductosCarrito(idCarrito, nodoproducto);
			}
			break;

		case 7:
			system("cls");
			cout << "------------------------------------------------ " << endl
				<< "                    Supermercado                  " << endl
				<< "------------------------------------------------- " << endl;
			nodocarrito = new NodoCarrito();
			nodocajera = new NodoCajera();
			nodoproducto = new NodoProducto();
			nodocarrito->setSiguiente(nodocarrito);
			nodocajera->setSiguiente(nodocajera);
			nodoproducto->setSiguiente(nodoproducto);
		
			cout << "\t\t\tLISTA DE CAJERAS" << endl;
			cout << "------------------------------------------------" << endl;
			 cola->imprimir(); 
			cout << "\t\t\tLISTA DE CARRITOS" << endl;
			cout << "------------------------------------------------" << endl;
			 pila->imprimirTodosCarritos();
			cout << "\t\t\tLISTA DE PRODUCTOS" << endl;
			cout << "------------------------------------------------" << endl;
			lista->imprimir();

			break;
		case 8:
			system("cls");
			pila->imprimirCarritosconProducto();
		}
		cout << "\n\t\t\t\t\tDigite 0 para salir" << endl;
		cin >> opcDow;
	} while (opcDow != 0);
	return 0;
};

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
	Cajera* cajera;
	Producto* producto;
	NodoCajera* nodocajera;
	NodoProducto* nodoproducto;
	NodoCarrito* nodoCarrito;
	ColaCajera* cola = new ColaCajera();
	PilaCarrito* pila = new PilaCarrito();
	ListaSimpleProductos* lista = new ListaSimpleProductos();
	string nombre;
	int id, opcSwitch = 0, opcDow = 0;

	do {
		system("color F0");
		system("cls");
		cout << "\t\tMENU" << endl
			<< "=========================================" << endl
			<< "1.Registrar una cajera" << endl
			<< "2.Imprimir una lista de cajeras" << endl
			<< "3. Mostrar una Orden" << endl
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
			cin >> nombre;
			cout << "Digite el id de la cajera" << endl;
			cin >> id;
			cajera = new Cajera();
			cajera->setNombreCajera(nombre);
			cajera->setIdCajera(id);
			nodocajera = new NodoCajera(cajera);
			cola->poner(nodocajera);
			break;
		case 2:
			system("cls");
			cola->imprimir();
			break;
		case 3:

			break;
		case 4:
			break;

		case 5:
			break;
		}
		cout << "\n\t\t\t\t\tDigite 0 para salir" << endl;
		cin >> opcDow;
	} while (opcDow != 0);
	return 0;
};

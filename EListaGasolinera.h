#include <string>
#include "Mensajes.h"
#include "EGasolinera.h"
#include "EDListaEnlazada.h"

//-------------ENTIDAD-LISTA-GASOLINERA---------------------------
class ListaGasolinera {
	Lista<Gasolinera> gasolineras;
	ofstream archivo;
public:
	//----------------FUNCIÓN-LISTA-GASOLINERA--------------------
	ListaGasolinera() {
		archivo.open("texto.txt");
	}

	//------------------FUNCIÓN-INSERCIÓN--------------------------
	void insercion() {
		string distrito, nombre;
		float monto90 = 0, monto95 = 0, montoglp = 0, montognv = 0;
		int opcion = 0;
		do { menu_incial(); cin >> opcion; } while (opcion != 1);
		cout << endl << "Consideraciones: ";
		cout << endl << "Si el nombre del distrito o el local tiene mas de dos palabras,";
		cout << endl << "usar guion (-) en vez de espacio ( ). Muchas gracias!" << endl;
		cout << endl << "Ingrese el distrito de la gasolinera: ";
		cin >> distrito;
		cout << endl << "Ingrese el nombre de la gasolinera: ";
		cin >> nombre;
		cout << endl << "Ingrese monto del gasohol 90: ";
		cin >> monto90;
		cout << endl << "Ingrese monto del gasohol 95: ";
		cin >> monto95;
		cout << endl << "Ingrese monto del GLP: ";
		cin >> montoglp;
		cout << endl << "Ingrese monto del GNV: ";
		cin >> montognv;
		gasolineras.insertarInicio(Gasolinera(distrito, nombre, monto90, monto95, montoglp, montognv));
		archivo << distrito << " | " << nombre << " | Gasohol 90 = " << monto90 << " | Gasohol 95 = " << monto95 << " | GLP = " << montoglp << " | GNV = " << montognv << endl;


		cout << endl << "¿Desea hacer otra operacion?";
		cout << endl << "1. Si";
		cout << endl << "2. No";
		cout << endl << "Ingrese su respuesta: "; cin >> opcion;
		if (opcion == 1) { insercion(); }
		else { system("cls"); archivo.close(); }

	}

	//------------------FUNCIÓN-LISTAR-(LAMBDA)--------------------
	void listar() {
		gasolineras.mostrar([](Gasolinera g) {cout << g.toString() << endl; });
	}

};
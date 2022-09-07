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
		string distrito, nombre;												//2
		float monto90 = 0, monto95 = 0, montoglp = 0, montognv = 0;				//8
		int opcion = 0;															//2
		do { menu_incial(); cin >> opcion; } while (opcion != 1);				//5
		cout << endl << "Consideraciones: ";									//2
		cout << endl << "Si el nombre del distrito o el local tiene mas de dos palabras,";		//2
		cout << endl << "usar guion (-) en vez de espacio ( ). Muchas gracias!" << endl;		//3
		cout << endl << "Ingrese el distrito de la gasolinera: ";				//2
		cin >> distrito;														//1
		cout << endl << "Ingrese el nombre de la gasolinera: ";					//2
		cin >> nombre;															//1
		cout << endl << "Ingrese monto del gasohol 90: ";						//2
		cin >> monto90;															//1
		cout << endl << "Ingrese monto del gasohol 95: ";						//2
		cin >> monto95;															//1
		cout << endl << "Ingrese monto del GLP: ";								//2
		cin >> montoglp;														//1
		cout << endl << "Ingrese monto del GNV: ";								//2
		cin >> montognv;														//1
		gasolineras.insertarInicio(Gasolinera(distrito, nombre, monto90, monto95, montoglp, montognv));		//2
		archivo << distrito << " | " << nombre << " | Gasohol 90 = " << monto90 << " | Gasohol 95 = " 
			<< monto95 << " | GLP = " << montoglp << " | GNV = " << montognv << endl;						//6

		cout << endl << "¿Desea hacer otra operacion?";							//2
		cout << endl << "1. Si";												//2
		cout << endl << "2. No";												//2
		cout << endl << "Ingrese su respuesta: ";								//2 
		cin >> opcion;															//1
		if (opcion == 1) {														//3
			insercion(); 
		}										
		else { 
			system("cls"); 
			archivo.close(); 
		}
	}
	//Función Detallada=62
	//Tiempo Asintótica=1

	//------------------FUNCIÓN-LISTAR-(LAMBDA)--------------------
	void listar() {
		gasolineras.mostrar([](Gasolinera g) {cout << g.toString() << endl; });
	}

	//--------------FUNCIÓN-ORDENAR-POR-VALOR------------------
	/*
	Generico buscar(Generico v) {//2+n(3+1)+2 = 4n+4 -> o(n)
		Nodo<Generico>* aux = inicio; //2
		while (aux != nullptr) {//n
			if (aux->valor == v) {//3
				return aux->valor;//1
			}
			aux = aux->sig;//2
		}
		return v;
	}
	void sortP(function<bool(Generico, Generico)> OrdenaP) { //5+n(n+11) = n^2+ 11n + 5 -> o(n^2)
		Nodo<Generico>* aux = inicio; //2
		Nodo<Generico>* aux1 = nullptr; //2
		Nodo<Generico>* temp; //1

		for (size_t i = 1; i <= cantidad - 1; i++) { //n
			for (size_t i = 1; i <= cantidad - 1; i++) { //n
				if (OrdenaP(valor, valor)) { //2
					temp = aux->valor;//3
					aux->valor = aux1->valor;//3
					aux1->valor = temp;//3
				}
			}
		}
	}
	*/
};
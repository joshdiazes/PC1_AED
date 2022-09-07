#include <iostream>
#include <functional>
#include <fstream>
#include <cstdlib>//srand
#include <ctime>//time
#include <cstdio>//printf
using namespace std;

//-------------------------CLASE-NODO----------------------------------
template<class Generico>
class Nodo {
public:
	Generico valor;
	Nodo<Generico>* anterior;
	Nodo<Generico>* siguiente;
	Nodo(Generico v) {
		valor = v;
		anterior = siguiente = nullptr;
	}
};

//-------------------------CLASE-LISTA----------------------------------
template<class Generico>
class Lista {
private:
	Nodo<Generico>* inicio;
	size_t cantidad;
public:
	//--------------------FUNCI�N-LISTA---------------------------------
	Lista() { inicio = nullptr; }

	//--------------------FUNCI�N-~LISTA--------------------------------
	~Lista() {
		Nodo<Generico>* temp;
		while (inicio != nullptr) {
			temp = inicio;
			inicio = inicio->siguiente;
			delete temp;
			temp = NULL;
		}
		delete inicio;
		inicio = nullptr;
	}

	//--------------------FUNCI�N-SIZE----------------------------------
	int size() { return cantidad; }

	//--------------------FUNCI�N-INSERTAR-INICIO-----------------------
	void insertarInicio(Generico v) {
		Nodo<Generico>* nodo = new Nodo<Generico>(v);

		if (inicio == nullptr)
			inicio = nodo;
		else {
			inicio->anterior = nodo;
			nodo->siguiente = inicio;
		}
		inicio = nodo;
		nodo = nullptr;
		cantidad++;
	}

	//---------------------FUNCI�N-INSERTAR-FINAL-------------------------
	void insertarFinal(Generico v) {
		Nodo<Generico>* nodo = new Nodo<Generico>(v);

		if (inicio == nullptr)
			inicio = nodo;
		else {
			Nodo<Generico>* nodo = inicio;
			for (size_t i = 1; i < cantidad; i++) {
				nodo = nodo->siguiente;
			}
			nodo->anterior = nodo;
		}
		inicio = nodo;
		nodo = nullptr;
		cantidad++;
	}

	//------------------------FUNCI�N-MOSTRAR-------------------------------
	void mostrar(function<void(Generico)> imprime) {
		Nodo<Generico>* nodo = inicio;
		while (nodo != nullptr) {
			imprime(nodo->valor);
			nodo = nodo->siguiente;
		}
	}
};

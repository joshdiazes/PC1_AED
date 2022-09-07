#include "EListaGasolinera.h"

class Controladora {
	ListaGasolinera* registros;
public:
	Controladora() {
		registros = new ListaGasolinera();
	}

	void run() {
		registros->insercion();
		registros->listar();
	}
};
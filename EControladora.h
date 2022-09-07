#include "EListaGasolinera.h"

//-----------CLASE-CONTROLADORA-----------------
class Controladora {
	ListaGasolinera* registros;
public:
	//-----------FUNCIÓN-CONTROLADORA-------------
	Controladora() {
		registros = new ListaGasolinera();
	}

	//---------FUNCIÓN-RUN-----------------------
	void run() {
		registros->insercion();		//2
		registros->listar();		//2
	}
	//Función Detallada=4
	//Tiempo Asintótico=1
};
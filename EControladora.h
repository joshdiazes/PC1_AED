#include "EListaGasolinera.h"

//-----------CLASE-CONTROLADORA-----------------
class Controladora {
	ListaGasolinera* registros;
public:
	//-----------FUNCI�N-CONTROLADORA-------------
	Controladora() {
		registros = new ListaGasolinera();
	}

	//---------FUNCI�N-RUN-----------------------
	void run() {
		registros->insercion();		//2
		registros->listar();		//2
	}
	//Funci�n Detallada=4
	//Tiempo Asint�tico=1
};
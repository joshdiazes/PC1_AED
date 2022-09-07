#include <string>
using namespace std;

//--------------ENTIDAD-GASOLINERA------------------
class Gasolinera {
public:
	string distrito;
	string nombre;
	float noventa;
	float noventaycinco;
	float glp;
	float gnv;
	
	Gasolinera(string distrito = "", string nombre = "", float noventa = 0, float noventaycinco = 0, float glp = 0, float gnv = 0) :
		distrito(distrito), nombre(nombre), noventa(noventa), noventaycinco(noventaycinco), glp(glp), gnv(gnv) {}
	string toString() { return nombre + " | Gasohol 90 = " + to_string(noventa) + " | Gasohol 95 = " 
		+ to_string(noventaycinco) + " | GLP = " + to_string(glp) + " | GNV = " + to_string(gnv); }
	
	/*
	->para imprimir por tipo de combustible ¿?
	string toString_90() { return nombre + " | Gasohol 90 = " + to_string(noventa); }
	string toString_95() { return nombre + " | Gasohol 95 = " + to_string(noventaycinco); }
	string toString_glp() { return nombre + " | GLP = " + to_string(glp); }
	string toString_gnv() { return nombre + " | GNV = " + to_string(gnv); }
	*/
};
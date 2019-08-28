#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Alumno;
class Maestro; 

#ifndef CLASE_CPP
#define CLASE_CPP

#include "Alumno.cpp"
#include "Maestro.cpp"

class Clase{
	protected:
		string id, nombre;
		//string hora;
		int uv, semestre, periodo, anio;
		double not_total;
		
	public:
		
};

#endif

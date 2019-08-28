#include <iostream>
#include <string>
#include "Persona.cpp"
#include "Usuario.cpp"
#include <vector>
using namespace std;
class Clase;

#ifndef ALUMNO_CPP
#define ALUMNO_CPP

#include "Clase.cpp"

class Alumno{
	protected:
		string carrera;
		vector <Clase*> pasadas;
		vector <Clase*> cursar;
		
	public:
		
};

#endif

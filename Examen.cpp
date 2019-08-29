#include <iostream>
#include <string>
#include <vector>
#include "Pregunta.cpp"
using namespace std;
class Clase;

#ifndef EXAMEN_CPP
#define EXAMEN_CPP

#include "Clase.cpp"

class Examen{
	protected:
		Clase* clase;
		string fecha;
		string hora;
		//int duracion;
		vector <Pregunta*> preguntas;
		double valor;
		
	public:
		Examen(){}

		Examen(Clase* clase,string fecha, string hora, double valor){
			this->clase=clase;
			this->fecha=fecha;
			this->hora=hora;
			this->valor=valor;
		}



		
};

#endif

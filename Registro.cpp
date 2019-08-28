#include <iostream>
#include <string>
#include "Persona.cpp"
#include "Usuario.cpp"
#include <vector>
using namespace std;

#ifndef REGISTRO_CPP
#define REGISTRO_CPP

class Registro : public Usuario, public Persona{
	protected:
		Persona* p;
		
	public:
		Registro():Usuario(), Persona(){}

		void printRegistro(){
			cout<<"Registro"<<endl;
			p->printPersona();
		}

		~Registro(){}
		
};

#endif

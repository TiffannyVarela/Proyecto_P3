#include <iostream>
#include <string>
using namespace std;

#ifndef PERSONA_CPP
#define PERSONA_CPP

class Persona{
	protected:
		string id, nombre, rol;
		
	public:
		Persona(){}

		Persona(string id, string nombre, string rol){
			this->id=id;
			this->nombre=nombre;
			this->rol=rol;
		}

		string getId(){
			return this->id;
		}

		void setId(string id){
			this->id=id;
		}

		string getNombre(){
			return this->nombre;
		}

		void setNombre(string nombre){
			this->nombre=nombre;
		}

		string getRol(){
			return this->rol;
		}

		void setRol(string rol){
			this->rol=rol;
		}

		void printPersona(){
			cout<<"ID: "<<id<<endl;
			cout<<"Nombre: "<<nombre<<endl;
			cout<<"Rol: "<<rol<<endl;
		}

		~Persona(){}
		
};

#endif

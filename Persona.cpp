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

		Persona(string id, nombre, rol){
			this->id=id;
			this->nombre=nombre;
			this->rol=rol;
		}

		void getId(){
			return this->id;
		}

		string setId(string id){
			this->id=id;
		}

		void getNombre(){
			return this->nombre;
		}

		string setNombre(string nombre){
			this->nombre=nombre;
		}

		void getRol(){
			return this->rol;
		}

		string setRol(string rol){
			this->rol=rol;
		}

		void printPersona(){
			cout<<"ID: "<<id<<endl;
			cout<"Nombre: "<<nombre<<endl;
			cout<<"Rol: "<<rol<<endl;
		}

		~Persona(){}
		
};

#endif

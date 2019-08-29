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
		
	public:
		Registro(string user, string pass, string id, string nombre, string rol):Usuario(user,pass), Persona(id,nombre,rol){}

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

		string getUser(){
			return this->user;
		}

		void setUser(string user){
			this->user=user;
		}

		string getPass(){
			return this->pass;
		}

		void setPass(string pass){
			this->pass=pass;
		}


		void printRegistro(){
			cout<<"Registro"<<endl;
			Persona::printPersona();
		}

		~Registro(){}
		
};

#endif

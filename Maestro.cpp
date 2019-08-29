#include <iostream>
#include <string>
#include "Persona.cpp"
#include "Usuario.cpp"
#include <vector>
using namespace std;
class Clase;

#ifndef MAESTRO_CPP
#define MAESTRO_CPP

#include "Clase.cpp"

class Maestro : public Usuario, public Persona{
	protected:
		string profesion;
		double sueldo;
		vector <Clase*> asignadas;
		
	public:
		
		Maestro(string profesion, double sueldo, string user, string pass, string id, string nombre, string rol):Usuario(user,pass), Persona(id,nombre,rol){
			this->profesion=profesion;
			this->sueldo=sueldo;
		}
		
		vector <Clase*> getAsignadas(){
			return this->asignadas;
		}
		
		void setAsignadas(vector <Clase*> asignadas){
			this->asignadas = asignadas;
		}
		
		void setAsigna(Clase* cur){
			asignadas.push_back(cur);
		}
		
		void remAsignada(int p){
			asignadas.erase(asignadas.begin()+p);
		}

		string getProfesion(){
			return this->profesion;
		}

		void setProfesion(string profesion){
			this->profesion=profesion;
		}
		
		
		double getSueldo(){
			return this->sueldo;
		}

		void setSueldo(double sueldo){
			this->sueldo=sueldo;
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
		
		void printMaestro(){
			Persona::printPersona();
		}
};

#endif

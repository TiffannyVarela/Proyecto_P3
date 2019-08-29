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

class Alumno : public Usuario, public Persona{
	protected:
		string carrera;
		vector <Clase*> pasadas;
		vector <Clase*> cursar;
		
	public:
		Alumno(string carrera, string user, string pass, string id, string nombre, string rol):Usuario(user,pass), Persona(id,nombre,rol){
			this->carrera=carrera;
			rol = "Alumno";
		}
		
		string getCarrera(){
			return this->carrera;
		}

		void setCarrera(string carrera){
			this->carrera=carrera;
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
		
		vector <Clase*> getPasadas(){
			return this->pasadas;
		}
		
		void setPasadas(vector <Clase*> pasadas){
			this->pasadas=pasadas;
		}
		
		void setPasada(Clase* pas){
			pasadas.push_back(pas);
		}
		
		void remPasada(int p){
			pasadas.erase(pasadas.begin()+p);
		}
		
		vector <Clase*> getCursar(){
			return this->cursar;
		}
		
		void setCursadas(vector <Clase*> cursar){
			this->cursar=cursar;
		}
		
		void setCursa(Clase* cur){
			cursar.push_back(cur);
		}
		
		void remCursada(int p){
			cursar.erase(cursar.begin()+p);
		}


		void printAlumno(){
			Persona::printPersona();
		}
		
		void printAlumReg(){
			Usuario::printUsuario();
			Persona::printPersona();
		}

};

#endif

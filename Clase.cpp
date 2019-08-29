#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Alumno;
class Maestro;
class Examen;	 

#ifndef CLASE_CPP
#define CLASE_CPP

#include "Alumno.cpp"
#include "Maestro.cpp"
#include "Examen.cpp"

class Clase{
	protected:
		string id, nombre;
		string hora;
		string uv, semestre, periodo, anio;
		vector <Examen*> examenes;
		vector<Alumno*> alumnos;
		Maestro* maestro;
		double notaT;
	public:
		Clase(){
			//maestro = new Maestro();
		}

		Clase(string id, string nombre, string hora,  string uv, string semestre, string periodo, string anio, /*Maestro* maestro,*/ double notaT){
			//this->maestro=maestro;
			notaT=0;
			this->id=id;
			this->nombre=nombre;
			this->hora=hora;
			this->uv=uv;
			this->semestre=semestre;
			this->periodo=periodo;
			this->anio=anio;
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
		string getHora(){
			return this->hora;
		}

		void setHora(string hora){
			this->hora=hora;
		}
		string getUv(){
			return this->uv;
		}

		void setUv(string uv){
			this->uv=uv;
		}
		string getSemestre(){
			return this->semestre;
		}

		void setSemestre(string semestre){
			this->semestre=semestre;
		}
		string getPeriodo(){
			return this->periodo;
		}

		void setPeriodo(string periodo){
			this->periodo=periodo;
		}
		string getAnio(){
			return this->anio;
		}

		void setAnio(string anio){
			this->anio=anio;
		}
		Maestro* getMaestro(){
			return this->maestro;
		}

		void setMaestro(Maestro* maestro){
			this->maestro=maestro;
		}

		vector <Alumno*> getAlumnos(){
			return this->alumnos;
		}
		
		void setAlumnos(vector <Alumno*> alumnos){
			this->alumnos=alumnos;
		}
		
		void setAlumno(Alumno* pas){
			alumnos.push_back(pas);
		}
		
		void remAlumno(int p){
			alumnos.erase(alumnos.begin()+p);
		}
		
		vector <Examen*> getExamenes(){
			return this->examenes;
		}
		
		void setExamenes(vector <Examen*> examenes){
			this->examenes=examenes;
		}
		
		void setExamen(Examen* cur){
			examenes.push_back(cur);
		}
		
		void remExamen(int p){
			examenes.erase(examenes.begin()+p);
		}

		double nota_total(){
			return 0;
		}
		
		void printClase(){
			cout<<"Nombre: "<<nombre<<endl;
		}
		
};

#endif

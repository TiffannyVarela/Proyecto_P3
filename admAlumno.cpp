#include<iostream> 
#include<string> 
#include <fstream>
#include <stdlib.h>
#include "Alumno.cpp"
#include<string.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

#ifndef ADMALUMNO_CPP
#define ADMALUMNO_CPP

class admAlumno
{
	private:
		string ruta;
		vector <Alumno*> alu;
	public:
		admAlumno(string ruta){
			this->ruta=ruta;
		}
		string getRuta(){
			return this->ruta;
		}

		void addAlumno(Alumno* r){
			alu.push_back(r);
		}

		vector<Alumno*> getAlumnos(){
			return this->alu;
		}

		void remAlumno(int p){
			alu.erase(alu.begin()+p);
		}

		int getN(){
			alu.size();
		}

		~admAlumno(){}
	
		string token(string cadena, string divisor, int pos){
	       if(cadena.size()>0){
	         char oracion[cadena.size()]; 
	         for (int i=0;i<=cadena.size();i++)
	         {oracion[i]=cadena[i];}                    
	         char *ptrtoken; 
	         int num=1;
	         const char* d=divisor.c_str();
	         ptrtoken = strtok(oracion , d);             
	         while(ptrtoken){
	             if(num==pos){ 
	                return ptrtoken;}                 
	             ptrtoken = strtok(NULL, d);
	             num++;}
	         return "";
	       }else{return "";}
	    }


	    void Escribir(){
	    	ofstream escribir;
	    	escribir.open(ruta.c_str());
	    	for (int i = 0; i < alu.size(); ++i)
	    	{
	    		escribir<<alu.at(i)->getUser()<<"/"
			    		<<alu.at(i)->getPass()<<"/"
			    		<<alu.at(i)->getId()<<"/"
			    		<<alu.at(i)->getNombre()<<"/"
			    		<<alu.at(i)->getCarrera()<<"/"
			    		<<alu.at(i)->getRol()<<"/";
			    		for(int j=0; j<alu.at(i)->getPasadas().size(); j++){
			    			escribir<<alu.at(i)->getPasadas()[j]<<",";
						}
						escribir<<"/";
						for(int j=0; j<alu.at(i)->getCursar().size(); j++){
			    			escribir<<alu.at(i)->getCursar().at(j)<<",";
						}
						escribir<<endl;
	    	}
	    	escribir.close();
	    }

	    void Leer(){
	    	fstream leer;
	    	string linea;
	    	alu.clear();
	    	leer.open(ruta.c_str());
	    	if (leer.is_open())
	    	{
	    		while(!leer.eof()){
	    			getline(leer,linea);
	    			if (linea.size()>0)
	    			{
	    				addAlumno(new Alumno(token(linea,"/",1),
	    										token(linea,"/",2),
	    										token(linea,"/",3),
	    										token(linea,"/",4),
	    										token(linea,"/",5),
	    										token(linea,"/",6)
	    										)
	    				);
	    			}
	    		}
	    	}
	    	leer.close();
	    }

	    void printAlu(){
	    	for (int i = 0; i < alu.size(); ++i)
	    	{
	    		alu.at(i)->printAlumno();
	    	}
	    }
	    
	    void printAluReg(){
	    	for (int i = 0; i < alu.size(); ++i)
	    	{
	    		cout<<endl;
	    		cout<<"Pos: "<<i<<endl;
	    		alu.at(i)->printAlumReg();
	    		cout<<endl;
	    	}
	    }

};
#endif

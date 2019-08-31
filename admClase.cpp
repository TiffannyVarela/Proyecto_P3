#include<iostream> 
#include<string> 
#include <fstream>
#include <stdlib.h>
#include "Clase.cpp"
#include<string.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

#ifndef ADMCLASE_CPP
#define ADMCLASE_CPP

class admClase{
	private:
		string ruta;
		vector <Clase*> clas;
	public:
		admClase(string ruta){
			this->ruta=ruta;
		}
		string getRuta(){
			return this->ruta;
		}

		void addClase(Clase* c){
			clas.push_back(c);
		}

		vector<Clase*> getClase(){
			return this->clas;
		}

		void remClase(int p){
			clas.erase(clas.begin()+p);
		}

		int getN(){
			clas.size();
		}

		~admClase(){}
	
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
	    	for (int i = 0; i < clas.size(); ++i)
	    	{
	    		escribir<<clas.at(i)->getId()<<"/"
			    		<<clas.at(i)->getNombre()<<"/"
			    		<<clas.at(i)->getHora()<<"/"
			    		<<clas.at(i)->getUv()<<"/"
			    		<<clas.at(i)->getPeriodo()<<"/"
			    		<<clas.at(i)->getAnio()<<"/"
			    		<<clas.at(i)->nota_total()<<"/"
			    		<<clas.at(i)->getMaestro()->getNombre()<<"/";//cambiar despues
			    		for(int j=0; j<clas.at(i)->getAlumnos().size(); j++){
			    			escribir<<clas.at(i)->getAlumnos()[j]<<",";
						}
						escribir<<"/";
						for(int j=0; j<clas.at(i)->getExamenes().size(); j++){
			    			escribir<<clas.at(i)->getExamenes().at(j)<<",";
						}
						escribir<<endl;
	    	}
	    	escribir.close();
	    }

	    void Leer(){
	    	fstream leer;
	    	string linea;
	    	clas.clear();
	    	leer.open(ruta.c_str());
	    	if (leer.is_open())
	    	{
	    		while(!leer.eof()){
	    			getline(leer,linea);
	    			if (linea.size()>0)
	    			{
	    				addClase(new Clase(token(linea,"/",1),
	    										token(linea,"/",2),
	    										token(linea,"/",3),
	    										token(linea,"/",4),
	    										token(linea,"/",5),
	    										token(linea,"/",6),
	    										token(linea,"/",7),
	    										//token(linea,"/",8),
	    										atof(token(linea,"/",9).c_str())
	    										)
	    				);
	    			}
	    		}
	    	}
	    	leer.close();
	    }

	    void printClas(){
	    	for (int i = 0; i < clas.size(); ++i)
	    	{
	    		cout<<endl;
	    		cout<<"Pos: "<<i<<endl;
	    		clas.at(i)->printClase();
	    		cout<<endl;
	    	}
	    }


};
#endif

#include<iostream> 
#include<string> 
#include <fstream>
#include <stdlib.h>
#include "Maestro.cpp"
#include<string.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

#ifndef ADMMAESTRO_CPP
#define ADMMAESTRO_CPP

class admMaestro
{
	private:
		string ruta;
		vector <Maestro*> mae;
	public:
		admMaestro(string ruta){
			this->ruta=ruta;
		}
		string getRuta(){
			return this->ruta;
		}

		void addMaestro(Maestro* r){
			mae.push_back(r);
		}

		vector<Maestro*> getMaestros(){
			return this->mae;
		}

		void remMaestro(int p){
			mae.erase(mae.begin()+p);
		}

		int getN(){
			mae.size();
		}

		~admMaestro(){}
	
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
	    	for (int i = 0; i < mae.size(); ++i)
	    	{
	    		escribir<<mae.at(i)->getProfesion()<<"/"
			    		<<mae.at(i)->getSueldo()<<"/"
			    		<<mae.at(i)->getUser()<<"/"
			    		<<mae.at(i)->getPass()<<"/"
			    		<<mae.at(i)->getId()<<"/"
			    		<<mae.at(i)->getNombre()<<"/"
			    		<<mae.at(i)->getRol()<<"/";
			    		for(int j=0; j<mae.at(i)->getAsignadas().size(); j++){
			    			escribir<<mae.at(i)->getAsignadas()[j]<<",";
						}
						escribir<<endl;
	    	}
	    	escribir.close();
	    }

	    void Leer(){
	    	fstream leer;
	    	string linea;
	    	mae.clear();
	    	leer.open(ruta.c_str());
	    	if (leer.is_open())
	    	{
	    		while(!leer.eof()){
	    			getline(leer,linea);
	    			if (linea.size()>0)
	    			{
	    				addMaestro(new Maestro(token(linea,"/",1),
	    										atof(token(linea,"/",2).c_str()),
	    										token(linea,"/",3),
	    										token(linea,"/",4),
	    										token(linea,"/",5),
	    										token(linea,"/",6),
	    										token(linea,"/",7)
	    										)
	    				);
	    			}
	    		}
	    	}
	    	leer.close();
	    }

	    void printMae(){
	    	for (int i = 0; i < mae.size(); ++i)
	    	{
	    		cout<<"Pos: "<<i<<endl;
	    		mae.at(i)->printMaestro();
	    	}
	    }
	    
	    void printMaeReg(){
	    	for (int i = 0; i < mae.size(); ++i)
	    	{
	    		cout<<endl;
	    		cout<<"Pos: "<<i<<endl;
	    		mae.at(i)->printMaestroReg();
	    		cout<<endl;
	    	}
		}

};
#endif

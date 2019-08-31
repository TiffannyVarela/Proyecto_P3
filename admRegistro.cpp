#include<iostream> 
#include<string> 
#include <fstream>
#include <stdlib.h>
#include "Registro.cpp"
#include<string.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

#ifndef ADMREGISTRO_CPP
#define ADMREGISTRO_CPP

class admRegistro
{
	private:
		string ruta;
		vector <Registro*> reg;
	public:
		admRegistro(string ruta){
			this->ruta=ruta;
		}
		string getRuta(){
			return this->ruta;
		}

		void addRegistro(Registro* r){
			reg.push_back(r);
		}

		vector<Registro*> getRegistro(){
			return this->reg;
		}

		void remRegistro(int p){
			reg.erase(reg.begin()+p);
		}

		int getN(){
			reg.size();
		}

		~admRegistro(){}
	
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
	    	for (int i = 0; i < reg.size(); ++i)
	    	{
	    		escribir<<reg.at(i)->getUser()<<"/"
			    		<<reg.at(i)->getPass()<<"/"
			    		<<reg.at(i)->getId()<<"/"
			    		<<reg.at(i)->getNombre()<<"/"
			    		<<reg.at(i)->getRol()<<endl;
	    	}
	    	escribir.close();
	    }

	    void Leer(){
	    	fstream leer;
	    	string linea;
	    	reg.clear();
	    	leer.open(ruta.c_str());
	    	if (leer.is_open())
	    	{
	    		while(!leer.eof()){
	    			getline(leer,linea);
	    			if (linea.size()>0)
	    			{
	    				addRegistro(new Registro(token(linea,"/",1),
	    										token(linea,"/",2),
	    										token(linea,"/",3),
	    										token(linea,"/",4),
	    										token(linea,"/",5)
	    										)
	    				);
	    			}
	    		}
	    	}
	    	leer.close();
	    }

	    void printReg(){
	    	for (int i = 0; i < reg.size(); ++i)
	    	{
	    		cout<<endl;
	    		cout<<"Pos: "<<i<<endl;
	    		reg.at(i)->printRegistro();
	    		cout<<endl;
	    	}
	    }

};
#endif

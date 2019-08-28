#include <iostream>
#include <string>
#include "Pregunta.cpp"
using namespace std;

#ifndef VOF_CPP
#define VOF_CPP

class VOF{
	protected:
		string resp;
		
	public:
		VOF(){}

		VOF(string resp){
			this->resp=resp;
		}

		string getRespuesta(){
			return this->resp;
		}

		void setRespuesta(string resp){
			this->resp.assign(resp);
		}
		

		double Puntos_pos(){

		}
};

#endif

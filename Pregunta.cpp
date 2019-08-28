#include <iostream>
#include <string>
using namespace std;

#ifndef PREGUNTA_CPP
#define PREGUNTA_CPP

class Pregunta{
	protected:
		string pre;
		double puntos;

	public:

		Pregunta(){}

		Pregunta(string pre, double puntos){
			this->pre=pre;
			this->puntos=puntos;
		}

		string getPregunta(){
			return this->pre;
		}

		void setPregunta(string pre){
			this->pre.assign(pre);
		}

		double getPuntos(){
			return this->puntos;
		}

		void setPuntos(double puntos){
			this->puntos=puntos;
		}

		virtual double Puntos_pos(double puntos)=0;
		
};

#endif

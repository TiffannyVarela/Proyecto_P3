#include <iostream>
#include <string>
#include <vector>
#include "Alumno.cpp"
#include "Clase.cpp"
#include "Enumeracion.cpp"
#include "Examen.cpp"
#include "Maestro.cpp"
#include "Multiple.cpp"
#include "Persona.cpp"
#include "Pregunta.cpp"
#include "Registro.cpp"
#include "Usuario.cpp"
#include "VOF.cpp"

int main();

int main()
{
	/* code */
	return 0;
}

int menu(){
	int opc=0;
	while (true){
		cout<<"MENU"<<endl
			<<"1.-Hacer Clic"<<endl
			<<"2.-Comprar Granja"<<endl
			<<"3.-Comprar Banco"<<endl
			<<"4.-Comprar Templo"<<endl
			<<"5.-Comprar Oreo"<<endl
			<<"6.-Comprar Migajas"<<endl
			<<"7.-Mostrar Edificios y Mejoras Compradas"<<endl
			<<"8.-Salir"<<endl;
			
		cout<<"Ingrese una opcion: ";
		cin>>opc;
		if(opc>=1 && opc<=8){
			return opc;
		}
		else{
			cout<<"Opcion elegida no es valida"<<endl;
		}
	}
	return 0;
}

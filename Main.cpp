#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include "admRegistro.cpp"
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

//int main();

int main()
{
	string user;
	string pass;
	//vector <Registro*> reg;
	Registro* registro;
	admRegistro admR("./registro.txt");
	string userN, passN, nombreN, idN, rolN;
	
	
	/*cout<<"Nuevo Usuario: ";
	cin>>userN;
	cout<<"Nuevo Password: ";
	cin>>passN;
	cout<<"Nuevo Id: ";
	cin>>idN;
	cout<<"Nuevo Nombre: ";
	cin>>nombreN;
	rolN="Registro";
	registro = new Registro(userN, passN, idN, nombreN, rolN);
	admR.addRegistro(registro);
	admR.Escribir();
	admR.Leer();
	admR.printReg();*/
	admR.Leer();
	cout<<"Prueba: "<<admR.getRegistro().at(0)->getNombre()<<endl;
	cout<<"Ingrese su usuario: ";
	cin>>user;
	cout<<"Ingrese Contrasenia: ";
	pass="";
	char car;
	car = getch();

	while(car!=13){
		if (car!=8)
		{
			pass.push_back(car);
			cout<<"*";
		}
		else{
			if (pass.length()>0)
			{
				cout<<"\b \b";
				pass=pass.substr(0, pass.length()-1);
			}
		}
		car = getch();
	}
	//cout<<pass<<endl;
	
	admR.Leer();
	//admR.printReg();
	cout<<admR.getRegistro().at(0)->getUser()<<endl;
	cout<<admR.getRegistro().at(0)->getPass()<<endl;
	for(int i=0; i< admR.getRegistro().size(); i++){
		if(admR.getRegistro().at(i)->getUser().compare(user)==0 && admR.getRegistro().at(i)->getPass()==pass){

		}
		else{

		}
	}
	
	
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

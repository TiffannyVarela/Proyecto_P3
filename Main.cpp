#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include "admRegistro.cpp"
#include "admAlumno.cpp"
#include "admMaestro.cpp"
#include "admClase.cpp"
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

int menu();
void ing_maestro();
int menuM();
void ing_alumno();
void ing_clase();
void mod_maestro();
void mod_alumno();
void mod_clase();
void elim_maestro();
void elim_alumno();
void elim_clase();
void asig_maestro();
void mat_alumno();

int main()
{
	string user;
	string pass;
	//vector <Registro*> reg;
	Registro* registro;
	admRegistro admR("./registro.txt");
	admAlumno admA("./alumno.txt");
	admMaestro admM("./maestro.txt");
	admClase admC("./clase.txt");
	string userN, passN, nombreN, idN, rolN;
	int opc=0;
	
	Maestro *m;
	string profN;
	double sueldoN;
	int opc2 =0;
	int pos =0;
	
	Alumno* a;
	
	Clase* c;
	
	
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
	//cout<<admR.getRegistro().at(0)->getUser()<<endl;
	//cout<<admR.getRegistro().at(0)->getPass()<<endl;
	for(int i=0; i< admR.getRegistro().size(); i++){
		if(admR.getRegistro().at(i)->getUser().compare(user)==0 && admR.getRegistro().at(i)->getPass()==pass){
			do{
				switch(opc=menu()){
					case 1:
						cout<<"Nuevo Usuario: ";
						cin>>userN;
						cout<<"Nuevo Password: ";
						cin>>passN;
						cout<<"Nuevo Id: ";
						cin>>idN;
						cout<<"Nuevo Nombre: ";
						cin>>nombreN;
						cout<<"Nueva Profesion: ";
						cin>>profN;
						cout<<"Nuevo Sueldo: ";
						cin>>sueldoN;
						rolN="Maestro";
						m = new Maestro(profN, sueldoN, userN,passN,idN,nombreN,rolN);
						admM.addMaestro(m);
						admM.Escribir();
						//admM.Leer();
						//admM.printAlu();
						userN="";
						passN="";
						nombreN="";
						idN="";
						profN="";
						sueldoN="";
						rolN="";
						break;
						
					case 2:
						admM.Leer();
						admM.printAlu();
						cout<<"Posicion a modificar: ";
						cin>>pos;
						if(pos>=0 && pos<admM.getN()){
							switch(opc2=menuM()){
								case 1:
									cout<<"Nuevo Usuario: ";
									cin>>userN;
									admM.getMaestros().at(pos)->setUser(userN);
									admM.printAlu();
									admM.Escribir();
									userN="";
									break;
									
								case 2:
									break;
									
								case 3:
									break;
									
								case 4:
									break;
									
								case 5:
									break;
									
								case 6:
									break;
									
								case 7:
									break;
							}
						}
						break;
						
					case 3:
						admM.Leer();
						admM.printAlu();
						cout<<"Posicion a eliminar: ";
						cin>>pos;
						if(pos>=0 && pos<admM.getN()){
							admM.remMaestro(pos);
							admM.Escribir();
						}
						break;
						
					case 4:
						break;
						
					case 5:
						break;
						
					case 6:
						break;
						
					case 7:
						break;
						
					case 8:
						break;
						
					case 9:
						break;
						
					case 10:
						break;
						
					case 11:
						break;
				}
			}while(opc!=12);
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
			<<"1.-Ingresar Maestro"<<endl
			<<"2.-Modificar Maestro"<<endl
			<<"3.-Eliminar Maestro"<<endl
			<<"4.-Ingresar Alumno"<<endl
			<<"5.-Modificar Alumno"<<endl
			<<"6.-Eliminar Alumno"<<endl
			<<"7.-Ingresar Clase"<<endl
			<<"8.-Modificar Clase"<<endl
			<<"9.-Eliminar Clase"<<endl
			<<"10.-Asignar Maestro"<<endl
			<<"11.-Matricular Alumno"<<endl
			<<"12.-Salir"<<endl;
			
		cout<<"Ingrese una opcion: ";
		cin>>opc;
		if(opc>=1 && opc<=12){
			return opc;
		}
		else{
			cout<<"Opcion elegida no es valida"<<endl;
		}
	}
	return 0;
}

int menuM(){
	int opc=0;
	while (true){
		cout<<"Que desea modificar?"<<endl
			<<"1.-Usuario"<<endl
			<<"2.-Contrasenia"<<endl
			<<"3.-Id"<<endl
			<<"4.-Nombre"<<endl
			<<"5.-Profesion"<<endl
			<<"6.-Sueldo"<<endl
			<<"7.-Salir"<<endl;
			
		cout<<"Ingrese una opcion: ";
		cin>>opc;
		if(opc>=1 && opc<=7){
			return opc;
		}
		else{
			cout<<"Opcion elegida no es valida"<<endl;
		}
	}
	return 0;
}

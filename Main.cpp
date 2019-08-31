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
int menuAdm();
int menuAl();
int menuMa();
int menuCl();
int menuM();
int menuA();
int menuC();

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
	int opc3=0;
	int pos =0;
	
	Alumno* a;
	string carreraN;
	
	Clase* c;
	string hora, uv,semestre, periodo,anio;

	admR.Leer();
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
	admR.Leer();
	for(int i=0; i< admR.getRegistro().size(); i++){
		if(admR.getRegistro().at(i)->getUser().compare(user)==0 && admR.getRegistro().at(i)->getPass()==pass){
			do{
				switch(opc=menuAdm()){
					case 1:
						do{
							switch(opc2=menuAl()){
								case 1:
									system("cls");
									cout<<"Nuevo Usuario: ";
									cin>>userN;
									cout<<"Nuevo Password: ";
									cin>>passN;
									cout<<"Nuevo Id: ";
									cin>>idN;
									cout<<"Nuevo Nombre: ";
									getline(cin,nombreN);
									getline(cin,nombreN);
									cout<<"Nueva Carrera: ";
									getline(cin,carreraN);
									rolN="Alumno";
									a = new Alumno(carreraN, userN, passN, idN,nombreN,rolN);
									admA.addAlumno(a);
									admA.Escribir();
									//admM.Leer();
									//admM.printAlu();
									userN="";
									passN="";
									nombreN="";
									idN="";
									carreraN="";
									rolN="";
									system("pause");
									break;
									
								case 2:
									system("cls");
									admA.Leer();
									admA.printAluReg();
									cout<<"Posicion a modificar: ";
									cin>>pos;
									if(pos>=0 && pos<admA.getN()){
										switch(opc2=menuA()){
											case 1:
												cout<<"Nuevo Usuario: ";
												cin>>userN;
												admA.getAlumnos().at(pos)->setUser(userN);
												admA.printAluReg();
												admA.Escribir();
												userN="";
												opc=0;
												break;
												
											case 2:
												cout<<"Nuevo Password: ";
												cin>>passN;
												admA.getAlumnos().at(pos)->setPass(passN);
												admA.printAluReg();
												admA.Escribir();
												passN="";
												opc=0;
												break;
												
											case 3:
												cout<<"Nueva Id: ";
												cin>>idN;
												admA.getAlumnos().at(pos)->setId(idN);
												admA.printAluReg();
												admA.Escribir();
												idN="";
												opc=0;
												break;
												
											case 4:
												cout<<"Nuevo Nombre: ";
												getline(cin, nombreN);
												getline(cin, nombreN);
												admA.getAlumnos().at(pos)->setNombre(nombreN);
												admA.printAluReg();
												admA.Escribir();
												nombreN="";
												opc=0;
												break;
												
											case 5:
												cout<<"Nueva Carrera: ";
												getline(cin, carreraN);
												getline(cin, carreraN);
												admA.getAlumnos().at(pos)->setCarrera(carreraN);
												admA.printAluReg();
												admA.Escribir();
												carreraN="";
												opc=0;
												break;
												
												
										}
										system("pause");
									}
									
									break;
										
								case 3:
									system("cls");
									admA.Leer();
									admA.printAluReg();
									cout<<"Posicion a eliminar: ";
									cin>>pos;
									if(pos>=0 && pos<admA.getN()){
										admA.remAlumno(pos);
										admA.Escribir();
									}
									system("pause");
									break;
									
								case 4:
									break;
							}
						
						}while(opc2!=5);
						break;
						
					case 2:
						do{
							switch(opc2=menuMa()){
								case 1:
									system("cls");
									cout<<"Nuevo Usuario: ";
									cin>>userN;
									cout<<"Nuevo Password: ";
									cin>>passN;
									cout<<"Nuevo Id: ";
									cin>>idN;
									cout<<"Nuevo Nombre: ";
									getline(cin,nombreN);
									getline(cin,nombreN);
									cout<<"Nueva Profesion: ";
									getline(cin,profN);
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
									sueldoN=0;
									rolN="";
									system("pause");
									break;
									
								case 2:
									system("cls");
									admM.Leer();
									admM.printMaeReg();
									cout<<"Posicion a modificar: ";
									cin>>pos;
									if(pos>=0 && pos<admM.getN()){
										switch(opc2=menuM()){
											case 1:
												cout<<"Nuevo Usuario: ";
												cin>>userN;
												admM.getMaestros().at(pos)->setUser(userN);
												admM.printMaeReg();
												admM.Escribir();
												userN="";
												opc=0;
												break;
												
											case 2:
												cout<<"Nuevo Password: ";
												cin>>passN;
												admM.getMaestros().at(pos)->setPass(passN);
												admM.printMaeReg();
												admM.Escribir();
												passN="";
												opc=0;
												break;
												
											case 3:
												cout<<"Nueva Id: ";
												cin>>idN;
												admM.getMaestros().at(pos)->setId(idN);
												admM.printMaeReg();
												admM.Escribir();
												idN="";
												opc=0;
												break;
												
											case 4:
												cout<<"Nueva Nombre: ";
												getline(cin,nombreN);
												getline(cin,nombreN);
												admM.getMaestros().at(pos)->setNombre(nombreN);
												admM.printMaeReg();
												admM.Escribir();
												nombreN="";
												opc=0;
												break;
												
											case 5:
												cout<<"Nueva Profesion: ";
												getline(cin,profN);
												getline(cin,profN);
												admM.getMaestros().at(pos)->setProfesion(profN);
												admM.printMaeReg();
												admM.Escribir();
												profN="";
												opc=0;
												break;
												
											case 6:
												cout<<"Nuevo Sueldo: ";
												cin>>sueldoN;
												admM.getMaestros().at(pos)->setSueldo(sueldoN);
												admM.printMaeReg();
												admM.Escribir();
												sueldoN=0;
												opc=0;
												break;
												
										}
										system("pause");
									}
									break;
										
								case 3:
									system("cls");
									admM.Leer();
									admM.printMaeReg();
									cout<<"Posicion a eliminar: ";
									cin>>pos;
									if(pos>=0 && pos<admM.getN()){
										admM.remMaestro(pos);
										admM.Escribir();
									}
									system("pause");
									break;
									
								case 4:
									break;
							}
						
						}while(opc2!=5);
						break;
						
					case 3:
						do{
							switch(opc2=menuCl()){
								case 1:
									system("cls");
									cout<<"Nuevo Id: ";
									cin>>idN;
									cout<<"Nuevo Nombre: ";
									getline(cin,nombreN);
									getline(cin,nombreN);
									cout<<"Nueva Hora: ";
									cin>>hora;
									cout<<"Nueva UV: ";
									cin>>uv;
									cout<<"Nueva Semestre: ";
									cin>>semestre;
									cout<<"Nueva Periodo: ";
									cin>>periodo;
									cout<<"Nueva Anio: ";
									cin>>anio;
									c = new Clase(idN,nombreN,hora,uv,semestre,periodo,anio,0);
									admC.addClase(c);
									admC.Escribir();
									//admM.Leer();
									//admM.printAlu();
									nombreN="";
									idN="";
									hora="";
									uv="";
									semestre="";
									periodo="";
									anio="";
									system("pause");
									opc2=0;
									break;
									
								case 2:
									system("cls");
									admM.Leer();
									admM.printMaeReg();
									cout<<"Posicion a modificar: ";
									cin>>pos;
									if(pos>=0 && pos<admM.getN()){
										switch(opc2=menuC()){
											case 1:
												cout<<"Nueva Id: ";
												cin>>idN;
												admC.getClase().at(pos)->setId(idN);
												admC.printClas();
												admC.Escribir();
												idN="";
												opc=0;
												break;
												
											case 2:
												cout<<"Nuevo Nombre: ";
												getline(cin,nombreN);
												getline(cin,nombreN);
												admC.getClase().at(pos)->setNombre(nombreN);
												admC.printClas();
												admC.Escribir();
												nombreN="";
												opc=0;
												break;
												
											case 3:
												cout<<"Nueva Hora: ";
												cin>>hora;
												admC.getClase().at(pos)->setHora(hora);
												admC.printClas();
												admC.Escribir();
												hora="";
												opc=0;
												break;
												
											case 4:
												cout<<"Nueva UV: ";
												cin>>uv;
												admC.getClase().at(pos)->setUv(uv);
												admC.printClas();
												admC.Escribir();
												uv="";
												opc=0;
												break;
												
											case 5:
												cout<<"Nuevo Semestre: ";
												getline(cin, semestre);
												admC.getClase().at(pos)->setSemestre(semestre);
												admC.printClas();
												admC.Escribir();
												semestre="";
												opc=0;
												break;
												
											case 6:
												cout<<"Nuevo Periodo: ";
												cin>>periodo;
												admC.getClase().at(pos)->setPeriodo(periodo);
												admC.printClas();
												admC.Escribir();
												periodo="";
												opc=0;
												break;
												
											case 7:
												cout<<"Nuevo Anio: ";
												cin>>anio;
												admC.getClase().at(pos)->setAnio(anio);
												admC.printClas();
												admC.Escribir();
												anio="";
												opc=0;
												break;
										}
										system("pause");
									}
									break;
										
								case 3:
									system("cls");
									admC.Leer();
									admC.printClas();
									cout<<"Posicion a eliminar: ";
									cin>>pos;
									if(pos>=0 && pos<admC.getN()){
										admC.remClase(pos);
										admC.Escribir();
									}
									system("pause");
									break;
									
							}
						
						}while(opc2!=4);
						break;
						
						
								case 4:
									system("cls");
									cout<<"Nuevo Usuario: ";
									cin>>userN;
									cout<<"Nuevo Password: ";
									cin>>passN;
									cout<<"Nuevo Id: ";
									cin>>idN;
									cout<<"Nuevo Nombre: ";
									getline(cin,nombreN);
									getline(cin,nombreN);
									rolN="Registro";
									registro = new Registro(userN, passN, idN, nombreN, rolN);
									admR.addRegistro(registro);
									admR.Escribir();
									//admM.Leer();
									//admM.printAlu();
									userN="";
									passN="";
									nombreN="";
									idN="";
									rolN="";
									system("pause");
									
									break;
				}
				
				
			}while(opc!=5);
		}
		else{

		}
	}
	
	
	return 0;
}


int menuAdm(){
	int opc=0;
	while (true){
		system("cls");
		cout<<endl;
		cout<<"Administracion"<<endl
			<<"1.-Alumnos"<<endl
			<<"2.-Maestros"<<endl
			<<"3.-Clase"<<endl
			<<"4.-Crear Admin"<<endl
			<<"5.-Salir"<<endl;
			
		cout<<"Ingrese una opcion: ";
		cin>>opc;
		if(opc>=1 && opc<=5){
			return opc;
		}
		else{
			cout<<"Opcion elegida no es valida"<<endl;
		}
	}
	return 0;
}

int menuAl(){
		int opc=0;
	while (true){
		system("cls");
		cout<<endl;
		cout<<"MENU"<<endl
			<<"1.-Ingresar Alumno"<<endl
			<<"2.-Modificar Alumno"<<endl
			<<"3.-Eliminar Alumno"<<endl
			<<"4.-Matricular Alumno"<<endl
			<<"5.-Salir"<<endl;
			
		cout<<"Ingrese una opcion: ";
		cin>>opc;
		if(opc>=1 && opc<=5){
			return opc;
		}
		else{
			cout<<"Opcion elegida no es valida"<<endl;
		}
	}
	return 0;
}

int menuMa(){
		int opc=0;
	while (true){
		system("cls");
		cout<<endl;
		cout<<"MENU"<<endl
			<<"1.-Ingresar Maestro"<<endl
			<<"2.-Modificar Maestro"<<endl
			<<"3.-Eliminar Maestro"<<endl
			<<"4.-Asignar Clase"<<endl
			<<"5.-Salir"<<endl;
			
		cout<<"Ingrese una opcion: ";
		cin>>opc;
		if(opc>=1 && opc<=5){
			return opc;
		}
		else{
			cout<<"Opcion elegida no es valida"<<endl;
		}
	}
	return 0;
}

int menuCl(){
		int opc=0;
	while (true){
		system("cls");
		cout<<endl;
		cout<<"MENU"<<endl
			<<"1.-Ingresar Clase"<<endl
			<<"2.-Modificar Clase"<<endl
			<<"3.-Eliminar Clase"<<endl
			<<"4.-Salir"<<endl;
			
		cout<<"Ingrese una opcion: ";
		cin>>opc;
		if(opc>=1 && opc<=4){
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
		cout<<endl;
		cout<<"Que desea modificar?"<<endl
			<<"1.-Usuario"<<endl
			<<"2.-Contrasenia"<<endl
			<<"3.-Id"<<endl
			<<"4.-Nombre"<<endl
			<<"5.-Profesion"<<endl
			<<"6.-Sueldo"<<endl;
			
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

int menuA(){
	int opc=0;
	while (true){
		cout<<endl;
		cout<<"Que desea modificar?"<<endl
			<<"1.-Usuario"<<endl
			<<"2.-Contrasenia"<<endl
			<<"3.-Id"<<endl
			<<"4.-Nombre"<<endl
			<<"5.-Carrera"<<endl;
			
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

int menuC(){
	int opc=0;
	while (true){
		cout<<endl;
		cout<<"Que desea modificar?"<<endl
			<<"1.-Id"<<endl
			<<"2.-Nombre"<<endl
			<<"3.-Hora"<<endl
			<<"4.-UV"<<endl
			<<"5.-Semestre"<<endl
			<<"6.-Periodo"<<endl
			<<"7.-Anio"<<endl;
			
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

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
void ing_alumno();
void ing_clase();
void mod_maestro();
int menuM();
void mod_alumno();
int menuA();
void mod_clase();
int menuC();
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
	string carreraN;
	
	Clase* c;
	string hora, uv,semestre, periodo,anio;
	
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
//	cout<<"Prueba: "<<admR.getRegistro().at(0)->getNombre()<<endl;
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
						
					case 5:
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
									break;
									
								case 3:
									break;
									
								case 4:
									break;
									
								case 5:
									break;
									
								case 6:
									break;
									
							}
							system("pause");
						}
						break;
						
					case 6:
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
						
					case 7:
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
						
						//rolN="Alumno";
						c = new Clase(idN,nombreN,hora,uv,semestre,periodo,anio,0);
						admC.addClase(c);
						admC.Escribir();
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
		system("cls");
		cout<<endl;
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
		cout<<endl;
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

int menuA(){
	int opc=0;
	while (true){
		cout<<endl;
		cout<<"Que desea modificar?"<<endl
			<<"1.-Usuario"<<endl
			<<"2.-Contrasenia"<<endl
			<<"3.-Id"<<endl
			<<"4.-Nombre"<<endl
			<<"5.-Carrera"<<endl
			<<"6.-Salir"<<endl;
			
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

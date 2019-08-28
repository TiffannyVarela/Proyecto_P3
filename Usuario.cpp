#include <iostream>
#include <string>
using namespace std;

#ifndef USUARIO_CPP
#define USUARIO_CPP

class Usuario{
	protected:
		string user, pass;
		
	public:
		Usuario(){}

		Usuario(string user, string pass){
			this->user=user;
			this->pass=pass;
		}

		void getUser(){
			return this->user;
		}

		string setUser(string user){
			this->user=user;
		}

		void getPass(){
			return this->pass;
		}

		string setPass(string pass){
			this->pass=pass;
		}

		~Usuario(){}
		
};

#endif

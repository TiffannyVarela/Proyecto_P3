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

		virtual string getUser()=0;

		virtual void setUser(string user)=0;

		virtual string getPass()=0;

		virtual void setPass(string pass)=0;

		~Usuario(){}
		
};

#endif

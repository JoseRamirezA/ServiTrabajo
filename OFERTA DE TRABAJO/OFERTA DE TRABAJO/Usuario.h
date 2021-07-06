#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <string>

using namespace std;

class Usuario
{
protected:
	string username;
	string password;
public:
	Usuario();
	Usuario(const string&, const string&);
	~Usuario();
	void setUsername(const string&);
	void setPassword(const string&);
	string getUsername();
	string getPassword();
};
#endif // USUARIO_H
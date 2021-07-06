#include "Usuario.h"

Usuario::Usuario() {}

Usuario::Usuario(const string& username, const string& password)
{
	this->username = username;
	this->password = password;
}

Usuario::~Usuario() {}

void Usuario::setUsername(const string& username)
{
	this->username = username;
}

void Usuario::setPassword(const string& password)
{
	this->password = password;
}

string Usuario::getUsername()
{
	return username;
}

string Usuario::getPassword()
{
	return password;
}
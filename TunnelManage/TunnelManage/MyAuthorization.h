#ifndef  _MYAUTHORIZATION_H
#define  _MYAUTHORIZATION_H
#include <iostream>
#include <fstream>
#include <time.h>
#include <sstream>
#include "Windows.h"
using namespace std;
class Authorization
{
public:
	Authorization(const string, const string, const string);
	bool IsAuthorized();
	int Authorized();
	int CreateKeyFile(string,string);
	bool CreateMachineCode();
private:
	bool IsFileExit(const string name);
	bool CreateMyFile(const string fileName,string content="");
	bool RemoveMyFile(const string str);
	bool CheckVerIdFile();
	string a, b, c;
};
#endif
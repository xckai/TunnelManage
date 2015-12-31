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
	/*
	a 已经授权过的文件 c:\windows \system32\yzyyzy.txt
	b 机器码文件 c:\shield\monitor\machin_coad.txt
	c 经过授权的文件 c:\shield\monitor\ soft_data\ ver_id.txt
	a1 授权成功后另需生成的文件c:\windows\system32\yangyupeng.txt
	*/
public:
	Authorization(const string, const string, const string);
	Authorization();
	bool IsAuthorized();
	int Authorized();
	int CreateKeyFile(string,string);
	bool CreateMachineCode();
private:
	bool IsFileExit(const string name);
	bool CreateMyFile(const string fileName,string content="");
	bool RemoveMyFile(const string str);
	bool CheckVerIdFile();
	string a, b, c,a1,floder1,floder2,admin;
	
};
#endif
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
	a �Ѿ���Ȩ�����ļ� c:\windows \system32\yzyyzy.txt
	b �������ļ� c:\shield\monitor\machin_coad.txt
	c ������Ȩ���ļ� c:\shield\monitor\ soft_data\ ver_id.txt
	a1 ��Ȩ�ɹ����������ɵ��ļ�c:\windows\system32\yangyupeng.txt
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
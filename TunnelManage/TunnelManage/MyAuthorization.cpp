#include "stdafx.h"
#include "MyAuthorization.h"
#include "CPUID.h"
#include "StringEncode.h"
Authorization::Authorization( string _a, string _b, string _c)
{ 
	a =_a;
	b = _b;
	c = _c;
}
int Authorization::Authorized(){
	try {
		//a 主文件,b 机器码文件, c 授权文件
		if (IsFileExit(a))
		{
			OutputDebugString(L"已经过授权");
			return 8;
		}
		else{
			if (IsFileExit(c))//授权文件存在
			{
				if (CheckVerIdFile())//验证授权
				{
					CreateMyFile(a);
					RemoveMyFile(c);
					OutputDebugString(L"验证授权成功");
					return 8;//ok
				}
				else{
					RemoveMyFile(c);
					CreateMachineCode();
					OutputDebugString(L"验证授权失败");
					return 1;//delete file 
				}

			}
			else//授权文件不存在
			{
				CreateMachineCode();//生成机器码
				OutputDebugString(L"生成机器码");
				return 1;
			}
		}
	}
	catch (exception e)
	{
		return -1;
	}

}
bool Authorization::CheckVerIdFile()
{
	stringstream ss;
	SYSTEMTIME sysTime;
	GetSystemTime(&sysTime);
	ss << sysTime.wYear << sysTime.wMonth << sysTime.wDay;
	string myTime = ss.str();
	ifstream inFile(c.c_str(), ofstream::in | ofstream::binary);
	string MyStr;
	inFile >> MyStr;
	if (MyStr.length()<13)
	{
		return false;
	}
	string enCodeStr;

	for (int i = 0; i < MyStr.length()-5;++i)
    {
		enCodeStr += MyStr[i];
    }
	string decodeStr = StringEncode().base64_decode(enCodeStr);
	string decodeTime,decodeMachineCode;
	for (int i = 0; i < decodeStr.length() - myTime.length();++i)
	{
		decodeMachineCode += decodeStr[i];
	}
	CPUID myCpu;
	if (myCpu.GetModel()!=decodeMachineCode)
	{
	
		return false;
	}
	for (int i = decodeStr.length() - myTime.length(); i<decodeStr.length(); ++i)
	{
		decodeTime += decodeStr[i];
	}
	
	if (myTime == decodeTime)
	{
		return true;
	}else
	{
		
		return false;
	}
}
bool Authorization::IsFileExit(const string name)
{
	ifstream inFile(name.c_str());
	if (inFile)
	{
		return true;
	}
	else{
		return false;
	}

}
bool Authorization::CreateMyFile(const string str,string content)
{
	ofstream outFile(str.c_str(), ofstream::out | ofstream::binary);
	if (outFile)
	{
		outFile << content;
		outFile.close();
		return true;
	}
	else
	{
		return false;
	}
}
bool Authorization::RemoveMyFile(const string str){
	if (0 == remove(str.c_str()))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Authorization::IsAuthorized()
{
	return IsFileExit(a);
}
int Authorization::CreateKeyFile(string fileName,string machineFile)
{
	try{
		SYSTEMTIME sysTime;
		GetSystemTime(&sysTime);
		stringstream ss;
		ss << sysTime.wYear << sysTime.wMonth << sysTime.wDay;
		string myTime = ss.str();
		ifstream myInfile(machineFile);
		string machineCode;
		myInfile >> machineCode;
		string myStr = machineCode + myTime;
		//string myEncodeStr = base64_encode(reinterpret_cast<const unsigned char*>(myStr.c_str()), myStr.length());
		string myEncodeStr= StringEncode().base64_encode(myStr);
		myEncodeStr += "@!$%c";
		cout << myStr;
		CreateMyFile(fileName, myEncodeStr);
		return 0;
	}
	catch (exception e)
	{
		return -1;
	}
}
bool Authorization::CreateMachineCode()
{
	CPUID cpu;
	string myStr = cpu.GetModel();

	return CreateMyFile(b, myStr);

}

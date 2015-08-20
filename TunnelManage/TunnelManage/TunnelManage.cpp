// TunnelManage.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include <iostream> 
#include "string"
#include <fstream>
#include <windows.h>
using namespace std;

class FunctionManage
{
public:
	static int GapCalcute(int w,int x,int l,int r,WCHAR *resultBuffer)
	{
		wstring result=L""; 
		
		wstring exceptionResult=L"999,999";
		try
		{
			if ((r+l)!=0 && w!=0)
			{
				int _k=(r+l)/w;
				int _d=(r-l)/(2*_k);
				int _x=x+_d;
				result += to_wstring(_d);
				result += L",";
				result += to_wstring(_x);
				lstrcpyW(resultBuffer, result.c_str());
				int t = result.size();
				return result.size()+1;
			}else{
				lstrcpyW(resultBuffer, exceptionResult.c_str());
				return exceptionResult.size();
				
			}

		}catch (exception  &e){
			
			lstrcpyW(resultBuffer, exceptionResult.c_str());
			return exceptionResult.size();
		}
	}
	static int Authorized(string a,string b,string c){
		//a ���ļ�,b �������ļ�, c ��Ȩ�ļ�
		if (IsFileExit(a))
		{
			return 8;
		}else{
			if (IsFileExit(c))//��Ȩ�ļ�����
			{
				if (CheckVerIdFile(c))//��֤��Ȩ
				{
					CreateMyFile(a);
					RemoveMyFile(c);
					return 8;//ok
				}else{
					RemoveMyFile(c);
					CreateMyFile(b);
					return 1;//delete file 
				}

			}else//��Ȩ�ļ�������
			{
				CreateMyFile(b);//���ɻ�����
				return 1;
			}
		}
		
	}
	static bool  CheckVerIdFile(string str)
	{

		return true;
	}
	static bool IsFileExit(const string name)
	{
		ifstream inFile(name.c_str());
		if (inFile)
		{
			return true;
		}else{
			return false;
		}

	}
	static bool CreateMyFile(const string str)
	{
		ofstream outFile(str.c_str(),ofstream::out|ofstream::binary);
		if (outFile)
		{
			outFile.close();
			return true;
		}else
		{			
			return false;
		}
		
		
		
		
	}
	static bool RemoveMyFile(const string str){
		if (0==remove(str.c_str()))
		{
			return true;
		}else
		{
			return false;
		}
	}
}functionManage;
extern"C"_declspec(dllexport) int  GapCalculate(int w,int x,int l,int r,WCHAR * buffer)
{
	return functionManage.GapCalcute(w, x, l, r, buffer);
}


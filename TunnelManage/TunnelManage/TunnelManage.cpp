// TunnelManage.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include <iostream> 
#include "string"
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
}functionManage;
extern"C"_declspec(dllexport) int  GapCalculate(int w,int x,int l,int r,WCHAR * buffer)
{
	return functionManage.GapCalcute(w, x, l, r, buffer);
}


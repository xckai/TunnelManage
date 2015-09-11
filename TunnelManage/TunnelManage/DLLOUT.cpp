
#include "stdafx.h"
#include "MyAuthorization.h"
#include "TunnelManage.cpp"
using namespace std;
std::string WChar2Ansi(LPCWSTR pwszSrc)
{
	int nLen = WideCharToMultiByte(CP_ACP, 0, pwszSrc, -1, NULL, 0, NULL, NULL);
	if (nLen <= 0) return std::string("");
	char* pszDst = new char[nLen];
	if (NULL == pszDst) return std::string("");
	WideCharToMultiByte(CP_ACP, 0, pwszSrc, -1, pszDst, nLen, NULL, NULL);
	pszDst[nLen - 1] = 0;
	std::string strTemp(pszDst);
	delete[] pszDst;
	return strTemp;
}
string ws2s(wstring& inputws){ return WChar2Ansi(inputws.c_str()); }
FunctionManage functionManage;
extern"C"_declspec(dllexport) int  GapCalculate(int w, int x, float l, float r, WCHAR * buffer)
{
	return functionManage.GapCalcute(w, x, l, r, buffer);
}
extern"C"_declspec(dllexport) int  Authorized()
{
	/*LPCWSTR a, LPCWSTR b, LPCWSTR c
	string _a = ws2s((wstring)a);
	string _b = ws2s((wstring)b);
	string _c = ws2s((wstring)c);*/
	Authorization auth;
	return auth.Authorized();
}
extern"C"_declspec(dllexport)int CreateKey(LPCWSTR a, LPCWSTR b)
{ //a 读取机器码的路径 b 生成key的路径
	string _a = ws2s((wstring)a);
	string _b = ws2s((wstring)b);
	Authorization auth;
	return auth.CreateKeyFile(_a, _b);
}
extern"C"_declspec(dllexport)int RingCalculate(int n, int w, int dr, int lxj, int l0, int l1, int l2, int l3, int l4, int l5, WCHAR *resultBuffer) {
	return functionManage.RingCalculate(n,w,dr,lxj,l0,l1,l2,l3,l4,l5,resultBuffer);
}
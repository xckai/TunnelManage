// TunnelManage.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include <iostream> 
#include "string"
#include <fstream>
#include <windows.h>
#include <atlstr.h>
#include "MyAuthorization.h"
#include <vector>

using namespace std;

class FunctionManage
{
public:
	static int GapCalcute(int w,int x,float l,float r,WCHAR *resultBuffer)
	{
		wstring result=L""; 
		
		wstring exceptionResult=L"9999,9999";
		try
		{
			Authorization auth;

			if (!auth.IsAuthorized())
			{
				lstrcpyW(resultBuffer, exceptionResult.c_str());
				return exceptionResult.size();
			}

			if ((r+l)!=0 && w!=0)
			{
				float _k=(r+l)/w;
				float _d=(r-l)/(2*_k);
				float _x=x+_d;
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
	static string  RingCalcute6(int n,int w,int dr,int lxj,int l0,int l1,int l2,int l3,int l4,int l5){
		int ring=0,jxc=0,erro=0,mymax=0,q=0,m=0,k=0;
		string result="";
		vector<int > lmax,la,lx;
		lmax.resize(6);
		la.resize(6);
		IntilRing("e:\\123.txt",ring,jxc,lmax,la);
		
		lx.push_back(l0);lx.push_back(l1);
		lx.push_back(l2);lx.push_back(l3);
		lx.push_back(l4);lx.push_back(l5);		
		if (dr!=0 )
		{
			ring=dr;
			dr=0;
		}
		if (lxj==1)
		{
			for (int i=0;i<6;++i)
			{
				if (lx.at(erro)>lx.at(i))
				{
					erro=i;
				}
				if (lx.at(mymax)<lx.at(i))
				{
					mymax=i;
				}
			}
			for (int i=0;i<6;++i)
			{
				/*if ((lmax.at(i)-lx.at(i))>20 && (lmax.at(i)-lx.at(i)< 0.75 * w))
				{
					lmax.at(i)=lx.at(i);
				}*/
				if ((i!=erro)&&(i!=mymax))
				{
					if ((lx.at(i)-lmax.at(i)>0))
					{
						lmax.at(i)=lx.at(i);
						q+=(lx.at(i)-la.at(i));
						m++;
					}
					if (lmax.at(i)-lx.at(i)>0.75*w)
					{
						++k;
					}
				}
				if  ((lx.at(i)-lmax.at(i)>0))
				{
					lmax.at(i)=lx.at(i);
				}
			}
			if (q>0 && m>0)
			{
				jxc=q/m;
				
			}
			if (k>=n-2)
			{
				jxc=0;
				ring++;
				
				for (int i=0;i<6;++i)
				{
					if (i!= erro && i!=mymax)
					{
						la.at(i)=lx.at(i);
						lmax.at(i)=lx.at(i);
					}
				}
			}
			
			StoryRing("e:\\123.txt",ring,jxc,lmax,la);
			result+=to_string(jxc);
			result+=to_string(ring);
			result+=to_string(dr);
		}
		
		return result;
	}		
    static bool IntilRing(string filename,int & ring,int & jxc,vector<int> &lmax,vector <int> &la )
	{
		Wow64EnableWow64FsRedirection(FALSE);
		ifstream File(filename.c_str(), ofstream::in | ofstream::binary);
		if (File)
		{

			File>>ring;
			File>>jxc;
			for (int i=0;i<lmax.size();++i)
			{
				File>>lmax.at(i);
			}
			for (int i=0;i<la.size();++i)
			{
				File>>la.at(i);
			}
			File.close();
			Wow64EnableWow64FsRedirection(true);
			return true;
		}
		else
		{
			Wow64EnableWow64FsRedirection(true);
			for (int i=0;i<lmax.size();++i)
			{
				lmax.at(i)=0;
			}
			for (int i=0;i<la.size();++i)
			{
				la.at(i)=0;
			}
			ring =0;
			jxc =0;
			return false;
		}


	}
	static bool StoryRing(string filename,int & ring,int & jxc,vector<int> &lmax,vector <int> &la )
	{
		Wow64EnableWow64FsRedirection(FALSE);
		ofstream File(filename.c_str(), ofstream::out | ofstream::binary);
		if (File)
		{

			File<<ring;
			File<<" ";
			File<<jxc;
			File<<" ";

			for (int i=0;i<lmax.size();++i)
			{
				File<<lmax.at(i);
				File<<" ";

			}
			for (int i=0;i<la.size();++i)
			{
				File<<la.at(i);
				File<<" ";

			}
			File.close();
			Wow64EnableWow64FsRedirection(true);
			return true;
		}
		else
		{
			Wow64EnableWow64FsRedirection(true);
			
			return false;
		}


	}
};


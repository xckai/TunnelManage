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
#include<algorithm>

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
	static int  RingCalculate(int n, int w, int dr, int lxj, int l0, int l1, int l2, int l3, int l4, int l5, WCHAR *resultBuffer){
		wstring result = L"";
		wstring exceptionResult = L"9999,9999";
		string file = "C:\\shield\\monitor\\pro_rin.txt";
		try
		{
			if (Authorization().IsAuthorized())
			{
				int ring = 0, jxc = 0, erro = -1, mymax = -1, k = 0;
				float q = 0, m = 0;
				//string result="";
				vector<int > lmax, la, lx;
				lmax.resize(n);
				la.resize(n);
				IntilRing(file, ring, jxc, lmax, la);
				lx.push_back(l0); lx.push_back(l1);
				lx.push_back(l2); lx.push_back(l3);
				if (6 == n)
				{
					lx.push_back(l4); lx.push_back(l5);
				}



				if (dr != 0)
				{
					ring = dr;
					dr = 0;
				}
				if (lxj == 1)
				{
					int t_max = -1, t_min = -1;
					int t_max_val = -1, t_min_val = -1;
					float t_midvalue = 0;
					vector<int>t_vec = lx;
					sort(t_vec.begin(), t_vec.end());
					int acc = 0;
					for (int i = 1; i<t_vec.size() - 1; ++i)
					{
						acc += t_vec[i];
					}
					t_midvalue = acc / (t_vec.size() - 2);
					t_max_val = t_vec[t_vec.size() - 1];
					t_min_val = t_vec[0];
					for (int i = 0; i < lx.size(); ++i)
					{
						if (lx[i] == t_max_val)
						{
							t_max = i;
						}
						if (lx[i] == t_min_val)
						{
							t_min = i;
						}
					}
					if ((t_max_val - t_midvalue)>100)
					{
						mymax = t_max;
					}
					if ((t_midvalue - t_min_val)>100)
					{
						erro = t_min;
					}

					for (int i = 0; i<n; ++i)
					{
						/*if ((lmax.at(i)-lx.at(i))>20 && (lmax.at(i)-lx.at(i)< 0.75 * w))
						{
						lmax.at(i)=lx.at(i);
						}*/
						if ((i != erro) && (i != mymax))
						{
							if ((lx.at(i) - lmax.at(i)>0))
							{
								lmax.at(i) = lx.at(i);
								q += (lx.at(i) - la.at(i));
								m++;
							}
							if (lmax.at(i) - lx.at(i)>0.75*w)
							{
								++k;
							}
						}
						if ((lx.at(i) - lmax.at(i)>0))
						{
							lmax.at(i) = lx.at(i);
						}
					}
					if (q>0 && m>0)
					{
						jxc = (q / m + 0.5);

					}
					if (k >= n - 2)
					{
						jxc = 0;
						ring++;

						for (int i = 0; i<n; ++i)
						{
							if (i != erro && i != mymax)
							{
								la.at(i) = lx.at(i);
								lmax.at(i) = lx.at(i);
							}
							/*la.at(i) = lx.at(i);
							lmax.at(i) = lx.at(i);*/
						}
					}
					for (int i = 0; i < lmax.size(); ++i){
						if ((lmax[i] - lx[i])>0.75*w)
						{
							lmax[i] = lx[i];
						}
					}

					StoryRing(file, ring, jxc, lmax, la);
					result += to_wstring(ring);
					result += L",";
					result += to_wstring(jxc);
					result += L",";
					
					result += to_wstring(dr);
				}
				else {
					result = exceptionResult;
					result += L",9991";
				}
				//cout <<"本次计算 erro为 ：" <<erro << " max 为： " << mymax << endl;
				//cout << "lmax的值分别为： ";
				//for (int i = 0; i < lmax.size(); ++i)
				//{
				//	cout << lmax[i] << " ";
				//}
				////cout <<endl <<"la 的值为： ";
				//for (int i = 0; i < la.size(); ++i)
				//{
				//	cout << la[i] << " ";
				//}
				//cout << endl;
				
			}
			else {
				result = exceptionResult;
				result += L",9999";
			}

		}
		catch (exception &e)
		{
			result = exceptionResult;
			result += L",9990";
			
		}
		
		lstrcpyW(resultBuffer, result.c_str());
		return result.size()+1;
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


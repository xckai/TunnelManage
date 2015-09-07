// MyTester2012.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "TunnelManage.cpp"
#include <iostream>
#include <iomanip>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	int i;
	while (true)
	{
		
		vector<int> lmax;
		lmax.resize(10);
		
		
		ifstream File("E:\\github\\TunnelManage\\test.txt", ofstream::in | ofstream::binary);
		ofstream outfile("E:\\github\\TunnelManage\\testresult.txt", ofstream::out | ofstream::binary);
		string str;
		while (getline(File, str)){
			stringstream ss(str);
			for (int i = 0; i < lmax.size(); ++i)
			{
				int num;
				ss >> num;
				lmax.at(i) = num;
			}
			string resultstr1,str2;
			ss >> resultstr1;
			ss >> str2;
			outfile << "Calculate result is : " << FunctionManage().RingCalcute6(lmax.at(0), lmax.at(1), lmax.at(2), lmax.at(3), lmax.at(4), lmax.at(5), lmax.at(6), lmax.at(7), lmax.at(8), lmax.at(9)) << setw(25)<<" Expect result is : " << resultstr1 << " " << str2 << "\r\n";
		}
		outfile << "done";
		outfile.close();
		cin >> str;
		
	}	
	//cout<<functionManage.CreateMyFile("");
	return 0;
}


// MyTester2012.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "TunnelManage.cpp"

int _tmain(int argc, _TCHAR* argv[])
{
	int i;
	while (true)
	{
		
		vector<int> lmax;
		lmax.resize(10);
		for (int i=0;i<lmax.size();++i)
		{
			cin>>lmax.at(i);
		}
		
		
		cout << FunctionManage().RingCalcute6(lmax.at(0),lmax.at(1),lmax.at(2),lmax.at(3),lmax.at(4),lmax.at(5),lmax.at(6),lmax.at(7),lmax.at(8),lmax.at(9))<<endl;
	}	
	//cout<<functionManage.CreateMyFile("");
	return 0;
}


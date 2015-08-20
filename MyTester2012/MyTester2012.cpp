// MyTester2012.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "TunnelManage.cpp"

int _tmain(int argc, _TCHAR* argv[])
{
	int i;
	while (cin>>i)
	{
		cout<<  functionManage.Authorized("D:\\a.txt","D:\\b.txt","D:\\c.txt");

	}
	
	//cout<<functionManage.CreateMyFile("");
	
	return 0;
}


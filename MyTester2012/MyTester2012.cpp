// MyTester2012.cpp : �������̨Ӧ�ó������ڵ㡣
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


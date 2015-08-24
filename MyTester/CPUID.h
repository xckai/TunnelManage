//Cpuid.h 类声明
//抄袭自互联网，并在此基础上做了一些修改。可以得到cpu的制造商，cpu型号以及cpu主频，用任何软件更改系统，均不会改变以上内容的结果，因为使用了汇编指令cpuid直接读取cpu固有信息。

#ifndef _CPUID_H
#define _CPUID_H

#include <string>
#include <windows.h>
using namespace std;

class CPUID
{
public:
	CPUID();
	virtual ~CPUID();
	string	GetOEM();		//Producer
	string	GetModel();		//Model主模块 
	LONGLONG GetFrequencyEn(DWORD sleepTime = 1000);//获取cpu主频
	LONG	 GetFrequency();
private:
	void  Executecpuid(DWORD veax); //用以执行cpuid指令
	DWORD  m_eax;   // 存储返回的eax
	DWORD  m_ebx;   // 存储返回的ebx
	DWORD  m_ecx;   // 存储返回的ecx
	DWORD  m_edx;   // 存储返回的edx
};

#endif 


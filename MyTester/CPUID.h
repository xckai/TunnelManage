//Cpuid.h ������
//��Ϯ�Ի����������ڴ˻���������һЩ�޸ġ����Եõ�cpu�������̣�cpu�ͺ��Լ�cpu��Ƶ�����κ��������ϵͳ��������ı��������ݵĽ������Ϊʹ���˻��ָ��cpuidֱ�Ӷ�ȡcpu������Ϣ��

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
	string	GetModel();		//Model��ģ�� 
	LONGLONG GetFrequencyEn(DWORD sleepTime = 1000);//��ȡcpu��Ƶ
	LONG	 GetFrequency();
private:
	void  Executecpuid(DWORD veax); //����ִ��cpuidָ��
	DWORD  m_eax;   // �洢���ص�eax
	DWORD  m_ebx;   // �洢���ص�ebx
	DWORD  m_ecx;   // �洢���ص�ecx
	DWORD  m_edx;   // �洢���ص�edx
};

#endif 


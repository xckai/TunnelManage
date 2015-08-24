//Cpuid.cpp ��ʵ��
#include "stdafx.h"
#include "Cpuid.h"

static const int CONST_DWSIZE = sizeof(DWORD);

CPUID::CPUID()
:m_eax(0), m_ebx(0), m_ecx(0), m_edx(0)
{

}

CPUID::~CPUID()
{

}

void CPUID::Executecpuid(DWORD veax)
{
	// ��ΪǶ��ʽ�Ļ����벻��ʶ�� ���Ա����
	// ���Զ����ĸ���ʱ������Ϊ����
	DWORD deax;
	DWORD debx;
	DWORD decx;
	DWORD dedx;

	__asm
	{
		mov eax, veax
			cpuid
			mov deax, eax
			mov debx, ebx
			mov decx, ecx
			mov dedx, edx
	}

	m_eax = deax; // ����ʱ�����е����ݷ������Ա����
	m_ebx = debx;
	m_ecx = decx;
	m_edx = dedx;
}

/*  ���ҵĵ����ϵ���Ҽ���ѡ�����ԣ������ڴ��ڵ����濴��һ��CPU����Ϣ��
�����CPU���̱��ַ�����CPU���̱��ַ���Ҳ��ͨ��cpuid�õ��ġ�
�����̱���ַ����ܳ�(48���ַ�)�����Բ�����һ��cpuidָ��ִ��ʱȫ���õ���
����intel�����ֳ���3��������eax����������ֱ���0x80000002,0x80000003,0x80000004��
ÿ�η��ص�16���ַ������մӵ�λ����λ��˳�����η���eax, ebx, ecx, edx��
��ˣ�������ѭ���ķ�ʽ��ÿ��ִ�����Ժ󱣴�����Ȼ��ִ����һ��cpuid��
*/
string CPUID::GetModel()
{
	const DWORD BRANDID = 0x80000002;  // ��0x80000002��ʼ����0x80000004����
	char cBrand[CONST_DWSIZE * 4 * 3 + 1] = { 0 };    // �����洢�̱��ַ�����48���ַ�

	for (DWORD i = 0; i < 3; i++)   // ����ִ��3��ָ��
	{
		Executecpuid(BRANDID + i);
		// ÿ��ִ�н����󣬱����ĸ��Ĵ������asc�뵽����
		memcpy(cBrand + i*CONST_DWSIZE * 4 + CONST_DWSIZE * 0, &m_eax, CONST_DWSIZE);
		memcpy(cBrand + i*CONST_DWSIZE * 4 + CONST_DWSIZE * 1, &m_ebx, CONST_DWSIZE);
		memcpy(cBrand + i*CONST_DWSIZE * 4 + CONST_DWSIZE * 2, &m_ecx, CONST_DWSIZE);
		memcpy(cBrand + i*CONST_DWSIZE * 4 + CONST_DWSIZE * 3, &m_edx, CONST_DWSIZE);
	}
	return string(cBrand);  // ��string����ʽ����
}

/*    ��Intel Pentium���ϼ����CPU�У���һ����Ϊ��ʱ�����Time Stamp�����Ĳ�����
����64λ�޷����������ĸ�ʽ����¼����CPU�ϵ�������������ʱ����������
����Ŀǰ��CPU��Ƶ���ǳ��ߣ��������������Դﵽ���뼶�ļ�ʱ���ȡ�
�����ȷ�����������ַ������޷�����ġ�
��Pentium���ϵ�CPU�У��ṩ��һ������ָ��RDTSC��Read Time Stamp Counter��
����ȡ���ʱ��������֣������䱣����EDX:EAX�Ĵ�������
*/
LONGLONG CPUID::GetFrequencyEn(DWORD sleepTime)
{
	HANDLE hp = ::GetCurrentProcess(); //��ȡ��ǰ����
	HANDLE ht = ::GetCurrentThread(); //��ȡ��ǰ�߳�

	DWORD  pc = ::GetPriorityClass(hp); //��ȡ��ǰ�������ȶ�
	DWORD  tp = ::GetThreadPriority(ht); //��ȡ��ǰ�߳����ȶ�

	BOOL   flag1 = FALSE, flag2 = FALSE;
	DWORD  low1 = 0, high1 = 0, low2 = 0, high2 = 0;

	flag1 = ::SetPriorityClass(hp, REALTIME_PRIORITY_CLASS);  //����ǰ�������ȶ��������
	flag2 = ::SetThreadPriority(ht, THREAD_PRIORITY_HIGHEST); //����ǰ�߳����ȶ��������

	::Sleep(10);
	LARGE_INTEGER fq, st, ed;
	::QueryPerformanceFrequency(&fq); //��ȷ��ʱ
	::QueryPerformanceCounter(&st);  //�����ʼʱ��
	__asm        //��õ�ǰcpu��ʱ��������
	{
		rdtsc
			mov low1, eax
			mov high1, edx
	}
	::Sleep(sleepTime);     //���̹߳���Ƭ��
	::QueryPerformanceCounter(&ed);  //��ý���ʱ��
	__asm        //��õ�ǰcpu��ʱ��������
	{
		rdtsc
			mov low2, eax
			mov high2, edx
	}


	if (flag1)
		::SetPriorityClass(hp, pc);  //����ǰ�������ȶȻָ�ԭ��
	if (flag2)
		::SetThreadPriority(ht, tp);  //����ǰ�߳����ȶȻָ�ԭ��

	::CloseHandle(hp);
	::CloseHandle(ht);

	//��cpu��ʱ��������ת����64λ����
	LONGLONG begin = (LONGLONG)high1 << 32 | low1;
	LONGLONG end = (LONGLONG)high2 << 32 | low2;

	//�����λ�õ�cpuʱ�����������Լ��ʱ�䣬���õ�cpu��Ƶ�ʡ�
	//����windows��Sleep�����д�Լ15�����������windows�ľ�ȷ��ʱΪ׼
	return (end - begin)*fq.QuadPart / (ed.QuadPart - st.QuadPart);
}

//��ȡCPUƵ��,��λ: MHZ  
LONG CPUID::GetFrequency()
{
	int start, over;
	_asm
	{
		RDTSC
			mov start, eax
	}
	Sleep(50);
	_asm
	{
		RDTSC
			mov over, eax
	}
	return (over - start) / 50000;
}

/*   ��eax = 0��Ϊ������������Եõ�CPU����������Ϣ��
cpuidָ��ִ���Ժ󣬻᷵��һ��12�ַ�����������Ϣ��
ǰ�ĸ��ַ���ASC�밴��λ����λ����ebx���м��ĸ�����edx������ĸ��ַ�����ecx��
*/
std::string CPUID::GetOEM()
{
	char cVID[CONST_DWSIZE* 3 + 1] = { 0 };   // �ַ����������洢��������Ϣ
	Executecpuid(0);  // ִ��cpuidָ�ʹ��������� eax = 0
	memcpy(cVID + CONST_DWSIZE * 0, &m_ebx, CONST_DWSIZE); // ����ǰ�ĸ��ַ�������
	memcpy(cVID + CONST_DWSIZE * 1, &m_edx, CONST_DWSIZE); // �����м��ĸ��ַ�������
	memcpy(cVID + CONST_DWSIZE * 2, &m_ecx, CONST_DWSIZE); // ��������ĸ��ַ�������

	return string(cVID);  // ��string����ʽ����
}

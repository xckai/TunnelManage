//Cpuid.cpp 类实现
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
	// 因为嵌入式的汇编代码不能识别 类成员变量
	// 所以定义四个临时变量作为过渡
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

	m_eax = deax; // 把临时变量中的内容放入类成员变量
	m_ebx = debx;
	m_ecx = decx;
	m_edx = dedx;
}

/*  在我的电脑上点击右键，选择属性，可以在窗口的下面看到一条CPU的信息，
这就是CPU的商标字符串。CPU的商标字符串也是通过cpuid得到的。
由于商标的字符串很长(48个字符)，所以不能在一次cpuid指令执行时全部得到，
所以intel把它分成了3个操作，eax的输入参数分别是0x80000002,0x80000003,0x80000004，
每次返回的16个字符，按照从低位到高位的顺序依次放在eax, ebx, ecx, edx。
因此，可以用循环的方式，每次执行完以后保存结果，然后执行下一次cpuid。
*/
string CPUID::GetModel()
{
	const DWORD BRANDID = 0x80000002;  // 从0x80000002开始，到0x80000004结束
	char cBrand[CONST_DWSIZE * 4 * 3 + 1] = { 0 };    // 用来存储商标字符串，48个字符

	for (DWORD i = 0; i < 3; i++)   // 依次执行3个指令
	{
		Executecpuid(BRANDID + i);
		// 每次执行结束后，保存四个寄存器里的asc码到数组
		memcpy(cBrand + i*CONST_DWSIZE * 4 + CONST_DWSIZE * 0, &m_eax, CONST_DWSIZE);
		memcpy(cBrand + i*CONST_DWSIZE * 4 + CONST_DWSIZE * 1, &m_ebx, CONST_DWSIZE);
		memcpy(cBrand + i*CONST_DWSIZE * 4 + CONST_DWSIZE * 2, &m_ecx, CONST_DWSIZE);
		memcpy(cBrand + i*CONST_DWSIZE * 4 + CONST_DWSIZE * 3, &m_edx, CONST_DWSIZE);
	}
	return string(cBrand);  // 以string的形式返回
}

/*    在Intel Pentium以上级别的CPU中，有一个称为“时间戳（Time Stamp）”的部件，
它以64位无符号整型数的格式，记录了自CPU上电以来所经过的时钟周期数。
由于目前的CPU主频都非常高，因此这个部件可以达到纳秒级的计时精度。
这个精确性是上述两种方法所无法比拟的。
在Pentium以上的CPU中，提供了一条机器指令RDTSC（Read Time Stamp Counter）
来读取这个时间戳的数字，并将其保存在EDX:EAX寄存器对中
*/
LONGLONG CPUID::GetFrequencyEn(DWORD sleepTime)
{
	HANDLE hp = ::GetCurrentProcess(); //获取当前进程
	HANDLE ht = ::GetCurrentThread(); //获取当前线程

	DWORD  pc = ::GetPriorityClass(hp); //获取当前进程优先度
	DWORD  tp = ::GetThreadPriority(ht); //获取当前线程优先度

	BOOL   flag1 = FALSE, flag2 = FALSE;
	DWORD  low1 = 0, high1 = 0, low2 = 0, high2 = 0;

	flag1 = ::SetPriorityClass(hp, REALTIME_PRIORITY_CLASS);  //将当前进程优先度设置最高
	flag2 = ::SetThreadPriority(ht, THREAD_PRIORITY_HIGHEST); //将当前线程优先度设置最高

	::Sleep(10);
	LARGE_INTEGER fq, st, ed;
	::QueryPerformanceFrequency(&fq); //精确计时
	::QueryPerformanceCounter(&st);  //获得起始时间
	__asm        //获得当前cpu的时间周期数
	{
		rdtsc
			mov low1, eax
			mov high1, edx
	}
	::Sleep(sleepTime);     //将线程挂起片刻
	::QueryPerformanceCounter(&ed);  //获得结束时间
	__asm        //获得当前cpu的时间周期数
	{
		rdtsc
			mov low2, eax
			mov high2, edx
	}


	if (flag1)
		::SetPriorityClass(hp, pc);  //将当前进程优先度恢复原样
	if (flag2)
		::SetThreadPriority(ht, tp);  //将当前线程优先度恢复原样

	::CloseHandle(hp);
	::CloseHandle(ht);

	//将cpu的时间周期数转化成64位整数
	LONGLONG begin = (LONGLONG)high1 << 32 | low1;
	LONGLONG end = (LONGLONG)high2 << 32 | low2;

	//将两次获得的cpu时间周期数除以间隔时间，即得到cpu的频率。
	//由于windows的Sleep函数有大约15毫秒的误差，故以windows的精确计时为准
	return (end - begin)*fq.QuadPart / (ed.QuadPart - st.QuadPart);
}

//获取CPU频率,单位: MHZ  
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

/*   把eax = 0作为输入参数，可以得到CPU的制造商信息。
cpuid指令执行以后，会返回一个12字符的制造商信息，
前四个字符的ASC码按低位到高位放在ebx，中间四个放在edx，最后四个字符放在ecx。
*/
std::string CPUID::GetOEM()
{
	char cVID[CONST_DWSIZE* 3 + 1] = { 0 };   // 字符串，用来存储制造商信息
	Executecpuid(0);  // 执行cpuid指令，使用输入参数 eax = 0
	memcpy(cVID + CONST_DWSIZE * 0, &m_ebx, CONST_DWSIZE); // 复制前四个字符到数组
	memcpy(cVID + CONST_DWSIZE * 1, &m_edx, CONST_DWSIZE); // 复制中间四个字符到数组
	memcpy(cVID + CONST_DWSIZE * 2, &m_ecx, CONST_DWSIZE); // 复制最后四个字符到数组

	return string(cVID);  // 以string的形式返回
}

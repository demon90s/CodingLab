#include <iostream>

// 如果函数被noexcept声明，就表示如果从其中抛出了异常，程序会被 abort 。

void foo() noexcept
{
	throw 0;
}

int main()
{
	// 捕获也没有用，foo违反了 noexcept 声明
	try {
		foo();
	} catch (...)
	{
	}

	std::cout << "normal end" << std::endl;
}

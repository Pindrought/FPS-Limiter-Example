#include "FPSLimiter.h"
#include <iostream>

int main()
{
	FPSLimiter fpslimiter;
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Test" << std::endl;
		fpslimiter.Pulse(60);
	}
	return 0;
}
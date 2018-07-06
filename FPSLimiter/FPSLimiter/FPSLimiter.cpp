#include "FPSLimiter.h"
#ifdef _WIN32 
#include <Windows.h>
#else//Linux Sleep that functions like win32 sleep
#define Sleep(duration) sleep(duration/1000)
#include <unistd.h>
#endif


FPSLimiter::FPSLimiter()
{
	t.Start();
}

void FPSLimiter::Pulse(double maxfps)
{
	t.Stop();
	double currentfps = 1000.0/t.GetMilisecondsElapsed();
	if (currentfps > maxfps)
	{
		double maxElapsedTime = 1000.0 / maxfps;
		double waitTime = maxElapsedTime - t.GetMilisecondsElapsed();
		if (waitTime > 0) //sanity check
		{
			Sleep(waitTime);
		}
	}
	t.Start();
}
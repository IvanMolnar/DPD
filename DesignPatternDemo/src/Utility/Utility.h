#pragma once

#pragma warning( disable : 4244)

#include <stdlib.h>
#include <time.h>

class Utilities
{
public:

	static int getRandomNumber(int min, int max)
	{
		return min + rand() % (max - min);
	}

private:
	Utilities() { srand(time(NULL)); }
	Utilities(const Utilities &old);
	const Utilities &operator=(const Utilities &old);
	~Utilities() {}
};
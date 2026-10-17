#include <ctime>
#include <cstdlib>

#include "Random.hpp"

namespace Random
{
	int getRandomNumber(int min, int max)
	{
	    static bool hasBeenInitiatedSeed = false;
	    if (!hasBeenInitiatedSeed)
	    {
		    unsigned int seed = static_cast<unsigned int>(std::time(nullptr));
		    std::srand(seed);
		    hasBeenInitiatedSeed = true;
	    }

	    int randomInt = std::rand();
	    return randomInt % (max - min + 1) + min;
	}
}

#include "Random.h"

#include <ctime>
#include <cstdlib>
#include <cmath>

namespace Random
{

	int integer(int low, int high)
	{
	    if ( low == high || low > high ) return low;
		return rand() % (high - low + 1) + low;
	}

	double decimalD( double low, double high, int precision )
	{
		double multiplier = pow(10, precision);

		low *= multiplier;
		high *= multiplier;

		double newNum = integer(low, high);

		return newNum / multiplier;
	}

	float decimalF( float low, float high, int precision )
	{
		float multiplier = pow(10, precision);

		low *= multiplier;
		high *= multiplier;

		float newNum = integer(low, high);

		return newNum / multiplier;
	}

}

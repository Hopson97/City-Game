#ifndef RANDOM_H_INCLUDED
#define RANDOM_H_INCLUDED

namespace Random
{
	int integer		( int low, int high );

	double decimalD ( double low, double high, int precision = 1 );
	float decimalF  ( float low,  float high,  int precision = 1 );
}

#endif

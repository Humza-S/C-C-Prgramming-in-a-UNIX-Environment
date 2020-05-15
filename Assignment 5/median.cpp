#include "median.h"

double median::findMedian(int* arr, int& size)
{
	double median = -1;
	if ( (size % 2) == 0 ) {
		int *left = arr + ((size - 1) / 2);
		int *right = arr + (size / 2);
		median = (double)*left + (double)*right;
		median /= 2.0;
	}
	else
		median = *(arr + (size / 2));
	
	return median;
}

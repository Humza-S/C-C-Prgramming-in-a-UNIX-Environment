#include "mode.h"

int mode::findMode(int*& arr, int& size)
{
	int mode = -1;
	int maxCount = 1;
	for (int i = 0; i < size; i ++ ) {
		int count = 0;
		for (int j = 0; j < size; j++) {
			if (arr[i] == arr[j])
				count++;
		}
		if (count > maxCount) {
			maxCount = count;
			mode = arr[i];
		}
	}
	return mode;
}

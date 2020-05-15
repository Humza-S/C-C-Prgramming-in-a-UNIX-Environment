#include <iostream>
#include <stdio.h>
#include "mode.h"
#include "median.h"

int main()
{
	int num_students;
	printf("Enter number of students surveyed: ");
	scanf("%d", &num_students);

	int *arr = new int[num_students];
	double avg = 0;

	std::cout << "\nFor the following entries, enter them in ascending order\n";

	for (int i = 0; i < num_students; i++) {
		printf("Enter the number of movies for Student #%d: ", i+1);
		int num_movies;
		scanf("%d", &num_movies);
		arr[i] = num_movies;
		avg += arr[i];
	}

	avg /= 2.0;

	std::cout << "THE AVERAGE IS: " << avg << "\n";
	std::cout << "THE MEDIAN IS: " << median::findMedian(arr, num_students) << "\n";
	std::cout << "THE MODE IS: " << mode::findMode(arr, num_students) << "\n";
}

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	srand(time(NULL));   // Initialization, should only be called once.
	//int r = rand();
	double x = 0;
	double y = 0;
	double points[2];
	points[0] = 0.0f;
	points[1] = 0.0f;
	clock_t begin = clock();
	for (int i = 0; i < 10000000; i++)
	{
		x = (double)rand() / (double)RAND_MAX;
		//printf("X: %d", x);
		y = (double)rand() / (double)RAND_MAX;
		//printf("Y: %d", y);
		if ((x * x) + (y * y) <= 1)
		{
			points[0]++;
		}
		else {
			points[1]++;
		}
	}
	

	/* here, do your time-consuming job */

	clock_t end = clock();
	double timeSpent = (double)(end - begin) / CLOCKS_PER_SEC;
	double pi = 4*(points[0] / 10000000);
	printf("time spent: %f \n", timeSpent);
	printf("aproximacion de PI: %f", pi);
}

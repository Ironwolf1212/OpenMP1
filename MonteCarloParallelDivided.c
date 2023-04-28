#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

int main() {
	srand(time(NULL));   // Initialization, should only be called once.
	//int r = rand();
	int NUM_THREADS = 4;
	double x = 0;
	double y = 0;
	double points[2];
	double piCollection[NUM_THREADS];
	points[0] = 0.0f;
	points[1] = 0.0f;
	clock_t begin = clock();
	#pragma omp parallel num_threads(NUM_THREADS) private(x,y) reduction(+:points) 
	{
	#pragma omp for schedule(dynamic)
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
		piCollection[omp_get_thread_num()] = 4 * (points[0] / (points[0]+points[1]));
		printf("ID: %d Azules: %.0f TotalProcesados: %.0f EstimacionPi: %f \n", omp_get_thread_num(), points[0], points[0] + points[1], piCollection[omp_get_thread_num()]);
	}

	clock_t end = clock();
	double timeSpent = (double)(end - begin) / CLOCKS_PER_SEC;
	double pi = 4*(points[0] / 10000000);
	printf("time spent: %f \n", timeSpent);
	printf("aproximacion de PI: %f", pi);
}

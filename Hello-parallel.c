#include <stdio.h>
#include <omp.h>

int main(int argc,char *argv[]){
	int t_id,num_t;
	double time_start;
	double time_now;
	time_start = omp_get_wtime();
	
//	printf("Start Time: %f \n", time_start);
	#pragma omp parallel num_threads(212)
	{
		num_t = omp_get_num_threads();
		t_id = omp_get_thread_num();
		
		printf("Hello Wolrd form thread ID %d %d \n",t_id,num_t);
		
	}
//	printf("Now Time: %f \n", time_now);
	time_now = omp_get_wtime();
	printf("Time: %f mSec",(time_now-time_start)*1000);
	return 0;
}

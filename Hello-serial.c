#include <stdio.h>
#include <omp.h>

int main(int argc,char *argv[]){
	int t_id=1;
	double time_start;
	double time_now;
	time_start = omp_get_wtime();
	printf("Hello world from thread ID %d \n", t_id);
	time_now = omp_get_wtime();
	printf("Time: %f mSec",(time_now-time_start)*1000);
	return 0;
}

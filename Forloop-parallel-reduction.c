#include <stdio.h>
#include <math.h>
#include <omp.h>

#define NUMBER 500000

int main(int argc,char *argv[]){
	int i,data[NUMBER],num_t,t_id;
	double result = 0.0;
	double time_start;
	double time_now;
	
	time_start = omp_get_wtime();
//	#pragma omp parallel for 
	for(i=0;i<NUMBER;i++){
//		num_t = omp_get_num_threads();
		data[i]=i*i;
	}
	#pragma omp parallel for reduction(+:result)
	for(i=0;i<5;i++){
		num_t = omp_get_num_threads();
		t_id = omp_get_thread_num();
		result+=(sin(data[i])-cos(data[i]))/(sin(data[i])+cos(data[i]));
 		printf("T_id: %d I : %d\n", t_id, i);
	}	
	printf("Result = %f \n", result);
	
	time_now = omp_get_wtime();
	printf("Time: %f mSec Thread: %d",(time_now-time_start)*1000, num_t);
}

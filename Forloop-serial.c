#include <stdio.h>
#include <math.h>
#include <omp.h>

#define NUMBER 500000

int main(int argc,char *argv[]){
	int i,data[NUMBER];
	double result = 0.0;
	double time_start;
	double time_now;
	
	time_start = omp_get_wtime();
	
	for(i=0;i<NUMBER;i++){
		data[i]=i*i;
	}
	for(i=0;i<NUMBER;i++){
		result+=(sin(data[i])-cos(data[i]))/(sin(data[i])+cos(data[i])); 
	}	
	printf("Result = %f \n", result);
	
	time_now = omp_get_wtime();
	printf("Time: %f mSec ",(time_now-time_start)*1000);
}

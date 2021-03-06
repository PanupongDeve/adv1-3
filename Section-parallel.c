#include <stdio.h>
#include <omp.h>
#define NUMBER 100


double alpha(){
	int i; 
	double a=0.0;
	
	int num_t,t_id;
	num_t = omp_get_num_threads();
	t_id = omp_get_thread_num();
	
	for(i=0;i<NUMBER;i++){
		a+=(i-1)/(i+1);
	}
	
	printf("T_ID_aplha: %d Num_T: %d\n", t_id, num_t);
	return a;
}

double beta(){
	int i;
	double b=0.0;
	
	int num_t,t_id;
	num_t = omp_get_num_threads();
	t_id = omp_get_thread_num();
	
	for(i=NUMBER;i>0;i--){
		b += i*(i-1);
	}
	
	printf("T_ID_beta: %d Num_T: %d\n", t_id, num_t);
	return b;
	
}

double delta(){
	int i,j; 	
	double c=0.0;
	
	int num_t,t_id;
	num_t = omp_get_num_threads();
	t_id = omp_get_thread_num();
	
	for(i=NUMBER,j=0;i>0,i<NUMBER;i--,j++)
		c+=(i-j)/NUMBER;
		
	printf("T_ID_delta: %d Num_T: %d\n", t_id, num_t);
	return c;
}

double gamma(double d, double e){
	return (d-e);
}

double epsilon(double f,double g){
	return (f+g);
}

int main(int argc,char *argv[]){
	double w,v,x,y;
	#pragma omp parallel
	{
			w=alpha();
			v=beta();
			y=delta();	
	}

	x=gamma(v,w);
	printf("%12.4f\n", x);
	printf("%12.4f", epsilon(x,y));
	
	return 0;
	
}

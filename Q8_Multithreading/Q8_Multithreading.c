#include <stdio.h>
#include <pthread.h>

double mean,std_dev;  int median;

typedef struct Thread{
	int *array; 
	int size;
} Thread;


void *calculate_mean(void *args){
	Thread *mean_args = (Thread *)args;
	for(int i = 0; i< mean_args->size; i++){
		mean = mean + (mean_args->array[i]); 
	}
	mean = mean / (mean_args->size); 
	return mean_args; 
}

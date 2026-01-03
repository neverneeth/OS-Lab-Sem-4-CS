#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>


double mean,std_dev, median;

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


void *calculate_median(void *args){
	Thread *median_args = (Thread *)args;
	int *ar = (int *)malloc((median_args->size)* sizeof(int));
	for(int i = 0; i < median_args->size; i++){
		ar[i] = median_args->array[i]; 
	}
	for(int i  = 0; i < (median_args->size - 1); i++){
		int small = ar[i], pos = i;
		for(int j = i+1; j < (median_args->size); j++){
			if(ar[j] < small){
				small = ar[j]; pos = j;
			}
		}
		ar[pos] = ar[i];
		ar[i] = small;
	}
	if((median_args->size)%2 == 0){
		double mid = median_args->size / 2;
		median = (ar[mid] + ar[mid-1]) /2 ;
	} else{
		median = ar[(median_args->size)/2] ;
	}
	free(ar); 
	return median_args;
}

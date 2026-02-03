#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <math.h>



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
		int mid = median_args->size / 2;
		median = (ar[mid] + ar[mid-1]) / 2.0 ;
	} else{
		median = ar[(median_args->size)/2] ;
	}
	free(ar); 
	return median_args;
}


void *calculate_std_dev(void *args){
	Thread *sd_args = (Thread *)args;
	double mean = 0.0;
	for(int i = 0; i < sd_args->size; i++){
		mean = mean + sd_args->array[i];
	}
	mean = mean / (sd_args->size);
	double numerator = 0;
	for(int i = 0 ; i< sd_args->size; i++){
		numerator += pow( sd_args->array[i] - mean, 2) ;
	}
	std_dev = sqrt(numerator / sd_args->size);
	return sd_args;
}



int main(int argc, char *argv[]){
        if(argc <= 1){
		printf("\nArgument Error\n");
		return 1;
	}
	int ar[argc-1], pos = 1;
	for(int i = 0; i < argc-1; i++){
		ar[i] = atoi(argv[pos++]);
	}
	printf("\nEntered: \n");
	for(int i = 0; i < argc-1; i++){
		printf("%d ", ar[i]);
	} printf("\n");

	Thread thread;
	thread.array = ar; thread.size = argc-1;
	pthread_t tid_mean, tid_median, tid_sd;


	pthread_create(&tid_mean, NULL, calculate_mean, (void *)&thread); 
	pthread_join(tid_mean, NULL);


	pthread_create(&tid_median, NULL, calculate_median, (void *)&thread);
	pthread_join(tid_median, NULL);


	pthread_create(&tid_sd, NULL, calculate_std_dev, (void *)&thread);
	pthread_join(tid_sd, NULL);


	printf("\nMean = %lf\nMedian = %lf\nStandard Deviation = %lf\n", mean, median, std_dev);

	return 0;
}

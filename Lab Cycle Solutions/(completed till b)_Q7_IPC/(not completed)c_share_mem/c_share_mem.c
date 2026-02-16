#include <stdio.h>
#include <string.h>
#include <sys/shm.h>
#include <ctype.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


typedef struct {
	char str1[100];
	char str2[100];
	char str3[100];
	char comb_str[300];
	int status;
} SharedData;

int main(){
	key_t key = ftok("shmfile", 65);

	int shmid = shmget(key, sizeof(SharedData), 0666 | IPC_CREAT);

	if(shmid == -1){
		printf("\nSharing memory failed !\n");
		return 1;
	}

	SharedData *data = (SharedData *) shmat(shmid, (void *)0, 0);
	data->status = 0;

	
}
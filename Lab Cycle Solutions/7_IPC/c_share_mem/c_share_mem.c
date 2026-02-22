#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <ctype.h>
#include <semaphore.h>

#define SHM_NAME "/shm"
#define MAX_SIZE 1024

int main(){

	int shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0644);
	ftruncate(shm_fd, MAX_SIZE);

	char *mptr = mmap(0, MAX_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

	char s1[256], s2[256], s3[256];

	sem_t *parent_done = sem_open("/semaphore", O_CREAT, 0644, 0);

	pid_t pid = fork();

	// Child
	if(pid == 0){
		sem_wait(parent_done); // Implemented sempahore because cant depend on user to finish input in fixed seconds

		sscanf(mptr, "%[^\n]\n%[^\n]\n%[^\n]", s1, s2, s3);

		char concatenated_string[MAX_SIZE];

		sprintf(concatenated_string, "%s %s %s", s1, s2, s3);
		strcpy(mptr, concatenated_string);

		sem_close(parent_done);
		munmap(mptr, MAX_SIZE);
		close(shm_fd);
	}
	// Parent
	else{
        	printf("\nEnter first string: ");
        	fgets(s1, sizeof(s1), stdin);
        	s1[strcspn(s1, "\n")] = '\0';

        	printf("Enter second string: ");
        	fgets(s2, sizeof(s2), stdin);
        	s2[strcspn(s2, "\n")] = '\0';

        	printf("Enter third string: ");
        	fgets(s3, sizeof(s3), stdin);
        	s3[strcspn(s3, "\n")] = '\0';

		sprintf(mptr, "%s\n%s\n%s", s1, s2, s3);

		sem_post(parent_done);

		wait(NULL);

		char result[MAX_SIZE];
        	strcpy(result, mptr);

        	// Flip case
        	for (int i = 0; result[i] != '\0'; i++) {
        	    if (islower(result[i]))
        	        result[i] = toupper(result[i]);
        	    else if (isupper(result[i]))
        	        result[i] = tolower(result[i]);
        	}

        	printf("Final Output (Flipped Case): %s\n\n", result);

		sem_close(parent_done);
		sem_unlink("/semaphore");

		munmap(mptr, MAX_SIZE);
		close(shm_fd);
		shm_unlink(SHM_NAME);

	}

	return 0;
}

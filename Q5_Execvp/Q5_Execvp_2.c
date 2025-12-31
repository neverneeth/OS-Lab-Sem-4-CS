#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
    pid_t pid;
    pid = fork();
    if(pid == 0){
        
        char *args[] = {"./myadder", "10", "20", NULL}; 
        execvp(args[0], args);
    } else{
        printf("\nThis is the second program.\n"); 
    }
    


    return 0;
}
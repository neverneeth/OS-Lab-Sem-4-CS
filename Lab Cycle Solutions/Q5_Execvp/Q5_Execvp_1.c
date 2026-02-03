#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    int a, b, sum; 

    if(argc != 3){
        printf("\nArgument Error\n"); 
        return 1;
    }
    a = atoi(argv[1]); 
    b = atoi(argv[2]); 

    sum = a+b;
    printf("\nSum of %d and %d = %d\n", a, b, sum); 

    return 0;
}

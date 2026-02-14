#include <stdio.h>
#include <stdbool.h>

int main()
{

	int P,R;
	printf("No of processes: ");
	scanf("%d",&P);
	printf("No of Types :");
	scanf("%d",&R);


	int allocation[P][R];
    int max[P][R];

    printf("\nEnter Allocation Matrix (%d x %d):\n", P, R);
    for (int i = 0; i < P; i++) {
        printf("For Process P%d:\n", i);
        for (int j = 0; j < R; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("\nEnter Max Matrix (%d x %d):\n", P, R);
    for (int i = 0; i < P; i++) {
        printf("For Process P%d:\n", i);
        for (int j = 0; j < R; j++) {
            scanf("%d", &max[i][j]);
        }
    }
    int available[R];

    printf("\nEnter Available Resources (%d values):\n", R);
    for (int j = 0; j < R; j++) {
        scanf("%d", &available[j]);
    }

    int need[P][R];
    bool finished[P];
    for(int i=0;i<P;i++)
    	finished[i]=false;
    int safeSequence[P];
    int count=0;

    for(int i=0;i<P;i++)
    {
    	for(int j=0;j<R;j++)
    	{
    		need[i][j]=max[i][j]-allocation[i][j];
    	}
    }

    while(count<P)
    {
    	bool found=false;
    	for(int i=0;i<P;i++)
    	{
    		if(!finished[i])
    		{
    			bool possible=true;
    			for(int j=0;j<R;j++)
    			{
    				if(need[i][j]>available[j])
    				{
    					possible=false;
    					break;
    				}
    			}

    			if(possible)
    			{
    				for(int j=0;j<R;j++)
    				{
    					available[j]+=allocation[i][j];
    				}
    				safeSequence[count++]=i;
    				finished[i]=true;
    				found=true;
    			}
    		}
    	}

    	if(!found)
    	{
    		printf("System is in deadlock state \n");
    		return 0;
    	}
    }

    printf("System is in safe state \n");
    printf("Safe Sequence :  ");
    for(int i=0;i<P;i++)
    {
    	printf(" P%d --> ",safeSequence[i]);
    }
    printf(" End\n");
    return 0;


}
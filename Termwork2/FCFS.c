#include <stdio.h>
#include <stdlib.h>

int main (){
	
	int bt[20] ,wt[20] ,tat[20] , i , n ;
	
	float wtavg ,tatavg ;
	
	printf("Enter Burst Number Of Process : " ) ;
	
	scanf("%d" ,&n );
	
	for (int i = 0 ; i < n ;i++){
	
		printf("Enter Burst Time For Process : " );
		
		scanf("%d" ,&bt[i] );

	}

	wt[0]=0;
	
	tat[0] = bt[0] ;
	
	wtavg = 0 ;
 
	tatavg = tat[0] ;
	
	for (i=1 ; i < n ;i++){
		
		wt[i] = wt[i-1] + bt[i-1] ;
		
		tat[i] = tat[i-1] + bt[i] ;
	
		wtavg += wt[i];
		
		tatavg += tat[i] ;

	}

	printf("Process |t Burst Time |t Waiting Time |t Turn Arround Time " );
	
	for (i = 0 ; i < n;i++){
		
		printf("\n p%d\t\t%d\t\t%d\t\t%d \n",i,bt[i],wt[i],tat[i]);
	
	}
	
	printf("Avg Waiting Time : %f \n",wtavg / n );
	
	printf("Avg Turn Arround Time Time : %f \n",tatavg / n );
	
	return 0;
}

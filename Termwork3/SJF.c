#include <stdio.h>
#include <stdlib.h>

int main (){

	int p[20] ,bt[20] ,wt[20] ,tat[20] , i , k , n ,temp ;
	
	float wtavg ,tatavg ;
	
	printf("Enter The Number Of Process : "  );
	
	scanf("%d" ,&n );

	for (i = 0 ; i < n ; i++) {
	
		p[i] =  1;
	
		printf("Enter The Burst Time For Process  %d :", i );
		
		scanf("%d" ,&bt[i] );

	}


	for (i = 0 ; i < n ;i++ ) {
	
		for (k = i + 1 ; k < n; k++ ){
			
			if ( bt[i] > bt[k] ) {

				temp = bt[i] ;

				bt[i] = bt[k] ;
			
				bt[k] = temp ;
				
				temp = p[i] ;
				
				p[i] = p[k] ;
				
				p[k] = temp ;

			}

		}


	}
	
	wt[0] = wtavg = 0 ;
		
	tat[0] = tatavg = bt[0] ;
	
	for (i = 1 ; i < n ;i++) { 
	
		wt[i] = wt[i-1] + bt[i-1] ;

		tat[i] = tat[i-1] + bt[i] ;
		
		wtavg += wt [i] ;
		
		tatavg += tat[i] ;

	}

	printf("Process |t Burst Time |t Wiating Time |t Turn Arround Time " ) ;
	
	for ( i = 0 ;i < n ;i++ ) {
	
		printf("\n p%d\t\t%d\t\t%d\t\t%d\t\t\n" ,i,bt[i],wt[i],tat[i]);


	}

	printf("Avg Waiting Time : %f \n" ,wtavg / n );
	
	printf("Avg Turn Arround Time %f \n " ,tatavg /n );
	
	return 0;

}

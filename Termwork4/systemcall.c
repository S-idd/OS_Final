#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main () {

	pid_t pid ;

	pid = fork () ;
	
	if ( pid < 0 ) {

		printf("Fork Falied \n ");

		return 1;

	}

	else if (pid == 0) {
		
		printf("Child Process My Pid is :%d \n ",getpid () );

		sleep (20);
		
		printf("Executing The Child Process \n ");

		execlp("/bin/ls","ls",NULL);

		perror ("execlp");

		exit(1);

	}

	else {

		printf("Parent Process : My PID is %d \n",getpid());

		printf("Child Process Sleeping For 20 Seconds \n" );

		wait (NULL);

		printf("Parent Process : child Process Has Terminated \n " ); 


	}

	return 0 ;

}


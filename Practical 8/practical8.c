#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
    int random;
    int status;

    if (argc < 1){
    	printf("Invalid amount of arguments passed.");
	return -1;
    }

    int length = atoi(argv[1]);
    for(int i = 0; i < length; i++){

    // task 1
    pid_t pid = fork();
  
    // error checking
    if (pid < 0) {
        perror("Fork Failed!");
          return -1;
    }

    if(pid == 0){
           printf("Child Process %d: PID = %d\n", i+1, getpid());
           printf("Child's Parent Process %d: PPID = %d\n", i+1, getppid());
    	   
	   random = (rand() % 5) + 1; // randomise 2-4
	   sleep(random);
           int ecall = 10 * i;
           exit(ecall);

    } else {
	   wait(&status);
	   printf("Parent has finished waiting: Child is finished\n");
           printf("Parent Process: PID = %d\n", getpid());
	   if (WIFEXITED(status)) {
		printf("Child Process %d has exited with status of %d\n\n", i+1, WEXITSTATUS(status));
	   } else {
		// error checking if child did not exit properly
	   	psignal(WTERMSIG(status), "Exit Signal");

	   }
    }



    // use wait() or waitpid() to paause parent process until child process terminates
    // getppid() gets its process ID of its parent where getpid() gets process of current process

    // can use WIFEEXITED
    
    // Task 2
  }
}


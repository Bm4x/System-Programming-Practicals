#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
    int random;
    int status;

    if (argc < 2){
    	  printf("Invalid amount of arguments passed.\n");
	      return -1;
    }

    pid_t pid[atoi(argv[1])];

    // first loop to create childen processes (and display info)
    for(int i = 0; i < atoi(argv[1]); i++){
    pid[i] = fork();

    // error checking
    if (pid[i] < 0) {
        perror("Fork Failed!");
          return -1;
    }

    if(pid[i] == 0){
           printf("Child Process %d: PID = %d\n", i+1, getpid());
           printf("Child's Parent Process %d: PPID = %d\n\n", i+1, getppid());
    	   
	         random = (rand() % 5) + 1; // randomise 2-4
	         sleep(random);
           int ecall = 10 * i;
           exit(ecall);

    } 
  }
    // second loop which parents wait for all child processes to finish
    for(int i = 0; i < atoi(argv[1]); i++){
	      waitpid(pid[i], &status, 0);
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
    
    // Task 2
}



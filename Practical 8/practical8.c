#include	<stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char* argv[]){
    int random;
    for(int i = 0; i < 1; i++){
        random = rand() % 10;
        printf("Current Process PID = %d\n", getpid());

        printf("Parent's Child PpID = %d\n", getppid());
        sleep(random);

        pid_t pid = fork();

        if(pid < 0) {
            perror("Fork failed!");
            return -1;
    }
    if(pid == 00){
          printf("Child Process: PID = %d\n", getpid());
          printf("Child Process: PPID = %d\n", getppid());
    } else {

          printf("Parent Process: PID = %d\n", getpid());
    }
    // task 1
    fork();
    sleep(5);
    int ecall = 10 * i;
    exit(ecall);
    // use wait() or waitpid() to paause parent process until child process terminates
    // getppid() gets its process ID of its parent where getpid() gets process of current process

    // can use WIFEEXITED
    
    // Task 2
  }
}

#include	<stdio.h>
#include random


int main(int argc, char* argv[]){
    int random;
    for(int i = 0; i < 2; i++){
        random = rand() % 10;
        printf("current pid = %d\n", getpid());
        sleep(random);
        if(!fork() != 0 ) exit()0;

  }
}

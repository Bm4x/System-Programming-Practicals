#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n){
        if(n == 0 || n == 1) { // base if equals 0 or 1 (function ends)
            return n;
        }
        return fibonacci(n - 1) + fibonacci(n - 2); // general case until it cannot call itself
    }


int main(int argc, char*argv[]){
    printf("Enter size for fibonacci sequence: "); // display
    if(argc == 2){
        int n = atoi(argv[1]); // type in terminal before executing

        // prints fibonacci sequence using fibonacci function
        for(int i  = 0; i < n; i++){
            printf("%d", fibonacci(i));
            printf("\n");
        }
    } 
}
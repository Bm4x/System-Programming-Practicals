#include <stdio.h>
#include <stdlib.h>

/* Comparison function for sorting integers in descending order */
int compare(const void *x, const void *y) {
    int intx = *((int*)x);
    int inty = *((int*)y);

    /* return the result of the comparison value, insert you code here */
    if(intx > inty) return 1;
    if(intx < inty) return -1;

}

int main() {
    int arrint[] = {16, 5, 8, 1, 3, 2};
    int n = 6;

    printf("The array: ");
	/* print the array, insert you code here*/
    for(int i = 0; i < n; i++){
        printf("%d  ", arrint[i]);
    }
    printf("\n"); // adds clarity

    /* Sort the array using qsort(), insert you code here */
    qsort(arrint, n, sizeof(arrint[0]), compare);

    printf("The sorted array: ");

    /* print the sorted array, insert you code here*/
    for(int i = 0; i < n; i++){
        printf("%d  ", arrint[i]);
    }
    return 0;
}
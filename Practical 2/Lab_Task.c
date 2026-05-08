#include <stdio.h>
#include <stdlib.h>

typedef char DATA ;

struct node
{
DATA d ;
struct node * next ;
};

void print(struct node *head){
    struct node *current = head;
    while(current != NULL){
        printf("%c  ", current->d);
        current = current->next;
    }
}

void reverse(struct node **head){
    struct node *prev = NULL;
    struct node *current = *head;
    struct node *next = NULL;
    while (current != NULL){
        next = current->next;
        current->next = prev;

        prev = current;
        current = next;
    }
    *head = prev;
}

int main(){
    struct node *head = NULL;
    
    char list[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9',};

    for(size_t i = 0; i < sizeof(list); i++){
        struct node *newNode = (struct node*)malloc(sizeof(struct node));
        newNode->d = list[i];

        newNode->next = head;

        head = newNode;
        // if(head == NULL){
        //     head = newNode;
        // } else {
        //     temp = head;
        //     while(temp->next != NULL) {
        //         temp = temp->next;
        //     }
        //     temp->next = newNode;
        // }
    }
    printf("Printing List: ");
    print(head);
    
    reverse(&head);
    printf("\nPrinting Reverse List: ");
    print(head);
}
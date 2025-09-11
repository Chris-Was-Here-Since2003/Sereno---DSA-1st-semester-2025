#include <stdio.h>
#include <stdlib.h>
#include "arrayQueue.h"
#include "types.h"

int main() {
    // write your code here
    Queue * reg = initialize();
    Queue *pri = initialize();
    int cnt=0;
    int choice = 0;
    do{
        printf("\n--- Pharmacy Queueing System ---\n");
        printf("1. Enter Regular Queue\n");
        printf("2. Enter Priority Queue\n");
        printf("3. Call Next Customer\n");
        printf("4. Display Queues\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
            if(!isFull(reg)){
                enqueue(reg, ++cnt);
                printf("You have entered the Regular queue. Your number is %d.\n", cnt);
            }
            else{
                printf("Regular queue is full. Please try again later.\n");
            }
            break;
            case 2:
            if(!isFull(pri)){
            enqueue(pri, ++cnt);
            printf("You have entered the Priority queue. Your number is %d.\n", cnt);
            }
            else{
                printf("Priority queue is full. Please try again later.\n");
            }
            break;
            case 3:
            if(!isEmpty(pri)){
                printf("Calling next customer from Priority Queue. Customer number: %d\n", dequeue(pri));
            }else if(!isEmpty(reg)){
                 printf("Calling next customer from Regular Queue. Customer number: %d\n", dequeue(reg));
            }
            else{
                printf("No person on Queue");
            }
            break;
            case 4:
                printf("\n-- Current Queue Status --\n");
                printf("Regular Queue: ");
                display(reg);
                printf("\nPriority Queue: ");
                display(pri);
                printf("\n");
            break;
            case 5:
            printf("Exiting program. Goodbye!");
            break;
            default:
            printf("Invalid Choice.\n\n");
            break;
            
        }
    }while(choice!=5);
    return 0;
}

// Online C compiler to run C program online
#include <stdio.h>
#include <stdbool.h>
#define MAXBIT 8
void initialize(unsigned char *set);
void insert(unsigned char *set, int element);
void delete(unsigned char *set, int element);
bool find(unsigned char set, int element);
unsigned char union_(unsigned char A, unsigned char B);
unsigned char intersection(unsigned char A, unsigned char B);
unsigned char difference(unsigned char A, unsigned char B);
void display(unsigned char set);
int main() {
    unsigned char A, B;
    int choice, element, operation;
    
    initialize(&A);
    initialize(&B);
    
    printf("===== Bit-Vector Set Operations Menu =====\n");
    printf("Maximum elements in set: 0-7\n\n");
    
    do {
        printf("\n===== Main Menu =====\n");
        printf("1. Operations on Set A\n");
        printf("2. Operations on Set B\n");
        printf("3. Set Operations (Union, Intersection, Difference)\n");
        printf("4. Display both sets\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                do {
                    printf("\n--- Set A Operations ---\n");
                    printf("Current Set A: ");
                    display(A);
                    printf("1. Insert element\n");
                    printf("2. Delete element\n");
                    printf("3. Find element\n");
                    printf("4. Back to main menu\n");
                    printf("Enter choice: ");
                    scanf("%d", &operation);
                    
                    switch(operation) {
                        case 1:
                            printf("Enter element to insert (0-7): ");
                            scanf("%d", &element);
                            insert(&A, element);
                            printf("Inserted %d into Set A\n", element);
                            break;
                        case 2:
                            printf("Enter element to delete (0-7): ");
                            scanf("%d", &element);
                            delete(&A, element);
                            printf("Deleted %d from Set A\n", element);
                            break;
                        case 3:
                            printf("Enter element to find (0-7): ");
                            scanf("%d", &element);
                            if(find(A, element))
                                printf("%d is in Set A\n", element);
                            else
                                printf("%d is NOT in Set A\n", element);
                            break;
                        case 4:
                            break;
                        default:
                            printf("Invalid choice\n");
                    }
                } while(operation != 4);
                break;
                
            case 2:
                do {
                    printf("\n--- Set B Operations ---\n");
                    printf("Current Set B: ");
                    display(B);
                    printf("1. Insert element\n");
                    printf("2. Delete element\n");
                    printf("3. Find element\n");
                    printf("4. Back to main menu\n");
                    printf("Enter choice: ");
                    scanf("%d", &operation);
                    
                    switch(operation) {
                        case 1:
                            printf("Enter element to insert (0-7): ");
                            scanf("%d", &element);
                            insert(&B, element);
                            printf("Inserted %d into Set B\n", element);
                            break;
                        case 2:
                            printf("Enter element to delete (0-7): ");
                            scanf("%d", &element);
                            delete(&B, element);
                            printf("Deleted %d from Set B\n", element);
                            break;
                        case 3:
                            printf("Enter element to find (0-7): ");
                            scanf("%d", &element);
                            if(find(B, element))
                                printf("%d is in Set B\n", element);
                            else
                                printf("%d is NOT in Set B\n", element);
                            break;
                        case 4:
                            break;
                        default:
                            printf("Invalid choice\n");
                    }
                } while(operation != 4);
                break;
                
            case 3:
                do {
                    printf("\n--- Set Operations (A and B) ---\n");
                    printf("Set A: ");
                    display(A);
                    printf("Set B: ");
                    display(B);
                    printf("1. Union (A | B)\n");
                    printf("2. Intersection (A & B)\n");
                    printf("3. Difference (A - B)\n");
                    printf("4. Back to main menu\n");
                    printf("Enter choice: ");
                    scanf("%d", &operation);
                    
                    switch(operation) {
                        case 1: {
                            unsigned char result = union_(A, B);
                            printf("Union Result: ");
                            display(result);
                            break;
                        }
                        case 2: {
                            unsigned char result = intersection(A, B);
                            printf("Intersection Result: ");
                            display(result);
                            break;
                        }
                        case 3: {
                            unsigned char result = difference(A, B);
                            printf("Difference Result (A - B): ");
                            display(result);
                            break;
                        }
                        case 4:
                            break;
                        default:
                            printf("Invalid choice\n");
                    }
                } while(operation != 4);
                break;
                
            case 4:
                printf("\n--- Current Sets ---\n");
                printf("Set A: ");
                display(A);
                printf("Set B: ");
                display(B);
                break;
                
            case 5:
                printf("Exiting...\n");
                break;
                
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 5);
    
    return 0;
}
void initialize(unsigned char *set){
    *set = 0;
}
void insert(unsigned char *set, int element){
    if(element>=MAXBIT){
        return;
    }
    *set |= (1 << element);
    return;
}
void delete(unsigned char *set, int element){
    if(element>=MAXBIT){
        return;
    }
     *set &= ~(1 << element);
    return;
}
bool find(unsigned char set, int element){
    if(element>=MAXBIT){
        return false;
    }
    unsigned char mask = 1;
    
  return (set &= mask << element) > 0 ? true : false;
}
unsigned char union_(unsigned char A, unsigned char B){
    return A | B;
}
unsigned char intersection(unsigned char A, unsigned char B){
    return A & B;
}
unsigned char difference(unsigned char A, unsigned char B){
    return A - ~B;
}
void display(unsigned char set){
    unsigned char mask = 1;
    mask <<= MAXBIT-1;
   while(mask!=0){
        if(mask&set){
            printf("1 ");
        }else{
            printf("0 ");
        }
        mask >>= 1;
    }
    
    printf("\n");
}


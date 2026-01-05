// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node*next;
}Node;

typedef struct{
    Node*top;
}List;

List* initialize();
void empty(List *list);
void push(List *list, int value);
int pop(List *list);
int peek(List *list);
void display(List *list);


int main() {
    List *l = initialize();
    for(int i = 0; i < 3; i++){
        insertLast(l, i*10);
    }
    int x;
    int y;
    int z;
    do{
        y = 0;
        z = 0;
        printf("\n==== Linked List Operations Menu ====\n");
        printf("Current List: ");
        display(l);
        printf("Count: %d\n", l->count);
        printf("\nWhat to do?\n");
        printf("1. Push element\n");
        printf("2. Pop element\n");
        printf("3. Peek element\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &x);
        switch(x){
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &y);
                push(l, y);
                break;
            case 2:
                printf("Popped: %d\n", pop(l));
                break;
            case 3:
                printf("Peeked element: %d\n", peek(l));
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Input\n");
                break;
        }
    }while(x != 4);
    empty(l);
    return 0;
}
List* initialize(){
    List * L = (List*)malloc(sizeof(List));
    if(L==NULL){
        printf("Allocation unsuccessful, returning NULL");
        return NULL;
    }
    L->top = NULL;
    L->count = 0;
    return L;
}

void push(List *list, int value){
    Node *new = (Node*)malloc(sizeof(Node));
    new->data=value;
    new->next = list->top;
    list->top = new;
}

int pop(List *list){
    Node*temp = list->top;
    list->top = temp->next;
    int val = temp->data;
    free(temp);
    return val;
}
int peek(List *list){
    if(list->top==NULL){
        printf("List is empty");
        return -1;
    }
    return list->top->data;
}

void display(List *list){
    Node*temp  = list->top;
    for(int i = 0; i < list->count; i++){
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

}

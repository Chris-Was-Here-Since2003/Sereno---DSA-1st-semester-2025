#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct{
int items[MAX];
int top;
}Stack;
Stack* initialize();
void push(Stack* s, int value);
int pop(Stack* s);
int peek(Stack* s);
void display(Stack* s);
int main(){
    Stack *S = initialize();
    int x;
    int y;
    do{
        y = 0;
        printf("\n==== Stack Operations Menu ====\n");
        printf("Stack: ");
        display(S);
        printf("\n\nWhat to do?\n");
        printf("1. Push element\n");
        printf("2. Pop element\n");
        printf("3. Peek top element\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &x);
        switch(x){
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &y);
                push(S, y);
                break;
            case 2:
                printf("Popped: %d\n", pop(S));
                break;
            case 3:
                printf("Top element: %d\n", peek(S));
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Input\n");
                break;
        }
    }while(x != 4);
}

Stack*initialize(){
    Stack*new = (Stack*)malloc(sizeof(Stack));
    new->top = -1;
    return new;
}
void push(Stack*s, int value){
    if(s->top-1==MAX){
        printf("Stack is full!\n");
        return;
    }
    s->items[++s->top]=value;
}
int pop(Stack*s){
    if(s->top==-1){
        printf("Stack is empty!");
    }
return s->items[s->top--];
}

int peek(Stack*s){
    if(s->top==-1){
        printf("Stack is empty!");
    }
    return s->items[s->top];
}

void display(Stack*s){
    if(s->top==-1){
        printf("Stack is empty!");
        return;
    }
    for(int i = s->top; i > 0; i--){
        printf("|%d", s->items[i]);
    }
    printf("|");
}


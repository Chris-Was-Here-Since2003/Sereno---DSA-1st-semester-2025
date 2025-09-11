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
Stack *S=initialize();
for(int i =0; i < 5; i++){
    push(S, i+1);
}
printf("Popping\n");
for(int i = 0; i < 3; i++){
    printf("%d", pop(S));
}

printf("\nPeeking\n");
printf("%d", peek(S));
printf("\n");
display(S);
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


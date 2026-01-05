#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct{
    int items[MAX];
    int count;
}List;
typedef struct{
    List list;
    int front;
    int rear;
}Queue;

Queue* initialize();
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int front(Queue* q);
void display(Queue* q);

int main(){
    Queue *Q = initialize();
    int x;
    int y;
    do{
        y = 0;
        printf("\n==== Queue Operations Menu ====\n");
        printf("Queue: ");
        display(Q);
        printf("\nFront: %d, Rear: %d\n", Q->front, Q->rear);
        printf("\nWhat to do?\n");
        printf("1. Enqueue element\n");
        printf("2. Dequeue element\n");
        printf("3. Peek front element\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &x);
        switch(x){
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &y);
                enqueue(Q, y);
                break;
            case 2:
                printf("Dequeued: %d\n", dequeue(Q));
                break;
            case 3:
                printf("Front element: %d\n", front(Q));
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
Queue* initialize(){
    Queue *Q = (Queue*)malloc(sizeof(Queue));
    Q->list.count = 0;
    Q->front = -1;
    Q->rear = -1;
    return Q;
}
void enqueue(Queue* q, int value){
    if(q->list.count==MAX){
        printf("Queue is FULL!");
        return;
    }
    q->list.items[(q->rear+1)%MAX]=value;
    if(q->list.count==0){
        q->front=0;
        q->rear =0;
    }else{
        q->rear = (q->rear+1)%MAX;
    }
    q->list.count++;
}
int dequeue(Queue* q){
    if(q->list.count==0){
        printf("Queue is empty!");
    }
    int temp = q->list.items[q->front];
    printf("bd: %d\n", q->list.count);
    q->front = (q->front+1)%MAX;
    if(q->list.count==1){
        q->front = -1;
        q->rear = -1;
    }
    q->list.count--;
    printf("ad: %d\n", q->list.count);
    return temp;
}
int front(Queue* q){
    if(q->list.count==0){
        printf("Queue is empty!");
    }
    return q->list.items[q->front];
}
void display(Queue* q){
    for(int i = 0; i < q->list.count; i++){
        printf("%d", q->list.items[q->front+i]%MAX);
    }
    printf("\nCount: %d", q->list.count);
}

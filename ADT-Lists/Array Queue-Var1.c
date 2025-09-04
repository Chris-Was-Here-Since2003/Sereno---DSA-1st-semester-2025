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
    for(int i = 0; i < 8; i++){
        enqueue(Q, i*i);
    }
    display(Q);
    printf("\n");
    for(int i = 0; i < 2; i++){
    printf("removed %d\n",dequeue(Q));
    }
    printf("\n");
    display(Q);
     for(int i = 0; i < 3; i++){
        enqueue(Q, i+1);
    }
    printf("\n");
    display(Q);
    printf("\nFront: %d\n", Q->front);
    printf("Rear: %d\n", Q->rear);
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

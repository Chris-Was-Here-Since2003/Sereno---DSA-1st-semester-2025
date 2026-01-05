// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node*next;
}Node;

typedef struct{
    Node*front;
    Node*rear;
}Queue;

Queue* initialize();
void enqueue(Queue *queue, int value);
int dequeue(Queue *queue);
bool isEmpty(Queue* queue);
bool isFull(Queue* q);
int front(Queue *queue);
void display(Queue *queue);

int main() {
    Queue *Q = initialize();
    for(int i = 0; i < 3; i++){
        enqueue(Q, i*10);
    }
    int x;
    int y;
    do{
        y = 0;
        printf("\n==== Queue Operations Menu ====\n");
        printf("Queue: ");
        display(Q);
        printf("\nFront: %d, Rear: %d\n", Q->front->data, Q->rear->data);
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

void enqueue(Queue *queue, int value){
    Node *new = (Node*)malloc(sizeof(Node));
    new->data=value;
    new->next = queue-front;
    queue->front->next = new;

    queue->rear = new;
}

int dequeue(Queue *queue){
    Node*temp = queue->front;
    int val = temp->data;
    queue->front = temp->next;
    free(temp);
    return val;
}
int front(Queue *queue){
    if(queue->front==NULL){
        printf("Queue is empty");
        return -1;
    }
    return queue->front->data;
}

void display(Queue *queue){
    Node*temp  = queue->front;
    for(int i = 0; i < queue->count; i++){
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

}

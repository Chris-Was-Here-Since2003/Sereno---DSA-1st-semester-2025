// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node*next;
}Node;

typedef struct{
    Node*head;
    int count;
}List;

List* initialize();
void empty(List *list);
void insertFirst(List *list, int data);
void insertLast(List *list, int data);
void insertPos(List *list, int data, int index);
void deleteStart(List *list);
void deleteLast(List *list);
void deletePos(List *list, int index);
int retrieve(List *list, int index);
int locate(List *list, int data);
void display(List *list);


int main() {
    List *l = initialize();
    printf("Initiallization + insertion\n");
    insertFirst(l, 24);
    for(int i = 1; i < 8; i++){
        insertPos(l, i*i, i);
    }
    display(l);
    printf("\n%d\n", l->count);
    
    deleteStart(l);
    display(l);printf("\n");
    deleteLast(l);
    display(l);
    for(int i = 1; i < 4; i++){
        deletePos(l, i);
    }
    display(l);
    printf("%d\n", l->count);
    printf("At 2: %d\n", retrieve(l, 2));
      printf("At 0: %d\n", retrieve(l, 0));
    for(int i = 10; i < 18; i++){
        insertLast(l, i*i);
    }
    printf("refiling data set...\n");
    printf("new data set:");
    display(l);
    printf("locating...\n");
    printf("100 is at %d\n", locate(l, 100));
    printf("1 is at %d\n", locate(l, 1));
    printf("289 is at %d\n", locate(l, 289));
    printf("1000 is at %d\n", locate(l, 1000));
    printf("%d\n", l->count);
    printf("retrieving...\n");
    printf("1 is %d\n", retrieve(l, 1));
    printf("10 is %d\n", retrieve(l, 10));
    printf("5 is %d\n", retrieve(l, 5));
    printf("20 is %d\n", retrieve(l, 20));
    return 0;
}
List* initialize(){
    List * L = (List*)malloc(sizeof(List));
    if(L==NULL){
        printf("Allocation unsuccessful, returning NULL");
        return NULL;
    }
    L->head = NULL;
    L->count = 0;
    return L;
}
void empty(List *list){
    Node *temp  = list->head;
    Node *nxt;
    while(temp!=NULL){
        nxt = temp->next;
        free(temp);
        temp = nxt;
    }
    list->count = 0;
    free(list);
    
}
void insertFirst(List *list, int data){
    Node *new = (Node*)malloc(sizeof(Node));
    new->data=data;
    new->next = list->head;
    list->head = new;
    list->count++;
}
void insertLast(List *list, int data){
    Node *new = (Node*)malloc(sizeof(Node));
    new->data=data;
    new->next = NULL;
    Node*temp = list->head;
    if(temp==NULL){
        insertFirst(list, data);
        return;
    }
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = new;
    list->count++;
}
void insertPos(List *list, int data, int index){
    if(index>list->count){
        printf("Invalid index");
        return;
    }
    Node *new = (Node*)malloc(sizeof(Node));
    new->data=data;
    if(index==0){
        insertFirst(list, data);
        return;
    }
    if(index==list->count){
        insertLast(list, data);
        return;
    }
    list->count++;
    Node*temp= list->head;
    for(int i = 0; i < index; i++){
        temp = temp->next;
    }
    new->next = temp->next;
    temp->next = new;//insertion process
    
}
void deleteStart(List *list){
    Node*temp = list->head;
    list->head = temp->next;
    list->count--;
    free(temp);
}
void deleteLast(List *list){
    Node*temp = list->head;
    if(temp->next==NULL){//activates if only one data
        deleteStart(list);
        return;
    }
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    Node*byebye = temp->next;
    temp->next=NULL;
    list->count--;
    free(byebye);
}
void deletePos(List *list, int index){
    if(index>list->count){
        printf("Invalid Position");
        return;
    }
    if(index==0){
    deleteStart(list);
    return;
    }
    if(index==list->count){
    deleteLast(list);
    return;
    }
    list->count--;
    Node*temp= list->head;
    for(int i = 0; i < index-1; i++){
        temp = temp->next;//traverse to before index
    }
   Node*byebye = temp->next;
    temp->next = temp->next->next;
    free(byebye);
}
int retrieve(List *list, int index){
    if(index>list->count){
        printf("Invalid index");
        return 80084;
    }
    Node*temp = list->head;
    for(int i = 0; i < index; i++){
        temp = temp->next;
    }
    return temp->data;
}
int locate(List *list, int data){
    int index = 0;
    Node*temp = list->head;
   while(temp!=NULL){
        if(data==temp->data){
            return index;
        }
        index++;
        temp = temp->next;
    }
    return -1;
    
}
void display(List *list){
    Node*temp  = list->head;
    for(int i = 0; i < list->count; i++){
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

}


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
        printf("1. Insert at start\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete from start\n");
        printf("5. Delete from end\n");
        printf("6. Delete at position\n");
        printf("7. Retrieve element at position\n");
        printf("8. Locate element\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &x);
        switch(x){
            case 1:
                printf("Enter value to insert at start: ");
                scanf("%d", &y);
                insertFirst(l, y);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &y);
                insertLast(l, y);
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &y);
                printf("Enter position: ");
                scanf("%d", &z);
                insertPos(l, y, z);
                break;
            case 4:
                deleteStart(l);
                printf("Deleted from start\n");
                break;
            case 5:
                deleteLast(l);
                printf("Deleted from end\n");
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &y);
                deletePos(l, y);
                break;
            case 7:
                printf("Enter position to retrieve: ");
                scanf("%d", &y);
                int ret = retrieve(l, y);
                if(ret != 80084){
                    printf("Retrieved value at position %d: %d\n", y, ret);
                }
                break;
            case 8:
                printf("Enter value to locate: ");
                scanf("%d", &y);
                int loc = locate(l, y);
                if(loc == -1)
                    printf("%d not found\n", y);
                else
                    printf("%d is at position %d\n", y, loc);
                break;
            case 9:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Input\n");
                break;
        }
    }while(x != 9);
    empty(l);
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
    list->head = NULL;
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
    for(int i = 0; i < index-1; i++){
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
    if(index>=list->count){
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

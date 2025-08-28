#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct List{
    int data[MAX];
    int count;
}Etype, *EPtr;

void initialize(EPtr L){
    L->count = 0;
    return;
}
void insertPos(EPtr L, int data, int position){
    if(L->count >= MAX){
        printf("Array is full");
        return;
    }//case where array is full
    if(L->count < position){
        printf("Invalid insertPos:\n");
        return;
    }//case where position is greater/equal to position
    int temp = data;
    data = L->data[position];//switch data and position of data
    L->data[position] = temp;
    
    for(int i = position+1; i < L->count+1; i++){
        temp = data;
        data = L->data[i];//keep switching data and temp until count
        L->data[i] = temp;
    }
    
    L->count++;
    return;//code success
}
void deletePos(EPtr L, int position)
{
    if(L->count<=position){
        printf("Invalid deletePos:\n");
        return;
    }
     if(L->count==position){
        L->count--;
        return;
    }
    for(int i = position; i < L->count; i++){//increment till count
        L->data[i]= L->data[i+1];
    }
    L->count--;
    return;//works for now
}
int locate(EPtr L, int data){
    int booly = -1;
    for(int i = 0; i < L->count; i++){
        if(L->data[i]==data){
            booly = i;
        }
    }
    return booly;
}
int retrieve(EPtr L, int position){
    if(L->count <= position){
        printf("Out of Bounds");
        return 0;
    }
    return L->data[position];
}
void insertSorted(EPtr L, int data){
     if(data > L->data[L->count-1]){
        insertPos(L, data, L->count);//case where data is larger than final
        return;
    }
    for(int i = 0; i < L->count; i++){
        if(data < L->data[i]){
            insertPos(L, data, i);
            break;
        }
    }
    return;
}
void display(EPtr L){
      for(int i = 0; i < L->count; i++){
        printf("%d -> ", L->data[i]);
    }
}
void makeNULL(EPtr L){
    free(L);
    L=NULL;
    return;
}

int main(){
    
    EPtr L = (EPtr)malloc(sizeof(Etype));
    display(L);
    printf("\n");
    initialize(L);
    for(int i = 0; i < 5; i++){
        insertPos(L, 50 + i*i, i);
    }
    insertPos(L, 666, 5);
    insertPos(L, 999, 5);
    insertPos(L, 777, 5);
    printf("Insert test: \n");
    display(L);//case for insert
    printf("\nCOUNT: %d", L->count);
    deletePos(L, 5);
    deletePos(L, 5);
    deletePos(L, 5);
    printf("\nDELETE: \n");
    display(L);
    printf("\nCOUNT: %d", L->count);
    printf("\nLocate List: 114 -> %d", locate(L, 114));
    printf("\nLocate List: 99 -> %d", locate(L, 99));
    printf("\nRetrieve List(3): %d", retrieve(L, 3));
    printf("\nRetrieve List(4): %d", retrieve(L, 4));
    printf("\nCOUNT: %d\n", L->count);
    display(L);
    insertSorted(L, 55);
    printf("\ninsert sorted:\n");
    display(L);
    printf("\nCOUNT: %d\n", L->count);
    makeNULL(L);
    display(L);
    printf("\n");
    display(L);
}

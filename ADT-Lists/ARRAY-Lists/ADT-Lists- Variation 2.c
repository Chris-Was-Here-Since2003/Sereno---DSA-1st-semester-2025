#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct List{
    int data[MAX];
    int count;
}Etype, *EPtr;//Note: This is var 2. If in wrong file. Oh noes.

void initialize(EPtr L);
void insertPos(EPtr L, int data, int position);
void deletePos(EPtr L, int position);
int locate(EPtr L, int data);
int retrieve(EPtr L, int position);
void insertSorted(EPtr L, int data);
void display(EPtr L);
void makeNULL(EPtr L);


int main(){
    
    EPtr L = (EPtr)malloc(sizeof(Etype));
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
    printf("\nLocate List: 50 -> %d", locate(L, 50));
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
void insertPos(EPtr L, int data, int position){
    if(L->count >= MAX){
        printf("Array is full");
        return;//array must not be full
    }//case where array is full
    if(L->count < position){
        printf("Invalid insertPos:\n");//check for valid position
        return;
    }//case where position is greater/equal to position
    int temp = data;
    data = L->data[position];//Insert element into specified position
    L->data[position] = temp;
    
    for(int i = position+1; i < L->count+1; i++){
        temp = data;
        data = L->data[i];//shift elements to the right
        L->data[i] = temp;
    }
    
    L->count++;//increment count
    return;//code success
}
void deletePos(EPtr L, int position)
{
    if(L->count<position){
        printf("Invalid deletePos:\n");
        return;//position must be valid
    }
     if(L->count==position){
        L->count--;//decrement count
        return;
    }
    for(int i = position; i < L->count; i++){//increment till count
        L->data[i]= L->data[i+1];//shift elements to the right
    }
    L->count--;//decrement count
    return;//works for now
}
int locate(EPtr L, int data){
    int booly = -1;//if data not found, return -1
    for(int i = 0; i < L->count; i++){
        if(L->data[i]==data){
            booly = i;//loop through array til found
        }
    }
    return booly;
}
int retrieve(EPtr L, int position){
    if(L->count < position){
        printf("Out of Bounds");//position must be valid
        return 0;
    }
    return L->data[position];//return elem located in given position
}
void insertSorted(EPtr L, int data){
     if(data > L->data[L->count-1]){
        insertPos(L, data, L->count);//case where data is larger than final, insertPos handles array checking
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
    L->count = 0;//set count to 0
    for(int i = 0; i<L->count; i++){
        L->data[i] = 0;
    }
    free(L);
    L=NULL;
    return;
}
void initialize(EPtr L){
    L->count = 0;//set count to zero
    return;
}


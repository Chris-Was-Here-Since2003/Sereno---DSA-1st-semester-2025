#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct List{
    int data[MAX];
    int count;
}Etype, *EPtr;
void initialize(EPtr L){
    L->count = 0;

}
void insertPos(EPtr L, int data, int position){
    if(L->count >= MAX){
        printf("Array is full");
        return L;
    }//case where array is full
    if(L->count <= position){
        L->data[L->count] = data;//case where position is greater than count
        L->count++;
        return  L;
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
    return L;//code success
}
void deletePos(EPtr L, int position);
int locate(EPtr L, int data);
int retrieve(EPtr L, int position);
void insertSorted(EPtr L, int data);
void display(EPtr L);
void makeNULL(EPtr L);

int main(){
    EPtr L;
    initialize(L);
    for(int i = 0; i < 5; i++){
        insertPos(L, 50 + i*i, i);
    }
}

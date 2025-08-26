#include <stdio.h>
#include <stdlib.h>
#define MAX 16
typedef struct List{
    int data[MAX];
    int count;
}List;

List initialize(List L){
    L.count = 0;
    return L;//code success
}
List insertPos(List L, int data, int position){
    if(L.count >= MAX){
        printf("Array is full");
        return L;
    }//case where array is full
    if(L.count <= position){
        L.data[L.count] = data;//case where position is greater than count
        L.count++;
        return  L;
    }//case where position is greater/equal to position
    int temp = data;
    data = L.data[position];//switch data and position of data
    L.data[position] = temp;
    
    for(int i = position+1; i < L.count+1; i++){
        temp = data;
        data = L.data[i];//keep switching data and temp until count
        L.data[i] = temp;
    }
    
    L.count++;
    return L;//code success
}
List deletePos(List L, int position){
    if(L.count==position){
        
    }
}
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L){
    for(int i = 0; i < L.count; i++){
        printf("%d -> ", L.data[i]);
    }
}

int main(){
    List L = initialize(L);
    for(int i = 0; i < 10; i++){
        L = insertPos(L, 50+i - i*i, i);
    }
    display(L);
    L=insertPos(L, 666, 5);
    L=insertPos(L, 999, 5);
    L=insertPos(L, 777, 5);
    printf("\n");
    display(L);//case for insert
    
    
    
}


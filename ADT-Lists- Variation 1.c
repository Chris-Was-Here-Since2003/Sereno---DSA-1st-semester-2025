#include <stdio.h>
#include <stdlib.h>
#define MAX 16
typedef struct List{
    int data[MAX];
    int count;
}List;

List initialize(List L){
    L.count = 0;
    return L;
}
List insertPos(List L, int data, int position){
    if(L.count >= MAX){
        printf("Array is full");
        return L;
    }
    if(L.count-1 < position){
        L.data[L.count] = data;//case where position is greater than count
        L.count++;
        return  L;
    }
    int temp = data;
    data = L.data[position];//switch data and position of data
    L.data[position] = temp;
    for(int i = position+1; i < L.count; i++){
        temp = data;
        data = L.data[i];//keep switching data and temp until count
        L.data[i] = temp;
    }
}
List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L);

int main(){
    List L = initialize(L);
    if(L.count==0){
        printf("success");
    }
}


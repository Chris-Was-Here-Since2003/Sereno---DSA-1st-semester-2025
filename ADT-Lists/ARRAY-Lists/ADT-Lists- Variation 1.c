#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct List{
    int data[MAX];
    int count;
}List;//Note: This is Var1, if in wrong file, rip 

List initialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L);


int main(){
    List L = initialize(L);
    for(int i = 0; i < 5; i++){
        L = insertPos(L, 50 + i*i, i);
    }
    printf("Original Case: \n");
    display(L);
    L=insertPos(L, 666, 5);
    L=insertPos(L, 999, 5);
    L=insertPos(L, 777, 5);
    printf("\nInsert test: \n");
    display(L);//case for insert
    printf("\nCOUNT: %d", L.count);
    L = deletePos(L, 5);
    L = deletePos(L, 5);
    L = deletePos(L, 5);
    printf("\nDELETE: \n");
    display(L);
    printf("\nCOUNT: %d", L.count);
    printf("\nLocate List: 66 -> %d", locate(L, 66));
    printf("\nLocate List: 50 -> %d", locate(L, 50));
    printf("\nLocate List: 777 -> %d", locate(L, 777));
    printf("\nCOUNT: %d", L.count);
    L = insertSorted(L, 55);
    printf("\ninsert sorted 55:\n");
    display(L);
    printf("\nCOUNT: %d", L.count);   
}

List initialize(List L){
    L.count = 0;
    return L;//code success
}
List insertPos(List L, int data, int position){
    if(L.count >= MAX){
        printf("Array is full");
        return L;
    }//case where array is full
    if(L.count < position){
        printf("Invalid Insertpos: %d > %d\n", position, L.count);
        return  L;
    }//case where position is greater/equal to position
    int temp = data;
    data = L.data[position];//switch data and position of data
    L.data[position] = temp;
    
    for(int i = position+1; i < L.count+1; i++){
        temp = data;
        data = L.data[i];//shifting to the right
        L.data[i] = temp;
    }
    
    L.count++;
    return L;//code success
}
List deletePos(List L, int position){
     if(L.count<position){
        printf("Invalid deletePos:\n");
        return L;
    }
    for(int i = position; i < L.count; i++){//increment till count
        L.data[i]= L.data[i+1];
    }
    L.count--;//decrement count
    return L;//return modified List
}
int locate(List L, int data){
    int booly = -1;//-1 = not found
    for(int i = 0; i < L.count; i++){
        if(L.data[i]==data){
            booly = i;
        }
    }
    return booly;
}
List insertSorted(List L, int data){
    if(data > L.data[L.count-1]){
        L =  insertPos(L, data, L.count);//case where data is larger than final
        return L;
    }
    for(int i = 0; i < L.count; i++){
        if(data < L.data[i]){
            L =  insertPos(L, data, i);//insert element into correct value
            break;
        }
    }
    return L;//return modified list
}
void display(List L){
    for(int i = 0; i < L.count; i++){
        printf("%d -> ", L.data[i]);
    }
}


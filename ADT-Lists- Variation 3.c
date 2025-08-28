// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct List{
    int *data;
    int count;
    int max;
}List;

List resize(List L){
    L.max*=2;
    printf("New max: %d\n", L.max);
    int*temp =(int*)realloc(L.data, sizeof(int) * L.max);
    if(temp==NULL){
        printf("ALLOCATION FAILED");
        return L;
    }
    L.data = temp;
    return L;
}
List initialize(List L){
    L.data = (int*)malloc(sizeof(int)*MAX);
    L.count = 0;
    L.max = MAX;
    return L;
}
List insertPos(List L, int data, int position){
    if(L.count >= L.max){
        L = resize(L);
    }//case where array is full
    if(L.count < position){
        printf("Invalid InsertPos\n");
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
        L.count--;
        return L;
    }
    for(int i = position; i < L.count; i++){//increment till count
        L.data[i]= L.data[i+1];
    }
    L.count--;
    return L;//works for now
}
int locate(List L, int data){
        int booly = -1;
    for(int i = 0; i < L.count; i++){
        if(L.data[i]==data){
            booly = i;
        }
    }
    return booly;
}
List  insertSorted(List L, int data){
     if(data > L.data[L.count-1]){
        L =  insertPos(L, data, L.count);//case where data is larger than final
        return L;
    }
    for(int i = 0; i < L.count; i++){
        if(data < L.data[i]){
            L =  insertPos(L, data, i);
            break;
        }
    }
    return L;
}
void display(List L){
        for(int i = 0; i < L.count; i++){
        printf("%d -> ", L.data[i]);
    }
}



int main() {
     List L = initialize(L);
    for(int i = 0; i < 20; i++){
        L = insertPos(L, 50 + i*i, i);
    }
    printf("Original Case: \n");
    display(L);
    printf("\nInserting new...\n");
    L=insertPos(L, 666, 5);
    L=insertPos(L, 999, 5);
    L=insertPos(L, 777, 5);
    printf("Insert test result: \n");
    display(L);//case for insert
    printf("\nCOUNT: %d", L.count);
    L = deletePos(L, 5);
    L = deletePos(L, 5);
    L = deletePos(L, 5);
    printf("\nDELETE: \n");
    display(L);
    printf("\nCOUNT: %d", L.count);
    printf("\nLocate List: 114 -> %d", locate(L, 114));
    printf("\nLocate List: 99 -> %d", locate(L, 99));
    printf("\nLocate List: 777 -> %d", locate(L, 777));
    printf("\nCOUNT: %d", L.count);
    L = insertSorted(L, 55);
    printf("\ninsert sorted:\n");
    display(L);
    printf("\nCOUNT: %d", L.count);
    
}
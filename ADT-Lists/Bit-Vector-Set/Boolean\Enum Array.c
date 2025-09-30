// Online C compiler to run C program online
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define ARRAY_SIZE 8
typedef bool Set[ARRAY_SIZE];

void initialize(Set set);
void insert(Set set, int element);
void delete(Set set, int element);
bool find(Set set, int element);
void union_(Set A, Set B, Set C);
void intersection(Set A, Set B, Set C);
void difference(Set A, Set B, Set C);
void display(Set set);


int main() {
    Set x;
    Set y;
    Set z;
    initialize(x);
    initialize(z);
    
    insert(x, 0);
    display(x);
    
    insert(x, 5);
    insert(x, 7);
    delete(x, 0);
    display(x);
    
    insert(y, 1);
    insert(y, 6);
    display(y);
    
    insert(y, 7);
    display(x);
    display(y);
    
    union_(x, y, z);
    display(z);
    
    difference(x,y,z);
    display(z);
    
    intersection(x, y, z);
    display(z);
    return 0;
}
void initialize(Set set){
    for(int i = 0; i < ARRAY_SIZE; i++){
        set[i]=false;
    }
}
void insert(Set set, int element){
    if(element >=ARRAY_SIZE){
        return;
    }
    *&set[element] = true;
}
void delete(Set set, int element){
    if(element >=ARRAY_SIZE){
        return;
    }
    *&set[element] = false;
}
bool find(Set set, int element){
    if(element >=ARRAY_SIZE){
        return false;
    }
    return set[element];
}
void union_(Set A, Set B, Set C){
    Set temp;
    initialize(temp);
    for(int i = 0; i < ARRAY_SIZE; i++){
        temp[i] = A[i] | B[i];
    }
    C= temp;
}
void intersection(Set A, Set B, Set C){
    Set temp;
    initialize(temp);
    for(int i = 0; i < ARRAY_SIZE; i++){
        temp[i] = A[i] & B[i];
    }
    C= temp;
}
void difference(Set A, Set B, Set C){
    Set temp;
    initialize(temp);
    for(int i = 0; i < ARRAY_SIZE; i++){
        temp[i] = A[i] - ~(B[i]);
    }
    C=temp;
}
void display(Set set){
  for(int i = 0; i < ARRAY_SIZE;i++){
        if(set[ARRAY_SIZE-i-1]){
            printf("1 ");
        }else{
            printf("0 ");
        }
    }
    
    printf("\n");
}

// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#define MAX 20
typedef struct baby{
    int elem;
    int next;
}Cell, Heapspace[MAX];

typedef struct head{
    Heapspace H;
    int avail;
}VHeap;//note to self, avail is index, L is head
void initialize(VHeap *V){
    V = (VHeap*)malloc(sizeof(VHeap));
    V->avail = 0;
    for(int i = 0; i < MAX-1; i++){
        **(V->H[i].next) = i+1;
        printf("%d\n",   V->H[i].next);
    }
    V->H[MAX-1].next=-1;
    
}
int allocSpace(VHeap* V){
    int ret = V->avail;
    V->avail = V->H[ret].next;
    printf("%d = %d", V->avail,  V->H[ret].next);
    return ret;
}
void deallocSpace(VHeap* V, int index){
  return;
    
}
void insertFirst(int* L, VHeap* V, int elem){
    int newCell = allocSpace(V);//check available space to insert;
    if(newCell!=-1){
    V->H[newCell].elem = elem;
    V->H[newCell].next = *L;//L is pointer to first node
    *L = newCell;//set newCell index to be head
    }
}
void insertLast(int* L, VHeap* V, int elem){
    int newCell = allocSpace(V);
    V->H[newCell].elem = elem;
    V->H[newCell].next = -1;
    int *trav = L;
    while(*trav!=-1){
        trav = &V->H[*trav].next;//here, trav is no longer L, but the NEXT
    }
    *trav = newCell;//set next of trav to newCell
    
    
}
void insertSorted(int* L, VHeap* V, int elem);
void delete(int* L, VHeap* V, int elem);
void deleteAllOccurrence(int* L, VHeap* V, int elem);
void display(int L, VHeap V){
    int trav = L;
    while(trav!=-1){
        printf("%d->", V.H[trav].elem);
        trav = V.H[trav].next;//here, value of trav is next
    }
}


int main() {
    // Write C code here
    printf("Try programiz.pro\n");
    VHeap *V;
    initialize(V);
    int L = -1;
    insertFirst(&L, V, 3);

    
    return 0;
}

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
    V->avail = 0;
    for(int i = 0; i < MAX-1; i++){
        V->H[i].next = i+1;
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
    V->H[index].next = V->avail;
    V->avail = index;
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
void insertSorted(int* L, VHeap* V, int elem){

}
void delete(int* L, VHeap* V, int elem){
        int trav = L;
    while(trav!=-1){
        if(V.H[V.H[trav].next].elem == elem){
            V.H[trav].next = V.H[V.H[trav].next].next;
            return;
        }
        trav = V.H[trav].next;//here, value of trav is next
    }
}
void deleteAllOccurrence(int* L, VHeap* V, int elem){
    int trav = L;
    while(trav!=-1){
        if(V.H[V.H[trav].next].elem  == elem){
            V.H[trav].next = V.H[V.H[trav].next].next;
        }
        trav = V.H[trav].next;//here, value of trav is next
    }
}
void display(int L, VHeap V){
    int trav = L;
    while(trav!=-1){
        printf("%d->", V.H[trav].elem);
        trav = V.H[trav].next;//here, value of trav is next
    }
}


int main() {
    VHeap *V = (VHeap*)malloc(sizeof(VHeap));
    initialize(V);
    int L = -1;
    int x;
    int elem;
    
    do {
        printf("\n===== Cursor-Based List (Heap) Menu =====\n");
        printf("List: ");
        display(L, *V);
        printf("\nAvailable Space Index: %d\n", V->avail);
        printf("\nOperations:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Display list\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &x);
        
        switch(x) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &elem);
                insertFirst(&L, V, elem);
                printf("Inserted %d at beginning\n", elem);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &elem);
                insertLast(&L, V, elem);
                printf("Inserted %d at end\n", elem);
                break;
            case 3:
                printf("Current List: ");
                display(L, *V);
                printf("\n");
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(x != 4);
    
    free(V);
    return 0;
}

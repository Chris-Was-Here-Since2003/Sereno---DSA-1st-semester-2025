#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10
typedef struct List{
    int *data;
    int count;
    int max;
}List;//This is var 4, make sure this doesn't get lost
void initialize(List *L);
void insertPos(List *L, int data, int position);
void deletePos(List *L, int position);
int locate(List *L, int data);
int retrieve(List *L, int position);
void insertSorted(List *L, int data);
void display(List *L);
void resize(List *L);
void makeNULL(List *L);
int main(){
    List* L = (List*)malloc(sizeof(List));
    initialize(L);
    for(int i = 0; i < 5; i++){
        insertPos(L, 50 + i*i, i);
    }
    int x;
    int y;
    int z;
    do{
        y = 0;
        z = 0;
        printf("\n==== List Operations Menu ====\n");
        printf("Current List: \n");
        display(L);
        printf("\nCount: %d\n", L->count);
        printf("\nWhat to do?\n");
        printf("1. Insert at position\n");
        printf("2. Insert sorted\n");
        printf("3. Delete at position\n");
        printf("4. Locate element\n");
        printf("5. Retrieve element at position\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &x);
        switch(x){
            case 1:
                printf("Enter digit to insert: ");
                scanf("%d", &y);
                printf("Enter position to insert: ");
                scanf("%d", &z);
                insertPos(L, y, z);
                break;
            case 2:
                printf("Enter digit to insert in sorted order: ");
                scanf("%d", &y);
                insertSorted(L, y);
                break;
            case 3:
                printf("Enter position to delete: ");
                scanf("%d", &y);
                deletePos(L, y);
                break;
            case 4:
                printf("Enter digit to locate: ");
                scanf("%d", &y);
                int loc = locate(L, y);
                if(loc == -1)
                    printf("%d not found\n", y);
                else
                    printf("Location of %d is %d\n", y, loc);
                break;
            case 5:
                printf("Enter position to retrieve: ");
                scanf("%d", &y);
                int ret = retrieve(L, y);
                if(ret != 0){
                    printf("Retrieved value: %d\n", ret);
                }
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Input\n");
                break;
        }
    }while(x != 6);
    makeNULL(L);
}
//functions start here
void initialize(List* L){
    L->data = (int*)malloc(sizeof(int)*LENGTH);//dynamic allocation using length
    L->max = LENGTH;//set max to defined LENGTH
    L->count = 0;//set count to 0
    return;
}
void insertPos(List* L, int data, int position){
    if(L->count < position){
    printf("Invalid insertPos:\n");
    return;
    }//case where position is not valid
    
    if(L->count >= L->max){
        resize(L);
    }//case where array is full

    int temp = data;
    data = L->data[position];//insert into position
    L->data[position] = temp;
    
    for(int i = position+1; i < L->count+1; i++){
        temp = data;
        data = L->data[i];//shifting to the right
        L->data[i] = temp;
    }
    
    L->count++;//increment count
    return;//code success
}
void deletePos(List* L, int position)
{
    if(L->count<position){
        printf("Invalid deletePos:\n");
        return;//position must be valid
    }
    for(int i = position; i < L->count; i++){//shift to the right
        L->data[i]= L->data[i+1];
    }
    L->count--;//decrement count
    return;//works for now
}
int locate(List* L, int data){
    int booly = -1;//set if not found
    for(int i = 0; i < L->count; i++){
        if(L->data[i]==data){
            booly = i;//i is position
        }
    }
    return booly;
}
int retrieve(List* L, int position){
    if(L->count <= position){
        printf("Out of Bounds");
        return 0;
    }
    return L->data[position];
}
void insertSorted(List* L, int data){
     if(data > L->data[L->count-1]){
        insertPos(L, data, L->count);//case where data is larger than final, insertPos takes care of array checking
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
void display(List* L){
      for(int i = 0; i < L->count; i++){
        printf("%d -> ", L->data[i]);
    }
}
void makeNULL(List* L){
    L->count = 0;
    for(int i = 0; i<L->count; i++){
    L->data[i] = 0;
    }
    free(L);
    L=NULL;
    return;
}

void resize(List* L){
    L->max*=2;
    printf("New max: %d\n", L->max);
    int*temp =(int*)realloc(L->data, sizeof(int) * L->max);
    if(temp==NULL){
        printf("ALLOCATION FAILED");
        return;
    }
    L->data = temp;
}


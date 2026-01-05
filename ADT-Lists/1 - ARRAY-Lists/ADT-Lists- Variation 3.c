#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10
typedef struct List{
    int *data;
    int count;
    int max;
}List;//This is variation 3, if this is found on another found, rip;

//function prototype
List initialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List  insertSorted(List L, int data);
void display(List L);
List resize(List L);

int main() {
    List L = initialize(L);
    for(int i = 0; i < 5; i++){
        L = insertPos(L, 50 + i*i, i);
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
        printf("\nCount: %d\n", L.count);
        printf("\nWhat to do?\n");
        printf("1. Insert at position\n");
        printf("2. Insert sorted\n");
        printf("3. Delete at position\n");
        printf("4. Locate element\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &x);
        switch(x){
            case 1:
                printf("Enter digit to insert: ");
                scanf("%d", &y);
                printf("Enter position to insert: ");
                scanf("%d", &z);
                L = insertPos(L, y, z);
                break;
            case 2:
                printf("Enter digit to insert in sorted order: ");
                scanf("%d", &y);
                L = insertSorted(L, y);
                break;
            case 3:
                printf("Enter position to delete: ");
                scanf("%d", &y);
                L = deletePos(L, y);
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
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Input\n");
                break;
        }
    }while(x != 5);
}
//functions start here
List initialize(List L){
    L.data = (int*)malloc(sizeof(int)*LENGTH);//Dynamically allocate memory 
    L.count = 0;//set count to 0
    L.max = LENGTH;//set max to defined length
    return L;//return list
}
List insertPos(List L, int data, int position){
    if(L.count >= L.max){
        L = resize(L);
    }//case where array is full, calling resize function
    if(L.count < position){
        printf("Invalid InsertPos\n");
        return  L;
    }//case where position is not valid
    int temp = data;
    data = L.data[position];//inserting element at specified position
    L.data[position] = temp;
    
    for(int i = position+1; i < L.count+1; i++){
        temp = data;
        data = L.data[i];//shifting elements to the right
        L.data[i] = temp;
    }
    
    L.count++;//increment count
    return L;//return modified list
}
List deletePos(List L, int position){
    if(L.count < position){
        printf("Invalid Position");
        return List;
    }
    for(int i = position; i < L.count; i++){//shifting to the right
        L.data[i]= L.data[i+1];
    }
    L.count--;//decerement count
    return L;//return modified List
}
int locate(List L, int data){
        int booly = -1;//return this if not found
    for(int i = 0; i < L.count; i++){
        if(L.data[i]==data){
            booly = i;
        }
    }
    return booly;
}
List  insertSorted(List L, int data){
     if(data > L.data[L.count-1]){
        L =  insertPos(L, data, L.count);//case where data is larger than final, insertPos takes care of array checking
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
List resize(List L){
    L.max*=2;
    printf("Max Updated: %d\n", L.max);
    int*temp =(int*)realloc(L.data, sizeof(int) * L.max);
    if(temp==NULL){
        printf("ALLOCATION FAILED");
        return L;//just to check
    }
    L.data = temp;
    return L;
}



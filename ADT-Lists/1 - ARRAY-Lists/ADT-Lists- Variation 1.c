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
    int x;
    int y;
    int z;
    do{
    y=0;
    z=0;
    printf("\n==== List Operations Menu ====\n");
    printf("Current List: \n");
    display(L);
    printf("What to do?");
    printf("1. Insert at Position\n");
    printf("2. Delete at Position\n");
    printf("3. Locate\n");
    printf("4. exit\n");
    scanf("%d", &x);
    switch(x){
        case 1:
            printf("Enter digit to insert.\n")
            scanf("%d", &y);
            printf("Enter position to insert.\n")
            scanf("%d", &z);
            L = insertPos(L, y, z);
            break;
        case 2:
            printf("Enter position to delete.\n");
            scanf("%d", &y);
            L = deletePos(L, y);
            break;
        case 3:
            printf("Enter digit to locate.\n");
            scanf("%d", &y);
            int loc = locate(L, y);
            if(loc == -1)
                printf("%d not found\n", y);
            else{
            printf("Location of %d is %d\n", y, loc);
            }
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid Input\n");
            break;

        
    }

    }while(x != 4);
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


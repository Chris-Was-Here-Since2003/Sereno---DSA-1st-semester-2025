#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct Node{
    char* key;
    struct Node* next;
}Node;

typedef struct HashTable{
    Node** table;
}HashTable;

int hash(const char* str){
    int hash = 0;
    while(*str){
        hash += (int)(*str);
        str++;
    }
    return hash%MAX;
}
void initialize(HashTable* ht){
    ht->table = (Node**)malloc(sizeof(Node*)*MAX);
    for(int i = 0; i < MAX; i++){
        ht->table[i] = NULL;
    }
}
void insert(HashTable* ht, const char* key){
    int index = hash(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = (char*)malloc(strlen(key)+1);
    strcpy(newNode->key, key);
    newNode->next = ht->table[index];
    ht->table[index] = newNode;
}
void display(HashTable* ht){
    for(int i = 0; i < MAX; i++){
        printf("Index %d: ", i);
        Node* temp = ht->table[i];
        while(temp){
            printf("%s -> ", temp->key);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
int main(){
    HashTable ht;
    initialize(&ht);
    int x;
    int y;
    do{
        y=0;
        printf("===== Open Hashing Menu =====\n");
        printf("1. Insert key\n");
        printf("2. Display Hash Table\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &x);
        switch(x){
            case 1:
                {
                    char buffer[100];
                    printf("Enter key to insert: ");
                    scanf("%s", buffer);
                    insert(&ht, buffer);
                    break;
                }
            case 2:
                display(&ht);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Input\n");
                break;
        }
    }while(x != 3);
    }
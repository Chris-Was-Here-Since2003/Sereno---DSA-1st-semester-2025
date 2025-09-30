// Online C compiler to run C program online
#include <stdio.h>
#include <stdbool.h>
#define MAXBIT 8
void initialize(unsigned char *set);
void insert(unsigned char *set, int element);
void delete(unsigned char *set, int element);
bool find(unsigned char set, int element);
unsigned char union_(unsigned char A, unsigned char B);
unsigned char intersection(unsigned char A, unsigned char B);
unsigned char difference(unsigned char A, unsigned char B);
void display(unsigned char set);
int main() {
    unsigned char x;
    unsigned char y;
    initialize(&x);
    insert(&x, 0);
    insert(&x, 5);
    display(x);
    delete(&x, 0);
    insert(&x, 7);
    display(x);
    insert(&y, 1);
    insert(&y, 6);
    display(y);
    display(union_(x, y));
    insert(&y, 7);
    display(intersection(x, y));
    display(x);
    display(y);
    display(difference(y, x));
    return 0;
}
void initialize(unsigned char *set){
    *set = 0;
}
void insert(unsigned char *set, int element){
    if(element>=MAXBIT){
        return;
    }
    *set |= (1 << element);
    return;
}
void delete(unsigned char *set, int element){
    if(element>=MAXBIT){
        return;
    }
     *set &= ~(1 << element);
    return;
}
bool find(unsigned char set, int element){
    if(element>=MAXBIT){
        return false;
    }
    unsigned char mask = 1;
    
  return (set &= mask << element) > 0 ? true : false;
}
unsigned char union_(unsigned char A, unsigned char B){
    return A | B;
}
unsigned char intersection(unsigned char A, unsigned char B){
    return A & B;
}
unsigned char difference(unsigned char A, unsigned char B){
    return A - ~B;
}
void display(unsigned char set){
    unsigned char mask = 1;
    mask <<= MAXBIT-1;
   while(mask!=0){
        if(mask&set){
            printf("1 ");
        }else{
            printf("0 ");
        }
        mask >>= 1;
    }
    
    printf("\n");
}


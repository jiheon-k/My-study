#include<stdio.h>
int main(void){
    int a=10;
    for(int i=1; i<10; i++)
        printf("%d*%d = %d\n", i, a, i*a);
}
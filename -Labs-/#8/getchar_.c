#include<stdio.h>

int main(){
    char m;

    printf("please enter your sentences:: ");
    while((m=getchar()) != EOF){
        putchar(m);
    }

    return 0;
}
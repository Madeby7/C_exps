#include<stdio.h>

int main(){
    char id[8];
    printf("enter the id :: ");
    scanf("%s",id);

    int i=0;
    int sum = 0;

    while(id[i]>='0' && id[i]<='9'){
        sum += (id[i++]-'0');
        sum*=10;

    }
    printf("%d", sum);

    return 0;

}
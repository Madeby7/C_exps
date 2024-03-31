#include<stdio.h>

int main(){
    char *List[]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};

    //printf("%c",*(List[1]+2));

    
    for(int i = 0;i<7;i++){
        printf("\n%s\n", List[i]);
    }
    int i=6;

    while(i>=0){
        printf("\n%s\n", List[i--]);
    }
    
    /*
        -> demek ki direkt indexlerdeki pointerlar arasında gezmek istersek, 
        bu şekilde bir tanımlama ile bağlangıç değerlerini alıp direkt string yazdırır gibi yazdırma şansımız var demektir.

    */

    return 0;
}
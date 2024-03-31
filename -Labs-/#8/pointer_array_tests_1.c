#include<stdio.h>

int main(){

    char * List[]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};

    //printf("%c",*(List[1]+2));

    printf("\n%s\n", *(List[2]));
    

    /* 
        -> bu pointer arrayler ile ilgili çok kritik bir şeyi tanımlıyor.
            Başlangıç değerlerinden direkt %s olarak ifade çekilebilioyr.
            normal bir array gibi, ama içindekini pointer olarak müdehale edersek,
            yani list[1] mesela direkt 1. indexteki string ifadenin başlangıç değerine atanmıştır.
            bunu arttırarak azaltarak pointer içindeki gezintimizi sağlayabiliriz.

    */
   int i=0;
    while(i<7){
        while (*(List[i]) != '\0'){
            printf("%c",*(List[i]++));
        }
        printf("\n");
        i++;

    }
    

    /*
    her bir pointer arrayinin alt kademesinde direkt adres  gibi ilerlenebilioyr.
    çünkü bu bir pointer arrayidir (List adlı pointer arrayi); ve bir arttırarak içinde bu şekil gezilebilir, referens verdiği değer
    direkt char değişkeninden işlem yapılmaktadır.
    bunuda normal bir string arrayinde sona kadar işlemini pointer ile sağlayabiliriz, anlamına gelioyr.


    */

   /*
   -> direkt dışarıdaki büyk arrayin pointerları arasında gezmek istersem de buna benzer bir metodoloji izleyeerk ilerleyebiliriz.
        bu sefer dışarıdakı ptr[i] inin değil direkt ptr yi arttırarak içinde gezmeye çalışabiliriz.

   */
    printf("\n\n\n");
    i=0;
    for(i;i<7;i++){
        printf("\n%s", List[i]);
    }
    
        

    return 0 ;

}
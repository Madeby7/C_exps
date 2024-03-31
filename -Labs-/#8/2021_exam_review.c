#include<stdio.h>


void bit_display(unsigned char Bits[], unsigned char message);


int main(){
    unsigned char Bits[8] = {'0'};
    // buraya dikkat, teker teker atama yapılacağı(for içinde vs) bu şekilde süslü belirtmiyoruz.
    unsigned char m=255;
    // görünüm 00001100 şeklinde olacak. o zmn sağ sol shifting yaparak yakalayabiliriz.

    m  = m>>6;
    m = m<<2;


    bit_display(Bits, m);


    return 0;
}

void bit_display(unsigned char Bits[], unsigned char message){
    unsigned char mask = 1;
    int i,k;
    for(k=0;k<8;k++){
        if((message & mask) == mask){
            Bits[7-k] = '1'; // = mask de olabilir.
            
        }
        else{
            Bits[7-k] = '0';
        }
        mask = mask << 1;

    }
    printf("\n");
    for(i=0;i<8;i++){
        printf("%c", Bits[i]);

    }
    printf("\n");
}

#include<stdio.h>
#define MAX 100

// kullanıcıdan istenen bir değr boyutunda bir matris oluşturup onu biçimlendirmemiz istenen bir örnektir.
// labda başarılı olamamıştık, şimdi yeniden inceleyeceğim.


void crt_pattern(char arr[MAX][MAX],int length);
void pr_pattern(char arr[MAX][MAX],int length);

int main(){
    int h,n;

    printf("\nPlease enter the high and wight(should be same value) :: ");
    scanf("%d",&h);

    n= h;
    char array[MAX][MAX];

    crt_pattern(array, n);

    return 0;

}


void crt_pattern(char arr[MAX][MAX],int length){
    int i,j,k;
    k= length;

    // matris dizaynı sağlandı, iç içe loop mantığıyla satır ve stünlar boyunca ilerleyeceğiz.
    /*
        -> if; else if; else durumlarının her biri içinde matrisin kısımlarına göre ayrılacak ve işlencektir.
        yani i ve j değerlerinin birbirleriyle olan kıyaslarına göre şekillenecek.
        burada 2 ye ayırmak ve ona göre yazmak daha mantıklı ve basit olacaktır.

    
    */
    for(i=0;i<k;i++){
        for(j=0;j<k;j++){
            if(i<=k/2){
                if((i==j) || (j == (k-i-1)) || i==0 || j==0 || j==k-1){
                    arr[i][j] = '*';
                }
                else if(j<k/2 && j<i){
                    arr[i][j] = '1';
                }
                else if(j<k/2 && j>i){
                    arr[i][j] = '2';
                }
                else if(j>=k/2 && j<(k-i-1)){
                    arr[i][j] = '2';
                }
                else if(j>=k/2 && j>(k-i-1)){
                    arr[i][j] = '4';
                }
                else{
                    arr[i][j] = '-';
                }
            }
            /*
            -> parametreleri verirkenki bağılılıklara dikkat etmek önemli.
            lab sırasında bunu karıştırmışız. conditions kısmında ve lik veyalık durumlarına göre direkt bunları ilerletmek öenmliydi.
            ve tamamen çizmiş oluyordu.
            
            
            */
            else{
                if((i==j) || (j == (k-i-1)) || i==k-1 || j==0 || j==k-1){
                    arr[i][j] = '*';
                }
                else if(j<k/2 && j<k-i-1){
                    arr[i][j] = '1';
                }
                else if(j<=k/2 && j>k-i-1){
                    arr[i][j] = '3';
                }
                else if(j>=k/2 && j<i){
                    arr[i][j] = '3';
                }
                else if(j>=k/2 && j>i){
                    arr[i][j] = '4';
                }
            }
        }
    }
    pr_pattern(arr,k);
}
void pr_pattern(char arr[MAX][MAX],int length){
    int i,j,k;
    k = length;

    for(i=0;i<k;i++){
        for(j=0;j<k;j++){
            printf("%c",arr[i][j]);
        }
        printf("\n");
    }
}
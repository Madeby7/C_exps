#include<stdio.h>
#include<stdlib.h>

#define N 10
void swap(int v[],int i, int j);

int main(){ 
   
   int v[N];
   int i,j;
   
   // geriye doğru bir array tekrar arkadan sıralama yapıyoruz. 

   v[0]=4;
   v[1]=12;   	
   v[2]=16;
   v[3]=18;    	
   v[4]=28;
   v[5]=44; 
   v[6]=62;   	
   v[7]=66;
   v[8]=88;    	
   v[9]=98;
   int count= 0;

   for (i=(N-2);i>=0;i--){
   		for (j=0;j<=i;j++){
   			if (v[j] < v[j+1])
				swap(v,j,(j+1));
                count++;
		   }    
   }
   
   /*for (i=0;i<=N-2;i++){
   		for (j=0;j<=N-2-i;j++){
   			if (v[j] < v[j+1])
				swap(v,j,(j+1));
		   }
   }*/

   for (i=0;i<=(N-1);i++)
		printf("\nv[%d]= %d",i,v[i]);  

    printf("\n\n%d",count);
    
    char str[] = "456";
    int num = atoi(str);

    printf("\n\nKarakter Dizisi: %s, Tamsayi: %d\n", str, num);
}/*End main*/
   
	


void swap(int v[],int i, int j)
	{
		
		int temp;
		
		temp = v[i];	
		v[i] = v[j];
		v[j] = temp;
			
    
	}	
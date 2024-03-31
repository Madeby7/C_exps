#include <stdio.h>



int main()
{
	/*
    char * ic;
	char c;
	char s[]="Izmir Yükek Teknoloji Ensitüsü";
	
	printf("%p", &s[0]);
	printf("\n%c", s[0]);		
	
	ic=s;
	ic++;
	c=*ic;

	printf("\n%p",ic);
	printf("\n%c",c);
	printf("\n%p",*&ic);
	printf("\n%p",&*ic);		
    
    */

   /*
   unsigned short mask = ~0;
    mask = mask>>8;
    mask = mask<<4;

	unsigned short int b=967;

      printf("\n%d",b&mask);
      printf("\n%d",b|mask);
      printf("\n%d",b&(~mask));
      printf("\n%d",b|(~mask));
   
   */

  /*
    int h,w,i,j;
    char c[4]={'+','-','*','x'};
	
	h=w=16;
	int count=0;
	
	for (i=0; i<h; i++){
		
		for (j=0; j<w; j++){
			
			if ((i < h/2) && (j < w/2)){
				putchar(c[0]);
			}
			if ((i < h/2) && (j >= w/2)){
				putchar(c[1]);
			}		     
			if ((i >= h/2) && (j < w/2)) {
				putchar(c[2]);
			}
			if ((i >= h/2) && (j >= w/2)){
				putchar(c[3]);	
			}				
			
		}
		
	    putchar('\n');
	    count++;		
		
	}
	
	printf("\ncount = %d ",count);
  */
    
    
	
    unsigned int sum=0;
	
	i=0;
	while(i>=0)
	{
		
		sum = (sum + id[8-i])*10;
		if(id[i] != 0){
            printf("\n%c",id[8-i]);
        }
		    
		i--;
	}
	
	printf("sum = %d", sum);
    return 0;
}

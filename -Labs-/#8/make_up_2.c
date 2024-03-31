#include<stdio.h>


int main(){
    char id[]="267800329";
	unsigned int i=0;
	
	while(id[i] != '\0'){
        i++;
    }
	    
	printf("i=%u",i);
    unsigned int sum=0;
	
	i=0;
	while(i<9)
	{
		
		sum = (sum * 10) + (id[i] - '0');

        
		if(id[i] != 0){
            printf("\n%c",id[i]);
        }
		    
		i++;
	}
	
	printf("\nsum = %u", sum);

    return 0;

}
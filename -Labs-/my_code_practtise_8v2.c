#include<stdio.h>
#include<math.h>
#include<string.h>
unsigned int crt_mask(unsigned int mbit, int pstart, int pend);
void bitdisplayer(unsigned int value);



/*
	-> ana olay mask olarak al�d��m�z de�eri sistem i�eriisde gezdirmek. 
		& operat�r� ile de spesifik yerdeki bilgiyi alaca��z.
		practise sette 8 lik bitler olarak ta��nma i�lemi yap�l�yor. bu noktada olu�turdu�umuz mask ya da say
		
*/
int main(){
	
	int pstart,pend,n,mask;
	n = 8; // we take 8 bit 8 bit in mask;
	unsigned int x = 73353510;
	
	int i;
	
	pstart = 7;
	pend  = 0;
	
	unsigned int readed,t;
	
	for(i=0;i<4;i++){
		mask = crt_mask(1, pstart, pend);
		printf("\n%u",mask);
		
		readed = (x & mask);
		printf("\n%u",readed);
		
		readed = readed>>(i*7);
		printf("\n    %u",readed);
		bitdisplayer(readed);
		pstart += 8;
		pend += 8;
		
	}
	
	
	return 0;
	
}

unsigned int crt_mask(unsigned int mbit, int pstart, int pend){
	
	unsigned int mc=~0;
	
	mc = (mc>>(32-(pstart-pend+1))) << pend;
	return mc;
	
}

void bitdisplayer(unsigned int value){
	char bitcol[8] = {'0'};
	int i,j;

	int t = (int)value;
	printf("	%d",t);
	// son bit 2^0 =1 olacak bu noktada de�erlendirirken, e�er 2 ye b�l�nebiliyorsa son bit 0, 1 ise 2 demektir, bunu yaparken s�rekli shifting yaparak de�eri alta �ekebilirim.
	
	for(i=7;i>=0;i--){
		if(t%2 == 1){
			bitcol[i] = '1';
		}
		else{
			bitcol[i] = '0';
		}
		t = t>>1;
	}
	printf("    ");
	for(i=0;i<8;i++){
		printf("%c",bitcol[i]);
	}
}


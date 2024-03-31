#include<stdio.h>
void countWords(char arr1[]);
void countVowelsAndConsonants(char arr1[]);


int main(){
	char st[100];
	int i,k;
	printf("please enter your sentence :: ");
	for(i=0;(k=getchar())!= EOF && (k != '\n');i++){
		st[i] = k;
		
	}
	st[i] = '\0';
	
	countWords(st);
	countVowelsAndConsonants(st);
	
	
	return 0;
	
}

void countWords(char arr1[]){
	
	int i,c;
	c =1;
	for(i=0;arr1[i] !='\0';i++){
		if(arr1[i] == ' '){
			c++;
		}
	}
	
	
	printf("\n\nnumber of the ords in the sentence: %d", c);
}

void countVowelsAndConsonants(char arr1[]){
	int i,vow,con;
	vow =0;
	con =0;
	
	char ch;
	
	for(i=0;arr1[i] !='\0';i++){
		ch = tolower(arr1[i]);
		if((ch != ' ') && (ch !='\t') && (ch !='\a') ){
			if((ch == 'a') || (ch =='e') || (ch =='i') || (ch == 'u') || (ch =='o')){
				vow++;
				
			}
			else{
				con++;
			}
		}
	}
	
	printf("\n\nnumber of vowel letters in the sentence : %d", vow);
	printf("\n\nnumber of consonant letters in the sentence : %d", con);
}



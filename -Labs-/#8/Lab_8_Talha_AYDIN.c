#include<stdio.h>


void storepattern(char arr1[][100], int len);
void printArrays(char arr1[][100], int len);
int main(){
	int s;
	printf("Enter the lenght of sides :: ");
	scanf("%d", &s);
	int h = s;
	int w = s;
		
	char arr[100][100];
	
	storepattern(arr, s);
	
	
	
	return 0;
}

void storepattern(char arr1[][100], int s){
	
	int i,j;
	
	for(i=0;i<s;i++){
		for(j=0;j<s;j++){
			if(i<=s/2){
				
				if(i==j || i == s-j-1 || i==0 || j ==0 || i==s-1 || j==s-1){
					arr1[i][j] = '*';
				}
			
				else if (i>j){
					arr1[i][j] = '1';
				}
				
				else if ((j>i) || j<s-j-1){
					arr1[i][j] = '2';
				}
				
				else if((i>j) || j>(s-i-1)){
					arr1[i][j] = '3';
				}
			}
			
			else{
				if((i==j || i == s-j-1 || i==0 || j ==0 || i==s-1 || j==s-1)){
					arr1[i][j] = '*';
				}
				
				else if (i>j){
					arr1[i][j] = '4';
				}
				
				else if ((j>i) || j<s-j-1){
					arr1[i][j] = '3';
				}
				
				else if((i>j) || j>(s-i-1)){
					arr1[i][j] = '3';
				}	
			}
				
		}
	}
	
	printArrays(arr1,s);
}

void printArrays(char arr1[][100], int s){
	
	int i,j;
	for(i=0;i<s;i++){
		for(j=0;j<s;j++){
			printf("%c", arr1[i][j]);
		}
		printf("\n");
	}
}

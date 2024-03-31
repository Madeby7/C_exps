#include<stdio.h>
#include<time.h>


void max_and_record(int arr1[]);
void print_arr(int arr2[]);

int main(){
	
	int arr1[10];
	
	srand(time(NULL));
	
	
	int i;
	for(i=0;i<10;i++){
		arr1[i] = 1 + rand()%100;
		printf("%d\t",arr1[i]);
	}
	
	max_and_record(arr1);
	
	
	return 0;
}


void max_and_record(int arr1[]){
	
	int arr2[10];
	int max,k,i,r;
	
	for(k=0;k<10;k++){
		max =0;
		for(i=0;i<10;i++){
			
			if(max<arr1[i]){
				max = arr1[i];
				r =i;
			}
		}
		arr2[k] = arr1[r];
		arr1[r] = 0;
	}
	
	// function of printing;
	print_arr(arr2);
	
	
}
void print_arr(int arr2[]){
	printf("\n\n");
	int k;
	for(k=0;k<10;k++){
		
		printf("%d\t",arr2[k]);
	}
}



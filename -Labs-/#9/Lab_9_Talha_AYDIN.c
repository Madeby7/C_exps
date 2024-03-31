#include<stdio.h>
#include<math.h>
#define pi 3.14159265


char plotArray[21][41];
double generateSinwave(double time, double amplitude,double frequency);
void clearScreen(void);
void plotWaveform(double Amplitude, double frequency);

int main(){
	
	double m,f;
	int i,j;
	printf("\nWelcome to Wave generator on Oscilloscope Screen");
	printf("\nPleaase enter the magnetude :: ");
	scanf("%lf",&m);
	printf("\nPlease enter frequency :: ");
	scanf("%lf",&f);
	clearScreen();
	plotWaveform(m, f);
	
	
	printf("\n\n\n");
	for(i=0;i<21;i++){
		for(j=0;j<41;j++){
			printf("%c",plotArray[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}


double generateSinwave(double time, double amplitude,double frequency){
	return amplitude*sin(0.4*pi*(time*frequency));
}

void clearScreen(void){
	//plotArray[21][41]
	int i,j;
	
	
	for(i=0;i<21;i++){
		for(j=0;j<41;j++){
			if(j==20){
				if(i%5 ==0){
					plotArray[i][j] = '+';
				}
				else{
					plotArray[i][j] = '|';
				}
			}
			else if(i==10){
				if(j%5 ==0){
					plotArray[i][j] = '+';
				}
				else{
					plotArray[i][j] = '-';
				}
			}
			else{
				plotArray[i][j] = ' ';
			}
		}
	}
}



void plotWaveform(double Amplitude, double frequency){
	
	int t;
	double value;
	int v;
	
	for(t=-20;t<21;t++){
		value= generateSinwave(t*0.5,Amplitude,frequency);
		v = (int)(5.0 * value);
		printf("\n%d",v);
		
		plotArray[v+10][t+20] = '.';
	}
}

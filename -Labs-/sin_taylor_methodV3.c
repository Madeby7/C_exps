#include<stdio.h>
# define pi 3.141592

// 3 fonksyonlla ifade edip ayrý bir fonskyondan hesaplatýp direkt, int main içeriisnden deðerleri alacaðým.


double factoriel(int n){
	int i;
	double fact =1.0;
	
	for(i=1;i<=n;i++){
		fact *= i;
		
	}
	return fact;
}


double pow(double value, int n){
	int i;
	double pw =1.0;
	
	for(i=0;i<n;i++){
		pw *= value;
		
	}
	return pw;
	
}


double sin(double x, int j){
	
	double sum= 0.0;
	double result;
	int sign = 1;// direkt önündeki deðer. zaten periodik olarak ilerleyeceði için 1 ile baþlayýp sonra negatif sonra bir daha pozitif þekilde ilerleyecek.
	
	int k,terms;
	
	for(k=0;k<j;k++){
		terms = (2*k+1);
		result = sign*(pow(x,terms)/factoriel(terms));
		sum += result;
		sign = -sign;
		// burasý kritik, böyle bir kullaným daha öncesinde tasarlamamýþtým, ana notlara eklensin.
	}
	return sum;
	
}
int main(){
	double radius;
	
	printf("Please enter the radius (in terms of radian) :: ");
	scanf("%lf", &radius);
	
	printf("\n\n\n sin(%.2lf)  // in terms of (%lf) = %.4lf",radius,radius*180/pi, sin(radius,20));
	
	
	
	return 0;
}

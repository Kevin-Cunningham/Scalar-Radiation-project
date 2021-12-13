//Compilation instructions:
//gcc -o q2 Question2.c -lm

#include <stdio.h>
#include <math.h>


double SnSum(int n, double a, double r);
double SnExact(int i, double a, double r);

int main(void){
	
	//QUESTION 2
	int j, n;
	double a, r, summation, exact;

	//Loop that runs from 1 to 3
	for(j=1; j<=3; j++){
	//Switch-cases	
		switch(j){
			case 1:
				a=2.0, r=0.01, n=10000;
				printf("n = %d, a = %lf, r = %lf\n\n",n,a,r);
				summation = SnSum(n,a,r), exact = SnExact(n,a,r);
				printf("Summation = %lf, formula = %lf,\nSummation-formula = %lf\n\n\n", summation, exact, summation-exact);
				break;
			case 2:
				a=0.01, r = 1.1, n=500;
				printf("n = %d, a = %lf, r = %lf\n\n",n,a,r);
				summation = SnSum(n,a,r), exact = SnExact(n,a,r);
				printf("Summation = %lf, formula = %lf,\nSummation-formula = %lf\n\n\n", summation, exact, summation-exact);
				break;
			case 3:
				a = 0.0001, r=2.0, n=100;
				printf("n = %d, a= %lf, r = %lf\n\n",n,a,r);
				summation = SnSum(n,a,r), exact = SnExact(n,a,r);
				printf("Summation = %lf, formula = %lf,\nSummation-formula = %lf\n\n\n", summation, exact, summation-exact);
				break;
			default:
				break;
		}
	}
	//Cases 1 and 3 work well. Case 2 does not work very well.
	printf("Cases 1 and 3 work very well, case 2 does not work so well.\n");
}


//Function to calculate sum as in assignment
double SnSum(int n, double a, double r){
	double sum=0;
	int i;
	for(i=0; i<=n; i++){
		sum += pow(r,i);
	}	
	return a*sum;
}
//formula for the sum, as in the assignment.
double SnExact(int n, double a, double r){
	return a*(1-pow(r,n+1))/(1-r);
}

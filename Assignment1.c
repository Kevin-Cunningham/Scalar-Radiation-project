//Compilation instructions:
//gcc -o assignment Assignment1.c -lm

#include <stdio.h>
#include <math.h>

int intfunc(int n);
int numchars(int n);
double SnSum(int n, double a, double r);
double SnExact(int i, double a, double r);

int main(void){
	//QUESTION 1
	// x,y,z hold the last 3 values in the series, counter count show many chars are included on a line
	int x=0, y=0, z = 50, counter=0;

	//print out the first number (the input)
	printf("%d, ", z);
	counter = numchars(z)+2;

	//While loop continues until the last 3 values in the series are 4,2,1
	while(x!=4 && y!=2 && z!=1){
		// update x,y,z
		x = y;
		y = z;
		z = intfunc(z);		
		
		//update counter
		counter = counter + numchars(z) + 2;

		//Start a new line and reset counter to make sure a line is <40 chars
		if(counter>40){
			printf("\n");
			counter = numchars(z) + 2;
		}
		//print z
		printf("%d, ",z);

	}
	printf("\n\n\n");
	
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

//The function described in the question
int intfunc(int n){
	
	if(2*(n/2)==n){
		return n/2;	
	}	
	else{
		return 3*n +1;
	}
}

//Function to count number of chars in an int
int numchars(int n){
	int test=1, i=10, counter=0;
	while(test!=0){
		test = n/i;
		i= 10*i;
		counter++;
	}
	return counter;
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

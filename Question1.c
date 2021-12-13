//Compilation instructions:
//gcc -o q1 Question1.c -lm

#include <stdio.h>
#include <math.h>

int intfunc(int n);
int numchars(int n);

int main(void){
	//QUESTION 1
	// x,y,z hold the last 3 values in the series, counter count show many chars are included on a line
	//z is the first input for the question, e.g. in the example, z=50
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
	printf("\n");
	
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


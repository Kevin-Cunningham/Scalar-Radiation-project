#include <stdio.h>

void main(void){
	int i, *p;
	i=42;
	p=&i;

	printf("p   points to  %p\n", p);
	printf("p+1 points to %p\n",p+1);

	printf("*p = %d, i = %d\n",*p,i);
	printf("*(p+1)=%d\n",*(p+1));

	int a[10], *q, *r, j;
	for(j=0;j<10;j++){
		a[j]=j*j;
	}
	p = &a[2]; //Points to 3rd element 
	printf("p = %p, *p = %d\n",p,*p);

	q = p+3; //points to 6th element
	printf("q = %p, *q = %d\n",q,*q);

	r = p-2; //points to 1st element
	printf("r = %p, *r = %d\n",r,*r);

	i=q-r; //diff between locations of cell e.g. 6-1
	printf("i = %d\n",i);

}

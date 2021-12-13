#include <stdio.h>

void main(void){
	int a[3], i, *p;

	for (i=0;i<=2;i++){
		a[i]=i;
	}
	p=&a[0];
	printf("p = %p, *p = %d\n",p,*p);
	p++;
	printf("p = %p, *p = %d\n",p,*p);
	*(p++);
	printf("p = %p, *p = %d\n",p,*p);
	*p++;
	printf("p = %p, *p = %d\n",p,*p);
	
	for(i=0; i<=2; i++){
		printf("a[%d] = %d\n",i,a[i]);
	}
}

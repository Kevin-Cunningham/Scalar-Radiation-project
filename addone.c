#include <stdio.h>

void addonetome(int *me){
	*me = *me +1;
	me = NULL;
}

void main(){
	int i=1;
	int *p = &i;
	addonetome(p);
	printf("i = %d, *p = %d\n",i,*p);
}

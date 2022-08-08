//記憶體用較少 但cpu耗比較多(指令較多)  
#include <stdio.h>
int main(){
	int integer, sum;
	printf("Please enter the first interger: ");
	scanf("%d", &integer);
	sum = integer;
	printf("Please enter the second integer: ");
	scanf("%d", &integer);
	sum = sum + integer; 
	printf("Please enter the third integer: ");
	scanf("%d", &integer);
	sum = sum + integer;
	printf("Sum is %d.\n", sum);

}


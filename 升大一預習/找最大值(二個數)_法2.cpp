#include <stdio.h>

int main() {
    int a, max;
	printf("Please enter the first integer: ");
	scanf("%d", &a);
	max=a; 
	printf("Please enter the second integer: ");
	scanf("%d", &a);
	if (max<a){
		max=a;
	}
	printf("The maximum is %d.\n", max);
    return 0;
}


#include <stdio.h>
int main(){
	int a, b, c;
	printf("Please enter the first integer: ");
    scanf("%d", &a);
    printf("Please enter the second integer: ");
    scanf("%d", &b);
    printf("Please enter the third integer: ");
    scanf("%d", &c);
    double avg = (a + b + c) / 3.;
    printf("Average: %f\n", avg);
    return 0;
}


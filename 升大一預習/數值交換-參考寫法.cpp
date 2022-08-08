#include <stdio.h>
int main(){
	int integer1, integer2, temp;
	printf("Please enter the first interger: ");
	scanf("%d", &integer1);
	printf("Please enter the second integer: ");
	scanf("%d", &integer2);
	
	temp= integer1;
    integer1 = integer2;
    integer2 = temp;
    
	printf("integer1: %d\n", integer1); 
    printf("integer2: %d\n", integer2);
    return 0;
}

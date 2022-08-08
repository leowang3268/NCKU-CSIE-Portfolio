//2個變數 
//限制: 能做加減的整數 
#include <stdio.h>
int main(){
	int integer1, integer2, temp;
	printf("Please enter the first interger: ");
	scanf("%d", &integer1); //integer1: 3 
	printf("Please enter the second integer: ");
	scanf("%d", &integer2); //integer2: 5
	
	integer1 = integer1 + integer2; //integer1: 8, integer2: 5
	integer2 = integer1 - integer2; //integer1: 8, integer2: 3 
	integer1 = integer1 - integer2; //integer1: 5, integer2: 3
	 
    
	printf("integer1: %d\n", integer1); //integer1: 5
    printf("integer2: %d\n", integer2); //integer2: 3 
    return 0;
}

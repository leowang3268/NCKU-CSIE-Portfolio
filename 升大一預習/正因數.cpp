#include <stdio.h>

int main() {
    printf("Please enter a positive number: ");
	int num;
	int cnt = 0;
	scanf("%d", &num);
	printf("The factors of %d are: ", num); 
	int i;
	for(i=1; i<=num && isPrime; i++) {
		if(num%i==0) {
			printf("%d ", i);
			cnt+=1;
		}
	}
    return 0; 
}


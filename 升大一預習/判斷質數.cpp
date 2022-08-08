#include <stdio.h>

int main() {
    printf("Please enter a positive number: ");
	int N;
	int isPrime = 1;
	scanf("%d", &N);
	int num;
	for (num=2; num<N && isPrime; num++) {
		if(N%num==0) {
		    isPrime = 0;
		}
	}
	if (isPrime) {
	    printf("Yes\n");
    } else {
    	printf("No/n");
	}
    return 0; 
}


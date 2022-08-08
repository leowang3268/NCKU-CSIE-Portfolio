#include <stdio.h>

int main() {
    printf("Please enter a positive number: ");
	int N;
	scanf("%d", &N);
	int num;
	for (num=2; num<N && N%num!=0; num++); 
	if (num==N) {
	    printf("Yes\n");
    } else {
    	printf("No/n");
	}
    return 0; 
}

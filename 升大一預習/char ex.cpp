#include <stdio.h>

int main() {
	char ch1, ch2;
	printf("Please enter a capital alphabet: ");
	scanf("%c", &ch1);
	ch2=ch1+32;
	printf("%c\n", ch2); 
    return 0; 
}


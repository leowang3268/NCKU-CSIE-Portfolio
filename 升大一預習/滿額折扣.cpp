#include <stdio.h>

int main() {
	int num, total;
    printf("Please enter the number of guest: ");
    scanf("%d", &num);
    if (num<10){
    	total=300*num;
	}
    if (num>=10){ 
        total=300*0.8*num;
	}
	printf("total is %d.\n", total);
    return 0;
}


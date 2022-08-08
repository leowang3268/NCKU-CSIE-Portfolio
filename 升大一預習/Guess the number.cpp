#include <stdio.h>

int main() {
	int num, total, ori;
    printf("Please enter the number of customers: ");
    scanf("%d", &num);
    ori=300*num;
    if (ori>=3000){ 
        total=ori*0.8;
	}
	printf("Total: %d\n", total);
    return 0;
}


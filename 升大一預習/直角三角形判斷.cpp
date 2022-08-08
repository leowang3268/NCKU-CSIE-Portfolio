#include <stdio.h>

int main() {
    int a, b, c;
    printf("Please enter the lengths: ");
    scanf("%d%d%d", &a, &b, &c);
    if ( a*a==b*b+c*c || b*b==a*a+c*c || c*c==a*a+b*b ){  //if(side1==side2 && side2!=side3) 
   		printf("Rectangular triangle\n");
		       	
   	}
   	return 0;
}


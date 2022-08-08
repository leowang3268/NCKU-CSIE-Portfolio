#include <stdio.h>

int main() {
    int a, b, c;
    printf("Please enter the lengths: ");
    scanf("%d%d%d", &a, &b, &c);
    
    if ( a==b && b==c &&c==a ){
	    printf("Regular triangle\n");
    }
	
	if ( a==b || b==c || a==c ){
		printf("Isosceles triangle\n"); 
    }
    
	if ( a*a==b*b+c*c || 
	     b*b==a*a+c*c || 
		 c*c==a*a+b*b ){
   		printf("Rectangular triangle\n");
   	}
		       	
   	
   	return 0;
}


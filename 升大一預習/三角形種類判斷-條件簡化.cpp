//a<=b<=c 
#include <stdio.h>

int main() {
    int a, b, c;
    printf("Please enter the lengths: ");
    scanf("%d%d%d", &a, &b, &c);
    
/*藉由數值交換將三邊長由小到大排列*/   
 
    if ( a==c ){
	    printf("Regular triangle\n");
    }
	
	if ( a==b || b==c ){                //相同的必相鄰 
		printf("Isosceles triangle\n"); 
    }
    
	if ( c*c==a*a+b*b ){
   		printf("Rectangular triangle\n");
   	}
		       	
   	
   	return 0;
}


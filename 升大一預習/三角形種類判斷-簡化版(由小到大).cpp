#include <stdio.h>

int main() {
    int a, b, c, t;
    printf("Please enter the lengths: ");
    scanf("%d%d%d", &a, &b, &c);
    
    if (a>b){ t=a; a=b; b=t; }
    if (a>c){ t=a; a=c; c=t; }
    if (b>c){ t=b; b=c; c=t; }
    
    if ( a==c )  //當if的{}內只包含一條敘句時,{}可省略 
	    printf("Regular triangle\n");
    
	if ( a==b || b==c )
		printf("Isosceles triangle\n"); 
    
    
	if ( c*c==a*a+b*b )
   		printf("Rectangular triangle\n");
   	
	       	
   	
   	return 0;
}


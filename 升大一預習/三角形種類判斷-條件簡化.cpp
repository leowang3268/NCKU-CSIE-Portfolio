//a<=b<=c 
#include <stdio.h>

int main() {
    int a, b, c;
    printf("Please enter the lengths: ");
    scanf("%d%d%d", &a, &b, &c);
    
/*�ǥѼƭȥ洫�N�T����Ѥp��j�ƦC*/   
 
    if ( a==c ){
	    printf("Regular triangle\n");
    }
	
	if ( a==b || b==c ){                //�ۦP�����۾F 
		printf("Isosceles triangle\n"); 
    }
    
	if ( c*c==a*a+b*b ){
   		printf("Rectangular triangle\n");
   	}
		       	
   	
   	return 0;
}


#include <stdio.h>

int main() {
    int a, b, c, med;
    printf("Please enter three integers: ");
    scanf("%d%d%d", &a, &b, &c);
    med=a;
    //接著假設ａ是最大值和ａ是最小值的狀況 
    if( (b-c)*(b-a)<0 ){
    	
        med=b;
        
    }

    if( (c-b)*(c-a)<0 ){
      	
        med=c;

    }
	
	
    printf("The median is %d.\n", med); 
    return 0;
}


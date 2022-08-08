#include <stdio.h>

int main() {
    int a, b, c, med;
    printf("Please enter three integers: ");
    scanf("%d%d%d", &a, &b, &c);
    med=a;
    if(a>b&&a>c){
    	
        med=b;
        
        if(med<c){
            med=c;
        }
    }

      if(a<b&&a<c){
      	
        med=b;
        if(med>c){
        	
            med=c;
        }
    }
	
	
    printf("The median is %d.\n", med); 
    return 0;
}


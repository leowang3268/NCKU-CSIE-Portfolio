#include <stdio.h>
//��a,b,c�̤p������a �A��b,c���p������b 
int main() {
    int a, b, c, t;
	scanf("%d%d%d", &a, &b, &c);
	printf("Before: %d %d %d\n ", a, b, c);
	
	if (a>=b){
		t=a;
		a=b;  
		b=t;
		if (a>c){
			a=c;
			c=t;
		}
	} 
	if (b>c){
		t=b;    
		b=c;
		c=t;
	}
	printf("After: %d %d %d\n", a, b, c);
    return 0;
}


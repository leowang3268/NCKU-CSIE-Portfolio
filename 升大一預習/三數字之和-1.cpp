//三數字之和 
#include <stdio.h>
int main(){
	int integer1, integer2, integer3;
	printf("Please enter the first interger: ");
	scanf("%d", &integer1);
	printf("Please enter the second integer: ");
	scanf("%d", &integer2);
	printf("Please enter the third integer: ");
	scanf("%d", &integer3);
	double avg=(integer1+integer2+integer3)/3.;
	printf("Average is %f.\n",avg); //類似跳脫的概念 &d會把sum的值拿過來                        
	
}

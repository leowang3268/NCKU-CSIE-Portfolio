#include<stdio.h>

int main(){
    int score;
    do {
        scanf("%d", &score); 
        if(score==-1) break;
        else if(score>=80) printf("A\n");
        else if(score>=70) printf("B\n");
        else if(score>=60) printf("C\n");
        else printf("F\n");      
    } while(-1<=score<=100);
    return 0;
}


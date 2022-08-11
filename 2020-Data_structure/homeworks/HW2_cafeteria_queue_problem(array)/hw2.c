#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAXSTACK 100
#define MAXQUEUE 100

int stack[MAXSTACK];
int top = -1;
void push(int);
int pop();

int queue[26][MAXQUEUE];
int rear = -1;
int front = -1;
void enqueue(char, int);
int dequeue(char);


int main () 
{ 
	char str[100][10];
	int n = 0;	
	FILE *fin, *fout;
	fin = fopen("input.txt", "r");
	fout = fopen("output.txt", "w");
	
	while(!feof(fin)) { 
		fgets(str[n], 10, fin);
		int value;
    	if (str[n][0]=='P' && str[n][1]=='U' || str[n][0]=='E' || str[n][0]=='D') //if PUSH or ENQUEUE or DEQUEUE
		{
			if(str[n][0]=='P') //PUSH
			{
				if ((str[n][6]-'0') <=9 && (str[n][6]-'0') >= 0) //two digits 
					value = (str[n][5]-'0') * 10 + (str[n][6]-'0'); 
				else	                                         //one digit
					value = str[n][5]-'0';
				push(value);
			}
			else if(str[n][0]=='E') //ENQUEUE
			{
				char ch = str[n][8] - 'A';
				enqueue(ch, pop()); 
			}
			else //DEQUEUE
			{
				char ch = str[n][8] - 'A';
				fprintf(fout, "%d\n", dequeue(ch));
			}	
		}
		else if(str[n][0]=='P' && str[n][1]=='O') //POP  
		{
			//fprintf(fout, "%d\n", pop());   pop的內容會等到dequeue時再印出 
		}
		
		n++;
    }
	return 0;	
}

void push(int data)
{
	if(top>=MAXSTACK-1)
		fprintf(stderr, "stack is full.\n");
	else
	{
		top++;
		stack[top] = data;
	}
}

int pop()
{
	int data;
	if(top==-1)
		fprintf(stderr, "stack is empty.\n");
	else 
	{
		data = stack[top];
		top--;
		return data;		
	}		
}

void enqueue(char ch, int value)
{
	if(rear>=MAXQUEUE-1)	
		fprintf(stderr, "the queue is full.\n");
	else
	{
		rear++;
		queue[ch][rear] = value;
	}

}

int dequeue(char ch)
{
	if(front>=rear)
		fprintf(stderr, "the queue is empty.\n");
	else
	{
		front++;
		int data = queue[ch][front];
		return data;
	}
}

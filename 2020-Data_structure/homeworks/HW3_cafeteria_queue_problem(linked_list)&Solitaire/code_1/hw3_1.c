#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct stack * stackPointer;
typedef struct stack {
	int data;
	stackPointer link;
};
stackPointer top;
void push(int);
int pop();

typedef struct queue * queuePointer;
typedef struct queue {
	int data;
	queuePointer link;
};
queuePointer front[100], rear[100];
void enqueue(int, int);
int dequeue(int);


int main () 
{ 
	char str[100];
	
	while(scanf("%s", str)!=EOF) { 
		 // Extract the first token
		
   		int popvalue;

			if(strcmp(str, "PUSH")==0) //PUSH
			{
				int value;
			    scanf("%d", &value);
				push(value);
			}
			else if(strcmp(str, "ENQUEUE")==0) //ENQUEUE
			{
				char index;				
				scanf("%c", &index);
				if(index>=65 && index<=90)
					index -= 65;
				else if(index>=97 && index<=122)
					index -= 97;
				enqueue(index, popvalue); 
			}
			else if (strcmp(str, "DEQUEUE")==0) //DEQUEUE
			{
				char index;				
				scanf("%c", &index);
				if(index>=65 && index<=90)
					index -= 65;
				else if(index>=97 && index<=122)
					index -= 97;
				int popped = dequeue(index);
				printf("%d\n", popped);
			}	
			
		else if(strcmp(str, "POP")==0) //POP  
		{
			popvalue = pop();
			//fprintf(fout, "%d\n", pop());   pop的內容會等到dequeue時再印出 
		}
    }

	return 0;	
}

void push(int data)
{
	stackPointer tmp =  malloc(sizeof(*tmp));
	tmp->data = data;
	tmp->link = top;
	top = tmp;
}

int pop()
{
	stackPointer tmp = top;
	int data;
	if(!tmp)
		fprintf(stderr, "The stack is empty.\n");
	data = tmp->data;
	top = tmp->link;
	free(tmp);
	return data;
}

void enqueue(int index, int data)
{
	queuePointer tmp = malloc(sizeof(*tmp));
	tmp->data = data;
	tmp->link = NULL;
	if(front[index])
		rear[index]->link = tmp;
	else
		front[index]= tmp;
	rear[index] = tmp;
} 

int dequeue(int index)
{
	queuePointer tmp = front[index];
	int data;
	if(!tmp)
		fprintf(stderr, "The queue is empty.\n");
	data = tmp->data;
	front[index] = tmp->link;
	free(tmp);
	return data;
}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct pokerNode *pokerPointer;
typedef struct pokerNode {
	char point[2];
	pokerPointer next;
};
pokerPointer first, current, previous;

void printList();
pokerPointer searchNode(char[2]);
pokerPointer deleteNode(pokerPointer);

int main() 
{	
	int n = 0;	
	char str[2];
	int i;
	for(i = 0; i< 13; i++) //Åª¤Jªì©lµP²Õ 
	{
		current = malloc(sizeof(*current));
		scanf("%s", current->point);
		//current->point[2] = '\0';
		//if(strcmp(current->point,"-1")==0)
		//	break;
		if(n==0)
			first = current;
		else 
			previous->next = current;
		current->next = NULL;
		previous = current;
		n++;
	}
	printList();
	printf("\n");
	
	char toFind[2];
	for(i=13; i>0; i--)
	{
		if(i==13)
			strcpy(toFind, "K");
		else if(i==12)
			strcpy(toFind, "Q");
		else if(i==11)
			strcpy(toFind, "J");
		else if(i==1)
			strcpy(toFind, "A");
		else 
			sprintf(toFind,"%d",i);
		
		pokerPointer pos = searchNode(toFind);
		
		while(pos!=first)
		{
			pokerPointer last = first;
			pokerPointer first_record = first;
			while(last->next!=NULL)
				last = last->next;
			first = first_record->next;	
			first_record->next = NULL;
			last->next = first_record;
			
			printList();
			if(i>1)
				printf("\n");
		}

		first = deleteNode(pos);
		
		if(first!=NULL)
			printList();
		if(i>2)
			printf("\n");
	}

	return 0;
} 

void printList()
{   
	pokerPointer tmp = first;
	if(first==NULL)
		fprintf(stderr, "List is empty!\n");
	else 
	{
		while(tmp!=NULL)
		{
			printf("%s ", tmp->point);
			tmp = tmp->next;
		}
	}
}

pokerPointer searchNode(char toFind[2])
{
	pokerPointer tmp = first;
	while(tmp!=NULL)
	{
		if(strcmp(tmp->point, toFind) == 0)
			return tmp;
		else 
			tmp = tmp->next;
	}
	return NULL;
}

pokerPointer deleteNode(pokerPointer pos)
{
	pokerPointer tmp = first;
	if(first==NULL) 
	{
		fprintf(stderr, "List is empty!\n");
		return NULL;
	}
	first = first->next;
	free(pos);
	return first;	
} 

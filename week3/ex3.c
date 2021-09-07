#include <stdio.h>
#include <stdlib.h>

struct Node 
{
	int value;
	struct Node* next;
};

void print_list (struct Node* cur)
{
	while (cur != NULL)	
	{
		printf ("%d ", cur->value);
		cur = cur->next;
	}                  
}

void insert_node (struct Node *cur, struct Node *newNode, int prevValue)
{
	while (cur->value != prevValue)
		cur = cur->next;
	newNode->next = cur->next;	
	cur->next = newNode;
}

void delete_node (struct Node **head, int value)
{
	struct Node *cur;
	cur = *head;
	if ((*head)->value == value)
	{
		*head = (*head)->next;
		free (cur);
		return;
	}
	while (cur->next->value != value)
		cur = cur->next;
	cur->next = cur->next->next;
}

int main ()
{
	struct Node *head = NULL;
	struct Node *second = NULL;
	struct Node *third = NULL;

	head = (struct Node*) malloc (sizeof (struct Node));
	second = (struct Node*) malloc (sizeof (struct Node));
	third = (struct Node*) malloc (sizeof (struct Node));
	
	head->value = 1;
	second->value = 2;
	third->value = 3;
	
	head->next = second;
	second->next = third;
	third->next = NULL;
	                   
	printf ("Enter 1 to Insert Node\n");
	printf ("Enter 2 to Remove Node\n");
	printf ("Enter 3 to Print All Nodes\n");
	printf ("Enter 0 to Exit\n");
	while (1)
	{
		int x;
		scanf ("%d", &x);
		if (x == 0)
			return 0;
		if (x == 1)
		{	
			int v, p;
			printf ("Value: ");
			scanf ("%d", &v);
			printf ("After which Node (Value of Node): ");
			scanf ("%d", &p);
	 		
	 		struct Node *newNode = NULL; 
	 		newNode = (struct Node*) malloc (sizeof (struct Node));
	 		newNode->value = v;
			insert_node (head, newNode, p);
		}  
		if (x == 2)
		{
			int v;
			printf ("Value of Removing Node: ");
			scanf ("%d", &v);
			
			delete_node (&head, v);
		}
		if (x == 3)
		{
			printf ("List: ");
			print_list (head);
			printf ("\n");
		}
	}                   
}              
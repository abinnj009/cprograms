#include <stdio.h>
#include <stdlib.h>

typedef struct nodes {
int data;
struct  nodes *prev;
struct  nodes *next;
}node;

node *initializer(void *ptr,int data)
{
	node *p = malloc(sizeof(node));
	p->data = data;
	p->next = p->prev = ptr; 
}
node *head = NULL;
int insert_tail(int data)
{
	node *travel=NULL;
	node *temp = initializer(NULL,data);
	
	if(head==NULL) {
		//list empty
		head = temp;
		return 0;
	}
	else 	{
		//list is not empty so reach the last node
		travel = head;
		while(travel->next != NULL){
			travel = travel->next;
		}
		//now ptr travel is at the last node 
		travel->next = temp;
		temp->prev = travel;
	}
return 0;
}
void show_list(const node *head)
{
	const node *temp;
	if(head == NULL)
		printf("\n Ehh!, list is empty");
	else {
		temp = head;
		printf("\n");
		while(temp != NULL){
			printf("%d->",temp->data);
			temp = temp->next; 
		}
		printf("NULL");
	}
}

main()
{
//	head = malloc(sizeof(node));
//	head->data = 10;
//	head->next = head->prev = NULL;
	insert_tail(20);
	insert_tail(30);
	show_list(head);
}

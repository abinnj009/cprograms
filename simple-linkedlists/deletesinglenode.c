#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
}node;

int count = 0;
struct node *head = NULL;
void insert_end(int data)
{
	struct node *temp, *travel;
	temp = malloc(sizeof(struct node));
	temp->next = NULL;
	temp->data = data;

	if(head == NULL) {
		head = temp;
	}
	else {
		travel = head;
		while(travel->next != NULL){
			travel = travel->next;
		}
		travel->next = temp;	
	}
	count ++;

}
void show_list()
{
	struct node *travel;
	if(head == NULL) {
		printf("\nList empty!\n");
	}
	else {
		travel = head;
		while(travel != NULL) {
			printf("%d->",travel->data);
			travel = travel->next;
		}
		printf("NULL\n");
	}
}
int delete_node(int pos) 
{
	struct node *travel, *temp;
	int i = 0;
	if(head == NULL){
		//list empty
		return 0;
	}
	if(pos == 1) {
		temp = head;
		head = head->next;
	//	free(head);
		return 0;
	}
	travel = head;
	for(i;i<pos - 2;i++) {
		if(pos > count) //invalid pos
			return 0;
		travel = travel->next;
	}//travel->next is the node to be deleted
	if (travel->next->next == NULL) {//if thelast node
		free(travel->next);
		travel->next = NULL;//done
		return 0;
	}

	temp = travel->next;
	travel->next = travel->next->next;
	free(temp);
return 0;
}
int main()
{
	insert_end(50);
	insert_end(70);
	insert_end(90);
	insert_end(110);
	show_list();
	delete_node(1);
	show_list();
	return 0;
}

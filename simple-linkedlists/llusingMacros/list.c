#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

List *list_init(void (*destroy)(void *data),
	int (*cmp)(const void *fdata, const void *data))
{
	List *rlist;
	if((rlist = malloc(sizeof(*rlist))) != NULL) {
		rlist->head = NULL;
		rlist->tail = NULL;
		rlist->size = 0;
		rlist->destroy = destroy;
		rlist->cmp = cmp;
	}
	return rlist;
}

void list_destory(List *list) {

	ListElmt *el;
	void *data;
	while((el = list_head(list)) != NULL) {
		list_rem_next(list, NULL, &data);
		list->destroy(data);
	}
	free(list);
}

int list_ins_next(List *list, ListElmt *elmt, void *data)
{
	ListElmt *addElmt = malloc(sizeof *addElmt);
	if(addElmt == NULL)
		return -1;
	addElmt->data = data;
	if(elmt == NULL) {
		addElmt->nextElmt = list->head;
		elmt = list->head = addElmt; //using elmt for checking list tail
	}
	else {
		addElmt->nextElmt = elmt->nextElmt;
		elmt->nextElmt = addElmt;
	}
	//updating list->tail if needed
	if(elmt == list->tail)
		list->tail = addElmt;
	list->size++;
	return 0;
}

int list_ins_off(List *list, size_t off, void *data) 
{
	size_t i;
	ListElmt *elmt = NULL;
	if(off<0 || off >= list->size)
		return list_append(list, data);
	for(i = 0;i < off; ++i)
		elmt = elmt->nextElmt;
	return 0;

}
int list_drem_next(List *list, ListElmt *element) 
{
	void *data;
	int ret = list_rem_next(list, element, &data);
	if(ret != 0)
		return ret;
	list->destroy(data);
	return 0;
}

int list_rem_next(List *list, ListElmt *element, void **data)
{
	ListElmt *remElmt;

	//the list still not contain any element
	if(list->size ==0 || element->nextElmt ==NULL)
		return -1;
	*data = element->nextElmt->data;
	remElmt = element->nextElmt;
	
	element->nextElmt = element->nextElmt->nextElmt;
	if(remElmt == list->tail)
		list->tail = element;
	free(remElmt);
	list->size--;
	return 0;
}

ListElmt *find(List *list, void *data, ListElmt *sElmt)
{
	if(list->size == 0 || list->cmp == NULL)
		return NULL;
	sElmt = sElmt ? sElmt : list_head(list);
	while(sElmt && list->cmp(sElmt->data, data))
		sElmt = sElmt->nextElmt;
	return sElmt;
}
main()
{
}

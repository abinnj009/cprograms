#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

#define list_size(list) (list->size)

#define list_head(list) (list->head)
#define list_tail(list) (list->tail)
#define list_is_head(list,element) (element == list_head(list))
#define list_is_tail(list,element) (element == list_tail(list))

#define list_append(list, data) list_ins_next(list, list->tail, data)
#define list_preprend(list, data) list_ins_next(list, NULL, data)

#define list_data(element) (element->data)
#define list_next(element) (element->nextElmt)

typedef struct ListElmt_{
	void *data;
	struct ListElmt_ *nextElmt;
} ListElmt;

typedef struct List_{
	ListElmt *head;
	ListElmt *tail;
	size_t size;
	void (*destroy)(void *data);
	int (*cmp)(const void *fdata,const void *sdata);
}List;

List *list_init(void (*destroy)(void *data),int (*cmp)( \
	const void *fdata, const void *sdata));
void list_destroy(List *list);
int list_ins_off(List *list, size_t off, void *data);
int list_ins_next(List *list, ListElmt *element, void *data);
int list_drem_next(List *list, ListElmt *element);
int list_rem_next(List *list, ListElmt *element, void **data);
ListElmt *list_find(List *list, void *data, ListElmt *sElmt);
#endif


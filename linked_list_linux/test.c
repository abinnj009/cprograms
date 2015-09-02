#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef struct edge_attr {
	int d;
	struct list_head list;
} edge_attributes_t;

typedef struct edge {
	int id;
	edge_attributes_t *attributes;
} edge_t;

int main() {
	int i;
	struct list_head *pos;
	edge_attributes_t *elem;
	edge_t *a = (edge_t *)malloc(sizeof(edge_t));

	a->id = 12;
	a->attributes = (edge_attributes_t *)malloc(sizeof(edge_attributes_t));

	INIT_LIST_HEAD(&a->attributes->list);

	for( i = 0; i < 5; ++i) {
		elem = (edge_attributes_t *)malloc(sizeof(edge_attributes_t));
		elem->d = i;
		list_add(&elem->list, &a->attributes->list);
	}
	list_for_each(pos, &(a->attributes->list)) {
		elem = list_entry(pos, edge_attributes_t, list);
		printf("%d\n", elem->d);
	}
	return 0;
}

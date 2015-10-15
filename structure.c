#include <stdio.h>
#include <stdlib.h>
struct my_struct
{
	int x;
	int y;
}*obj;

struct my_struct* pointer(int c, int d)
{
obj->x = c;
obj->y = d;
return obj;
}
int main()
{
	obj = (struct my_struct*) malloc(sizeof(struct my_struct));
	struct my_struct *pqq;
	pqq = obj;
	pqq = pointer(10,12);
	printf("x:%d,y:%d",pqq->x,pqq->y);
	return 0;
}

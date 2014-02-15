/*
 * sorted-list.c
 */

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	"sorted-list.h"

int compareInts(void *p1, void *p2)
{
	int i1 = *(int*)p1;
	int i2 = *(int*)p2;

	return i1 - i2;
}

int compareDoubles(void *p1, void *p2)
{
	double d1 = *(double*)p1;
	double d2 = *(double*)p2;

	return (d1 < d2) ? -1 : ((d1 > d2) ? 1 : 0);
}

int compareStrings(void *p1, void *p2)
{
	char *s1 = p1;
	char *s2 = p2;

	return strcmp(s1, s2);
}

int main(int argc, char** argv)
{ //integer test
	int testList = {5,5,5,5,5};
	int *intPtr;

	SortedListPtr sl = SLCreate(compareInts, NULL);

	//SLInsert(sl, intPtr);

	SortedListIteratorPtr iterator = SLCreateIterator(sl);

	//printf("%d\n",SLNextItem(iterator));


	SLDestroy(sl);
	SLDestroyIterator(iterator);
}

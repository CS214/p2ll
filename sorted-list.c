/*
*sorted-list.c
*
*Big-O analysis:
*
*
*
*/

#include "sorted-list.h"

SortedListPtr SLCreate(CompareFuncT cf, DestructFuncT df){
	SortedListPtr sl = (SortedListPtr) malloc(sizeof(struct SortedList));
	sl->head = NULL;
	sl->comparator = cf;
	sl->destroyer = df;

	return sl;
}

void SLDestroy(SortedListPtr list){ //NOT COMPLETED
	if(list != NULL) //when list is done make loop to traverse through entire tree
		free(list);
}

int SLInsert(SortedListPtr list, void *newObj){
	return 0;
}

int SLRemove(SortedListPtr list, void *newObj){ //NOT COMPLETED
	return 0;
}

SortedListIteratorPtr SLCreateIterator(SortedListPtr list){
	return NULL;
}

void SLDestroyIterator(SortedListIteratorPtr iter){ //NOT COMPLETED
	if(iter != NULL)
		free(iter);
}

void *SLNextItem(SortedListIteratorPtr iter){ //NOT COMPLETED
	return NULL;
}
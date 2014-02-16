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
{
	 //***************** INTEGER TEST ***********************
	/*int testList[] = {-6, -6, 5, 7, 2, 10, 1 ,5 ,3 ,3};
	int i;
	int *intPtr;

	SortedListPtr sl = SLCreate(compareInts, NULL);
	
	for(i=0; i<(sizeof(testList)/sizeof(testList[0])); i++){
		intPtr = &testList[i];
		SLInsert(sl, intPtr);
	}

	SortedListIteratorPtr iterator = SLCreateIterator(sl);

	intPtr = SLNextItem(iterator);

	while((intPtr = (int*)SLNextItem(iterator)) != NULL){
		printf("%d\n", *intPtr);
	}

	SLDestroy(sl);
	SLDestroyIterator(iterator);*/
	
	//***************** STRING TEST ***********************
	int i;
	char* string1 = "Hey";
	char* string2 = "Boy";
	char* string3 = "Zeus";
	char* stringPtr = (char*) malloc(sizeof(string3));

	SortedListPtr stringsl = SLCreate(compareStrings, NULL);

	SLInsert(stringsl, string1);
	SLInsert(stringsl, string2);
	SLInsert(stringsl, string3);
	
	/*for(i=0; i<(sizeof(stringList)/sizeof(stringList[0])); i++){
		stringPtr = (char*) stringList[i];
		SLInsert(sl, stringPtr);
	}*/

	SortedListIteratorPtr stringiterator = SLCreateIterator(stringsl);

	while((stringPtr = (char*) SLNextItem(stringiterator)) != NULL){
		printf("%s\n", stringPtr);
	}

	SLDestroy(stringsl);
	SLDestroyIterator(stringiterator);
}

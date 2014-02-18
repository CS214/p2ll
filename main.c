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

int main(int argc, char** argv){

	//***************** STRING TEST ***********************
	int i;
	const char* stringList[] = {"Hey", "Boy", "Zeus", "world", " ", "blah", " zzz", "aaa"};

	char* stringPtr = (char*) malloc(sizeof(stringList));

	SortedListPtr stringsl = SLCreate(compareStrings, NULL);
	/*
	for(i=0; i<(sizeof(stringList)/sizeof(stringList[0])); i++){
		stringPtr = (char*) stringList[i];
		SLInsert(stringsl, stringPtr);
	}
	*/
	SortedListIteratorPtr stringiterator2 = SLCreateIterator(stringsl);
	SLNextItem(stringiterator2);

	SLInsert(stringsl, "f");
	SLInsert(stringsl, "d");
	SLInsert(stringsl, "b");
	//SLRemove(stringsl, "Apple");
	
	
	
	
	SortedListIteratorPtr stringiterator = SLCreateIterator(stringsl);

	while((stringPtr = (char*) SLNextItem(stringiterator)) != NULL){
		printf("%s\n", stringPtr);
	}

	//cleans mess
	free(stringPtr);
	SLDestroy(stringsl);
	SLDestroyIterator(stringiterator);
}
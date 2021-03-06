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

void SLDestroy(SortedListPtr list){
	if(list == NULL)
		return; // dont do anything
	else{
		NodePtr deleter;

		while(list->head != NULL){ //delete all dynamically allocated nodes
			deleter = list->head;
			list->head = list->head->next;
			free(deleter);
		}

		free(list); //then free the structure
	}
}

int SLInsert(SortedListPtr list, void *newObj){
	if(list == NULL)
		return 0; //error list wasn't created correctly
	else{
		NodePtr tempNode = (NodePtr) malloc(sizeof(struct Node));
		tempNode->data = newObj;
		tempNode->next = NULL;

		if(list->head == NULL){ //if this is the first item to be added to the list
			list->head = tempNode;
		}
		else if(list->head->next == NULL){ //there is only 1 item in the list
			if(list->comparator(list->head->data, newObj) == 0){ //same as head
				free(tempNode); //don't need it to store data
				return 0; //duplicate error;
			}
			else if(list->comparator(list->head->data, newObj) > 0){ //new object is smaller (it becomes second on list)
				list->head->next = tempNode;
				return 1;
			}
			else{ //new object is larger, it becomes the head
				tempNode->next = list->head;
				list->head = tempNode;
				return 1;
			}
		}
		else{ //there are at least 2 items in the list
			if(list->comparator(list->head->data, newObj) == 0){ //since the loop beggins on second object we must check it against head first
				free(tempNode);
				return 0;
			}
			else if(list->comparator(list->head->data, newObj) < 0){ //if object is larger than head it becomes head
				tempNode->next = list->head;
				list->head = tempNode;
				return 1;
			}

			NodePtr traverse = list->head->next;
			NodePtr lagging = list->head;
			while(traverse != NULL){
				if(list->comparator(traverse->data, newObj) == 0){ //duplicate
					free(tempNode); //don't need it to store data
					return 0; //duplicate error
				} 		
				else if(list->comparator(traverse->data, newObj) > 0){ //new object is smaller (it goes towards end of list)
					lagging = traverse;
					traverse = traverse->next;
				}
				else{ //new object is larger (add it to this spot)
					tempNode->next = traverse;
					lagging->next = tempNode;
					return 1;
				}
			}
			if(list->comparator(lagging->data, newObj) > 0){ //tests one more time, if smaller than last item, adds to the end of the list
				lagging->next = tempNode;
			}
		}
	}
	return 1; //makes compiler happy
}

int SLRemove(SortedListPtr list, void *newObj){ //NOT COMPLETED

	if(list == NULL)
		return 0;
	else if(list->head == NULL)
		return 0;
	
	else if(list->comparator(list->head->data, newObj) == 0){
		list->head = list->head->next;
	}
	else
	{
		NodePtr lagging = list->head;
		NodePtr traverse = list->head->next;

		while(traverse != NULL)
		{
			if(list->comparator(traverse->data, newObj) == 0)
			{
				lagging->next = traverse->next;
				free(traverse);
				return 1;
			}
			else
			{
				lagging = traverse;
				traverse = traverse->next;
			}
		}
		if(list->comparator(lagging->data, newObj) == 0)
		{
			free(lagging);
			return 1;
		}
	}	
	return 0;
}

SortedListIteratorPtr SLCreateIterator(SortedListPtr list){
	if(list == NULL || list->head == NULL) //list must be initialized and have at least one item
		return NULL;
	
	SortedListIteratorPtr iterator = (SortedListIteratorPtr) malloc(sizeof(struct SortedListIterator));
	iterator->currentNode = list->head;
	iterator->nextNode = list->head->next;
	
	return iterator;
}

void SLDestroyIterator(SortedListIteratorPtr iter){
	if(iter != NULL) //all we have to free is iter, not anything it points to in the list
		free(iter);
}

void *SLNextItem(SortedListIteratorPtr iter){ //make sure all those cases are taken care of
	if(iter == NULL)
		return NULL;
	else if(iter->currentNode == NULL)
		return NULL; //returning a null terminates the loop when printing the it
	else{
		void * dataReturned = malloc(sizeof(iter->currentNode->data));
		dataReturned = iter->currentNode->data;
		iter->currentNode = iter->nextNode;
		if(iter->nextNode != NULL)
			iter->nextNode = iter->nextNode->next;
		
		return dataReturned;
	}	
}

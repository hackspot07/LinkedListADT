#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>


LinkedList createList(void){
	LinkedList *new_list = malloc(sizeof(LinkedList));
	new_list->head = NULL;
	new_list->tail = NULL;
	new_list->count = 0;
	return *new_list;
};

#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


LinkedList createList(void){
	LinkedList *new_list = malloc(sizeof(LinkedList));
	if(new_list != NULL){ 
		new_list->head = NULL;
		new_list->tail = NULL;
		new_list->count = 0;
		return *new_list;
	}else{
		printf("%s\n","Memory does not exist");
		return *new_list;
	}
};

Node * create_node(void *data){
	Node *new_node = malloc(sizeof(Node));
	if(new_node != NULL){ 
		new_node->data = data;
		new_node->next = NULL;
		return new_node;
	}else{
		printf("%s\n","Memory does not exist");
		return 0;
	}
};

int add_to_list(LinkedList* list, Node* node){
	if(list->head == NULL)
		list->head = node;

    while(list->head->next != NULL){ 
		list->head = *(list->head->next);
		list->count++;
	}
	list->tail = node;
	list->count++;
    return list->count;
};
    

void *get_first_element(LinkedList list){
	return list.head;
};

void *get_last_element(LinkedList list){
	return list.tail;
};
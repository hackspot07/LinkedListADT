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
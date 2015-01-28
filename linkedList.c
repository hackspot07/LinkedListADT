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

int add_to_list(LinkedList* studentList, Node* student){
	Node_ptr walker = studentList->head;
	if(walker == NULL){
		studentList->head = student;
		studentList->tail = student;
		studentList->count = 1;
		return 1;
	}
	while(walker != NULL){
		walker = *student->next;
		if(walker==NULL){
			walker = student;
			studentList->tail = student;
			return 1;
		}
		studentList->count++;
	}
	return 0;
};
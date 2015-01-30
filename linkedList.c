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
    else
    	list->tail->next = node;
	list->tail = node;
	list->count++;
    return list->count;
};
    

void *get_first_element(LinkedList list){
	return list.head;
};

void *get_last_element(LinkedList list){
	return list.tail;
}

void traverse(LinkedList list,Operation* operate){
	while(list.head != NULL){
		operate(&(list.head->data));
		list.head = list.head->next;
	}
};

void * getElementAt(LinkedList list, int index){
	int i = 0;
	if(list.count<index || index<0)
		return NULL;
	while(i<=index){
		if(i==index)
			return list.head->data;
		list.head = list.head->next;
		i++;
	}
	return NULL;
};

int indexOf(LinkedList list,void* data){
	int index = 0;
	while(list.head != NULL){
		if(list.head->data == data)
			return index;
		index++;
		list.head = list.head->next;
	}
	return -1;
};


void* deleteHead(LinkedList *list,int index){
	Node_ptr walker = list->head;
	list->head = list->head->next;
	if(list->count==0)
		list->tail = NULL;
	return walker->data;
};

void * deleteElementAt(LinkedList* list, int index){
	int i=0;
	Node_ptr walker = list->head;
	Node_ptr temp;
	if(index==0)
		return deleteHead(list,0);
	for(i=0;i < list->count;i++){
		temp = walker;
		walker = walker->next;
		if(i==index-1){
			list->count--;
			(walker->next==NULL)?(list->tail = temp):(temp->next = walker->next);
			return walker->data;
		};
	}
	return NULL;
};	
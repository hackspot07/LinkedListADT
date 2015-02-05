#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


LinkedList createList(void){
	LinkedList *new_list = calloc(sizeof(LinkedList),1);
	new_list->head = new_list->tail = NULL;
	new_list->count = 0;
	return *new_list;
};

Node * create_node(void *data){
	Node *new_node = calloc(sizeof(Node),1);
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
	Node_ptr prev = list->head;
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


void * deleteElementAt(LinkedList * list, int index){
	int i= 0;
	Node_ptr walker = list->head;
	Node_ptr temp = NULL;
	void* deletedElement;

	if(list->count <=index || index<0)
		return NULL;

	for(i=0; i< index; i++){
		temp = walker;
		walker = walker->next;
	}	

	if(list->tail==walker){
		list->tail=temp;
	}

	deletedElement = walker->data;
	(temp)?(temp->next =walker->next):(list->head =list->head->next);

	list->count--;
	free(walker);
	return deletedElement;
};

int asArray(LinkedList list, void** array){
	int i;
	for(i=0;i<list.count;i++){
		array[i] = list.head;
		list.head = list.head->next;
	}
	return i;
};

LinkedList * filter(LinkedList list,Predicate* test){
	LinkedList *result = malloc(sizeof(LinkedList));
	int i;
	*result = createList();
	for(i=0;i<list.count;i++){
		if(test(list.head->data)){
			add_to_list(result,list.head);
		}
		list.head = list.head->next;
	}
	return result;
};

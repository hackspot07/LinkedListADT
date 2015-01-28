#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

void* createNode(void){
	Node *new_node = malloc(sizeof(Node));
	printf("%p in function\n",new_node);
	
	return new_node;
};
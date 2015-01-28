#include "linkedlist.h"
#include "expr_assert.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void test_create_a_linkedList_it_return_head_NULL(){
	int count = 0;
	LinkedList expected = createList();
	assertEqual(0,(int)expected.head);
	assertEqual(0,(int)expected.tail);
};

void test_create_a_linkedList_it_return_with_0_element(){
	int count = 0;
	LinkedList expected = createList();
	assertEqual(count,((int)expected.count));
};

void test_create_a_node_it_contain_data_45_and_NULL(){
	int data = 45;
	Node *expected = create_node((void*)data);

	assertEqual(data,(int)expected->data);
	assertEqual((int)NULL,(int)expected->next);
	free(expected);
};

void test_create_a_node_it_contain_data_Parmatma_and_NULL(){
	char* data = "Parmatma";
	Node *expected = create_node((void*)data);
	char* expData = expected->data;

	assertEqual(strcmp(expData,data),0);
	assertEqual(0,(int)expected->next);
	free(expected);
};
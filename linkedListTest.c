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
	LinkedList expected = createList();
	assertEqual(0,((int)expected.count));
};

void test_create_a_node_it_contain_id_45_and_NULL(){
	int data = 45;
	Node *expected = create_node((void*)data);

	assertEqual(data,(int)expected->data);
	assertEqual(0,(int)expected->next);
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

void test_add_to_list_add_the_element_into_list_and_return_1(){
	int id = 23,yes;
	LinkedList student = createList();
	Node *expected = create_node((void*)id);
	yes = add_to_list(&student,expected);

	assertEqual(yes,1);
};

void test_add_to_list_add_the_element_into_list_and_give_count_1(){
	char* id = "hello";
	int yes;
	LinkedList student = createList();
	Node *expected = create_node((void*)id);
	yes = add_to_list(&student,expected);

	assertEqual(student.count,1);
};
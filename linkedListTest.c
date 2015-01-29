#include "linkedlist.h"
#include "expr_assert.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

LinkedList initialize(LinkedList list){
	int score1=23,score2=45;
	Node_ptr nodeToInsert,nodeToInsert1;

	nodeToInsert = create_node((void*)score1);
	add_to_list(&list,nodeToInsert);

	nodeToInsert1 = create_node((void*)score2);
	add_to_list(&list,nodeToInsert1);

	return list;
};

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
	Node_ptr expected = create_node((void*)data);

	assertEqual(data,(int)expected->data);
	assertEqual(0,(int)expected->next);
	free(expected);
};

void test_create_a_node_it_contain_data_Parmatma_and_NULL(){
	char* data = "Parmatma";
	Node_ptr expected = create_node((void*)data);
	char* expData = expected->data;

	assertEqual(strcmp(expData,data),0);
	assertEqual(0,(int)expected->next);
	free(expected);
};

void test_add_to_list_add_the_element_into_list_and_return_1(){
	int id = 23,count;
	LinkedList list = createList();
	Node_ptr expected = create_node((void*)id);
	count = add_to_list(&list,expected);

	assertEqual(count,1);
	free(expected);
};

void test_add_to_list_add_the_element_into_list_and_give_count_1(){
	char* name = "hello";
	char *name1 = "gello";
	int count;
	Node_ptr expected1,expected;
	LinkedList list = createList();

	expected = create_node((void*)name);
	count = add_to_list(&list,expected);
	
	expected1 = create_node((void*)name1);
	count = add_to_list(&list,expected1);

	assertEqual(count,2);
	free(expected);
	free(expected1);
};

void test_get_first_element_will_return_23(){
	Node *result;
	int id=23;
	LinkedList list = createList();
	list = initialize(list);
	result = get_first_element(list);

	assertEqual((int)result->data,23);
};

void test_get_last_will_return_45(){
	Node *result;
	LinkedList list = createList();
	list = initialize(list);
	result = get_last_element(list);

	assertEqual((int)result->data,45);
};

void increament(void* data){
	*(int*)data = *(int*)data + 1;
};

void test_traverse_gives_all_elements_by_increament_followed_by_one(){
	Node *result;
	LinkedList list = createList();
	list = initialize(list);

	traverse(list,increament);
	result = get_first_element(list);

	assertEqual((int)result->data, 24);
};

void test_traverse_gives_all_elements_by_increament_followed_by_one_get_last_46(){
	Node *result;
	LinkedList list = createList();
	list = initialize(list);

	traverse(list,increament);
	result = get_last_element(list);

	assertEqual((int)result->data, 46);
};

void changeCase(void* data){
	int i = 0;
	char* string1 = malloc(sizeof(char*));
	strcpy(string1,*(char**)data);
	while(string1[i]!='\0'){ 
		*((char*)string1) = *((char*)string1) - 32;
		i++;
	}
};

void test_traverse_gives_string_into_uppercase(){
	char* name = "hello";
	char *name1 = "gello";
	Node *result;
	Node_ptr expected1,expected;
	LinkedList list = createList();

	expected = create_node((void*)name);
	add_to_list(&list,expected);
	
	expected1 = create_node((void*)name1);
	add_to_list(&list,expected1);
	traverse(list,changeCase);

	result = get_first_element(list);

	assertEqual(strcmp("hello",result->data),0);
	free(expected);
	free(expected1);
};

void test_traverse_gives_string_into_uppercase_of_last_node(){
	char* name = "hello";
	char *name1 = "gello";
	Node *result;
	Node_ptr expected1,expected;
	LinkedList list = createList();

	expected = create_node((void*)name);
	add_to_list(&list,expected);
	
	expected1 = create_node((void*)name1);
	add_to_list(&list,expected1);
	traverse(list,changeCase);

	result = get_last_element(list);

	assertEqual(strcmp("gello",result->data),0);
	free(expected);
	free(expected1);
};
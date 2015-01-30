#include "linkedlist.h"
#include "expr_assert.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

LinkedList initialize(LinkedList list){
	int score1=23,score2=-12,score3=45;
	Node_ptr nodeToInsert,nodeToInsert1,nodeToInsert2;

	nodeToInsert = create_node((void*)score1);
	add_to_list(&list,nodeToInsert);

	nodeToInsert1 = create_node((void*)score2);
	add_to_list(&list,nodeToInsert1);

	nodeToInsert2 = create_node((void*)score3);
	add_to_list(&list,nodeToInsert2);

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

void test_add_to_list_add_the_student_record_into_list(){
	Student stu1;
	LinkedList list = createList();
	int count;
	Node* st;
	Node_ptr expected;
	stu1.id = count;
	stu1.name = "Parma";
	stu1.score = 20;
	expected = create_node(&stu1);
	count = add_to_list(&list,expected);
	st = get_first_element(list);

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
	for(i=0;string1[i]!='\0';i++)
		string1[i] = string1[i] - 32;
	*(char**)data = string1;
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

	assertEqual(strcmp("HELLO",result->data),0);
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

	assertEqual(strcmp("GELLO",result->data),0);
	free(expected);
	free(expected1);
};

void test_getelementAt_will_give_45_at_2(){
	LinkedList list = createList();
	void* result;
	list = initialize(list);
	result = getElementAt(list,2);

	assertEqual((int)result,45);
};

void test_getelementAt_will_give_NULL_at_4(){
	LinkedList list = createList();
	void* result;
	list = initialize(list);
	result = getElementAt(list,4);

	assertEqual((int)result,0);
};

void test_getelementAt_will_give_NULL_at_minus_1(){
	LinkedList list = createList();
	void* result;
	list = initialize(list);
	result = getElementAt(list,-1);

	assertEqual((int)result,0);
};

void test_getElementAt_will_give_hello_at_0(){
	char* name = "hello";
	char *name1 = "gello";
	void *result;
	Node_ptr expected1,expected;
	LinkedList list = createList();

	expected = create_node((void*)name);
	add_to_list(&list,expected);
	
	expected1 = create_node((void*)name1);
	add_to_list(&list,expected1);
	result = getElementAt(list,0);

	assertEqual(strcmp("hello",(char*)result),0);
	free(expected);
	free(expected1);
};


void test_indexof_will_give_index_2_for_45(){
	LinkedList list = createList();
	int data = 45,index;
	list = initialize(list);
	index = indexOf(list,(void*)data);

	assertEqual(index,2);
};

void test_indexof_will_give_index_0_for_23(){
	LinkedList list = createList();
	int data = 23,index;
	list = initialize(list);
	index = indexOf(list,(void*)data);

	assertEqual(index,0);
};

void test_indexof_will_give_index_minus_1_for_minus_23(){
	LinkedList list = createList();
	int data = -23,index;
	list = initialize(list);
	index = indexOf(list,(void*)data);

	assertEqual(index,-1);
};

void test_indexOf_will_give_1_for_gello(){
	char* name = "hello";
	char *name1 = "gello";
	int result;
	char* data = "gello";
	Node_ptr expected1,expected;
	LinkedList list = createList();

	expected = create_node((void*)name);
	add_to_list(&list,expected);
	
	expected1 = create_node((void*)name1);
	add_to_list(&list,expected1);
	result = indexOf(list,(void*)data);

	assertEqual(result,1);
	free(expected);
	free(expected1);
};


void test_delete_will_return_deleted_element_of_index_1(){
	Node_ptr result;
	void *result1;
	LinkedList list = createList();
	list = initialize(list);
	result = deleteElementAt(&list,1);
	result1 = getElementAt(list,0);

	assertEqual((int)result,-12);
	assertEqual((int)result1,23);
};

void test_delete_will_return_deleted_element_of_index_0(){
	Node_ptr result;
	void *result1;
	LinkedList list = createList();
	list = initialize(list);
	result = deleteElementAt(&list,0);
	result1 = getElementAt(list,0);

	assertEqual((int)result,23);
	assertEqual((int)result1,-12);
};

void test_delete_will_return_deleted_element_of_index_2(){
	Node_ptr result;
	void *result1;
	LinkedList list = createList();
	list = initialize(list);
	result = deleteElementAt(&list,2);
	result1 = getElementAt(list,0);

	assertEqual((int)result,45);
	assertEqual((int)result1,23);
};

void test_delete_will_return_deleted_tail_element_and_fix_another_tail(){
	Node_ptr result;
	Node_ptr result1;
	LinkedList list = createList();
	list = initialize(list);
	result = deleteElementAt(&list,2);
	result1 = get_last_element(list);

	assertEqual((int)result,45);
	assertEqual(*(int*)result1,-12);
};

void test_deleteElemetAt_will_delete_hello_and_give_gell_atFirst_index(){
	char* name = "hello";
	char *name1 = "gello";
	Node_ptr expected1,expected,result;
	LinkedList list = createList();

	expected = create_node((void*)name);
	add_to_list(&list,expected);
	
	expected1 = create_node((void*)name1);
	add_to_list(&list,expected1);

	result = deleteElementAt(&list,0);

	assertEqual(strcmp((char*)result,"hello"),0);
	free(expected);
	free(expected1);
};


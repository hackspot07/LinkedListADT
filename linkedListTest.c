#include "linkedlist.h"
#include "expr_assert.h"
#include <stdio.h>


void test_create_a_linkedList_it_return_head_NULL(){
	void *head = NULL,*tail = NULL;
	int count = 0;
	LinkedList expected = createList();
	assertEqual((int)head,((int)expected.head));
	assertEqual((int)tail,((int)expected.head));
};

void test_create_a_linkedList_it_return_with_0_element(){
	void *head = NULL,*tail = NULL;
	int count = 0;
	LinkedList expected = createList();
	assertEqual(count,((int)expected.count));
};
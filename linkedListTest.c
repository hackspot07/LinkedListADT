#include "linkedlist.h"
#include <stdio.h>


int main(int argc, char const *argv[]){ 
	Node_ptr new_node = createNode();
	printf("%p In main\n",new_node);
	return 0;
}

/*void test_create_a_linkedlist_that_contain_student_detail(){
	Node *new_node;
	new_node = createNode();
	printf("%p>>>>",new_node);
};*/
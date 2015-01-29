typedef struct node Node;
typedef Node * Node_ptr;

typedef struct linked_list LinkedList;
typedef LinkedList * linkedList_ptr;

struct linked_list{
	Node_ptr head;
	Node_ptr tail;
	int count;
};

struct node{
	void* data;
	Node_ptr *next;
};


LinkedList createList(void);
Node * create_node(void *data);
int add_to_list(LinkedList *,Node *);
void *get_first_element(LinkedList list);
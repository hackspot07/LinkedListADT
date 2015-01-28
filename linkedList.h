typedef struct node Node;
typedef Node * Node_ptr;

typedef struct linked_list LinkedList;

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
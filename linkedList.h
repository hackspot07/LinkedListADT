typedef struct node Node;
typedef Node * Node_ptr;
typedef struct student Student;

typedef struct linked_list LinkedList;
typedef LinkedList * linkedList_ptr;
typedef void Operation (void*); 
typedef int Predicate (void*);

struct linked_list{
	Node_ptr head;
	Node_ptr tail;
	int count;
};

struct node{
	void* data;
	Node_ptr next;
};

struct student{
	int id;
	char* name;
	int score;
};

LinkedList createList(void);
Node * create_node(void *data);
int add_to_list(LinkedList *,Node *);
void *get_first_element(LinkedList list);
void *get_last_element(LinkedList list);
void traverse(LinkedList list,Operation* operate);
void * getElementAt(LinkedList list, int index);
int indexOf(LinkedList list, void *node);
void * deleteElementAt(LinkedList* list, int index);
int asArray(LinkedList list, void** array);
LinkedList * filter(LinkedList list,Predicate* test);

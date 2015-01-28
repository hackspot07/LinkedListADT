typedef struct node Node;
typedef Node * Node_ptr;
typedef struct linked_list linkedList;

typedef struct student Student;
typedef  Student * Student_ptr;

struct linked_list{
	Node_ptr head;
	Node_ptr tail;
	int count;
};

struct node{
	void* data;
	Node_ptr *next;
};

struct student{
	char* name;
	int id;
	int score;	
}; 

void* createNode(void);

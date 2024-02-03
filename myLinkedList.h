//This is my linked list.h
struct node {
	int val;
	struct node *next;
};

struct node *addNodeToList(struct node *first, int val);

void printList(struct node *first, FILE *f);
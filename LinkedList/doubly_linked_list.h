#ifndef doubly_linked_list
#define doubly_linked_list

// Node struct
struct node {
	int x;
	struct node *next;
	struct node *prev;
};

void print_list(struct node* root);
void add(struct node* root, int x);
void addItemIndex(struct node *root, int index, int x);
struct node * addItemOrdered(struct node *root, int x);
struct node *delete(struct node *root, int x);

#endif

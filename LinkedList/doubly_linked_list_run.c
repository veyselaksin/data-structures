#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

int main(){
	struct node* root;

	root = (struct node*)malloc(sizeof(struct node));
	// root -> x = 1;
	// root -> next = NULL;
	// add(root, 2);
	// add(root, 3);
	// add(root, 4);
	// add(root, 5);


	root = NULL;
	root = addItemOrdered(root, 100);
	root = addItemOrdered(root, 10);
	root = addItemOrdered(root, 20);
	root = addItemOrdered(root, 500);
	root = delete(root, 500);
	root = delete(root, 20);

	/* root = delete(root, 100); */
	/* root = delete(root, 4); */


	// addItemIndex(root, 2, 100);
	print_list(root);
	
	return 0;
}

//---- BASIC LINKED LIST IMPLEMENTATION IN C ----

#include "stdio.h"
#include "stdlib.h"

// Node struct
struct node {
	int x;
	struct node* next;
};

// Print linked list
void print_list(struct node* root){
	struct node* temp = root;
	while(temp != NULL){
		printf("%d \n", temp -> x);
		temp = temp -> next;
	}
}

void add(struct node* root, int x){
	struct node* temp = root;
	while(temp -> next != NULL){
		temp = temp -> next;
	}

	temp -> next = (struct node*)malloc(sizeof(struct node));
	temp -> next -> x = x;
	temp -> next -> next = NULL;
}

void addItemIndex(struct node *root, int index, int x){
	struct node *iter = root;

	int i;
	for(i=0; i<index; i++)
		iter = iter->next;

	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->next = iter->next;
	iter->next = temp;
	temp->x = x;
		
}

struct node * addItemOrdered(struct node *root, int x){
	if (root==NULL){
		root = (struct node*)malloc(sizeof(struct node));
		root->next = NULL;
		root->x = x;
		return root;
	}

	if (root->x > x){
		struct node *temp = (struct node*)malloc(sizeof(struct node));
		temp->x = x;
		temp->next = root;
		return temp;
	}

	struct node *iter = root;
	while (iter->next != NULL && iter->next->x < x){
		iter = iter->next;
	}

	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->next = iter->next;
	iter->next = temp;
	temp->x = x;

	return root;
}

struct node * addItemCircular(struct node *root, int x){
	if (root == NULL){
		root = (struct node*)malloc(sizeof(struct node));
		root -> next = root;
		root -> x = x;

		return root;
	}

	if (root->x > x){
		struct node *temp = (struct node *)malloc(sizeof(struct node));
		temp -> x = x;
		temp -> next = root;

		struct node *iter = root;
		while (iter->next != root)
			iter = iter -> next;
		iter -> next = temp;
		return temp;
	}

	struct node *iter = root;
	while(root -> next != root && iter->next->x < x ){
		iter = iter->next;
	}

	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp -> next = iter -> next;
	iter -> next = temp;
	temp -> x = x;

	return root;
}

struct node *delete(struct node *root, int x){
	struct node *temp;
	struct node *iter = root;

	if(root->x == x){
		temp = root;
		root = root->next;
		free(temp);
		return root;
	}

	while(iter->next != NULL && iter->next->x != x){
		iter = iter->next;
	}

	if(iter->next == NULL){
		printf("number not found!\n");
		return root;
	}

	temp = iter->next;
	iter->next = iter->next->next;
	free(temp);
	return root;

}


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

	/* root = addItemCircular(root, 100); */
	/* root = addItemCircular(root, 10); */
	/* root = addItemCircular(root, 20); */
	root = delete(root, 100);
	root = delete(root, 4);
	/* root = addItemCircular(root, 200); */


	// addItemIndex(root, 2, 100);
	print_list(root);
	
	return 0;
}


//---- DOUBLY LIST IMPLEMENTATION IN C ----

#include "stdio.h"
#include "stdlib.h"
#include "doubly_linked_list.h"

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
		root->prev = NULL;
		root->x = x;
		return root;
	}

	if (root->x > x){
		struct node *temp = (struct node*)malloc(sizeof(struct node));
		temp->x = x;
		temp->next = root;
		temp->prev = NULL;
		return temp;
	}

	struct node *iter = root;
	while (iter->next != NULL && iter->next->x < x){
		iter = iter->next;
	}

	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->next = iter->next;
	temp->prev = iter;
	if (iter -> next != NULL)
		iter -> next -> prev = temp;
	iter->next = temp;
	temp->x = x;

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
	if (iter -> next != NULL)
		iter -> next -> prev = temp;
	return root;

}


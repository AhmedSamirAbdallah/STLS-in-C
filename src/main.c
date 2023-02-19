/*
 ============================================================================
 Name        : SingleLinkedList.c
 Author      : Ahmed Samir
 Version     :
 Copyright   : Your copyright notice
 Description : Single Linked List C
 ============================================================================
 */

#include "SLL.h"


int main(void) {
	struct Node* head = NULL; //define head of Linked List
	int size = 0 , n = 0;//start size of LinkedList with zero
	puts("Enter Size of Linked List");
	scanf("%d",&n);
	for(int i=0;i<=n;i++)insert_at(&head,i, i+1, &size);
	print_sll(&head);
	for(int i=n;i>=1;i--)push_front(&head, 7, &size);
	print_sll(&head);
	for(int i=1;i<=n;i++)push_back(&head, 7, &size);
	print_sll(&head);
	for(int i=1;i<=n;i++)pop_back(&head, &size);
	print_sll(&head);
	for(int i=1;i<=n;i++)pop_front(&head, &size);
	print_sll(&head);
	erase_at(&head,0,&size);
	print_sll(&head);
	push_back(&head,6,&size);
	push_back(&head,6,&size);
	print_sll(&head);
	erase_last_occuerence_of_value(&head,6,&size);
	print_sll(&head);
	erase_all_occuarence_of_value(&head,6,&size);
	print_sll(&head);
	for(int i=0;i<=n;i++)insert_at(&head,i, i+1, &size);
	print_sll(&head);
	unique_sll(&head,&size);
	print_sll(&head);
	printf("size  = %d\n",size);
	int idx =search(&head,6); // return place zero based or return -1 if not founded
	idx<0?puts("Not Found"):printf("%d\n",idx);
	return EXIT_SUCCESS;
}


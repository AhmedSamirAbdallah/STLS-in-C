/*
 *  SLL -> (Single Linked List)
 *
 *  Created on: Feb 12, 2023
 *
 *  Author: Ahmed Samir
 */
#include "SLL.h"


void insert_at(struct Node ** headRef, int index, int data, int* size){
	if(*(size)<index)return;
	if(!index)
	{
		push_front(headRef,data,size);
	}
	else if (index+1==*size)
	{
		push_back(headRef,data,size);
	}
	else {
			struct Node * node =  (struct Node *)malloc(sizeof(struct Node));
			node->data = data;
			node->next=NULL;
			struct Node * cur = *headRef;
			struct Node * prev = NULL;

			for(int i=0;i<index;i++){
				prev = cur;
				cur=cur->next;
			}
			prev->next = node;
			node->next = cur;
			(*size)++;
	}

}
void push_front(struct Node **headRef, int data, int* size){
	struct Node* node =(struct Node*)malloc(sizeof(struct Node));
	node->data = data;
	node->next = *headRef;
	*headRef = node;
	(*size)++;
}
void push_back(struct Node ** headRef, int data, int* size){
	struct Node *node= (struct Node *)malloc(sizeof(struct Node));
	node->data = data;
	node->next=NULL;
	(*size)++;
	struct Node * cur = *headRef;
	if(cur==NULL){
		*headRef = node;
		return;
	}
	while(cur->next!=NULL){
		cur = cur->next;
	}
	cur->next = node;

}
void erase_at(struct Node **headRef, int index, int * size){
	struct Node * cur = *headRef;
	if(index>=(*size))return;
	(*size)--;
	if(!index){
		struct Node * tmp = cur; //to be removed
		cur = cur->next;
		*headRef =cur;
		free(tmp);
		return;
	}
	for(int i=0;i<index-1;i++){
		cur=cur->next;
	}
	struct Node *NewNext = cur->next->next;
	struct Node * tmp = cur->next; //to be removed
	cur->next = NewNext;
	free(tmp);
}

void erase_first_occuerence_of_value(struct Node ** head, int target, int* size){
	struct Node * cur = *head;
	struct Node * prev = NULL;
	if (cur==NULL)return;
	(*size)--;
	if(cur !=NULL && cur->data==target){
		struct Node * tmp = cur; //to be removed
		cur = cur->next;
		*head = cur;
		free(tmp);
	}
	while(cur!=NULL){
		if (cur->data==target){
			struct Node *tmp = cur;
			prev->next = cur->next;
			free(tmp);
		}
		prev = cur;
		cur = cur->next;
	}
}
void erase_all_occuarence_of_value(struct Node ** headRef, int val, int * size){
	struct Node * cur = *headRef;
	struct Node * prev = NULL;
	while(cur!=NULL && cur->data==val)
	{
		struct Node* tmp  = cur;
		cur = cur->next;
		*headRef = cur;
		free(tmp);
		(*size)--;
	}
	while(cur!=NULL)
	{
		if(cur->data==val)
		{
			struct Node * tmp = cur;
			cur = cur->next;
			prev->next = cur;
			free(tmp);
			(*size)--;
		}
		else {
			prev = cur;
			cur = cur->next;
		}
	}
}
int max(int *x,int* y){
	return *x>=*y?*x:*y;
}
int get_max_value(struct Node ** headRef){
	struct Node * cur = *headRef;
	int max_value = -2e9; //initial value so small
	while(cur!=NULL)
	{
		max_value = max(&max_value,&cur->data);
		cur = cur->next;
	}
	return max_value;
}
void unique_sll(struct Node ** headRef, int* size){
	struct Node * cur = *headRef;
	struct Node * prev = NULL;
	int mx = get_max_value(headRef);
	int visited[SIZE]={0};
	while(cur!=NULL)
	{
		if(visited[cur->data])
		{
			struct Node * tmp = cur;
			cur = cur->next;
			prev->next = cur;
			free(tmp);
			(*size)--;
			continue;
		}
		visited[cur->data]=1;
		prev = cur;
		cur = cur->next;
	}
}
void erase_last_occuerence_of_value(struct Node ** headRef, int val , int* size){
	struct Node * cur = *headRef;
	struct Node * prev = NULL;
	struct Node * last = NULL;
	while(cur!=NULL)
	{
		if(cur->data==val)
		{
			last = prev;
		}
		prev = cur;
		cur = cur->next;
	}
	if(last==NULL)
	{
		if((*headRef)->data==val) //found in the first place
		{
			struct Node * tmp = *headRef;
			*headRef =(*headRef)->next;
			free(tmp);
			(*size)--;
			return;
		}
		else
		{
			return;   //not in linked list
		}
	}
	struct Node * tmp = last->next;
	last->next = tmp->next;
	free(tmp);
	(*size)--;
}
void pop_back(struct Node ** headRef, int* size){
	struct Node * cur= *headRef;
	struct Node *prev = NULL;
	if(!(*size))return;
	(*size)--;
	if(cur->next==NULL)
	{
		*headRef = NULL;
		free(cur);
		return;
	}
	while(cur->next!=NULL){
		prev=cur;
		cur = cur->next;
	}
	prev->next=NULL;
	free(cur);
}
void pop_front(struct Node ** headRef, int*size){
	if(!(*size))return;
	(*size)--;
	struct Node * tmp = *headRef;
	*headRef = (*headRef)->next;
	free(tmp);
}
int search(struct Node** headRef, int target){
	struct Node * cur = *headRef;
	int idx = 0 ;
	while(cur!=NULL)
	{
		if(cur->data==target)
		{
			return idx;
		}
		cur = cur->next;
		idx++;
	}
	return -1;
}
void print_sll(struct Node** head){
	struct Node *cur  = *head;
	while(cur!=NULL){
		printf("%d\n",cur->data);
		cur = cur->next;
	}
	puts("");
}

#include <stdio.h>
#include <stdlib.h>

//union Data{
//	char Char;
//	unsigned char unsignedChar;
//	int INT;
//	unsigned int unsignedINT;
//	short Short;
//	unsigned short int shortINT;
//	long int longINT;
//	long long int	LLINT;
//	unsigned long int unsignedLongINT;
//	unsigned long long int unsignedLongLongINT;
//	float Float;
//	double Double;
//	long double	longDouble;
//};
#define NULL ( (void *) 0)
#define SIZE 2000


struct Node{
	int data;
	struct Node * next;
};

void push_front(struct Node **,int, int*);//parameter
void push_back(struct Node **,int, int*);
void insert_at(struct Node **, int, int, int*);
void pop_front(struct Node **, int*);
void pop_back(struct Node **, int*);
void erase_at(struct Node **,int, int*);
void erase_first_occuerence_of_value(struct Node **,int, int*);
void erase_last_occuerence_of_value(struct Node **,int, int*);
void erase_all_occuarence_of_value(struct Node **, int, int*);
int get_max_value(struct Node **);
int search(struct Node**, int);
void unique_sll(struct Node **, int*);
void print_sll(struct Node **);


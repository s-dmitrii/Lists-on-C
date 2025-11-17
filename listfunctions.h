#ifndef LISTFUNCTIONS_H
#define LISTFUNCTIONS_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define LIST struct list 

LIST
{
	int key;
	float value;
	LIST* next;
};


LIST* create_list(void);

bool is_empty(LIST* L);

void push_start(LIST* L, int key, float value);
void push_end(LIST* L, int key, float value);


void pop_first(LIST* L);
void pop_key(LIST* L, int key);
void pop_all(LIST* L);

float value_key(LIST* L, int key);

void print_list(LIST* L);


#endif
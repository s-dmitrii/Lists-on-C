#include "listfunctions.h"


LIST* create_list() {
	LIST* cur;
	cur = (LIST*)malloc(sizeof(LIST));
	cur->key = 0;
	cur->value = 0;
	cur->next = NULL;
	return cur;
}


bool is_empty(LIST* L) {
	return !(L->next);
}


bool is_looped(LIST* L) {
	int capacity = 1;
	int count = 0;
	LIST** addresses = (LIST**)malloc(capacity * sizeof(LIST*));
	LIST* arr = L->next;
	while (arr) {
		for (int i = 0; i < count; i++)
			if (arr == *(addresses + i))
				return true;
		if (count >= capacity) {
			capacity *= 2;
			addresses = (LIST**)realloc(addresses, capacity * sizeof(LIST*));
		}
		*(addresses + count++) = arr;
		arr = arr->next;
	}
	return false;
}


void push_start(LIST* L, int key, float value) {
	LIST* cur;
	cur = malloc(sizeof(LIST));
	cur->key = key;
	cur->value = value;
	cur->next = L->next;
	L->next = cur;
}

void push_end(LIST* L, int key, float value) {
	LIST* cur;
	cur = malloc(sizeof(LIST));
	cur->key = key;
	cur->value = value;

	if (is_empty(L))
		L->next = cur;
	else {
		LIST* next = L->next;
		while (next->next)
			next = next->next;
		next->next = cur;
	}
	cur->next = NULL;
}


void pop_first(LIST* L) {
	if (!is_empty(L)) {
		LIST* del = L->next;
		L->next = L->next->next;
		free(del);
	}
}

/*deleting by key*/
void pop_key(LIST* L, int key) {
	LIST* previous = L;
	LIST* cur = L->next;
	while (cur) {
		if (cur->key == key) {
			previous->next = cur->next;
			free(cur);
			return 0;
		}
		previous = cur;
		cur = cur->next;
	}
	return -1;
}

void pop_all(LIST* L) {
	if (is_empty(L))
		return 0;
	LIST* previous;
	LIST* cur = L->next;
	while (cur->next) {
		previous = cur;
		cur = cur->next;
		free(previous);
	}
	free(cur);
	L->next = NULL;
}


/*returning a value by key*/
float value_key(LIST* L, int key) {
	LIST* cur = L->next;
	while (cur->next) {
		if (cur->key == key)
			return cur->value;
		cur = cur->next;
	}
	return -1;
}


void reverse_list(LIST* L) {
	if (is_empty(L) || !(L->next->next))
		return 0;
	LIST* prev = L->next;
	LIST* cur = prev->next;
	LIST* next = cur->next;
	prev->next = NULL;
	while (next) {
		cur->next = prev;
		prev = cur;
		cur = next;
		next = next->next;
	}
	cur->next = prev;
	L->next = cur;
}
 

void print_list(LIST* L) {
	LIST* cur = L->next;
	while (cur) {
		printf("%d:%f ", cur->key, cur->value);
		cur = cur->next;
	}
	printf("\n");
}
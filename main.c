#include"listfunctions.h"

void push_end_loop(LIST* L, int key, float value) {
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
	cur->next = L->next->next->next;
}

int main(){
	LIST* L = create_list();
	
	printf("\n");
	push_start(L, 1, 2.25);
	push_start(L, 2, 11.11);
	push_start(L, 3, 4.13);
	push_start(L, 4, 3.03);
	push_start(L, 5, 1.12);
	push_start(L, 6, 14.41);
	push_start(L, 7, 66.7);
	push_start(L, 8, 67.45);
	push_end_loop(L, 0, 666.5);

	if (is_looped(L)) {
		printf("\nloopa\n");
	}

	return 0;
}
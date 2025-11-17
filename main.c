#include"listfunctions.h"


int main(){
	LIST* L = create_list();
	
	printf("Adding elements to the beginning:\n");
	push_start(L, 1, 2.25);
	push_start(L, 2, 11.11);
	push_start(L, 3, 4.13);
	print_list(L);


	printf("\nAdding elements to the end:\n");

	push_end(L, 4, 9.64);
	push_end(L, 5, 8.1);
	push_end(L, 6, 6.02);
	print_list(L);


	printf("\nGetting a value by key(4):\n");

	printf("%f\n", value_key(L, 4));


	printf("\nDelete first:\n");

	pop_first(L);
	print_list(L);


	printf("\nDeleting by key(5):\n");

	pop_key(L, 5);
	print_list(L);


	printf("\nDelete all items:\n");

	pop_all(L);
	print_list(L);

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS

#include "Functions.h"

int main() {

	List head = { .exponent = 0, .number = 0, .next = NULL };
	List head_2 = { .exponent = 0, .number = 0, .next = NULL };

	pointer head_3 = createNode(0, 0);

	fromFileToPolynom("en_livstid_i_krig.txt", &head);
	fromFileToPolynom("Soldier_of_heaven.txt", &head_2);


	addPolynoms(&head, &head_2, head_3);
	
	printf("Added polynoms:\t");
	printStack(head_3);
	printf("\n");
	printf("Multiplied Polinoms:\t");
	multiplyStack(head_3);
	
	return 0;
}
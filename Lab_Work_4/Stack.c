#pragma once

#include "Functions.h"

pointer createNode(int exp, int coeff) {

	pointer newOne = (pointer)malloc(sizeof(List));
	if (!newOne) {
		printf("Allocation failed\n");
		return newOne;
	}

	newOne->exponent = exp;
	newOne->number = coeff;
	newOne->next = NULL;

	return newOne;
}

int push(pointer head, int exp, int coeff) {

	pointer newOne = createNode(exp, coeff);

	newOne->next = head->next;
	head->next = newOne;

	return 0;
}

int printStack(pointer head) {

	pointer temp = head->next;
	while (temp) {
		printf("%dx%d", temp->number, temp->exponent);
		if (temp->next)
			printf(" + ");
		temp = temp->next;
	}
	return 0;
}

int compareSizes(pointer head_1, pointer head_2) {
	pointer temp_1 = head_1;
	pointer temp_2 = head_2;
	int count_1 = 0, count_2 = 0;
	while (temp_1) {
		count_1++;
		temp_1 = temp_1->next;
	}

	while (temp_2) {
		count_2++;
		temp_2 = temp_2->next;
	}

	if (count_1 > count_2)
		return 1;
	else
		return 0;
}

int addPolynoms(pointer head_1, pointer head_2, pointer result) {

	pointer temp = head_1->next;
	pointer temp_2 = head_2->next;
	
	
		while (temp_2) {
			push(result, temp_2->exponent, temp_2->number);
			temp_2 = temp_2->next;
		}
		while (temp) {
			push(result, temp->exponent, temp->number);
			temp = temp->next;
		}
		/*start = start->next;
		while (temp) {
			while (start) {
				if (temp->exponent == start->exponent) {
					start->number += temp->number;
				}
				start = start->next;
			}
			start = result->next;
			temp = temp->next;

		}*/

	addHelp(result);

	return 0;
}

//int addHelp(pointer head) {
//
//	pointer start = head;
//	pointer prev = start;
//	pointer curr = start->next;
//
//	while (start) {
//		if (!curr)
//			break;
//		while (curr) {
//			if (start->exponent == curr->exponent) {
//				start->number += curr->number;
//				pop(prev);
//				break;
//				
//			}
//			prev = curr;
//			curr = curr->next;
//		}
//		
//		start = start->next;
//		prev = start;
//		curr = start->next;
//		
//	}
//	return 0;
//}

int pop(pointer element) {

	pointer temp = element->next;
	int x = temp->number;
	element->next = temp->next;
	free(temp);

	return x;

}

int addHelp(pointer head) {

	pointer start = head->next;
	pointer prev = start;
	pointer curr = start->next;

	while (start) {
		if (!curr)
			break;
		while (curr) {
			if (curr->exponent == start->exponent) {
				start->number += curr->number;
				pop(prev);
				curr = prev;
			}
			prev = curr;
			curr = curr->next;
		}
		start = start->next;
		prev = start;
		curr = start->next;

	}

	sortList(head);

	
	return 0;
}

int sortList(pointer head) {

	pointer start = head->next;
	pointer curr = start->next;
	pointer temp = NULL;
	int expt = 0;
	int coefft = 0;

	while (start) {
		curr = start->next;
		if (!curr)
			break;
		while (curr) {
			if (curr->exponent > start->exponent) {
				expt = curr->exponent;
				coefft = curr->number;

				curr->exponent = start->exponent;
				curr->number = start->number;

				start->exponent = expt;
				start->number = coefft;
			}
			curr = curr->next;
		}
		start = start->next;
	}

	return 0;
}

int multiplyStack(pointer head) {

	pointer temp = head->next;
	int exp = 0;
	int coeff = 1;
	while (temp) {
		exp += temp->exponent;
		coeff *= temp->number;
		temp = temp->next;
	}

	printf("%dx%d", coeff, exp);

	return 0;
}

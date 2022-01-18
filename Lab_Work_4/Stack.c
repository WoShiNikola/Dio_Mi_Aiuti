#include "Header.h"

pointer createElement(int coeff, int exponent) {

	pointer newElement = (pointer)malloc(sizeof(List));

	if (!newElement) {
		printf("We failed chief\n");
		return newElement;
	}

	newElement->_E = exponent;
	newElement->_C = coeff;
	newElement->next = NULL;

	return newElement;
}

int pushFromFile(char* fileName, pointer head) {

	FILE* fp = fopen(fileName, "r");
	int x = 0, y = 0;

	if (!fp) {
		printf("Nah, cant do it my man, it's the years\n");
		return -1;
	}
	while (!feof(fp)) {
		fscanf(fp, "%d %d", &x, &y);

		pointer newOne = createElement(x, y);

		if (head->next)
			sortedEntry(head, newOne);
		else {
			newOne->next = head->next;
			head->next = newOne;
		}

	}

	return 0;
}

int printStack(pointer headElement) {

	if (!headElement)
		return 0;

	pointer temp = headElement;

	while (temp) {
		printf("%dx%d ", temp->_C, temp->_E);
		temp = temp->next;
	}
	return 0;
}

int pop(pointer head) {

	if (!head->next)
		return 0;

	pointer temp = head->next;

	head->next = temp->next;
	free(temp);

	return 0;
}

//int find(pointer head, int coeff, int exponent) {
//
//	pointer temp = head->next;
//	while (temp) {
//
//	}
//
//	return 0;
//}
int sortStack(pointer head) {



	return 0;
}

//int sortedentry(pointer head, pointer toadd) {
//
//	
//	return 0;
//}
int sortedEntry(pointer head, pointer toAdd) {

	pointer temp = head;

	while (temp->next && temp->next->_E > toAdd->_E) {

		temp = temp->next;

	}
	if (temp->next) {
		if (temp->next->_E == toAdd->_E) {
			temp->next->_C += toAdd->_C;
			free(toAdd);
			return 0;
		}
	}
	toAdd->next = temp->next;
	temp->next = toAdd;

	return 0;
}

//int addPoynomials(pointer x1, pointer x2, pointer result) {
//
//	/*pointer t1 = x1->next;*/
//	/*pointer t2 = x2->next;
//
//	while (!(t1 == NULL && t2 == NULL)) {
//		if (!t1) {
//			addToEnd(result, t1->_C, t1->_E);
//			t2 = t2->next;
//		}
//		else if (!t2) {
//			addToEnd(result, t2->_C, t2->_E);
//			t1 = t1->next;
//
//		}
//		else if (t1->_E == t2->_E) {
//			addToEnd(t1->_C + t2->_C, t1->_E + t2->_E, result);
//			t2 = t2->next;
//			t1 = t1->next;
//		}
//		else if (t1->_E > t2->_E) {
//			addToEnd(t2->_C, t2->_E, result);
//			t2 = t2->next;
//
//		}
//		else if (t1->_E < t2->_E) {
//			addToEnd(t1->_C, t1->_E, result);
//			t1 = t1->next;
//
//		}
//		
//	}	*/
//
//	//t1 = result;
//	//while (t2) {
//	//	if (t1 && t1->_E == t2->_E) {
//	//		t1->_C += t2->_C;
//	//	}
//	//	else
//	//		sortedEntry(result, t2);
//
//	//	t2 = t2->next;
//	//}
//	return 0;
//}

int push(pointer result, int coeff, int exp) {

	pointer newOne = createElement(coeff, exp);

	newOne->next = result->next;
	result->next = newOne;

}

int addToEnd(int x, int y, pointer result) {

	pointer temp = result;

	if (!temp->next) {
		pointer newOne = createElement(x, y);

		newOne->next = temp->next;
		temp->next = newOne;

		return 0;
	}


	while (temp->next)
		temp = temp->next;

	pointer newOne = createElement(x, y);

	newOne->next = temp->next;
	temp->next = newOne;

	return 0;
}

int addPoynomials(pointer x1, pointer x2, pointer result) {

	pointer p1 = x1->next;
	pointer p2 = x2->next;

	while (p1) {
		sorted(result, p1->_C, p1->_E);
		p1 = p1->next;
	}
	while (p2) {
		sorted(result, p2->_C, p2->_E);
		p2 = p2->next;
	}
	

	return 0;
}

int multiplyPolynoms(pointer x1, pointer x2, pointer result) {

	pointer p1 = x1->next;
	pointer p2 = x2->next;

	int x = 1;
	int y = 0;

	for (; p1; p1 = p1->next) {
		for (p2 = x2->next; p2; p2 = p2->next) {
			x = p1->_C * p2->_C;
			y = p1->_E + p2->_E;

			sorted(result, x, y);
		}
	}



	return 0;
}

int sorted(pointer head, int x, int y) {

	sortedEntry(head, createElement(x,y));

	/*pointer temp = head;

	while (temp->next && temp->next->_E > y) {
		temp = temp->next;

	}
	newOne->next = temp->next;
	temp->next = newOne;*/

	return 0;
}

//int selfRegulate(pointer regulate) {
//
//	pointer prev = regulate;
//	pointer curr = regulate->next;
//	int did = 0;
//	do {
//		if (curr->_E == prev->_E) {
//			prev->_C += curr->_C;
//			pop(curr);
//
//
//			did = 1;
//		}
//		if (curr->next && did == 1) {
//			prev = regulate;
//			curr = prev->next;
//		}
//		prev = curr;
//		curr = curr->next;
//	} while (did);


	//int draw = 1;
	//pointer temp = regulate;
	//do {
	//	if (temp->_E == temp->next->_E) {
	//		temp->_C += temp->next->_C;
	//		pop(temp->next);
	//		draw = 0;
	//	}
	//	if (!temp->next)
	//		temp = regulate;
	//	temp = temp->next;
	//	
	//} while (draw == 1);
	//	


//	return 0;
//}
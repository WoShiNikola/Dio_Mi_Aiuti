#pragma once
#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _list* pointer;
typedef struct _list {
	int _C;
	int _E;
	pointer next;
}List;

/*Stack Operations*/
pointer createElement(int coeff, int exponent);
int pushFromFile(char* fileName, pointer head);
int pop(pointer head);
int find(pointer head, int coeff, int exponent);

int printStack(pointer headElement);
//int sortStack(pointer head);
int sortedEntry(pointer head, pointer toAdd);

int addPoynomials(pointer x1, pointer x2, pointer result);
//int push(pointer result, int coeff, int exp);
int addToEnd(int x, int y, pointer result);

int sorted(pointer head, int x, int y);
//int selfRegulate(pointer regulate);
int multiplyPolynoms(pointer x1, pointer x2, pointer result);


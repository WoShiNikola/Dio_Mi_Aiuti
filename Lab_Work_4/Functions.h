#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _list List;
typedef struct _list* pointer;

struct _list {
	int number;
	int exponent;
	pointer next;
};

int openFileCount(char* fileName);
int fromFileToPolynom(char* fileName, pointer head);
pointer createNode(int exp, int coeff);
int push(pointer head, int exp, int coeff);
int printStack(pointer head);

int addPolynoms(pointer head_1, pointer head_2, pointer result);
int compareSizes(pointer head_1, pointer head_2);
int addHelp(pointer head);
int pop(pointer element);
int sortList(pointer head);
int multiplyStack(pointer head);

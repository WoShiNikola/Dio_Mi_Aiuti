#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define COUNTRY_MAX (128)


typedef struct _tree* tPointer;
typedef struct _tree {
	char cityName[COUNTRY_MAX];
	int populationSize;
	tPointer left;
	tPointer right;
}Tree;
typedef struct _list* lPointer;
typedef struct _list {
	char countryName[COUNTRY_MAX];
	tPointer country;
	lPointer next;
}List;


lPointer CreateNode(char* countryName, char* townsFileName, tPointer countryLeaf);
tPointer createLeaf(char* cityName, int populus);

int openFileAndRead(char* fileName, lPointer head);
int addToList(char* countryName, char* townsFileName);
tPointer addToTree(tPointer root, char* townName, int populationSize);

int printTree(tPointer root);
int printList(lPointer head);




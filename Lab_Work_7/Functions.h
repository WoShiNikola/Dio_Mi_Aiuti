#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>

#define DIR_NAME_SIZE (128)

enum _commands {
	UNKNOWN_COMMAND,
	MAKE_DIRECTORY,
	CHANGE_DIRECTORY,
	STEPBACK_DIRECTORY,
	SHOW_CURRENT_DIRECTORY,
	STEP_UP_DIRECTORY,
	EXIT
};

typedef struct _tree* pointer;
typedef struct _tree {
	char dirName[DIR_NAME_SIZE];
	pointer left;
	pointer right;
}Tree;

typedef struct _list* s_pointer;
typedef struct _list {
	pointer treeElement;
	s_pointer next;
}List;
/***************************************  STACK  *******************************************************/
s_pointer createNode(pointer treeElement);
int push(s_pointer head, pointer treeElement);
int pop(s_pointer head);
int findElement(s_pointer head, char* soughtElement);
int isEmpty(s_pointer head);
int printPath(s_pointer head);
int checkIfAddChild(s_pointer head);
s_pointer returnCurrent(s_pointer head);
int printAllSubfolders(s_pointer thisNode);
pointer returnCurrentT(s_pointer head);
int stepAChild(s_pointer head);
/*******************************************************************************************************/
									//MIDDLE GROUND - THE PRICE OF MILE
/***************************************  Tree  ********************************************************/
pointer createLeaf(char* dirName);
pointer addChild(pointer root, char* dirName);
int addSibling(pointer root, char* dirName);
int checkIfLast(pointer element);
int findDirectory(pointer root, s_pointer head, char* dirName);

/*******************************************************************************************************/

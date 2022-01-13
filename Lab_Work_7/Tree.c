#include "Functions.h"

pointer createLeaf(char* dirName) {

	pointer newLeaf = (pointer)malloc(sizeof(Tree));

	if (!newLeaf) {
		printf("Nope bruh no leaf for you\n");
		return newLeaf;
	}
	strcpy(newLeaf->dirName, dirName);
	newLeaf->left = NULL;
	newLeaf->right = NULL;

	return newLeaf;
}

pointer addChild(pointer root, char* dirName){

	

	pointer temp = root;

	while (temp->left)
		temp = temp->left;
	
	pointer newChild = createLeaf(dirName);

	newChild->left = temp->left;
	temp->left = newChild;

	return newChild;
}

int addSibling(pointer root, char* dirName) {

	pointer temp = root;

	while (temp->right) {
		temp = temp->right;
	}

	pointer newSibling = createLeaf(dirName);

	newSibling->right = temp->right;
	temp->right = newSibling;

	return 0;
}

int checkIfLast(pointer element) {
	return element->left == NULL;
}

int findDirectory(pointer root, s_pointer head, char* dirName) {

	while (!isEmpty(head))
		pop(head);

	pointer temp = root->left;
	while (temp) {
		if (!_stricmp(temp->dirName, dirName)) {
			push(head, temp);
			return 0;
		}
		push(head, temp);
		temp = temp->left;
	}
	while (!isEmpty(head))
		pop(head);
	printf("Couldn't find it sorry\n");

	return 0;
}


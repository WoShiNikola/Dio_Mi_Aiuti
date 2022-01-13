#include "Functions.h"

s_pointer createNode(pointer treeElement) {

	s_pointer newNode = (s_pointer)malloc(sizeof(List));

	if (!newNode) {
		printf("Not good boss, memory allocation failed\n");
		return newNode;
	}

	newNode->treeElement = treeElement;
	newNode->next = NULL;

	return newNode;
}

int isEmpty(s_pointer head) {
	return head->next == 0;
}

int push(s_pointer head, pointer treeElement) {
	
	s_pointer newNode = createNode(treeElement);


	s_pointer temp = head;

	while (temp->next)
		temp = temp->next;

	newNode->next = temp->next;
	temp->next = newNode;

	return 0;
}

int pop(s_pointer head) {

	if (isEmpty(head)) {
		printf("Empty stack my guy\n");
		return 0;
	}
	
	s_pointer temp = head;
	s_pointer del = temp->next;
	while (del->next) {
		temp = del;
		del = del->next;
	}
	temp->next = del->next;
	free(del);

	return 0;
}

int findElement(s_pointer head, char* soughtElement) {

	return 0;
}

int printPath(s_pointer head) {
	
	s_pointer temp = head;

	while (temp) {
		printf("%s\\", temp->treeElement->dirName);
		temp = temp->next;
	}

	return 0;
}

int checkIfAddChild(s_pointer head) {
	
	if (!head->treeElement->left)
		return 1;
	
	s_pointer temp = head;

	while (temp->next)
		temp = temp->next;
	if (!temp->treeElement->left)
		return 1;
	else return 0;
}

s_pointer returnCurrent(s_pointer head) {
	s_pointer temp = head;

	while (temp->next)
		temp = temp->next;

	return temp;
}

int printAllSubfolders(s_pointer thisNode) {

	pointer temp = thisNode->treeElement->right;

	printf("All subfolders:\n");
	while (temp) {
		printf("\t - %s\n", temp->dirName);
		temp = temp->right;
	}
	return 0;
}

pointer returnCurrentT(s_pointer head) {
	s_pointer temp = head;

	while (temp->next)
		temp = temp->next;

	return temp->treeElement;
}

int stepAChild(s_pointer head) {
	
	pointer temp = returnCurrentT(head);

	if (temp->left) {
		push(head, temp->left);
		return 0;
	}
	else return 1;
	
}
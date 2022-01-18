#include "Header.h"

tPointer createLeaf(char* cityName, int populus) {

	tPointer newLeaf = (tPointer)malloc(sizeof(Tree));

	if (!newLeaf) {
		printf("Buddy nothing to do here\n");
		return NULL;
	}

	strcpy(newLeaf->cityName, cityName);
	newLeaf->populationSize = populus;
	newLeaf->left = NULL;
	newLeaf->right = NULL;

	return newLeaf;
}

tPointer addToTree(tPointer root, char* townName, int populationSize) {

	if (!root)
		return root;

	if (root->populationSize == 0) {
		root->populationSize = populationSize;
		strcpy(root->cityName, townName);
		return root;
	}

	if (root->populationSize < populationSize) {
		if (!root->right) {
			tPointer newLeaf = createLeaf(townName, populationSize);
			root->right = newLeaf;

			return newLeaf;
		}
		else
			addToTree(root->right, townName, populationSize);
	}
	else if (root->populationSize > populationSize) {
		if (!root->left) {
			tPointer newLeaf = createLeaf(townName, populationSize);
			root->left = newLeaf;

			return newLeaf;
		}
		else
			addToTree(root->left, townName, populationSize);
	}

	return root;
}

int printTree(tPointer root) {

	if (!root)
		return 0;
	printTree(root->left);
	printf("City: %s Population size: %d\n", root->cityName, root->populationSize);
	printTree(root->right);

	return 0;
}

tPointer searchLargerThan(tPointer root, int target){ 

	if (!root)
		return NULL;
	if (root->populationSize > target)
		return root;
	else
		searchLargerThan(root->right, target);

	return root;
}

int printLargerOnly(tPointer root, int target) {

	if (!root)
		return 0;
	
	if (root->populationSize > target) {
		printf("%s %d\n", root->cityName, root->populationSize);
	}
	printLargerOnly(root->right, target);
	printLargerOnly(root->left, target);
		
	return 0;
}

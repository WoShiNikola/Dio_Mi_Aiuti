#include "Header.h"

lPointer CreateNode(char* countryName, char* townsFileName, tPointer countryLeaf) {

	FILE* fp_2 = fopen(townsFileName, "r");
	if (!fp_2) {
		printf("Coldn't open file fp_2, sorry\n");
		return NULL;
	}
	char tempName_3[COUNTRY_MAX] = { '\0' };
	int temp = 0;
	lPointer newNode = (lPointer)malloc(sizeof(List));

	if (!newNode) {
		printf("Sorry senor!, this is no bueno\n");
		return NULL;
	}

	strcpy(newNode->countryName, countryName);
	while (!feof(fp_2)) {
		fscanf(fp_2, "%s %d", tempName_3, &temp);

		addToTree(countryLeaf, tempName_3, temp);
	}

	newNode->country = countryLeaf;
	newNode->next = NULL;

	fclose(fp_2);
	return newNode;
}


int addToList(char* countryName, char* townsFileName) {


	return 0;
}

int openFileAndRead(char* fileName, lPointer head) {

	FILE* fp = fopen(fileName, "r");
	char tempName_1[COUNTRY_MAX] = { '\0' };
	char tempName_2[COUNTRY_MAX] = { '\0' };

	while (!feof(fp)) {
		fscanf(fp, "%s %s", tempName_1, tempName_2);

		tPointer root = createLeaf("\0", 0);

		lPointer newOne = CreateNode(tempName_1, tempName_2, root);
		if (!newOne)
			return -1;
		newOne->next = head->next;
		head->next = newOne;
	}
	fclose(fp);
	return 0;
}

int printList(lPointer head) {

	lPointer temp = head;

	while (temp) {
		printf("Country: %s\n", temp->countryName);
		printTree(temp->country);
		printf("\n");
		temp = temp->next;
	}

	return 0;
}

#include "Header.h"

int main() {

	/*List head = { .country = NULL, .countryName = '\0', .next = NULL };

	openFileAndRead("Countries.txt", &head);*/

	Hash hashTable[TABLE_SIZE] = { NULL };
	
	openFileReadToHash("Countries.txt", hashTable);
	/*tPointer temp = NULL;

	printf("Enter number: ");
	int target = 0;
	scanf("%d", &target);

	if (temp = searchCountry(head.next, "Japan", target)) {
		
		printLargerOnly(temp, target);
	}*/

	//printf("%d", calculateKey("Seventeen"));

	for (int i = 0; i < TABLE_SIZE; i++) {
		lPointer temp = hashTable[i].List;
		
			printf("table place[%d]: \n", i);
		while (temp) {
			printf(" %s\n", temp->countryName);
			temp = temp->next;
		}
	}

	return 0;
}

int openFileReadToHash(char* fileName, Hash* hash) {

	FILE* fp = fopen(fileName, "r");

	char tempName_1[COUNTRY_MAX] = { '\0' };
	char tempName_2[COUNTRY_MAX] = { '\0' };
	int key = 0;
	while (!feof(fp)) {
		fscanf(fp, "%s %s", tempName_1, tempName_2);

		tPointer root = createLeaf("\0", 0);
		key = calculateKey(tempName_1);

		if (!hash[key].List) {
			hash[key].List = CreateNode(tempName_1, tempName_2, root);
		}
		else {
			lPointer temp = hash[key].List;
			while (temp->next)
				temp = temp->next;
			lPointer newOne = CreateNode(tempName_1, tempName_2, root);
			newOne->next = temp->next;
			temp->next = newOne;
		}
	}
	fclose(fp);
	return 0;
}






#include "Header.h"

int main() {

	List head = { .country = NULL, .countryName = '\0', .next = NULL };
	
	openFileAndRead("Countries.txt", &head);

	printList(head.next);

	return 0;
}










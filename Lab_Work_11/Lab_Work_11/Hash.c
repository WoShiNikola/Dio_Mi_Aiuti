#include "Header.h"

int calculateKey(char* countryName) {
	int key = 0;
	
	for (int i = 0; i < 5; i++) {
		key += (int)countryName[i];
	}
	return key % 11;
}


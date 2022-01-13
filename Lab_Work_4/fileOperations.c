#pragma once

#define _CRT_SECURE_NO_WARNINGS 
#include "Functions.h"


int openFileCount(char* fileName) {

	FILE* fp = fopen(fileName, "r");
	if (!fp)
		return -1;
	int exp = 0, coeff = 0;

	int count = 0;
	while (!feof(fp)) {
		fscanf(fp, "%d %d", &exp, &coeff);
		count++;
	}
	fclose(fp);
	return count - 1;
}

int fromFileToPolynom(char* fileName, pointer head) {

	FILE* fp = fopen(fileName, "r");
	if (!fp)
		return -1;
	int exp = 0, coeff = 0;

	while (!feof(fp)) {
		fscanf(fp, "%d %d", &coeff, &exp);

		push(head, exp, coeff);

	}

	return 0;
}
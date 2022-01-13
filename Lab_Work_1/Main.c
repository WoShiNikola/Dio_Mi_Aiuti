#define _CRT_SECURE_NO_WARNINGS


#include"Functions.h"



int main() {

	Students* students = dynamicAllocationAndRead(returnNumberOfStudents("Milf_List.txt"), "Milf_List.txt");
	printStudents(returnNumberOfStudents("Milf_List.txt"), students);

	printf("That's the whole list, Goodbye!!\n");

	return 0;
}
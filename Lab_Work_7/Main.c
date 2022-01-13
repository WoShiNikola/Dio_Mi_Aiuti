
#include "Functions.h"

int showMenu() {

	printf("\n\n**************************************************\nImmettere uno dei seguenti comandi : \t\t *\n"
		"\t\t 1 - 'md'\t\t\t *\n"
		"\t\t 2 - 'cd_dir'\t\t\t *\n"
		"\t\t 3 - 'cd..'\t\t\t *\n"
		"\t\t 4 - 'dir'\t\t\t *\n"
		"\t\t 6 - 'dir_up'\t\t\t *\n"
		"\t\t 5 - 'exit'\t\t\t *\n**************************************************\n\n");

	printf("Enter command---> \n\t\t   ");
	
	return 0;
}

int returnCommand(char* cmd) {

	if (!_stricmp("md", cmd))
		return MAKE_DIRECTORY;
	else if (!_stricmp("cd_dir", cmd))
		return CHANGE_DIRECTORY;
	else if (!_stricmp("cd..", cmd))
		return STEPBACK_DIRECTORY;
	else if (!_stricmp("dir", cmd))
		return SHOW_CURRENT_DIRECTORY;
	else if (!_stricmp("exit", cmd))
		return EXIT;
	else if (!_stricmp("dir_up", cmd))
		return STEP_UP_DIRECTORY;
	else
		return UNKNOWN_COMMAND;
}

int dirNameInput(char* name) {

	printf("Input directory name: \n\t");
	scanf(" %s", name);

	return 0;
}


int main() {
	
	pointer root = createLeaf("C:");
	s_pointer head = createNode(root);
	int choice = 0;
	int begin = 0;
	char command[DIR_NAME_SIZE] = { '\0' };
	char name[DIR_NAME_SIZE] = { '\0' };
	int folder = 0;
	
	while (1) {

		printf("Current directory: ");
		printPath(head);
		showMenu();
	
		scanf(" %s", command);

		system("cls");

		switch (returnCommand(command)) {
			case MAKE_DIRECTORY: {
				if (!begin) {
					dirNameInput(name);
					push(head, addChild(root, name));
					begin = 1;
					break;
				}
				if (checkIfAddChild(head)) {
					dirNameInput(name);
					push(head, addChild(root, name));
					break;
				}
				else {
					dirNameInput(name);
					addSibling(returnCurrentT(head), name);
					break;
				}
				
			}
			case CHANGE_DIRECTORY: {
				dirNameInput(name);
				findDirectory(root, head, name);
				break;
			}
			case STEP_UP_DIRECTORY: {
				stepAChild(head);
				break;
			}				
			case STEPBACK_DIRECTORY: {
				pop(head);
				if (isEmpty(head))
					begin = 0;
				break;
			} 
			case SHOW_CURRENT_DIRECTORY: {
				printAllSubfolders(returnCurrent(head));
				break;
			}
			case EXIT: goto end_of_main;
			default: break;
		}

	}

end_of_main: 
	printf("Goodbye :D \n");
	return 0;
}
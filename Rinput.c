#include <stdio.h>
#include <stdlib.h>

void Rinput(char* command, char username[15]) {//for removal
	int i = 0, j;
	for (i = 0; command[i] != ' '; i++);
	i++;
	for (i, j = 0; (command[i] != '\n') && (command[i] != NULL); i++) {
		username[j] = command[i];
		j++;
	}
	username[j] = NULL;
}
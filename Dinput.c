#include <stdio.h>
#include <stdlib.h>
void Dinput(char* command, char username[15], double *amount) {
	int i = 0, j;
	char sAmount[15];
	for (i = 0; command[i] != ' '; i++);
	i++;
	for (i, j = 0; command[i] != ' '; i++) {
		username[j] = command[i];
		j++;
	}
	username[j] = NULL;
	i++;
	for (j = 0, i; (command[i] != '\n') && (command[i] != NULL); i++) {
		sAmount[j] = command[i];
		j++;
	}
	sAmount[j] = NULL;
	*amount = atof(sAmount);
}
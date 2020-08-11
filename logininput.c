#include <stdio.h>
void logininput(char* command, char username[15], char password[15]) {
	int i = 0, j;
	for (i = 0; command[i] != ' '; i++);
	i++;
	for (i, j = 0; command[i] != ' '; i++) {
		username[j] = command[i];
		j++;
	}
	username[j] = NULL;
	i++;
	for (j = 0, i; command[i] != '\n'; i++) {
		password[j] = command[i];
		j++;
	}
	password[j] = NULL;
}
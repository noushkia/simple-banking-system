#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

int checkUserPass(users* head, char* username, char *password) {
	int userCheck = 0, passCheck = 0;
	users* curr;
	curr = head;//used to traverse through the list
	while (curr != NULL) {
		if (!strcmp(username,curr->username)) {
			userCheck = 1;
			break;
		}
		curr = curr->next;
	}
	if (userCheck == 0) {
		printf("No such user has been registered!\n");
		return 0;
	}
	while (curr != NULL) {
		if (!strcmp(password, curr->password)) {
			passCheck = 1;
			break;
		}
		curr = curr->next;
	}
	if (passCheck == 0) {
		printf("Wrong password!\n");
		return 0;
	}
	return 1;
}
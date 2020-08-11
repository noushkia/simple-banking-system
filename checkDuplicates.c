#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

int checkDuplicate(users* head, char* username, char *phoneNumber) {
	users* curr;
	curr = head;
	while (curr != NULL) {
		if (!strcmp(username,curr->username)) {
			printf("Name already taken!\n please choose another one.\n");
			return 0;
		}
		curr = curr->next;
	}
	curr = head;
	while (curr != NULL) {
		if (!strcmp(phoneNumber, curr->phoneNumber)) {
			printf("PhoneNumber already registered!\n please choose another one.\n");
			return 0;
		}
		curr = curr->next;
	}
	return 1;
}
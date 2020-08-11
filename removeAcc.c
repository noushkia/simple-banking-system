#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "Rinput.h"
void removeAcc(struct userinfo* head, char* command) {
	char username[15];
	struct userinfo* curr,*prev;
	Rinput(command, username);
	curr = head;
	while (curr->next != NULL) {
		if (strcmp(curr->username, username)) {
			prev = curr;
			curr = curr->next;
		}
		else break;
	}
	if (strcmp(curr->username, username)) {
		printf("User not found!\n");
		return;
	}
	prev->next = curr->next;
	curr->next = NULL;
	free(curr);
}
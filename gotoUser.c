#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

int gotoUser(struct userinfo* head, struct userinfo** user,char* username) {
	users* curr;
	curr = head;
	while ((curr != NULL)) {
		*user = curr;
		if (!strcmp(curr->username, username))
			break;
		else {
			curr = curr->next;
		}
	}
	if(!strcmp((*user)->username,username))
		return 1;
	else return 0;
}
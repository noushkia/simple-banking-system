#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "viewU.h"
#include "transfer.h"

int userCommands(struct userinfo* head, struct userinfo* user) {
	char command[60], *commandCheck;
	while (1) {
		int i = 0;
		commandCheck = (char*)malloc(20);
		gets(command);
		while ((command[i] != NULL)&&(command[i]!=' ')) {
			commandCheck[i] = command[i];
			i++;
		}
		commandCheck[i] = NULL;
		if (!strcmp(commandCheck, "transfer")) {
			transfer(head, user, command);
		}
		else if (!strcmp(commandCheck, "view")) {
			viewU(user);
		}
		else if (!strcmp(commandCheck, "logout")) {
			printf("Have a nice day!\n");
			break;
		}
		else {
			printf("Wrong command!\nPlease enter correct inputs!\n");
		}
		free(commandCheck);
		printf("What other task you wish to be done?\n");
	}
}
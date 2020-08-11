#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "logininput.h"//devides the input word by word
#include "struct.h"
#include "checkUserPass.h"
#include "gotoUser.h"
int login(int*aou, struct userinfo* head, struct userinfo** user) {
	struct userinfo* curr;
	curr = head;
	char username[15];
	char password[15];
	char first_word[15], *init;
	init = (char*)malloc(60);
	fgets(init, 60, stdin);
	for (int i = 0; (init[i] != ' ') && (init[i] != '\n'); i++) {
		first_word[i] = init[i];
		first_word[i + 1] = NULL;
	}
	if (!strcmp("login", first_word)) {//if the user wants to login
		logininput(init, username, password);
		if ((!strcmp(username, "admin")) && !strcmp(password, "123")) {
			*aou = 0;
		}
		else if (checkUserPass(head, username, password)) {
			printf("Welcome %s\nWhat would you like to do?\n", username);
			gotoUser(head, user, username);
			*aou = 1;
			free(init);
			return 1;
		}
		else {
			//printf("No such user has been registered!\n\n");
			free(init);
			return 0;
		}
	}
	else if (!strcmp(first_word, "exit")) {//if the user wants to exit
		printf("Exiting system...\n");
		free(init);
		return 2;
	}
	else {
		printf("Wrong command input!\nPlease try again!\n");
		free(init);
		return 0;
	}
	free(init);
	return 1;
}
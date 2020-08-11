#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "add_user.h"
#include "struct.h"
#include "removeAcc.h"
#include "viewA.h"
#include "deposit.h"
#include "withdraw.h"
#include "makeLinkedList.h"
int adminCommands(struct userinfo* head) {
	printf("Welcome dear admin!\nWhat would you like to do?\n");
	char command[60], commandCheck[15];
	//gets(command);
	while (1) {
		//makeLinkedList(&head);
		int i = 0;
		//commandCheck = (char*)malloc(20);
		fgets(command,60,stdin);
		while ((command[i] != ' ')&&(command[i] != '\n')) {
			commandCheck[i] = command[i];
			i++;
		}
		commandCheck[i] = NULL;
		if (!strcmp(commandCheck,"add_user")) {
			add_user(head, command);
			//printf("%d", head->balance);
		}
		else if (!strcmp(commandCheck,"deposit")) {
			deposit(head, command);
		}
		else if (!strcmp(commandCheck,"withdraw")) {
			withdraw(head, command);
		}
		else if (!strcmp(commandCheck,"view")) {
			viewA(head, command);
		}
		else if (!strcmp(commandCheck,"delete")) {
			removeAcc(head, command);
		}
		else if (!strcmp(commandCheck,"logout")) {
			printf("Have a nice day!\n");
			break;
		}
		else {
			printf("Wrong command!\nPlease enter correct inputs!\n");
		}
		//free(commandCheck);
		printf("What other task you wish to be done?\n");
	}
}
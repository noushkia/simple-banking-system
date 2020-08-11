#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "Dinput.h"

int withdraw(struct userinfo* head, char* command) {
	struct userinfo* curr;
	char username[15];
	char* s = (char*)malloc(15);
	s = "withdraw";
	double amount;
	Dinput(command, username, &amount);
	amount *= -1;
	if (!gotoUser(head, &curr, username)) {//checks availability
		printf("User not found!\n");
		return 0;
	}
	if (curr->balance < -(amount)) {
		printf("Insufficient funds in the account!\n");
		return 0;
	}
	curr->balance += amount;
	curr->transferCount++;
	trans* current_transfer = curr->transfers;
	while (current_transfer->next != NULL) {
		current_transfer = current_transfer->next;
	}
	if (!strcmp(current_transfer->mode, "No records available")) {
		current_transfer->mode = "withdraw";
		current_transfer->amount = amount;
		current_transfer->next = NULL;
	}
	else {
		current_transfer->next = (trans*)malloc(sizeof(trans));
		current_transfer->next->mode = (char*)malloc(15);
		current_transfer->next->mode = s;
		current_transfer->next->amount = amount;
		current_transfer->next->next = NULL;
	}
}
#include <stdio.h>
#include <stdlib.h>
#include "gotoUser.h"
#include "struct.h"
#include "Dinput.h"

int transfer(struct userinfo* head, struct userinfo* user, char* command) {
	struct userinfo* curr;
	curr = (struct userinfo*)malloc(sizeof(struct userinfo));
	char username[15];//name of target
	double amount;
	Dinput(command, username, &amount);
	if (!gotoUser(head, &curr, username)) {//finds which user to add amount
		printf("User not found!\n");
		return 0;
	}
	if (user->balance < amount) {
		printf("Insufficient funds in the account!\n");
		return 0;
	}
	user->balance -= amount;
	curr->balance += amount;
	user->transferCount++;
	curr->transferCount++;
	trans* receiver_transfer = curr->transfers;
	while (receiver_transfer->next != NULL) {//finds the node
		receiver_transfer = receiver_transfer->next;
	}
	if (!strcmp(receiver_transfer->mode, "No records available")) {
		receiver_transfer->mode = "receive";
		receiver_transfer->amount = amount;
		receiver_transfer->next = NULL;
	}
	else {
		receiver_transfer->next = (trans*)malloc(sizeof(trans));
		receiver_transfer->next->mode = (char*)malloc(15);
		receiver_transfer->next->mode = "receive";
		receiver_transfer->next->amount = amount;
		receiver_transfer->next->next = NULL;
	}
	trans* sender_transfer = user->transfers;
	while (sender_transfer->next != NULL) {//finds the node
		sender_transfer = sender_transfer->next;
	}
	if (!strcmp(sender_transfer->mode, "No records available")) {
		receiver_transfer->mode = "transfer";
		receiver_transfer->amount = amount;
		receiver_transfer->next = NULL;
	}
	else {
		sender_transfer->next = (trans*)malloc(sizeof(trans));
		sender_transfer->next->mode = (char*)malloc(15);
		sender_transfer->next->mode = "transfer";
		sender_transfer->next->amount = amount;
		sender_transfer->next->next = NULL;
	}
	//how to add transfer??
	/*check username availability
	check if balance>amount
	linked list update(balance(-a,+a) + transactions(user,target))
	print all on file all over again*/
	return 1;
}
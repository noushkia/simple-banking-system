#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
void makeLinkedList(struct userinfo** head) {
	int accReg = 0;
	char garbage[200];
	struct userinfo* curr;
	users* tail;
	FILE* accounts;
	accounts = fopen("Accounts.txt", "r");//opens the file to scan it and add info to the list
	if (accounts == NULL) {
		return;
	}
	curr = *head;
	curr->next = (struct userinfo*)malloc(sizeof(struct userinfo));
	curr = curr->next;
	while (!feof(accounts)) {
		curr->username = (char*)malloc(15);
		curr->password = (char*)malloc(15);
		curr->phoneNumber = (char*)malloc(15);
		if (fscanf(accounts, "Username: %s\n", curr->username) <= 0) {
			if (accReg == 0) {//CHECKS IF THERE IS ANY acc registered
				(*head)->next = NULL;
				return;
			}
			break;
		}
		fscanf(accounts, "Password: %s\n", curr->password);
		fscanf(accounts, "Phone number: %s\n", curr->phoneNumber);
		fscanf(accounts, "ID: %d\n", &curr->id);
		fscanf(accounts, "Balance: %lf\n", &curr->balance);
		fscanf(accounts, "Transactions Count: %d\n", &curr->transferCount);
		fgets(garbage, 256, accounts);
		curr->transfers = (trans*)malloc(sizeof(trans));
		curr->transfers->mode = (char*)malloc(15);
		if (curr->transferCount == 0) {
			curr->transfers->mode = "No records available";
			curr->transfers->next = NULL;
			fgets(garbage, 256, accounts);
			fgets(garbage, 256, accounts);//skips 2lines
		}
		trans* current_transfer = curr->transfers;
		for (int i = 1; i <= curr->transferCount; i++) {
			fscanf(accounts, "%s %lf\n", current_transfer->mode, &current_transfer->amount);
			current_transfer->next = (trans*)malloc(sizeof(trans));
			if (i == curr->transferCount)
				break;
			current_transfer= current_transfer->next;
			current_transfer->mode = (char*)malloc(15);

		}
		current_transfer->next = NULL;
		curr->next = (struct userinfo*)malloc(sizeof(struct userinfo));
		tail = curr;
		curr = curr->next;
		if (accReg == 0)
			(*head)->next = tail;
		accReg++;
	}
	if((*head)->next!=NULL)
		tail->next = NULL;
	fclose(accounts);
}
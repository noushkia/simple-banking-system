#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
void write(users* head) {
	FILE* accounts = fopen("Accounts.txt", "w");
	while (head->next != NULL) {
		fprintf(accounts, "Username: %s\n", head->next->username);
		fprintf(accounts, "Password: %s\n", head->next->password);
		fprintf(accounts, "Phone number: %s\n", head->next->phoneNumber);
		fprintf(accounts, "ID: %d\n", head->next->id);
		fprintf(accounts, "Balance: %lf\n",head->next->balance);
		fprintf(accounts, "Transactions Count: %d\n",head->next->transferCount);
		fprintf(accounts, "Transactions:\n\n");
		while (head->next->transfers != NULL) {
			if (head->next->transferCount == 0)
				fprintf(accounts, "%s\n", head->next->transfers->mode);
			else
				fprintf(accounts, "%s %lf\n",head->next->transfers->mode,head->next->transfers->amount);
			head->next->transfers = head->next->transfers->next;
		}
		head->next = head->next->next;
	}
	fclose(accounts);
}

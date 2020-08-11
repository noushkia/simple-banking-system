#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

void viewU(struct userinfo* user) {
	int i = 0;
	printf("*****************************************************\n");
	printf("Username: %s\n", user->username);
	printf("Password: %s\n", user->password);
	printf("Phone number: %s\n", user->phoneNumber);
	printf("ID: %d\n", user->id);
	printf("Balance: %lf\n",user->balance);
	printf("Transactions Count: %d\n",user->transferCount);
	printf("Transactions:\n\n");
	trans* current_transfer = user->transfers;
	for (i = 0; i < user->transferCount; i++) {
		printf("%s %lf\n",current_transfer->mode,current_transfer->amount);
		current_transfer = current_transfer->next;
	}
	if (i == 0)
		printf("No records available\n\n");
}
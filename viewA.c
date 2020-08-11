#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "Rinput.h"
#include "gotoUser.h"
void viewA(struct userinfo* head,char* command){
	int i = 0;
	char username[15];//to be viewed
	Rinput(command, username);
	struct userinfo* curr;
	curr = head;
	if (!gotoUser(head, &curr, username)) {//selects which acc to be viewed
		printf("User not found!\n");
		return;
	}
	printf("*****************************************************\n");
	printf("Username: %s\n", curr->username);
	printf("Phone number: %s\n", curr->phoneNumber);
	printf("ID: %d\n", curr->id);
	printf("Balance: %lf\n", curr->balance);
	printf("Transactions Count: %d\n", curr->transferCount);
	printf("Transactions:\n\n");
	trans* current_transfer = curr->transfers;
	for (i = 0; i < curr->transferCount; i++) {
		printf("%s %lf\n", current_transfer->mode, current_transfer->amount);
		current_transfer = current_transfer->next;
	}
	if (i == 0)
		printf("No records available\n\n");
}
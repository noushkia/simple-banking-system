#include <stdio.h>
#include <stdlib.h>
#include "AUinput.h"
#include "struct.h"
#include "checkDuplicates.h"
/*Need to use linked list!*/
int add_user(struct userinfo* head, char* command) {
	FILE *IDS;//id selector
	struct userinfo* curr;
	curr = head;
	char* username=(char*)malloc(15);
	char* password=(char*)malloc(15);
	char* phoneNumber=(char*)malloc(15);
	int idselector=1000;
	AUinput(command, username, password, phoneNumber);//devides the input word by word
	if (!checkDuplicate(head, username, phoneNumber)) {
		return 0;
	}
	IDS = fopen("IDSelector.txt", "r+");//chooses an id for the new account
	if (IDS == NULL)
		IDS = fopen("IDSelector.txt", "w+");
	fscanf(IDS, "%d", &idselector);
	idselector++;
	fseek(IDS, 0, SEEK_SET);
	fprintf(IDS, "%d", idselector);
	fclose(IDS);
 	while (curr->next != NULL) {
		curr = curr->next;
	}
	//now we input the default info
	curr->next = (users*)malloc(sizeof(users));
	curr = curr->next;
	curr->username = username;
	curr->password = password;
	curr->phoneNumber = phoneNumber;
	curr->id = idselector;
	curr->balance = 0;
	curr->transferCount = 0;
	curr->transfers = (trans*)malloc(sizeof(trans));
	curr->transfers->mode = (char*)malloc(15);
	curr->transfers->mode = "No records available";
	curr->transfers->next = NULL;
	curr->next = NULL;
	return 1;
}
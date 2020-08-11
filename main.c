#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "login.h"
#include "adminCommands.h"
#include "makeLinkedList.h"
#include "struct.h"
#include "makeLinkedList.h"
#include "userCommands.h"
#include "write.h"
#define true 1

void main() {
	int checkEnd=1,aou;//aou : Admin Or User
	struct userinfo *head ,*user;
	head = (struct userinfo*)malloc(sizeof(struct userinfo));
	user = (struct userinfo*)malloc(sizeof(struct userinfo));//defined for login of an account
	head->username = "admin";
	head->password = "123";
	head->phoneNumber = "00000000000";
	head->balance = 0;
	head->id = 0;
	head->transferCount = 0;
	head->transfers = NULL;
	head->next = NULL;
	makeLinkedList(&head);/*Forms the linked list based on the accounts file*/
	FILE* accounts = fopen("Accounts.txt", "r");
	if (accounts == NULL) {/*checks if there is any file*/
		accounts = fopen("Accounts.txt", "w");//adds a file
		fclose(accounts);
	}
	while (checkEnd) {
		while (true)//continues unless login wa successful or system exited
		{
			printf("Welcome to UTBank!\nPlease login as either admin or user:\n");
			int loginreturn = login(&aou,head,&user);
			if (loginreturn == 1)//someone logged in
				break;
			else if (loginreturn == 2) {
				checkEnd = 0;//exit
				break;
			}
		}
		if (checkEnd == 0)
			break;
		/*user*/if(aou){
			userCommands(head,user);
		}
		/*admin*/else {
			adminCommands(head);
		}
	}
	write(head);//writes the final list over the file
}
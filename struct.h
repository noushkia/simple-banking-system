struct transaction {
	char* mode;
	double amount;
	struct transaction* next;
};
struct userinfo {
	char* username;//max 15
	char* password;//max 15
	char* phoneNumber;//size 11
	long int id;
	double balance;
	int transferCount;
	struct transaction* transfers;
	struct userinfo* next;
};
typedef struct userinfo users;
typedef struct transaction trans;
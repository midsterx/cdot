#define MOD 1007
#define PRIME 23
#define MAX 300

struct node
{
    char type[100];
    char symbol[100];
    int value; // should be made union for different types
    int first_line_num;
    int last_line_num;
    int storage_req; // should accomodate for different stuff
    int scope, parentScope, funcScope;
    int valid; // 1 - valid, 0 - invalid
    long startAddress; // For function it will be the Line number in three address code
	int params;		// Number of parameters in a function
};

struct scopeTable{
	int scopeNum;
	int num;
	struct node symArr[MAX];
	struct scopeTable *parent;
	struct scopeTable *children[100];
	int numChild;
};

int addSym(struct scopeTable *head, char* givenSymbol, int lineno, char* givenType, int givenValue, int str_req, int scope);

int setVal(struct scopeTable *head, char *symbol, int lineno, int givenValue, int str_req);

int superAdd(struct scopeTable *head, char* givenSymbol, int add, int lineno, char* givenType, int givenValue, int str_req, int scope);

int findLen(struct scopeTable *head, char *givenId); // To find the length of an array	

struct scopeTable* addScope(struct scopeTable *head, int scopeNumber);

struct scopeTable* leaveScope(struct scopeTable *head);

struct node getVal(struct scopeTable *head, char *symbol, int *succ, int lineno);

int printsymtab(struct scopeTable *head);

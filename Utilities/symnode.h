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
    int scope_num;
    int valid;
};

struct scopeTable
{
	int num;
	struct node symarr[MAX];
	struct scopeTable *outer;
};

int hash(const char* str);

int addSym(struct scopeTable *head, char* givenSymbol, int lineno, char* givenType, int givenValue, int str_req);

int setVal(struct scopeTable *head, char *symbol, int lineno, int givenValue, int str_req);

int superAdd(struct scopeTable *head, char* givenSymbol, int add, int lineno, char* givenType, int givenValue, int str_req);

struct scopeTable* addScope(struct scopeTable *head, int gs);

struct scopeTable* delScope(struct scopeTable *head);

struct node getVal(struct scopeTable *head, char *symbol, int *succ, int lineno);

int printsymtab(struct scopeTable *head);

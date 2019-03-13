#define MOD 1007
#define PRIME 23
#define MAX 300

struct node
{
    char type[100];
    char symbol[100];
    char value[100];
    int line_num;
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

int addSym(struct scopeTable *head, char* givenSymbol, int lineno, char* givenType, char* data);

int setVal(struct scopeTable *head, char *symbol, int lineno, char* data);

int superAdd(struct scopeTable *head, char* givenSymbol, int add, int lineno, char* givenType, char* data);

struct scopeTable* addScope(struct scopeTable *head);

struct scopeTable* delScope(struct scopeTable *head);

struct node getVal(struct scopeTable *head, char *symbol, int *succ, int lineno);

int printsymtab(struct scopeTable *head);

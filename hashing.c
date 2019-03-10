#include <stdio.h>
#include <string.h>

#define MOD 1007
#define PRIME 23



char datatype[100];

typdef struct table_entry
{
	char type[100];
	char name[100];
	struct table_entry *next;
}

table_entry * symbol_table[MOD]={NULL};

//hash function
int hash(char * str)
{
	int len = strlen(str);
    int hash_value = 0;

    for(int i=0; i<len; i++)
    {
    	hash_value = (hash_value * PRIME + str[i]) % MOD;
    }

    printf("Hashed result:%d\n",hash_value);

    return hash_value;
} 


void insert(int lineNo, const char *name, const char *type) 
{
    if(lookup(name) != NULL)
        return;

    node *temp = malloc(sizeof(node));

    strcpy(temp->name, name);
    strcpy(temp->type, type);

    int hashValue = hash(name);
    temp->next = symbolTable[hashValue];
    symbolTable[hashValue] = temp;
}

node *lookup(const char *str) 
{
	int len = strlen(str);
	int hashValue = hash(str);

	//get node at hash value
	node *temp = symbolTable[hashValue];

	while(temp != NULL) 
	{
	    if(!strcmp(str, temp->name))
	        return temp;
	    temp = temp->next;
	}
	return NULL;
}


int main(int argc, char const *argv[])
{
	
	

	return 0;
}
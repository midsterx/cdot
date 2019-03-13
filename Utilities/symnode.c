#include "symnode.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int hash(const char* str)
// {
//     int len = strlen(str);
//     int hash_value = 0;

//     for(int i=0; i<len; i++)
//     {
//         hash_value = (hash_value * PRIME + str[i]) % MOD;
//     }

//     printf("Hashed result:%d\n",hash_value);

//     return hash_value;
// }

// struct node *lookup(const char *str) 
// {
//     int len = strlen(str);
//     int hashValue = hash(str);

//     //get node at hash value
//     struct node *temp = symarr[hashValue];

//     while(temp != NULL) 
//     {
//         if(!strcmp(str, temp->symbol))
//             return temp;
//         temp = temp->next;
//     }
//     return NULL;
// } 

// void insert(int tn, char t[], char s[], char v[], int ln, int sn, int token_count_flag, int scope_count_flag) 
// {
//     if(lookup(s) != NULL)
//         return;

//     int hashValue = hash(s);
//     struct node *temp = malloc(sizeof(struct node));

//     temp->token_num = tn++;
//     strcpy(temp->type, t);
//     strcpy(temp->symbol, s);
//     strcpy(temp->value, v);
//     temp->scope_num = sn;
//     temp->line_num = ln;
    
//     if (symarr[hashValue] == NULL)
//     {
//         symarr[hashValue] = temp;
//     }
//     else
//     {
//         struct node* start = symarr[hashValue];
//         while (start->next != NULL)
//             start = start->next;
//         start->next = temp;
//     }
    

//     //temp->next = symarr[hashValue];
//     //symarr[hashValue] = temp;
// }

int addSym(struct scopeTable *head, char* givenSymbol, int lineno, char* givenType, char* data) // to add to symbol table (new stuff)
{
	int newIndex = head->num;
	strcpy(head->symarr[newIndex].symbol, givenSymbol);
	head->symarr[newIndex].line_num = lineno;
	strcpy(head->symarr[newIndex].type, givenType);
    strcpy(head->symarr[newIndex].value, data);
	head->symarr[newIndex].valid = 1;
	head->num++;
	return 1;
}

int setVal(struct scopeTable *head, char *symbol, int lineno, char* data) // to set the value alone if symbol exists
{
	while(head!=NULL)
    {
		for(int i=0; i<head->num; i++)
        {
			if(strcmp(head->symarr[i].symbol, symbol)==0)
            {
                strcpy(head->symarr[i].value, data);
                return 1;
			}
		}
		head = head->outer;
	}
	return 0;	
}

int superAdd(struct scopeTable *head, char* givenSymbol, int add, int lineno, char* givenType, char* data)
{  
	int found = 0;
	for(int i=0; i<head->num; i++)
    {
		if(strcmp(head->symarr[i].symbol, givenSymbol)==0)
        {
			found = 1;
			setVal(head, givenSymbol, lineno, data);
			return 1; 
		}
	}
	if(found == 0 && add==1)
    {
		return addSym(head, givenSymbol, lineno, givenType, data);
	}
	return 0;
}


struct scopeTable* addScope(struct scopeTable *head)
{
	struct scopeTable *temp = malloc(sizeof(struct scopeTable));
	for(int i=0; i<MAX; i++)
    {
		temp->symarr[i].valid = 0;
	}
	temp->num = 0;
	temp->outer = head;
	head = temp;
	return head;
}

struct scopeTable* delScope(struct scopeTable *head)
{
	struct scopeTable *temp = head;
	head = head->outer;
	free(temp);
	return head;
}

struct node getVal(struct scopeTable *head, char *symbol, int *succ, int lineno)
{
	while(head!=NULL)
    {
		for(int i=0; i<head->num; i++)
        {
			if(strcmp(head->symarr[i].symbol, symbol)==0)
            {
				*succ = 1;
				head->symarr[i].line_num = lineno;
				return head->symarr[i];
			}
		}
		head = head->outer;
	}
	*succ = 0;	// if symbol doesn't exist in any scope
	struct node res;
	strcpy(res.symbol, "\0");
	return res;
}


int printsymtab(struct scopeTable *head)
{
    printf("\n\nSYMBOL TABLE\n\n");
    printf("Token No.\tType\tSymbol\tValue\tScope No.\tLine No.");
    printf("\n");
    while(head!=NULL)
    {
        for(int i=0, j=0; i<MAX && j < head->num; i++)
        {
            if(head->symarr[i].valid == 1)
            { 
                printf("%s\n", head->symarr[i].symbol);
                j++;
            }
        }
        head = head->outer;
    }
    return 1;
}
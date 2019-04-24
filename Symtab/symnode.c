#include "symnode.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int addSym(struct scopeTable *head, char* givenSymbol, int lineno, char* givenType, int givenValue, int str_req, int scope) // to add to symbol table (new stuff)
{
	int newIndex = head->num;
	strcpy(head->symArr[newIndex].symbol, givenSymbol);
	head->symArr[newIndex].first_line_num = lineno;
	head->symArr[newIndex].last_line_num = lineno;
	strcpy(head->symArr[newIndex].type, givenType);
    head->symArr[newIndex].value = givenValue;
	head->symArr[newIndex].storage_req = str_req;
	head->symArr[newIndex].valid = 1;
	head->symArr[newIndex].scope = scope;
	head->num++;
	return 1;
}

int setVal(struct scopeTable *head, char *symbol, int lineno, int givenValue, int str_req) // to set the value alone if symbol exists
{
	while(head!=NULL)
    {
		for(int i=0; i<head->num; i++)
        {
			if(strcmp(head->symArr[i].symbol, symbol)==0)
            {
                head->symArr[i].value = givenValue;
				head->symArr[i].storage_req = str_req;
                return 1;
			}
		}
		head = head->parent;
	}
	return 0;	
}

int superAdd(struct scopeTable *head, char* givenSymbol, int add, int lineno, char* givenType, int givenValue, int str_req, int scope)
{  
	int found = 0;
	for(int i=0; i<head->num; i++)
    {
		if(strcmp(head->symArr[i].symbol, givenSymbol)==0)
        {
			found = 1;
			setVal(head, givenSymbol, lineno, givenValue, str_req);
			return 1; 
		}
	}
	if(found == 0 && add==1)
    {
		return addSym(head, givenSymbol, lineno, givenType, givenValue, str_req, scope);
	}
	return 0;
}

int findLen(struct scopeTable *head, char *givenSymbol ){
	while(head!=NULL){
		for(int i=0; i<head->num; i++){
			if(strcmp(head->symArr[i].symbol, givenSymbol)==0){
				return head->symArr[i].storage_req / 4;
			}
		}
		head = head->parent;
	}
	return -1;
}

struct scopeTable* addScope(struct scopeTable *head, int scopeNumber)
{
	struct scopeTable *temp = malloc(sizeof(struct scopeTable));
	for(int i=0; i<MAX; i++){
		temp->symArr[i].valid = 0;
	}
	temp->num = 0;
	temp->parent = head;
	temp->numChild = 0;
	temp->scopeNum = scopeNumber;
	if (head!=NULL){
		head->children[head->numChild] = temp;
		head->numChild++;
	}
	head = temp;
	return head;
}

struct scopeTable* leaveScope(struct scopeTable *head){
	head = head->parent;
	return head;
}

struct node getVal(struct scopeTable *head, char *symbol, int *succ, int lineno)
{
	while(head!=NULL)
    {
		for(int i=0; i<head->num; i++)
        {
			if(strcmp(head->symArr[i].symbol, symbol)==0)
            {
				*succ = 1;
				head->symArr[i].last_line_num = lineno;
				return head->symArr[i];
			}
		}
		head = head->parent;
	}
	*succ = 0;	// if symbol doesn't exist in any scope
	struct node res;
	strcpy(res.symbol, "\0");
	return res;
}


int printsymtab(struct scopeTable *head)
{
    printf("\n\nSYMBOL TABLE\n\n");
    printf("Token\tType\tScope\tLine No.");
    printf("\n");
    while(head!=NULL)
    {
        for(int i=0, j=0; i<MAX && j < head->num; i++)
        {
            if(head->symArr[i].valid == 1)
            { 
                printf("%s\t%s\t%d\t%d\n", head->symArr[i].symbol, head->symArr[i].type, head->symArr[i].scope, head->symArr[i].first_line_num);
                j++;
            }
        }
        head = head->parent;
    }
    return 1;
}
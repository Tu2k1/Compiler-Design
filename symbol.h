
#ifndef SYMBOL_H_
#define SYMBOL_H_
#include"global.h"
#include"error.h"

int lookup(char s[]){
	int p;
	for (p = lastentry; p > 0; p--)
	    if (strcmp(symtable[p].lexptr, s) == 0)
	        return p;

	return 0;
}
int insert(char str[], int tok){

	int len = strlen(str);
	if (lastentry + 1 >= SYMMAX)
		error("symbol table full");

	if (lastchar + len + 1 >= STRMAX)
		error("lexemes array full");

	lastentry++;
	lastchar++;

	symtable[lastentry].token = tok;

	symtable[lastentry].lexptr = &lexemes[lastchar];

	lastchar += len;

	strcpy(symtable[lastentry].lexptr ,str);

	return lastentry;
}
#endif // SYMBOL_H_



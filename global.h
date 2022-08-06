
#ifndef GLOBAL_H_
#define GLOBAL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define STRMAX 999
#define SYMMAX 100

#define BSIZE  128
#define NONE   -1
#define EOS    '\0'

#define NUM    256
#define DIV    257
#define MOD    258
#define ID     259
#define DONE   260
#define IF     261
#define WHILE  262
#define THEN   263
#define DO     264
#define BEGIN  265
#define END    266
#define VOID   267




struct entry {
   char *lexptr;
   int token;
   };
FILE *input,*output,*err;
int tokenval = NONE;

int lineno = 1;
int lookahead;

char lexemes[STRMAX];
int lastchar = -1;
struct entry symtable[SYMMAX];
int lastentry = 0;
char lexbuf[BSIZE];
#endif // GLOBAL_H_



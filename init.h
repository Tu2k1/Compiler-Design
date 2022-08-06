#ifndef INIT_H_
#define INIT_H_
#include"global.h"
#include"symbol.h"

struct entry keywords[] = {
	"div", DIV,
	"mod", MOD,
	"if", IF,
	"while", WHILE,
	"begin", BEGIN,
	"end", END,
	"then", THEN,
	"do", DO,
	"void",VOID,
	0, 0
};

void init(){
	struct entry *p;
	for (p = keywords; p->token; p++)
		insert(p->lexptr,p->token);
}
#endif


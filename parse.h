#ifndef PARSE_H_
#define PARSE_H_
#include "emit.h"
#include "error.h"
#include "lexer.h"

int ifcount = -1,whilecount = -1;
int icounter = 0,wcounter = 0;
int tok; // store index
void parse(){
		lookahead = lexan();
		stmt();
		FuncDec();
		match(DONE);
}
void stmt(){
    switch(lookahead){
        case ID:
            tok = tokenval;
            match(ID);
            restID();
            break;
        case IF:
            ifcount++;
            icounter++;
            match(IF);
            match('('); expr(); match(')');
            fprintf(output,"pop r2\ncmp r2,0\nbe else%d\n",ifcount);
            match(THEN);
            stmt();
            fprintf(output,"else%d:\n",ifcount);
            if(icounter >= 2)
                ifcount--;
            break;
        case WHILE:
            whilecount++;
            wcounter++;
            fprintf(output,"while%d:\n",whilecount);
            match(WHILE);
            match('('); expr(); match(')');
            fprintf(output,"pop r2\ncmp r2,0\nbe endwhile%d\n",whilecount);
            match(DO);
            stmt();
            fprintf(output,"b while%d\nendwhile%d:\n",whilecount,whilecount);
            if(wcounter >= 2)
                whilecount--;
            break;
        case BEGIN:
            match(BEGIN);
            CS();
            match(END);
            break;
        default:
            return;
    }
}
void restID(){
    switch(lookahead){
        case '=':
            match('=');
            expr();
            fprintf(output,"pop %s\n",symtable[tok].lexptr);
            break;
        case '(':
            match('(');
            match(')');
            fprintf(output,"call %s\n",symtable[tok].lexptr);
            break;
        default:
            error("syntax error");
    }
}
void CS(){
    while(lookahead != END){
        stmt();match(';');
    }

}
void FuncDec(){
    while(lookahead == VOID){
        match(VOID);
        tok = tokenval;
        match(ID);
        fprintf(output,"%s:\n",symtable[tok].lexptr);
        match('(');
        match(')');
        match(BEGIN);
        CS();
        match(END);
        fprintf(output,"ret\n");
    }
}
void expr(){
    int t;
	term();
	while(1){
	   switch (lookahead) {
	     case '+': case '-':
	         t = lookahead;
	        match(lookahead);
	        term(); emit(t, NONE);
	       continue;
        default:
	       return;
	}
  }
}
void term(){
    int t;
	factor();
	while(1)
	     switch (lookahead) {
	        case '*': case '/': case DIV: case MOD:
	            t = lookahead;
                match(lookahead);
                factor();
                emit(t,NONE);
                continue;
            default:
                return;
	}
}
void factor(){
	switch (lookahead) {
	case '(':
		match('(');
        expr();
        match(')');
		break;
	case NUM:
	    emit(NUM, tokenval);
	    match(NUM);
		break;
	case ID:
	    emit(ID, tokenval);
	    match(ID);
		break;
	default:
		error("syntax error");
	}
}
void match(int t){
	if (lookahead == t)
		lookahead = lexan();
	else{
    switch(t){
        case EOF:
            error("error in closing file");
            break;
        case ';':
            error("semicolon missing");
            break;
        case ID:
        case NUM:
            error("operand missing");
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case DIV:
        case MOD:
            error("operator missing");
            break;
        case '=':
            error("equal sign missing");
            break;
        case END:
            error("end keyword missing");
            break;
        case '(':
        case ')':
            error("error in parenthesis");
            break;
        case DO:
            error("do keyword missing");
            break;
        case THEN:
            error("then keyword missing");
            break;
        default:
            error("syntax error");

        }
    }
}
#endif // PARSE_H_




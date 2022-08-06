#ifndef EMIT_H_
#define EMIT_H_
#include "global.h"
void emit(int token,int tval){
	switch(token) {
        case '+':
            fprintf(output,"pop r1\n");
            fprintf(output,"pop r2\n");
            fprintf(output,"add r2,r1\n");
            fprintf(output,"push r2\n");
            break;
		case '-':
            fprintf(output,"pop r1\n");
            fprintf(output,"pop r2\n");
            fprintf(output,"sub r2,r1\n");
            fprintf(output,"push r2\n");
            break;
		case '*':
            fprintf(output,"pop r1\n");
            fprintf(output,"pop r2\n");
            fprintf(output,"mult r2,r1\n");
            fprintf(output,"push r2\n");
            break;
		case '/':
            fprintf(output,"pop r1\n");
            fprintf(output,"pop r2\n");
            fprintf(output,"rdiv r2,r1\n");
            fprintf(output,"push r2\n");
            break;
        case DIV:
            fprintf(output,"pop r1\n");
            fprintf(output,"pop r2\n");
            fprintf(output,"div r2,r1\n");
            fprintf(output,"push r2\n");
            break;
        case MOD:
            fprintf(output,"pop r1\n");
            fprintf(output,"pop r2\n");
            fprintf(output,"mod r2,r1\n");
            fprintf(output,"push r2\n");
            break;
        case NUM:
            fprintf(output,"push %d\n",tval);
            break;
        case ID:
            fprintf(output,"push %s\n", symtable[tval].lexptr);
            break;
        default:
            fprintf(output,"token %d, tokenval %d\n ", token, tval);
	}
}
#endif



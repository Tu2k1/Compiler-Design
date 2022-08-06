#ifndef LEXER_H_
#define LEXER_H_
#include "symbol.h"
int lexan(){
	int t;
	while(1){
		t = getc(input);
		if (t == ' ' || t == '\t');

		else if (t == '\n')
            lineno++;

        else if (t == '^'){
            do{
                t = getc(input);
            }while(t != '\n');
            lineno++;
        }
        else if (t == '%'){
            do{
                t = getc(input);
                if (t == '\n')
                    lineno++;
            }while(t != '%');
        }
        else if (isdigit(t)) {
                ungetc(t,input);
                fscanf(input,"%d",&tokenval);
                return NUM;
		        }
        else if (isalpha(t)){
                int p, b = 0;
            while (isalnum(t)) {
                lexbuf[b++] = t;
                t = getc(input);

                if (b >= BSIZE)
                    error("compiler error");
                }
                lexbuf[b] = EOS;
                if (t != EOF)
                    ungetc(t, input);
                p = lookup(lexbuf);
                if(p == 0)
                    p = insert(lexbuf, ID);
                tokenval = p;
                return symtable[tokenval].token;
                }
        else if (t == EOF)
            return DONE;
        else
            return t;
    }
}
#endif // LEXER_H_




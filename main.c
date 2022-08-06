#include "init.h"
#include "parse.h"
void main (){
     input = fopen("file.exp","r");
     output = fopen("file.obj","w");
     err = fopen("file.err","w");
    if (input == NULL)
        printf("file doesn't exist\n");
    init();
    parse();
    fclose(input);
    exit(0);
}


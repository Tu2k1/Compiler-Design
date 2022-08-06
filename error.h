#ifndef ERROR_H_
#define ERROR_H_

void error(char* m){
	fprintf(err,"line %d: %s\n", lineno, m);
	exit(1);
}
#endif // ERROR_H_


%{
	#include <stdio.h>
	#include <string.h>
	#include <ctype.h>
	void yyerror(char const*);
	int yylex(void);
%}

%token VAR SIGN NUM

%%
	ASSIGN : | VAR ':''=' INT ';' ASSIGN;
	INT : SIGN NUM | NUM;
%%

void yyerror(char const *s) 
{
	fprintf(stderr, "%s\n", s);	
}

int yylex(void) 
{
	register char c;
	while (1) {		
		c = getchar();
		if (isspace(c)) continue;
		if (isalpha(c)) {
			for (; isalnum(c); c = getchar());
			return ungetc(c, stdin), VAR;
		}
		if (isdigit(c)) {
			for (; isdigit(c); c = getchar());
			return ungetc(c, stdin), NUM;
		}			
		if (c == '+' || c == '-') {
			return SIGN;
		}		
		return c;
	}
}
int main (void) {
	yyparse();
	return 0;
}

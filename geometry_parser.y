/**
 *	Parser Geometrico
 *
 *
 */
%{
#include <stdio.h>
#include <ctype.h>
#define MAXN 300

char lexema[MAXN];

typedef struct {int x, y;} Point;

Point sum(Point p, Point q) {
	Point r;
	r.x = p.x + q.x;
	r.y = p.y + q.y;
	return r;
}

Point yyval;
%}

%token POINT
%token ADD SUB MUL DIV
%token EOL

%%
calcList:
	| calcList exp EOL {}
;

exp: factor
	| exp ADD factor {}
	| exp SUB factor {}
;

factor: term
	| factor MUL term {}
	| factor DIV term {}
;

term: POINT;
%%

int main() {
	yyparse();
	return 0;
}

yyerror(char *msg) {
	fprintf(stderr, "error: %s\n", msg);
}


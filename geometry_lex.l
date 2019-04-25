%{
#include "geometry_parser.tab.h";
%}

%%
"+" {return ADD;}
"-" {return SUB;}
"*" {return MUL;}
"/" {return DIV;}
\([0-9]+,[0-9]+\) {
	int x, y;
	sscanf(yytext, "(%d,%d)", &x, &y);
	yyval.x = x;
	yyval.y = y;
	return POINT;
}
\n {return EOL;}
[ \t] {}
.	{printf("Mystery character %c\n", *yytext);}
%%

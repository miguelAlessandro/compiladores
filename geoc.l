%{
#include <geoC.h>
%}

%%
\[\[\s*[0-9]+(\.[0-9]+)?,\s*[0-9]+(\.[0-9]+)?\]\] {return POINT;}
[0-9]+(\.[0-9]+)? {return NUM;}
+ {return ADD;}
- {return SUB;}
/ {return DIV;}
* {return MUL;}
begin {return BEGIN;}
end {return END;}
if {return IF;}
for {return FOR;}
while {return WHILE;}
== {return EQUAL;}
!= {return DIFF;}
 
    if (strcasecmp(lexema, "and") == 0) return AND;
    if (strcasecmp(lexema, "or") == 0) return OR;
    if (strcasecmp(lexema, "point") == 0) return DATOPUNTO;
    if (strcasecmp(lexema, "**") == 0) return POW;
	return ID;
}

%%


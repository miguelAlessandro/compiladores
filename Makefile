#makefile to geoParser
geoParser: 	geometry_lex.l geometry_parser.y
			bison -d geometry_parser.y
			flex geometry_lex.l
			cc -o $@ geometry_parser.tab.c lex.yy.c -lfl


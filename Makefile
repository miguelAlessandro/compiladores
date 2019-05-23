#makefile to geoParser
geoParser: 	geoC.lpp geoC.ypp
			bison geoC.ypp
			flex geoC.lpp
			g++ -o $@ geoC.tab.cpp lex.yy.cpp -lfl


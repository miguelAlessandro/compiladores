#ifndef SYMBOL_HPP
#define SYMBOL_HPP
#include "trie.hpp"
#include <vector>
using namespace std;
const int maxN = 1e5;
struct Data{
	int token; 
	double value;
	Data(int token=0, double value=0.d) {
		this->token = token;
		this->value = value;
	}
};
Trie<Data> table(maxN);
struct oper {
	int op, it, l, r;
	oper(int op, int it, int l, int r): op(op), it(it), l(l), r(r) {}
};
vector<oper> codeTable;

void genCode(int op, int it, int l, int r) {
	codeTable.push_back(oper(op, it, l, r)); 
}

int putSymb(char name[], int token, double value) { 
	int id = table.find(name);	
	if (id) return id;
	return table.add(name, Data(token, value));
}

void printSymb(int root = 0, string s = "") {
	if (table.term[root]) {
		int id = table.id[root];
		printf("%d name = %s token = %d value %lf\n", id, s.c_str(), table.value[id].token, table.value[id].value);
	}
    for (int i = 0; i < 256; ++i) {
		if (table.link[root][i]) {
			printSymb(table.link[root][i], s + char(i));
		}
	}
}

void printTabCod() {
    for (int i = 0; i < codeTable.size(); ++i) {
		oper e = codeTable[i];
        printf("op = %d a1 = %d a2 = %d a3 = %c\n", e.op, e.it, e.l, e.r);
    }
	puts("");
}
#endif

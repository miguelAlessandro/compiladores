#ifndef SYMBOL_HPP
#define SYMBOL_HPP
#include <trie.hpp>
#include <vector>
const int maxN = 1e5;
struct Data{int token; double value;};
Trie<Data> table(maxN);
struct oper {int op, it, l, r;};
vector<oper> codeTable;

void genCode(int op, int it, int l, int r) {
	codeTable.push_back({op, it, l, r}); 
}

int tempVarN = 0;
int genTempVar() {
    char t[64];
    sprintf(t, "T_%d", tempVarN++);
    return putSymb(t, ID);
}

int putSymb(char name[], int token) {
	double value = 0.0;
	if (token == NUM) sscanf(name, "%lf", &value); 
	int id = table.find(name);	
	if (id) return id;
	return table.add(name, {token, value});
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
    for (auto e : codeTable) {
        printf("op = %d a1 = %d a2 = %d a3 = %c\n", e.op, e.it, e.l, e.r);
    }
	puts("");
}
#endif

#ifndef TRIE_HPP
#define TRIE_HPP
const int NIL = 0;
template<class T>
struct Trie {
public:
	vector<vector<int>> link;
	vector<T> value;	
	int elem, sz;
	vector<bool> term;
	vector<int> id;
	void Trie(int len, int sigma=256): elem(0), sz(0) {
		link.resize(len, vector<int>(sigma));
		value.resize(len);
		term.resize(len);
		id.resize(len);
	}	
	int add(char name[], T v) {
		int root=0;
		for (int i=0; name[i]; ++i) {
			int d = name[i];
			if (link[root][d]==0) link[root][d]=++elem;
			root=link[root][d];
		}
		term[root]=1;
		value[sz]=v;
		id[root] = ++sz;
		return id[root];
	}
	int find(char name[]) {
		int root=0;
		for (int i=0; name[i]; ++i) {
			int d=name[i];
			if (link[root][d] == 0) return 0;
			root=link[root][d];
		}
		if (not term[root]) return 0;
		return id[root];
	}
};
#endif

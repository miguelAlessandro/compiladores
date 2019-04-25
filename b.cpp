#include <bits/stdc++.h>
using namespace std;

const int maxN = 41;
bool memo[maxN][maxN][maxN][maxN][2];
bool vis[maxN][maxN][maxN][maxN][2];
string s;

bool dp(int cnt, int l1, int r1, int l2, bool turn) {
	if (cnt == n/2 and !turn) {	
		return l2 == n;
	}
	if (vis[cnt][l1][r1][l2][turn]) return memo[cnt][l1][r1][l2][turn];
	vis[cnt][l1][r1][l2][turn] = 1;
	bool ans = 0;
	if (turn&1) {
		for (int i = r1; i < n; ++i) {		
			ans |= dp(cnt + r1 - i + 1, l1, i, l2, 0);
		}
	} else {
		for (int i = l2; i < n; ++i) {		
			if (l1 + i - l2 == r1) break;
			if (s[i] != s[l1 + i - l2]) break;
			ans |= dp(cnt, l1 + i - l2 + 1, r1, i, 1);
		}
	}
	return memo[cnt][l1][r1][l2][turn] = ans;
}

int main() {

	return 0;
}

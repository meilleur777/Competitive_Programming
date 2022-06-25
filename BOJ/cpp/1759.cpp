#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	fast_io;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

int L, C;
vector<char> A(C);
vector<bool> chk;
vector<string> cand;

void makeCand(int now, int used) {
	if (used == L) {
		string temp("");
		for (int i = 0; i < C; i++) {
			if (chk[i]) {
				temp += A[i];
			} 
		}
		cand.push_back(temp);
		return;
	}
	if (now == C) {
		return;
	}

	chk[now] = true;
	makeCand(now + 1, used + 1);
	chk[now] = false;
	makeCand(now + 1, used);
}

int main() {
	init_code();

	cin >> L >> C;
	A.resize(C);
	chk = vector<bool> (C, false);
	for (int i = 0; i < C; i++) {
		cin >> A[i];
	}	
	sort(A.begin(), A.end());
	makeCand(0, 0);
	string vowel("aeiou");
	for (auto can : cand) {
		int vocnt = 0;
		for (auto j : can) {
			if (find(vowel.begin(), vowel.end(), j) != vowel.end()) {
				vocnt++;
			}
		}
		if (vocnt >= 1 && can.size() - vocnt >= 2) {
			cout << can << '\n';
		}
	}

	return 0;
}

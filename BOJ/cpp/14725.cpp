#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef struct _trie {
	string s;
	map<string, _trie*> mp;
} trie;

void newtrie(trie* now, string w) {
	map<string, _trie*>* q=new map<string, trie*>;
	trie* tmp=new trie;
	tmp->s=w;
	tmp->mp=*q;
	now->mp.insert({w, tmp});
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	map<string, _trie*> b;
	trie base={"", b};
	rep(i, n) {
		int k;
		cin >> k;
		trie* now=&base;
		rep(j, k) {
			string t;
			cin >> t;
			if (now->mp.find(t)==now->mp.end()) {
				newtrie(now, t);
			}
			now=now->mp[t];
		}
	}
	function<void(int, trie*)> pri=[&](int cnt, trie* a) {
		cout << a->s << '\n';
		for (auto [p, q]:a->mp) {
			rep(i, cnt) cout << "--";
			pri(cnt+1, q);
		}
	};
	for (auto [p, q]:base.mp) {
		pri(1, q);
	}

	return 0;
}

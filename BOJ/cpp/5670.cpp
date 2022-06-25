#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

typedef struct _trie {
	char s;
	bool ed=false;
	map<char, _trie*> mp;
} trie;

void newtrie(trie* now, char w) {
	map<char, _trie*>* q=new map<char, trie*>;
	trie* tmp=new trie;
	tmp->s=w;
	tmp->mp=*q;
	now->mp.insert({w, tmp});
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cout << fixed;
	cout.precision(2);

	int n;
	while (cin >> n) {
		vector<string> ww(n);
		map<char, _trie*> q;
		trie base={'.', false, q};
		rep(i, n) {
			string s;
			cin >> s;
			ww[i]=s;
			int l=(int)s.size();
			trie* now=&base;
			rep(j, l) {
				char c=s[j];
				if (now->mp.find(c)==now->mp.end()) {
					newtrie(now, c);
				}
				now=now->mp[c];
			}
			now->ed=true;
		}	
		function<int(trie*, int, string)> sol=[&](trie* now, int cnt, const string& s) {
			if (cnt==s.size()) return 0;
			int ret=0;
			ret+=(int)(now->mp.size())!=1 || now->ed;
			ret+=sol(now->mp[s[cnt]], cnt+1, s);
			return ret;
		};
		int sum=0;
		rep(i, n) {
			sum+=1+sol(base.mp[ww[i][0]], 1, ww[i]);
		}
		cout << (double)sum/n << '\n';
	}

	return 0;
}

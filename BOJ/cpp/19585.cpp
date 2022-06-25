#include <bits/stdc++.h>
using namespace std;

typedef struct {
	bool end;
	int v[26];
} trie;

trie* www[4000001];
int nxt=0;

void newnode(int parent, char x) {
	www[nxt]=(trie*)malloc(sizeof(trie));
	www[nxt]->end=false;
	memset(www[nxt]->v, 0, sizeof(int)*26);
	if (parent!=-1) www[parent]->v[x-'a']=nxt;
	nxt++;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	string s;
	int c, n, q;
	cin >> c >> n;
	newnode(-1, '0');
	while (c--) {
		cin >> s;
		int now=0;
		for (int j=0; j<(int)s.size(); j++) {
			if (!www[now]->v[s[j]-'a']) newnode(now, s[j]);
			now=www[now]->v[s[j]-'a'];
			if (j==(int)s.size()-1) www[now]->end=true;
		}
	}
	unordered_set<string> st;
	while (n--) {
		cin >> s;
		st.insert(s);
	}
	cin >> q;
	while (q--) {
		cin >> s;
		int now=0;
		bool flag=false;
		for (int i=0; i<(int)s.size(); i++) {
			if (!www[now]->v[s[i]-'a']) break;
			now=www[now]->v[s[i]-'a'];
			if (www[now]->end && st.find(s.substr(i+1))!=st.end()) {
				flag=true;
				break;
			}
		}
		if (flag) cout << "Yes\n";
		else cout << "No\n";
	}

	return 0;
}

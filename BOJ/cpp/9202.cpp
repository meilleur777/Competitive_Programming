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

int dy[]={0, 0, 1, 1, 1, -1, -1, -1};
int dx[]={1, -1, 1, 0, -1, 1, 0, -1};

int score(int a) {
	if (a==0 || a==1) return 0;
	if (a==3 || a==4) return 1;
	if (a==5) return 2;
	if (a==6) return 3;
	if (a==7) return 5;
	if (a==8) return 11;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int w;
	cin >> w;
	map<char, trie*> q;
	trie base={' ', false, q};
	rep(i, w) {
		string s;
		cin >> s;
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
	int b;
	cin >> b;
	cin.clear();
	while (b--) {
		if (b!=0) cin.clear();
		vector<string> brd(4);
		rep(i, 4) cin >> brd[i];
		string mx="";
		int acnt=0, sco=0;
		vector<vector<bool>> vis(4, vector<bool>(4, false));
		set<string> st;
		auto longest=[&](string a, string b) {
			if (a.size()==b.size()) return a<b?a:b;
			return a.size()<b.size()?b:a;
		};
		function<void(int, int, trie*, string)> sol=[&](int y, int x, trie* now, string s) {
			if (now->ed) {
				if (st.find(s)==st.end()) {
					st.insert(s);
					sco+=score(s.size());
					mx=longest(mx, s);
					acnt++;
				}
			}
			rep(d, 8) {
				int ny=y+dy[d], nx=x+dx[d];
				if (ny>=4 || ny<0 || nx>=4 || nx<0) continue;
				if (vis[ny][nx]) continue;
				char nxt=brd[ny][nx];
				if (now->mp.find(nxt)!=now->mp.end()) {
					vis[ny][nx]=true;
					sol(ny, nx, now->mp[nxt], s+nxt);
					vis[ny][nx]=false;
				}
			}
		};
		rep(i, 4) rep(j, 4) {
			if (base.mp.find(brd[i][j])!=base.mp.end()) {
				vis[i][j]=true;
				sol(i, j, base.mp[brd[i][j]], string(1, brd[i][j]));
				vis[i][j]=false;
			}
		}
		cout << sco << ' ' << mx << ' ' << acnt << '\n';
	}

	return 0;
}

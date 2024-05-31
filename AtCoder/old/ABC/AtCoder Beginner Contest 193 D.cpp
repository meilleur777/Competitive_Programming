#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

int k;
string s, t;
int taksco=0, aoksco=0;
vector<int> cnt;

int main() {
	init_code();
	cout << fixed;
	cout.precision(10);

	cin >> k >> s >> t;
	cnt=vector<int>(10, k);
	vector<int> tak(10, 0), aok(10, 0);
	ll sum=k*9;
	rep(i, 4) {
		tak[s[i]-'0']++;
		aok[t[i]-'0']++;
		cnt[s[i]-'0']--;
		cnt[t[i]-'0']--;
		sum-=2;
	}
	ld ans=0;
	ll allcnt=sum*(sum-1);
	ll takcnt=0;
	for (int i=1; i<10; i++) {
		if (cnt[i]==0) continue;
		cnt[i]--;
		tak[i]++;
		for (int j=1; j<10; j++) {
			if (cnt[j]==0) continue;
			cnt[j]--;
			aok[j]++;
			int taksco=0, aoksco=0;;
			for (int k=1; k<10; k++) {
				taksco+=k*pow(10, tak[k]);
				aoksco+=k*pow(10, aok[k]);
			}
			if (taksco>aoksco) {
				ll tmp=cnt[i]+1;
				if (i==j) tmp++;
				takcnt+=tmp*(cnt[j]+1);
			}
			aok[j]--;
			cnt[j]++;
		}	
		cnt[i]++;
		tak[i]--;
	}
	cout << takcnt/(ld)allcnt;

	return 0;
}

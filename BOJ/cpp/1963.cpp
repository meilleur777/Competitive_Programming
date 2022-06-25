#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

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

vector<bool> isPrime(1e5+1, true);

void sieve() {
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i*2 <= 1e5; i++) {
		for (int j = i*2; j <= 1e5; j += i) {
			isPrime[j] = false;		
		}
	}
}

int main() {
	init_code();

	sieve();
	int T;
	cin >> T;
	while (T--) {
		int a, b;
		cin >> a >> b;
		vector<int> vis(1e5+1, -1);
		vis[a] = 0;
		queue<int> q;
		q.push(a);
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 10; j++) {
					if (i == 0 && j == 0) continue;
					string s = to_string(now);
					s[i] = j + '0';
					int temp = stoi(s);
					if (vis[temp] == -1 && isPrime[temp]) {
						q.push(temp);
						vis[temp] = vis[now]+1;
					}
				}
			}			
		}
		if (vis[b] == -1) {
			cout << "impossible\n";
		}
		else {
			cout << vis[b] << '\n';
		}
	}	

	return 0;
}

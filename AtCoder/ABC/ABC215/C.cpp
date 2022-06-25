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

string S;
char temp[10];
vector<string> cand;
bool sel[10] = { false };

void makeCand(int now) {
	if (now == S.size()) {
		cand.push_back(temp);
		return;
	}

	for (int i = 0; i < S.size(); i++) {
		if (!sel[i]) {
			sel[i] = true;
			temp[now] = S[i];
			makeCand(now + 1);
			sel[i] = false;
		}
	}
}

int main() {
	init_code();

	int N;
	cin >> S >> N;

	sort(S.begin(), S.end());

	makeCand(0);

	sort(cand.begin(), cand.end());
	cand.erase(unique(cand.begin(), cand.end()), cand.end());

	cout << cand[N - 1];

	return 0;
}

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

const ll mod = 1e9+7;

int N;
string S("ACGT");
vector<string> can;

void makeFir(int now, string made) {
	if (now == 3) {
		if (made == "ACG" || made == "AGC" || made == "GAC") {
			return;
		}
		can.push_back(made);
		return;
	}

	for (auto i : S) {
		makeFir(now+1, made+i);
	}
}

map<pair<int, string>, ll> cache;

bool ok(string t) {
	if (string(t.begin(), t.end()-1) == "AGC" ||
		string(t.begin()+1, t.end()) == "AGC") {
		return false;
	}
	for (int i = 0; i < t.size()-1; i++) {
		string temp = t;
		swap(temp[i], temp[i+1]);
		if (string(temp.begin(), temp.end()-1) == "AGC" ||
			string(temp.begin()+1, temp.end()) == "AGC") {
			return false;
		}
	}
	return true;
}

ll solve(int now, string last) {
	if (now == N) {
		return 1;
	}

	map<pair<int, string>, ll>::iterator it = cache.find({now, last});
	if (it == cache.end()) {
		cache.insert({{now, last}, 0});
		it = cache.find({now, last});
	}
	else {
		return it->second;
	}

	for (auto i : S) {
		string temp = last+i;
		if (ok(temp)) {
			it->second += solve(now+1, string(temp.begin()+1, temp.end()));
			it->second %= mod;
		}
	}
	return it->second;
}

int main() {
	init_code();

	makeFir(0, "");
	cin >> N;
	ll ans = 0;
	for (auto i : can) {
		ans += solve(3, i);
		ans %= mod;
	}
	cout << ans;

	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, c;
	cin >> n >> c;
	vector<int> a(n);
	map<int, int> cnt, when;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		if (!when.count(a[i])) when[a[i]]=i;
		cnt[a[i]]++;
	}
	sort(a.begin(), a.end(), [&](int p, int q) {
        return cnt[p]==cnt[q]?when[p]<when[q]:cnt[p]>cnt[q];
	});
	for (auto i:a) cout << i << ' ';

	return 0;
}

#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n), b(n);
	rep(i, n) {
		cin >> a[i];
		b[i]=i+1;
	}
	if (a==b) {
		cout << "1 1\n1 1";
		return 0;
	}
	int left=0;
	while (a[left]==left+1) left++;
	int right=n-1;
	while (a[right]==right+1) right--;
	vector<int> c;
	for (int i=0; i<left; i++) c.push_back(a[i]);
	for (int i=right; i>=left; i--) c.push_back(a[i]);
	for (int i=right+1; i<n; i++) c.push_back(a[i]);
	if (b==c) {
		cout << "1 1\n" << left+1 << ' ' << right+1;
		return 0;
	}
	int sta=-1;
	rep(i, n) if (a[i]==left+1) sta=i;
	c=a;
	for (int i=0; i<=(sta-left)/2; i++) {
		swap(c[left+i], c[sta-i]);
	}
	int cle=0;
	while (c[cle]==cle+1) cle++;
	int cri=n-1;
	while (c[cri]==cri+1) cri--;
	for (int i=0; i<=(cri-cle)/2; i++) {
		swap(c[cle+i], c[cri-i]);
	}
	if (c==b) {
		cout << left+1 << ' ' << sta+1 << '\n' << cle+1 << ' ' << cri+1;
		return 0;
	}
	for (int i=n-1; i>=0; i--) {
		if (a[i]==right+1) sta=i;
	}	
	c=a;
	for (int i=0; i<=(right-sta)/2; i++) {
		swap(c[sta+i], c[right-i]);
	}
	cle=0, cri=n-1;
	while (c[cle]==cle+1) cle++;
	while (c[cri]==cri+1) cri--;
	for (int i=0; i<=(cri-cle)/2; i++) {
		swap(c[cle+i], c[cri-i]);
	}
	if (c==b) {
		cout << sta+1 << ' ' << right+1 << '\n' << cle+1 << ' ' << cri+1;
		return 0;
	}
	cout << -1;

	return 0;
}

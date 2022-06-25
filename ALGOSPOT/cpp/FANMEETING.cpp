#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*Female -> 0, Male -> 1*/

vector<int> multiply(const vector<int>& a, const vector<int>& b) {
	int asize = a.size(), bsize = b.size();
	vector<int> c(asize + bsize + 1, 0);
	for (int i = 0; i < asize; i++) {
		for (int j = 0; j < bsize; j++) {
			c[i + j] += a[i] * b[j];
		}
	}
	return c;
}

void addTo(vector<int>& a, vector<int>& b, int k) {
	int asize = a.size(), bsize = b.size();
	a.resize(max(asize, bsize + k));
	for (int i = 0; i < bsize; i++) a[i + k] += b[i];
}

void subFrom(vector<int>& a, vector<int>& b) {
	int bsize = b.size();
	for (int i = 0; i < bsize; i++) a[i] -= b[i];
}

vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
	int asize = a.size(), bsize = b.size();
	if (asize < bsize) return karatsuba(b, a);
	if (!asize || !bsize) return vector<int>();
	
	if (asize <= 50) return multiply(a, b);
	
	int half = asize / 2;
	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half, a.end());
	vector<int> b0(b.begin(), b.begin() + min(bsize, half));
	vector<int> b1(b.begin() + min(bsize, half), b.end());
	
	vector<int> z0 = karatsuba(a0, b0);
	vector<int> z2 = karatsuba(a1, b1);
	addTo(a0, a1, 0); addTo(b0, b1, 0);
	vector<int> z1 = karatsuba(a0, b0);
	subFrom(z1, z0); subFrom(z1, z2);
	
	vector<int> result;
	addTo(result, z0, 0);
	addTo(result, z1, half);
	addTo(result, z2, half * 2);
	return result;
}

int solve(const string& members, const string& fans) {
	int msize = members.size(), fsize = fans.size();
	vector<int> A(msize), B(fsize);
	for (int i = msize - 1; i >= 0; i--) A[i] = (members[msize - i - 1] == 'M');
	for (int i = 0; i < fsize; i++) B[i] = (fans[i] == 'M');
	
	int count = 0;
	vector<int> C = karatsuba(A, B);
	for (int i = msize - 1; i < fsize; i++) if (!C[i]) count++;
	return count;
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int C; cin >> C;
	while (C--) {
		string members, fans;
		cin >> members >> fans;
		cout << solve(members, fans) << '\n';	
	}
}


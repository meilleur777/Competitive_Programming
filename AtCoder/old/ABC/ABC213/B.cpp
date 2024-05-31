#include <vector>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

bool cmp(intp a, intp b) {
	return a.first > b.first;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
		
	int N;
	cin >> N;
	vector<intp> A(N);
	
	for (int i = 0; i < N; i++) {
		cin >> A[i].first;
		A[i].second = i + 1;
	}
	sort(A.begin(), A.end(), cmp);
	cout << A[1].second;
}


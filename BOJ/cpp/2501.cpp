#include <vector>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N, K;
	cin >> N >> K;
	vector<int> a;
	for (int i = 1; i <= N; i++) {
		if (N % i == 0) {
			a.push_back(i);
		}
	}	
	
	a.erase(unique(a.begin(), a.end()), a.end());
	if (a.size() < K) {
		cout << '0';
	}
	else {
		cout << a[K - 1];
	}
}


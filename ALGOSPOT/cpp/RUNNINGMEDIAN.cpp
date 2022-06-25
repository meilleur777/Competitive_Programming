#include <queue>
#include <vector>
#include <iostream>
#define MOD 20090711
using namespace std;

struct RNG {
	int seed, a, b;
	RNG(int _a, int _b) : a(_a), b(_b), seed(1983) {}
	int next() {
		int result = seed;
		seed = ((seed * (long long)a) + b) % MOD;
		return result;
	}
};

int solve(int n, RNG rng) {
	priority_queue<int, vector<int>, less<int> > maxHeap;
	priority_queue<int, vector<int>, greater<int> > minHeap;
	int ret = 0;
	
	for (int cnt = 1; cnt <= n; cnt++) {
		if (maxHeap.size() == minHeap.size()) maxHeap.push(rng.next());
		else minHeap.push(rng.next());
		
		if (!minHeap.empty() && !maxHeap.empty() && minHeap.top() < maxHeap.top()) {
			int a = maxHeap.top(), b = minHeap.top();
			maxHeap.pop(), minHeap.pop();
			maxHeap.push(b), minHeap.push(a);
		}
		ret = (ret + maxHeap.top()) % MOD;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
		
	int C; cin >> C;
	while (C--) {
		int N, a, b; cin >> N >> a >> b;
		RNG generator(a, b);
		cout << solve(N, generator) << '\n';
	}
}


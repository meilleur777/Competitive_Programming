#include <math.h>
#include <vector>
#include <float.h>
#include <iostream>
#include <algorithm>
using namespace std;

int N;
double best;
pair<int, int> A[100001];

void solve(int x, int y, int pcnt, int mcnt, int now) {
	if (now == N) {
		best = min(best, sqrt((double)x * x + (double)y * y));
		return;
	}
	
	if (pcnt > 0) {
		solve(x + A[now].first, y + A[now].second, pcnt - 1, mcnt, now + 1);
	}
	if (mcnt > 0) {
		solve(x - A[now].first, y - A[now].second, pcnt, mcnt - 1, now + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout << fixed;
	cout.precision(10);
	
	int T;
	cin >> T;
	while (T--) {
		best = DBL_MAX;
		
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> A[i].first >> A[i].second;
		}
		
		solve(0, 0, N / 2, N / 2, 0);	
		
		cout << best << '\n';	
	}
}


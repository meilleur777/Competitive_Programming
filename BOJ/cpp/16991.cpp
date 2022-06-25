#include <math.h>
#include <iostream>
#define INF 0x3F3F3F3F
#define NUM 16
using namespace std;

int N, x[NUM + 1], y[NUM + 1];
double cache[NUM + 1][1 << NUM], edges[NUM + 1][NUM + 1];

double solve(int now, int state) {
	if (state == (1 << N) - 1) return edges[now][0];
	
	double& ret = cache[now][state];
	if (ret != -1) return ret;
	
	ret = INF;	
	for (int i = 1; i < N; i++)
		if (!(state & (1 << i))) ret = min(ret, edges[now][i] + solve(i, state | (1 << i)));
	return ret;
}

void precalc() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			edges[i][j] = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout << fixed; cout.precision(10);
	
	cin >> N;
	fill_n(&cache[0][0], (NUM + 1) * (1 << NUM), -1);
	for (int i = 0; i < N; i++) cin >> x[i] >> y[i];
	precalc();
	cout << solve(0, 1) << '\n';
}


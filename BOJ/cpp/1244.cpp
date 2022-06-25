#include <iostream>
using namespace std;

void onoff(bool& b) { b = b ? false : true; }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int N; cin >> N;
	bool switches[102];
	for (int i = 1; i <= N; i++) cin >> switches[i];
	int K; cin >> K;
	for (int i = 0; i < K; i++) {
		int o, x; cin >> o >> x;
		if (o == 1) for (int j = x; j <= N; j += x) onoff(switches[j]);			
		else {
			onoff(switches[x]);
			int left = x - 1, right = x + 1;
			while (left > 0 && right <= N && switches[left] == switches[right]) {
				onoff(switches[left]); onoff(switches[right]);
				left--, right++;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << switches[i];
		if (!(i % 20) || i == N) cout << '\n';
		else cout << ' ';
	}
}


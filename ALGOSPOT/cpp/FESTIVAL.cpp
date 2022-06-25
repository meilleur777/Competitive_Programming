#include <iostream>
#include <vector>
#define INF 0x3F3F3F3F
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
using namespace std;

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cout << fixed;
	cout.precision(10);
	
	int C; cin >> C;
	while (C--) {
		double min = INF;
		vector<int> price;
		
		int N, L; cin >> N >> L;
		for (int i = 0; i < N; i++) {
			int a; cin >> a;
			price.push_back(a);
		}
		for (int days = L; days <= N; days++) {
			int sum = 0;
			for (int i = 0; i < days; i++) {
				sum += price[i];
			}
			min = MIN(min, (double)sum / days);
			
			for (int i = days; i < N; i++) {
				sum += price[i] - price[i - days];
				min = MIN(min, (double)sum / days);
			}
		}
		cout << min << '\n';
	}
}


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
	
	int N, M;
	cin >> M >> N;
	
	int C;
	cin >> C;
	
	vector<intp> store(C);
	for (int i = 0; i < C; i++) {
		cin >> store[i].first >> store[i].second;
	}	
	
	intp A;
	cin >> A.first >> A.second;
	
	int sum = 0;
	for (int i = 0; i < C; i++) {
		if (A.first == store[i].first) {
			sum += abs(A.second - store[i].second);
		}
		else {
			int a = A.first, s = store[i].first;
			if (a == 1) {
				if (s == 2) {
					int temp = store[i].second + A.second;
					sum += N + min(temp, 2 * M - temp);
				}
				else if (s == 3) {
					sum += store[i].second + A.second;
				}
				else if (s == 4) {
					sum += M - A.second + store[i].second;	
				}
			}
			else if (a == 2) {
				if (s == 1) {
					int temp = store[i].second + A.second;
					sum += N + min(temp, 2 * M - temp);
				}
				else if (s == 3) {
					sum += N - store[i].second + A.second;
				}
				else if (s == 4) {
					sum += M - A.second + N - store[i].second;
				}
			}
			else if (a == 3) {
				if (s == 1) {
					sum += store[i].second + A.second;
				}
				else if (s == 2) {
					sum += N - A.second + store[i].second;
				}
				else if (s == 4) {
					sum += M + min(store[i].second + A.second, 2 * N - store[i].second + A.second);
				}
			}
			else if (a == 4) {
				if (s == 1) {
					sum += A.second + M - store[i].second;
				}
				else if (s == 2) {
					sum += N - A.second + M - store[i].second;
				}
				else if (s == 3) {
					sum += M + min(store[i].second + A.second, 2 * N - store[i].second + A.second);
				}
			}
		}
 	}
 	
 	cout << sum;
}


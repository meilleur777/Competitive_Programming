#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
    int N, T, sum; cin >> N;
    for (int i = 1; i <= N; i++) {
        sum = T = i;
        while (T) {
            sum += T % 10;
            T /= 10;
        }
        if (sum == N) {
        	cout << i << '\n';
            return 0;
        }
    }
    cout << "0\n";
}


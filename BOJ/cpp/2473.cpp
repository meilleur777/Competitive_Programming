#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

/*용액 하나를 정하고, 나머지 두 용액을 Two-pointer Algorithm으로 구한다. O(N^2)*/

/*오답 이유 : 합이 0인 경우를 고려하지 않았다. start를 늘리던지 end를 줄이던지 상관이 없기 때문에
아무 값이나 조정해 해결했다. 사실 합이 0일 때 바로 종료해도 된다.*/

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N, result[3];
	ll A[5001], sum, minValue = 3000000003;
	
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	sort(A, A + N);
	
	for (int first = 0; first < N - 2; first++) {
		int start = first + 1, end = N - 1;
		while (start < end) {
			sum = A[first] + A[start] + A[end];
			if (abs(sum) < minValue) {
				minValue = abs(sum);
				result[0] = first;
				result[1] = start;
				result[2] = end;	
			}
			if (sum < 0) start++;
			else if (sum > 0 )end--;
			else {
				for (int i = 0; i < 3; i++) cout << A[result[i]] << ' ';
				cout << '\n';
				return 0;
			}
		}	
	}
	
	for (int i = 0; i < 3; i++) cout << A[result[i]] << ' ';
	cout << '\n';
}


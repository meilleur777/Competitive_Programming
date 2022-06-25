#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

/*prefix sum을 사용하면 상수 시간에 한쪽 부 배열의 합을 구할 수 있다.
이때 완전탐색으로 구현한다면 가능한 최대 경우의 수는 1000^4이므로 너무 많다.
합해서 T가 되는 경우를 구하면 되기 때문에 Two-Pointer로 해결해보자.
가능한 각각의 부 배열 합을 구해 놓은 뒤 오름차순 정렬한다.
첫 배열의 처음에, 다른 배열의 마지막에 포인터를 갖다놓고 쌍의 개수를 찾는다.*/

void getSum(int* src, vector<ll>& sum, int size) {
	for (int i = 1; i <= size; i++) {
		for (int j = 0; j < i; j++) {
			sum.push_back((ll)src[i] - (ll)src[j]);
		}
	}	
	sort(sum.begin(), sum.end());
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int x, T, n, m; cin >> T >> n;
	int A[1001] = { 0 }, B[1001] = { 0 };
	for (int i = 1; i <= n; i++) { cin >> x; A[i] = A[i - 1] + x; } 
	cin >> m;
	for (int i = 1; i <= m; i++) { cin >> x; B[i] = B[i - 1] + x; }
	
	vector<ll> sumA, sumB;
	getSum(A, sumA, n); getSum(B, sumB, m);
	
	ll count = 0;
	int left = 0, right = sumB.size() - 1;	
	while (left < sumA.size() && right >= 0) {
		ll sum = sumA[left] + sumB[right];
		if (sum < T) left++;
		else if (sum > T) right--;
		else {
			ll a = 1, b = 1;
			while (left < sumA.size() - 1 && sumA[left] == sumA[left + 1]) left++, a++;
			while (right > 0 && sumB[right] == sumB[right - 1]) right--, b++;
			count += a * b;
			left++;
		}
	}
	cout << count << '\n';
}


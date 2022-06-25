#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

/*40개의 정수가 주어지고, 부분수열의 합이 S인 경우의 수를 찾아야 한다. 단순히 완전탐색으로 구한다면
2^40으로 엄청나게 큰 수가 나온다. 그러나 배열을 반으로 쪼갠다면 2^20으로 100만 정도 크기가 된다.
이를 양쪽 배열에 대해 구한 다음, 양쪽 배열 각각에서 합이 S인 것을 찾고, 투 포인터 기법으로
전체 배열에서 합이 S인 것을 찾을 수 있다.*/

/*S가 0이면 아무 요소도 선택하지 않는 부분수열이 포함된다. 문제에서 크기가 양수인 부분수열만을
고려하므로, S가 0이면 구한 개수에서 1을 빼준다.*/

void calc(int current, int sum, const vector<int>& src, vector<int>& result) {
	if (current == src.size()) {
		result.push_back(sum);
		return;
	}
	calc(current + 1, sum, src, result);
	calc(current + 1, sum + src[current], src, result);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N, S; cin >> N >> S;
	vector<int> A(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	
	vector<int> sum1, sum2;
	vector<int> A1(A.begin(), A.begin() + A.size() / 2);
	vector<int> A2(A.begin() + A.size() / 2, A.end());
	
	calc(0, 0, A1, sum1); sort(sum1.begin(), sum1.end()); 
	calc(0, 0, A2, sum2); sort(sum2.begin(), sum2.end());
	
	ll count = 0;
	for (auto i : sum1) {
		auto a = lower_bound(sum2.begin(), sum2.end(), S - i);
		auto b = upper_bound(sum2.begin(), sum2.end(), S - i);
		count += (ll)(b - a);
	}
	
	if (!S) count--;
	cout << count << '\n';	
}


#include <queue>
#include <utility>
#include <limits.h>
#include <iostream>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	deque<p> dq;
	int N, D; cin >> N >> D;
	ll result = LLONG_MIN;
	for (int i = 1; i <= N; i++) {
		ll temp; cin >> temp;
		/*U-V>D이면 후보군에 포함되지 않는다.*/
		while (!dq.empty() && dq.front().second < i - D) dq.pop_front();
		/*원하는 위치에서 시작이 가능하다.*/
		if (!dq.empty()) temp += max(0LL, dq.front().first);
		result = max(result, temp);
		/*만일 지금 구한 값이 dq에 든 값보다 크거나 같으면, 최댓값의 후보가 될 수 없다.*/		
		while (!dq.empty() && dq.back().first <= temp) dq.pop_back();
		dq.push_back({ temp, i }); 		
	}
	cout << result << '\n';
}


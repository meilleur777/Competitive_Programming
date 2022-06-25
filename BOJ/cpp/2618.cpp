#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;

vector<p> event;
int W, cache[1005][1005], choice[1005][1005];

/*경찰차의 위치가 2차원이라 너무 많은 subproblem이 존재한다. 어떻게 하면 줄일 수 있을까?
생각해보니 경찰차가 존재하는 위치는 event가 있는 곳뿐이다.
우리가 필요한 정보는 가장 최근의 event가 무엇이고, 어떤 경찰차가 해결했는지이다.
그러나 이 경우에도 나머지 경찰차 한 대의 좌표 정보는 여전히 필요하다.
다시 생각해보니 그냥 경찰차 위치를 event 번호로 표현하면 될 것 같다.  
예를 들어 cache[500][501]이면 1번 차는 500을 해결한 상태이고, 2번 차는 501을 해결한 상태이다.
두 상태 중 큰 것이 가장 최근에 해결한 event라고 할 수 있겠다.*/

/*제일 첫 이벤트를 위해, event[0, 1]을 경찰차들의 초기 위치로 사용*/

/*해결한 경찰차 번호는 choice 배열에 저장한 후, 기록을 따라가기만 하면 된다.*/

/*event[a]와 event[b] 사이 거리 반환*/
int dist(int a, int b) {
	return abs(event[a].first - event[b].first) + abs(event[a].second - event[b].second); 
}

/*1번이 가장 최근에 해결한 event가 event1, 2번도 마찬가지일때,
앞으로 남은 event를 모두 해결하는 데 소요되는 이동 거리*/
int solve(int event1, int event2) {
	int nevent = max(event1, event2) + 1;
	if (nevent - 1 == W + 1) return 0;
	
	int& ret = cache[event1][event2];
	int& choose = choice[event1][event2];
	if (ret != -1) return ret;
	
	int move1 = dist(event1, nevent) + solve(nevent, event2);
	int move2 = dist(event2, nevent) + solve(event1, nevent);
	if (move1 < move2) choose = 1;
	else choose = 2;
	return ret = min(move1, move2);
}

void reconstruct(int event1, int event2, vector<int>& result) {
	int nevent = max(event1, event2) + 1;
	if (nevent - 1 == W + 1) return;
	
	int choose = choice[event1][event2];
	result.push_back(choose);
	if (choose == 1) reconstruct(nevent, event2, result);
	else reconstruct(event1, nevent, result);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	memset(cache, -1, sizeof(cache));
	
	int N; cin >> N >> W;
	event.push_back({ 1, 1 }); event.push_back({ N, N }); 
	
	for (int i = 0; i < W; i++) {
		int x, y; cin >> x >> y;
		event.push_back({ y, x });
	}
	cout << solve(0, 1) << '\n';	
	vector<int> result;
	reconstruct(0, 1, result);
	for (auto i : result) cout << i << '\n';
}


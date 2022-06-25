#include <string.h>
#include <iostream>
#define INF 0x3F3F3F3F
using namespace std;

int N, K, M, L;
int pre[13];	/*pre[a] a의 선수 과목*/
int classes[11]; /*class[a] a학기의 개설 과목*/
int cache[11][1 << 12];

/*x에 켜진 비트 수를 반환*/
int bitCount(int x) {
	if (!x) return 0;
	return __builtin_popcount(x); 
}

/*현재 semester학기이고, 들은 과목들이 taken으로 주어질 때, 앞으로 다녀야 할 최소 학기 반환 */
int solve(int semester, int taken) {
	/*K개 이상의 과목을 들은 경우*/
	if (bitCount(taken) >= K) return 0;
	/*남은 학기가 없을 경우*/
	if (semester == M) return INF;
	
	int& ret = cache[semester][taken];
	if (ret != -1) return ret;
	ret = INF;
	
	/*이번 학기에 수강 가능한 과목 중 아직 수강하지 않은 과목의 목록*/
	int canTake = (classes[semester] & ~taken);
	
	/*아직 선수 과목을 듣지 않은 과목들은 걸러낸다.*/
	for (int i = 0; i < N; i++) {
		if ((canTake & (1 << i)) && (taken & pre[i]) != pre[i]) {
			canTake &= ~(1 << i);
		}
	}
	
	/*들을 수 있는 과목 집합의 모든 부분집합(공집합 제외)을 순회한다.*/
	for (int take = canTake; take > 0; take = ((take - 1) & canTake)) {
		if (bitCount(take) > L) continue;
		ret = min(ret, solve(semester + 1, taken | take) + 1);
	}
	ret = min(ret, solve(semester + 1, taken));
	return ret; 
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int C; cin >> C;
	while (C--) {
		memset(pre, 0, sizeof(pre));
		memset(cache, -1, sizeof(cache));
		memset(classes, 0, sizeof(classes));
		
		cin >> N >> K >> M >> L;
		
		for (int i = 0; i < N; i++) {
			int R; cin >> R;
			for (int j = 0; j < R; j++) {
				int x; cin >> x; 
				pre[i] |= (1 << x);
			}
		}
		
		for (int i = 0; i < M; i++) {
			int c; cin >> c;
			for (int j = 0; j < c; j++) {
				int x; cin >> x;
				classes[i] |= (1 << x);
			}
		}
		int result = solve(0, 0);
		if (result >= INF) cout << "IMPOSSIBLE\n";
		else cout << result << '\n';
	}	
}


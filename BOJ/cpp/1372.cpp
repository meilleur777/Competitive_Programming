#include <string>
#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#define NUM 12
using namespace std;

/*단어 개수 N개에 대해 가능한 조합의 개수는 N!이다. 12!은 5억에 가까운 값이다.
어떤 단어를 뒤에 붙인 길이를 구하는 데 필요한 정보는 앞의 단어와 지금까지 붙인 길이이다.
앞의 단어의 종류는 12개, 지금까지 붙인 길이는 최대 12 * 50이므로 저장이 가능하다.
그러면 각 부분문제에 대해 뒤에 붙일 단어를 선택하는 데 O(N)의 시간이 소요되므로, 
전체 O(MN^2)의 시간복잡도가 요구된다.

이때 사전순으로 가장 먼저 오는 것을 선택해야 하므로, reconstruct()에서
문자열을 재구성할 때 후보 문자열들 중 가장 사전순으로 빠른 것을 선택한다.
매 단계마다 가장 빠른 것을 선택하므로 그 결과 또한 사전순으로 가장 빠르다.*/

int N;
string words[NUM + 1];
bool jump[NUM + 1] = { false }; /*어떤 문자열이 다른 문자열에 포함되면 jump*/
int overlap[NUM + 1][NUM + 1], cache[NUM + 1][1 << NUM];

/*마지막 조각이 last이고, 지금까지 used를 사용했을 때 앞으로 남은 문자열들을
추가하여 얻을 수 있는 overlap의 최대값 반환*/
int restore(int last, int used) {
	if (used == (1 << N) - 1) return 0;
			
	int& ret = cache[last][used];
	if (ret != -1) return ret;
	
	ret = 0;
	for (int next = 0; next < N; next++) {
		if (jump[next] || used & (1 << next)) continue;
		int temp = overlap[last][next] + restore(next, used | (1 << next));
		ret = max(ret, temp);
	}
	return ret;
}

string rcache[NUM + 1][1 << NUM];
string reconstruct(int last, int used) {
	if (used == (1 << N) - 1) return "";
	
	string& ret = rcache[last][used];
	if (ret != "e") return ret;
	
	vector<string> results;
	for (int next = 0; next < N; next++) {
		if (jump[next] || (used & (1 << next))) continue;
		
		int ifUsed = overlap[last][next] + restore(next, used | (1 << next));
		if (ifUsed == restore(last, used))
			results.push_back(words[next].substr(overlap[last][next])
			 + reconstruct(next, used | (1 << next)));
	}
	sort(results.begin(), results.end());
	return ret = results[0];
}

void precalc() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j || (jump[i] || jump[j])) continue;
			
			for (int l = 0; l <= (int)words[i].size(); l++) {
				int compared = min(words[i].size() - l, words[j].size());
				if (words[i].substr(l, compared) == words[j].substr(0, compared)) {
					if (compared == (int)words[j].size()) jump[j] = true;
					overlap[i][j] = compared;
					break;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; i++) cin >> words[i];
	
	int base = 0;
	memset(cache, -1, sizeof(cache));
	fill_n(&rcache[0][0], (NUM + 1) * (1 << NUM), "e");
	
	precalc();
	for (int i = 0; i < N; i++) if (jump[i]) base |= (1 << i);
	
	vector<string> results;	
	int resultValue = -1;
	for (int i = 0; i < N; i++) {
		if (jump[i]) continue;
		int temp = restore(i, base | (1 << i));
		resultValue = max(resultValue, temp);
	}	
	for (int i = 0; i < N; i++) {
		if (jump[i]) continue;
		if (restore(i, base | (1 << i)) == resultValue) 
			results.push_back(words[i] + reconstruct(i, base | (1 << i)));
	}
	sort(results.begin(), results.end());
	cout << results[0] << '\n';
}


#include <iostream>
#include <vector>
#include <algorithm>
#define INF 0x3F3F3F3F
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p;

vector<p> points;

bool xcompare(p a, p b) { return a.first < b.first; }
bool ycompare(p a, p b) { return a.second < b.second; }

ll power(ll a) { return a * a; }

ll dist(p a, p b) {
	ll m = a.first - b.first, n = a.second - b.second;
	return power(m) + power(n);
}

ll bruteforce(int left, int right) {
	ll result = INF;
	for (int i = left; i < right; i++) {
		for (int j = i + 1; j <= right; j++) {
			result = min(result, dist(points[i], points[j]));
		}
	}
	return result;
}

ll solve(int left, int right) {
	if (right - left < 3) return bruteforce(left, right);
	
	int mid = (left + right) / 2;
	ll result = min(solve(left, mid), solve(mid + 1, right));
	
	vector<p> copy;
	for (int i = left; i <= right; i++) {
		if (power(points[i].first - points[mid].first) < result) {
			copy.push_back(points[i]);
		}
	}
	sort(copy.begin(), copy.end(), ycompare);
	
	int csize = copy.size();
	for (int i = 0; i < csize; i++) {
		for (int j = i + 1; j < csize; j++) {
			if (power(copy[i].second - copy[j].second) >= result) break;
			else result = min(result, dist(copy[i], copy[j]));
		}
	}
	return result;
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		ll x, y; cin >> x >> y;
		points.push_back({x, y});
	} 
	sort(points.begin(), points.end(), xcompare);
	cout << solve(0, n - 1) << '\n';
}


#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    long long now=0;
    vector<long long> ret;
    for (int i=0; i<n; i++) {
        now+=x;
        ret.push_back(now);
    }
    return ret;
}
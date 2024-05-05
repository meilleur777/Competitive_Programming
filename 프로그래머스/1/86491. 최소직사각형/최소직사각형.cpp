#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> sizes) {
    for (auto& i:sizes) sort(i.begin(), i.end());

    int a=0, b=0;
    for (auto v:sizes) {
        a=max(a, v[0]);
        b=max(b, v[1]);
    }
    return a*b;
}

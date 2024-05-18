#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> d, int budget) {
    sort(d.begin(), d.end());
    int ptr=0;
    int now=0;
    while (ptr<(int)d.size() && now+d[ptr]<=budget) {
        now+=d[ptr];
        ptr++;
    }
    return ptr;
}
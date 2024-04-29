#include <bits/stdc++.h>
using namespace std;

int n, w;
vector<int> result;
vector<pair<int, int>> event;
vector<vector<int>> cache, choice;

int dist(int a, int b) {
    return abs(event[a].first - event[b].first) + abs(event[a].second - event[b].second); 
}

int dp(int event1, int event2) {
    int nevent=max(event1, event2)+1;
    if (nevent==w+2) return 0;
    
    int& ret=cache[event1][event2];
    int& choose=choice[event1][event2];
    if (ret!=-1) return ret;
    
    int move1=dist(event1, nevent)+dp(nevent, event2);
    int move2=dist(event2, nevent)+dp(event1, nevent);
    if (move1<move2) choose=1;
    else choose=2;

    return ret=min(move1, move2);
}

void reconstruct(int event1, int event2) {
    int nevent=max(event1, event2)+1;
    if (nevent==w+2) return;
    
    int choose=choice[event1][event2];
    result.push_back(choose);

    if (choose == 1) reconstruct(nevent, event2);
    else reconstruct(event1, nevent);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> w;
    event.push_back({1, 1});
    event.push_back({n, n});

    cache=vector<vector<int>>(n+2, vector<int>(n+2, -1));
    choice=vector<vector<int>>(n+1, vector<int>(n+1));
    
    for (int i=0; i<w; i++) {
        int x, y;
        cin >> x >> y;
        event.push_back({y, x});
    }

    cout << dp(0, 1) << '\n';    
    reconstruct(0, 1);
    for (auto i : result) cout << i << '\n';
}
